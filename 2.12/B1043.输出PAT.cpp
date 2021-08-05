//B1043 Êä³öPATest
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char,int> mp;
void Init(){
	mp['P'] = 0;
	mp['A'] = 0;
	mp['T'] = 0;
	mp['e'] = 0;
	mp['s'] = 0;
	mp['t'] = 0;
	
}

//int visited[7] = {0};
int main(){
	Init();
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(mp.count(a[i])>0){
			mp[a[i]]++;
		}
	}
	int max = -1;
	for(map<char,int> :: iterator it = mp.begin();it!=mp.end();it++){
		if(max < it->second){
			max = it->second;
		}
	}
	
	while(max>0){
		if(mp['P'] > 0){
			cout<<"P";
			mp['P']--;
		}
		if(mp['A'] > 0){
			cout<<"A";
			mp['A']--;
		}
		if(mp['T'] > 0){
			cout<<"T";
			mp['T']--;
		}
		if(mp['e'] > 0){
			cout<<"e";
			mp['e']--;
		}
		if(mp['s'] > 0){
			cout<<"s";
			mp['s']--;
		}
		if(mp['t'] > 0){
			cout<<"t";
			mp['t']--;
		}
		max--;
	}
	
	
	return 0;
} 
