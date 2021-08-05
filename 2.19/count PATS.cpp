//A1093 Count PATS
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int maxn = 100010;
int P[maxn];
int main(){
	string str;
	cin>>str;
	int countP = 0;
	int len = 0;
	for(int i=0;i<str.length();i++){
		if(str[i] == 'P'){
			countP++;
		}
		else if(str[i] == 'A'){
			P[len++] = countP;
		}
	}
	int countT=0;
	int ans = 0;
	for(int i=str.length()-1;i>=0;i--){
		if(str[i] == 'T'){
			countT++;
		}
		else if(str[i] == 'A'){
			ans = (long long)(ans + countT*P[--len])%1000000007;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
