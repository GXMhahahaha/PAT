//B1039 µ½µ×Âò²»Âò
#include <iostream>
#include <string>
using namespace std;

int hashTable[128] = {0};

int main(){
	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.length();i++){
		hashTable[a[i]]++;
	}
	for(int i=0;i<b.length();i++){
		hashTable[b[i]]--;
	}
	int extra = 0;
	int less = 0;
	for(int i=0;i<128;i++){
		if(hashTable[i]>0){
			extra+=hashTable[i];
		}
		else if(hashTable[i]<0){
			less+=(-hashTable[i]);
		}
	}
	//cout<<hashTable['8']<<endl;
	if(less>0){
		cout<<"No "<<less<<endl;
	}
	else{
		cout<<"Yes "<<extra<<endl;
	}
	return 0;
} 
