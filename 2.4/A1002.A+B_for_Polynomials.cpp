//A1002.A+B for Polynmials;
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1010;
double coef1[maxn] = {0};
double coef2[maxn] = {0};

vector<int> ex;
vector<double> coe;

int main(){
	int N1;
	cin>>N1;
	for(int i=0;i<N1;i++){
		int pos;
		cin>>pos;
		scanf("%lf",&coef1[pos]);
	}
	int N2;
	cin>>N2;
	for(int i=0;i<N2;i++){
		int pos;
		cin>>pos;
		scanf("%lf",&coef2[pos]);
	}
	
	for(int i=maxn-1;i>=0;i--){
		coef2[i] = coef1[i]+coef2[i];
		if(coef2[i]!=0){
			ex.push_back(i);
			coe.push_back(coef2[i]);
		}
	}
	cout<<ex.size();
	if(ex.size() > 0){
		cout<<" ";
	} 
	for(int i=0;i<ex.size();i++){
		printf("%d ",ex[i]);
		printf("%.1f",coe[i]);
		if(i<ex.size()-1){
			cout<<" ";
		}
	}
	
	return 0;
}
