#include <iostream>
using namespace std;

int hashT[10001] = {0};
int sequence[100010];
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		
		cin>>sequence[i];
		hashT[sequence[i]]++;
	}
	
	for(int i=0;i<N;i++){
		if(hashT[sequence[i]] == 1){
			cout<<sequence[i]<<endl;
			return 0;
		}
	}
	cout<<"None"<<endl;
	return 0;
} 
