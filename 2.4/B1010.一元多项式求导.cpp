//B1010 一元多项式求导
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 10010;
int di[maxn];
int zhi[maxn];
vector<int> vec;
int main(){
	int num = 0;
	do{
		scanf("%d %d",&di[num],&zhi[num]);
		num++;
	}while(getchar()!='\n');
	for(int i=0;i<num;i++){
		di[i] = di[i]*zhi[i];
		zhi[i]--;
		if(zhi[i]>=0){
			vec.push_back(di[i]);
			vec.push_back(zhi[i]);
		}
	}
	if(vec.size()==0){
		cout<<"0 0";
		return 0;
	}
	
	for(int i=0;i<vec.size();i++){
		cout<<vec[i];
		if(i<vec.size()-1){
			cout<<" ";
		}
	} 
	
	return 0;
} 
