//A1042 Shuffling Machine 其实变换牌的编号即可，变完之后再反向计算 
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
string P[54];
string Q[54];
int del[54];

void Init(){
	int j = 0;
	for(int i=0;i<9;i++){
		P[j].push_back('S');
		P[j].push_back(i+1+'0');
		j++;
	}
	P[j++] = "S10";
	P[j++] = "S11";
	P[j++] = "S12";
	P[j++] = "S13";
	
	for(int i=0;i<9;i++){
		P[j].push_back('H');
		P[j].push_back(i+1+'0');
		j++;
	}
	
	P[j++] = "H10";
	P[j++] = "H11";
	P[j++] = "H12";
	P[j++] = "H13";
	
	for(int i=0;i<9;i++){
		P[j].push_back('C');
		P[j].push_back(i+1+'0');
		j++;
	}
	
	P[j++] = "C10";
	P[j++] = "C11";
	P[j++] = "C12";
	P[j++] = "C13";
	
	for(int i=0;i<9;i++){
		P[j].push_back('D');
		P[j].push_back(i+1+'0');
		j++;
	}
	
	P[j++] = "D10";
	P[j++] = "D11";
	P[j++] = "D12";
	P[j++] = "D13";
	
	P[j++] = "J1";
	P[j] = "J2";
		
}

void change(){
	for(int i=0;i<54;i++){
		Q[del[i]-1] = P[i];
	}
	
	for(int i=0;i<54;i++){
		P[i] = Q[i];
	}
}
int main(){
	Init();
	int N;
	cin>>N;
	for(int i=0;i<54;i++){
		cin>>del[i];
	}
	for(int i=0;i<N;i++){
		change();
	}
	
	for(int i=0;i<54;i++){
		cout<<Q[i];
		if(i<53){
			cout<<" ";
		}
	}
	
	return 0;
} 
