//A1022 Digital Library
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

map<string,set<int>> mp[5];

//mp1,mp2,mp3,mp4,mp5;
int main(){
	int N;
	cin>>N;
	getchar();
	for(int i=0;i<N;i++){
		int id;
		string title;
		string author;
		string key;
		string publisher;
		string year;
		cin>>id;
		getchar();
		getline(cin,title);
		getline(cin,author);
		getline(cin,key);
		getline(cin,publisher);
		getline(cin,year);
		
		mp[0][title].insert(id);
		mp[1][author].insert(id);
		int pre=0,post=0;
		while(post<key.length()){
			while(key[post]!=' ' && post<key.length()){
				post++;
			}
			int len = post-pre;
			mp[2][key.substr(pre,len)].insert(id);
			post++;
			pre = post;
		}
		
		mp[3][publisher].insert(id);
		mp[4][year].insert(id);
	}
	int K;
	cin>>K;
	for(int i=0;i<K;i++){
		int q;
		scanf("%d: ",&q);
		string req;
		getline(cin,req);
		cout<<q<<": "<<req<<endl;
		if(mp[q-1][req].size()==0){
			cout<<"Not Found"<<endl;
		}
		else{
			for(set<int> :: iterator it=mp[q-1][req].begin();it!=mp[q-1][req].end();it++){
				//cout<<*it<<endl;
				printf("%07d\n",*it);
			}	
		}

	}
	
	
	return 0;
} 
