//B1027 ´òÓ¡É³Â©
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int sum;
	char c;
	cin>>sum>>c;
	int layer = floor(sqrt((sum+1)/2.0));
	int max = 2*layer-1;
	int cur = max;
	int left = sum+1-2*layer*layer;	
	while(cur>=1){
		for(int i=0;i<(max-cur)/2;i++){
			cout<<" ";
		}
		for(int i=0;i<cur;i++){
			cout<<c;
			sum--;
		}
		cout<<endl;
		cur-=2;		
	}
	cur+=4;
	while(cur<=max){
		for(int i=0;i<(max-cur)/2;i++){
			cout<<" ";
		}
		for(int i=0;i<cur;i++){
			cout<<c;
			sum--;
		}
		cout<<endl;
		cur+=2;				
	}
	cout<<left<<endl;
	return 0;
} 
