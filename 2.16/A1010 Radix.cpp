//A1010 Radix 
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

string N1,N2;
int comp;

map<char,int> mp;
void Init(){
	for(char c='0';c<='9';c++){
		mp[c] = c-'0';
	}
	for(char c='a';c<='z';c++){
		mp[c] = c-'a'+10;
	}
}

long long change(string num,int radix){			//把一个radix进制的数字转换为10进制 
	long long re = 0;
	for(int i=0;i<num.length();i++){
		re = re*radix + (mp[num[i]]);
		if(re<0){
			return -1;
		}
	}
	return re;
}

int cmp(long long a,long long b){
	if(b<0){
		return -1;
	}
	else if(a == b){
		return 0;
	}
	else if(a<b){
		return -1;
	}
	else if(a>b){
		return 1;
	}
}

int BiSearch(long long low,long long high,long long compare){
	
	while(low<=high){
	
		long long mid = (low+high)/2;
		long long midnum = change(N2,mid);
		int flag = cmp(compare,midnum);
		if(flag == 0){
			return mid;
		}
		if(flag == 1){
			low = mid+1;
		}
		else if(flag == -1){
			high = mid-1;
		}
	}
	return -1;
}

int main(){
	int flag;
	long long radix;
	cin>>N1>>N2>>flag>>radix;
//	long long comp;
	if(N1==N2){
		cout<<radix<<endl;
		return 0;
	}	
	if(flag == 2 ){									//一切以第一种情况为准，如果不是第一种情况，就把他转换为第一种情况 
		swap(N1,N2);
	}
	Init();
	long long compare = change(N1,radix); 
	long long min = -1;
	for(int i=0;i<N2.length();i++){
		if(min < mp[N2[i]] ){
			min = mp[N2[i]];
		}
	}
	long long MAX = max(min+1,compare)+1;
	
	int re = BiSearch(min+1,MAX,compare);
	if(re == -1){
		cout<<"Impossible"<<endl;
	}
	else{
		cout<<re<<endl;
	}
	
	return 0;
}
