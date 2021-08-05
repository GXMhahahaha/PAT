#include <iostream>
#include <map>
using namespace std;

map<string,int> mp;
int main(){
	int N,M;
	cin>>N>>M;
	int num = 1;
	
	for(int i=0;i<N;i++){
		string temp;
		cin>>temp;
		if(mp[temp] == 0){
			mp[temp] = num++;
		}
		
		
	}
	for(int i=0;i<M;i++){
		string temp;
		cin>>temp;
		cout<<mp[temp]<<endl;
	}
	
	return 0;
}
