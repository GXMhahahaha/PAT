//最长回文串
#include <iostream>
#include <string>
using namespace std;

const int maxn = 100;
bool dp[maxn][maxn];
string a;

int Longest(){
	int len = a.length();
	for(int i=0;i<len;i++){
		dp[i][i] = true ;
		if(i<len-1 && a[i] == a[i+1]){
			dp[i][i+1] = true;
		}
		else if(i<len-1 && a[i] != a[i+1]){
			dp[i][i+1] = false;
		}
	}
	for(int ll=3;ll<=len;ll++){
		for(int i=0;i<len;i++){
		
			if(i+ll<=len){
				if(a[i] == a[i+ll-1] && dp[i+1][i+ll-2]==true){
					dp[i][i+ll-1] = true;
				}
				else if(a[i]!=a[i+ll-1]){
					dp[i][i+ll-1] = false;
				}				
			}
			
		}
	}
	int max = -1;
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(dp[i][j] == true && j-i+1>max){
				max = j-i+1;
			}
		}
	}
	return max;
}

int main(){
	cin>>a;
	cout<<Longest();
	return 0;
} 
