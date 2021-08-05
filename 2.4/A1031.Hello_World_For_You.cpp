//A1031 Hello World For C
#include <iostream>
#include <string>
using namespace std;

int main(){
	string A;
	cin>>A;
	int max = -1;
	int n2,n1,n3;
	int len = A.length();
	
	for(int i=3;i<=len;i++){
		int temp = (len+2-i)/2;
		if((len+2-i)%2!= 0){
			continue;
		}
		if(temp<=i && temp>max){
			n1 = temp;
			n3 = n1;
			n2 = i;
			max = temp;
		}

	}
	for(int i=1;i<=n1-1;i++){
		cout<<A[i-1];
		for(int j=0;j<n2-2;j++){
			cout<<" ";
		}
		cout<<A[len-i]<<endl;
	}
	for(int j=n1-1;j<=n1+n2-2;j++){
		cout<<A[j];
	}

	return 0;
}
