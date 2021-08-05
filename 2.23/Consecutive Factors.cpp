//A1096 Consecutive Factors
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
vector<int> ans;
vector<int> temp_ans;
int main(){
	int N;
	cin>>N;
	int maxlen = 0;
	int templen = 0;	
	for(int i=2;i<=(int)sqrt(1.0*N);i++){
	
		if(N%i == 0){
			temp_ans.clear();
			temp_ans.push_back(i);
			templen = 1;
			int div = i;
			for(int j=i+1;j<=N;j++){
				div*=j;
				if(N%div==0){
					temp_ans.push_back(j);
					templen++;
				}
				else{
					break;
				}
			}

			if(templen > maxlen){
				ans = temp_ans;
				maxlen = templen;
			}
		}
	}

	if(templen == 0){
		cout<<"1"<<endl<<N<<endl;
		return 0;
	}
	
	cout<<maxlen<<endl;
	for(int i=0;i<maxlen;i++){
		printf("%d",ans[i]);
		if(i<maxlen-1){
			printf("*");
		}
	}
	cout<<endl;	

	return 0;
}
 
