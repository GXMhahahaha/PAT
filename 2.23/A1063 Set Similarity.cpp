//A1063 Set Similarity
#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
const int maxsize = 55;
set<int> st[maxsize];
int main(){
	int set_num;
	cin>>set_num;
	for(int i=0;i<set_num;i++){
		int data_num;
		cin>>data_num;
		for(int j=0;j<data_num;j++){
			int num;
			scanf("%d",&num);
			st[i+1].insert(num);
		}
	}
	
	int require_num;
	cin>>require_num;
	for(int i=0;i<require_num;i++){
		int fir,sec;
		scanf("%d %d",&fir,&sec);
		
		int count = 0;
		for(set<int> :: iterator it1 = st[fir].begin();it1!=st[fir].end();it1++){
			if(st[sec].find(*it1)!=st[sec].end()){
				count++;
			}
		}

		double ans = count*1.0/(st[fir].size()+st[sec].size()-count);
		ans*=100;
		printf("%.1f%\n",ans);

	}
	
	return 0;
}
