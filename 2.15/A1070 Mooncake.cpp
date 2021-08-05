//A1070 Mooncake
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 1010;
struct Mooncake{
	double storage;
	double price;
	double t_price;
}m[maxn];

bool cmp(Mooncake a,Mooncake b){
	return a.price > b.price;
}

int main(){
	int N,inventory;
	cin>>N>>inventory;
	for(int i=0;i<N;i++){
		cin>>m[i].storage;
	} 
	
	for(int i=0;i<N;i++){
		double temp;
		cin>>temp;
		m[i].t_price = temp;
		m[i].price = temp/m[i].storage;
	}
	
	double total = 0;
	double curr = 0;
	sort(m,m+N,cmp);
	for(int i=0;i<N;i++){
	
		if(curr+m[i].storage <= inventory){
			total+=m[i].t_price;
			curr+=m[i].storage;
			
		}
		else{
			total+=((inventory-curr)/m[i].storage)*m[i].t_price;
			break;			
		}
		
		
	} 
	printf("%.2f\n",total);

	return 0;
}
