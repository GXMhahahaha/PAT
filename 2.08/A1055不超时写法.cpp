//A1055.The.World's.Richest
//这道题只要求输出一段年龄的一部分人，因此要把财富排名高于100的舍弃掉 
#include <iostream>
#include <string>
#include <algorithm>

#define endl '\n'
using namespace std;

const int maxn = 100010;
int N,M;
struct Per{
	string name;
	int age;
	int wealth;
}per[maxn],valid[maxn]; 


bool cmp(Per a,Per b){
	if(a.wealth != b.wealth){
		return a.wealth > b.wealth;
	}
	else if(a.age != b.age){
		return a.age < b.age;
	}
	else if(a.name != b.name){
		return a.name < b.name;
	}
}

int age_count[201] = {0};

int main(){

	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>per[i].name>>per[i].age>>per[i].wealth;
	}
	sort(per,per+N,cmp);
	int valid_num = 0;
	for(int i=0;i<N;i++){
		if(age_count[per[i].age] <= 100){
			valid[valid_num++] = per[i];
			age_count[per[i].age]++;
		}
	}
	
	for(int i=0;i<M;i++){
		int num,low,high;
		cin>>num>>low>>high;
		cout<<"Case #"<<i+1<<":"<<endl;
		bool flag = false;
		int out_num = 0; 
		for(int j=0;j<valid_num;j++){
			if(valid[j].age>=low && valid[j].age<=high && out_num < num){
				cout<<valid[j].name<<" "<<valid[j].age<<" "<<valid[j].wealth<<endl;
				out_num++;
				flag = true;
			}

		}
		if(flag == false){
			cout<<"None"<<endl;
		}
	}
	

	return 0;
}
