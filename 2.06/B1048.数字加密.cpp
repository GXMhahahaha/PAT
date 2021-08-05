//B1048 Êı×Ö¼ÓÃÜ
#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
char c[13] = {'0','1','2','3','4','5','6','7','8','9','J','Q','K'};
int a[105]={0};
int b[105]={0};

int main(){
	string A,B;
	cin>>A>>B;
	
	int m = 1;
	for(int i=A.length()-1;i>=0;i--){
		a[m++] = A[i]-'0';
	}
	
	int j=1;
	for(int i=B.length()-1;i>=0;i--){
		b[j++] = B[i]-'0';
	}

	for(int k=1;k<max(m,j);k++){
		if(k%2==1){
			int temp = (a[k]+b[k]) % 13;
			s.push(c[temp]);
		}
		else{
			int temp = b[k] - a[k];
			if(temp<0){
				temp+=10;
				s.push('0'+temp);
			}
			else{
				s.push('0'+temp);
			}
		}
	}

	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	return 0;
}
