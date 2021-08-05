//A1054 The Dominant Color
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> mp;


int main(){
	int M, N;
	cin>>M>>N;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			int color;
			scanf("%d",&color);
			if(mp.count(color) == 0){
				mp[color] = 1;
			}
			else{
				mp[color]++;
			}
		}
	}
	
	int max = -1;
	int ans;
	for(map<int,int> :: iterator it = mp.begin();it!=mp.end();it++){
		if(it->second > max){
			max = it->second;
			ans = it->first;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
