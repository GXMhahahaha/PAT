//B1021 ��λ��ͳ��
#include <iostream>
#include <string>
using namespace std;
int hash1[10] = {0};

int main(){
	string num;
	cin>>num;
	for(int i=0;i<num.length();i++){
		hash1[num[i]-'0']++;
	}
	for(int i=0;i<10;i++){
		if(hash1[i]>0){
			cout<<i<<":"<<hash1[i]<<endl;
		}
	}
	return 0;
} 
