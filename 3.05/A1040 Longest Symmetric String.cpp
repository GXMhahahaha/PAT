//A1040 Longest Symmetric String 
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int maxn = 1010;
int dp[maxn][maxn];

int main(){
	string str;
	getline(cin,str);
	int len = str.length();
	for(int i=0;i<len;i++){
		dp[i][i] = 1;
	}

	
	int j=0;
	while(j+2<=len){
		if(str[j] == str[j+1]){
			
			dp[j][j+1] = 1;
			
		}
		else{
			dp[j][j+1] = 0;
		}
		j++;
	}	
	
	
	
	for(int ll = 3;ll<=len;ll++){
		int i=0;
		while(i+ll<=len){
			if(str[i] == str[i+ll-1]){
				if(dp[i+1][i+ll-2] == 1){
					dp[i][i+ll-1] = 1;
				}
			}
			else{
				dp[i][i+ll-1] = 0;
			}
			i++;
		}
	}
	
	int maxn = -1;
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(dp[i][j] && j-i+1 > maxn){
				maxn = j-i+1;
			}
		}
	}
	cout<<maxn<<endl;
	return 0;
} 
