//最长公共子列 
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
string a,b;
const int maxn = 100;
int dp[maxn][maxn] = {0};
vector<char> c[maxn][maxn];

int LCS(){									//注意这道题要从1开始输入 
	int len_a = a.length();
	int len_b = b.length();
	for(int i=0;i<=len_a;i++){
		dp[i][0] = 0;
	}
	for(int i=0;i<=len_b;i++){
		dp[0][i] = 0;
	}
	for(int i=1;i<=len_a;i++){
		for(int j=1;j<=len_b;j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
				c[i][j] = c[i-1][j-1];
				c[i][j].push_back(a[i-1]);
			}
			else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
				if(dp[i][j-1]>=dp[i-1][j]){
					c[i][j] = c[i][j-1];
				}
				else{
					c[i][j] = c[i-1][j];
				}
			}
		}
	}
	return dp[len_a][len_b];
	
}


int main(){
	cin>>a>>b;
 	cout<<LCS()<<endl;
 	int len_a = a.length();
	int len_b = b.length();
	for(int i=0;i<c[len_a][len_b].size();i++)
	cout<<c[len_a][len_b][i];

	return 0;
}
