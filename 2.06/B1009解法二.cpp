//B1009½â·¨2
#include <iostream>
#include <string>

using namespace std;
const int maxn = 90;
string a[maxn]; 

int main(){
	int num=0;
	do{
		cin>>a[num++];
	}while(getchar()!='\n');
	
	for(int j=num-1;j>=0;j--){
		cout<<a[j];
		if(j>0){
			cout<<" ";
		}
	}
	return 0;
}
