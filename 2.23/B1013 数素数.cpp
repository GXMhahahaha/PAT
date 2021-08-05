//B1013 ÊıËØÊı
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
#define INF 0x7fffffff
vector <int>ans;
int main(){
	int m,n;
	cin>>m>>n;
	int num = 0;
	for(int i=2;i<=INF;i++){
		bool flag = false;
		for(int j=2;j<=(int)sqrt(i);j++){
			if(i%j==0){
				flag = true;
				break;
			}
		}
		if(flag == false){
			num++;
			if(m<=num&&num<=n){
				ans.push_back(i);
			}
			else if(num>n){
				break;
			}
		}
	}
	
	int count = 0;
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		count++;
		if(count%10 != 0 && i!=ans.size()-1){
			printf(" ");
		}
		else if(count%10 == 0){
			printf("\n");
		}
	}
	
	return 0;
}
