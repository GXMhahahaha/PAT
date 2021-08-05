//A1048.Find.Coins
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int ht[1010] = {0};
int data[100010];
bool cmp(int a,int b){
	return a<b;
}

int main(){
	int N,M;
	cin>>N>>M;
	int validnum = 0;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		if(x < M){
			data[i] = x;
			ht[x]++;
			validnum++;			
		}

		
	}
	
	sort(data,data+validnum,cmp);
	
	for(int i=0;i<validnum;i++){
		int original = data[i];
		int other = M - data[i];
		
		if(ht[other] >= 1){
			if(other == original && ht[other] ==1){
				continue;
			} 
			
			cout<<data[i]<<" "<<other<<endl;
			return 0;
		}
	}
	cout<<"No Solution"<<endl;
	
	return 0;
}
