//B1018 ´¸×Ó¼ôµ¶²¼
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;
map<char,int> mp1,mp2;
map<int,char> num_char;
map<char,int> char_num;

int A_win=0,A_eq=0,A_los=0;
int B_win=0,B_eq=0,B_los=0;

void Judge(char a,char b){
	int x1 = char_num[a];
	int x2 = char_num[b];
	if((x1+1)%3 == x2){
		A_win++;
		B_los++;
		mp1[a]++;
	}
	else if(x1==x2){
		A_eq++;
		B_eq++;
	}
	else if((x2+1)%3 == x1){
		A_los++;
		B_win++;
		mp2[b]++;
	}
}

int main(){
	
	mp1['C'] = 0;
	mp1['J'] = 0;
	mp1['B'] = 0;
	mp2['C'] = 0;
	mp2['J'] = 0;
	mp2['B'] = 0;
	num_char[0] = 'C';
	num_char[1] = 'J';
	num_char[2] = 'B';
	char_num['C'] = 0;
	char_num['J'] = 1;
	char_num['B'] = 2;
	
	int N;
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++){
		char a,b;
		scanf("%c %c",&a,&b);
		getchar();
		Judge(a,b);
	}
	cout<<A_win<<" "<<A_eq<<" "<<A_los<<endl
	<<B_win<<" "<<B_eq<<" "<<B_los<<endl;
	
	map<char,int> :: iterator it;
	map<char,int> :: iterator it1;
	map<char,int> :: iterator it2;
	int max1 = -1;
	int max2 = -1;
	for(it=mp1.begin();it!=mp1.end();it++){
		if(it->second > max1){
			it1 = it;
			max1 = it->second; 
		}
	}

	for(it=mp2.begin();it!=mp2.end();it++){
		if(it->second > max2){
			it2 = it;
			max2 = it->second;
		}
	}
	cout<<it1->first<<" "<<it2->first;

	
	return 0;
} 
