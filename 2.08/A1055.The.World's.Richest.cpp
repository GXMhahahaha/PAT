//A1055.The.World's.Richest
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
}per[maxn];

struct Per_temp{
	string name;
	int age;
	int wealth;
}temp[maxn];

bool Search(int low,int high,int& st,int& en){
	for(st=0;st<N;st++){
		if(per[st].age<low){
			st++;
		}
		else{
			break;
		}
	}
	
	if(per[st].age > high || per[st].age < low){
		return 0;
	}
	
	for(en=st;en<N;en++){
		if(per[en].age<=high){
			en++;
		}
		else{
			break;
		}
	}

	return 1;
}


bool cmp1(Per a,Per b){
	return a.age<b.age;
}

bool cmp2(Per_temp a,Per_temp b){
	if(a.wealth!=b.wealth)
		return a.wealth > b.wealth;
	else if(a.wealth!=b.wealth){
		a.age<b.age;
	}
	else if(a.name!=b.name){
		return a.name<b.name;
	}
}

int main(){

	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>per[i].name>>per[i].age>>per[i].wealth;
	}
	sort(per,per+N,cmp1);
	cout<<endl;
	for(int i=0;i<N;i++){
		cout<<per[i].name<<" "<<per[i].age<<" "<<per[i].wealth<<endl;
	}
	
	for(int i=0;i<M;i++){
		int num,low,high;
		cin>>num>>low>>high;
		int st=0,en=0;								//st开始位置  en位置下一位 
		
		bool flag = Search(low,high,st,en);
		
		if(flag == 0){
			cout<<"Case #"<<i+1<<":"<<endl<<"None"<<endl;
		}
		else{
			cout<<"Case #"<<i+1<<":"<<endl;
			int len = en-st;
			cout<<st<<" "<<en<<" "<<endl;
			cout<<len<<endl;
			for(int k=st,j=0;j<len;j++,k++){
				temp[j].age = per[k].age;
				temp[j].name = per[k].name;
				temp[j].wealth = per[k].wealth;
			}
			sort(temp,temp+len,cmp2);
			if(len>=num){
				for(int j=0;j<num;j++){
					cout<<temp[j].name<<" "<<temp[j].age<<" "<<temp[j].wealth<<endl;
				}
			}
			else if(len<num){
				for(int j=0;j<len;j++){
					cout<<temp[j].name<<" "<<temp[j].age<<" "<<temp[j].wealth<<endl;
				}
			}
		}
		
	}
	return 0;
}
