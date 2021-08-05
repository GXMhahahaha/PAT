//A1059.Prime Factors
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const int maxn = 1e5;
int Prime[maxn];
struct Prime_factor{
	int num;
	int exp;
};


vector<Prime_factor> ans;
int main(){
	int N;
	cin>>N;
	if(N==1){
		cout<<"1=1"<<endl;
		return 0;
	}
	int ori = N;
	int count = 0;
	for(int i=2;i<=(int)sqrt(1.0*N);i++){
		bool flag = true;
		for(int j=2;j<=(int)sqrt(1.0*i);j++){
			if(i%j==0){
				flag = false;
			}
		}
		if(flag == true){
			Prime[count++] = i;
		}
	}
	
	for(int i=0;i<count;i++){
		
		if(N%Prime[i] == 0){
			int co = 0;
			int nu = Prime[i];
			
			while(N%Prime[i] == 0){
				co++;
				N/=Prime[i];
			
			}
			Prime_factor temp;
			temp.num = nu;
			temp.exp = co;
			ans.push_back(temp);		
		}

	}
	
	if(N>1){
		Prime_factor temp;
		temp.num = N;
		temp.exp = 1;
		ans.push_back(temp);
	}
	
	cout<<ori<<"=";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].num;
		if(ans[i].exp>1){
			cout<<"^"<<ans[i].exp;
		}
		if(i<ans.size()-1){
			cout<<"*";
		}
	}
    cout<<endl;
	return 0;
}
