//B1043 Êä³öPATest
#include <iostream>
#include <string>
using namespace std;
int hashT[6] = {0};
char dic[6] = {'P','A','T','e','s','t'};

int main(){
	string a;
	cin>>a;
	int sum = 0;
	for(int i=0;i<a.length();i++){
		for(int j=0;j<6;j++){
			if(a[i] == dic[j]){
				hashT[j]++;
				sum++;
			}
		}
	}
	
	while(sum>0){
		for(int i=0;i<6;i++){
			if(hashT[i]>0){
				cout<<dic[i];
				hashT[i]--;
				sum--;
			}
		}
	}
	
	return 0;
} 
