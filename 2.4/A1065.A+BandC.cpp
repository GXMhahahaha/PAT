//A+B and C
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define MAX "9223372036854775808"
#define _Max 9223372036854775807
#define endl '\n'
int main(){
	int T;
	cin>>T;
	long long A,B,C;
	for(int i=0;i<T;i++){
		string stA,stB,stC;
		cin>>stA>>stB>>stC;
		if(stA == MAX||stB == MAX||stC == MAX){
			if(stC == MAX){
				if(stA[0]=='-' || stB[0] == '-'){
					cout<<"Case #"<<i+1<<": false"<<endl;
					continue;	
				}
				else{
					if(stA == MAX){
						A = _Max;
					}
					else if(stA != MAX){
						sscanf(stA.c_str(),"%lld",&A);
						A--;	
					}
				
					if(stB == MAX){
						B = _Max;
					}
					else if(stB != MAX){
						sscanf(stB.c_str(),"%lld",&B);
						A--;	
					}
					C = _Max;
				}
			}
			
			else if(stA == MAX){
				if(stB[0]!='-'){
					cout<<"Case #"<<i+1<<": true"<<endl;
					continue;
				}
				else{
					A = _Max;
					sscanf(stB.c_str(),"%lld",&B);
					B++;
					sscanf(stC.c_str(),"%lld",&C);
				}
			}
			else if(stB == MAX){
					if(stA[0]!='-'){
					cout<<"Case #"<<i+1<<": true"<<endl;
					continue;
				}
				else{
					B = _Max;
					sscanf(stA.c_str(),"%lld",&A);
					A++;
					sscanf(stC.c_str(),"%lld",&C);
				}
			}	
		}
		
		else{
			sscanf(stA.c_str(),"%lld",&A);
			sscanf(stB.c_str(),"%lld",&B);
			sscanf(stC.c_str(),"%lld",&C);
		}
	
		long long sum = A+B;
		if(A>0&&B>0&&sum<0){
			cout<<"Case #"<<i+1<<": true"<<endl;
		}
		else if(A<0&&B<0&&sum>=0){
			cout<<"Case #"<<i+1<<": false"<<endl;
		}
		else if(sum>C){
			cout<<"Case #"<<i+1<<": true"<<endl;
		}
		else if(sum<=C){
			cout<<"Case #"<<i+1<<": false"<<endl;
		} 
	}

	
	return 0;
}
