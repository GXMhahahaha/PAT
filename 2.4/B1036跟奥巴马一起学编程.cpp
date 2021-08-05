//B1036 跟奥巴马一起学编程
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
	int N;
	char c;
	cin>>N>>c;
	int col = round(N/2.0);
	for(int i=0;i<col;i++){
		if(i==0||i==col-1){
			for(int j=0;j<N;j++){
				cout<<c;
			}
		}
		else{
			cout<<c;
			for(int j=0;j<N-2;j++){
				cout<<" ";
			}
			cout<<c;
		}
		cout<<endl;
	}
	return 0;
} 
