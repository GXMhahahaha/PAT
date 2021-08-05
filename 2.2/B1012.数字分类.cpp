//B1012 数字分类 在输入时进行分类 
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000;
vector<int> A1,A2,A3,A4,A5;

int main(){
	int N;
	scanf("%d ",&N);
	for(int i=0;i<N;i++){
		int temp;
	//	scanf("%d",&temp);
		cin>>temp;
		if(temp%5==0 && temp%2==0){
			A1.push_back(temp);
		}
		else if(temp%5==1){
			A2.push_back(temp);
		}
		else if(temp%5==2){
			A3.push_back(temp);
		}
		else if(temp%5==3){
			A4.push_back(temp);
		}
		else if(temp%5==4){
			A5.push_back(temp);
		}
	}
	int a1=0,a2=0,a3=0;
	double a4;
	int a5 = -1;
	for(int i=0;i<A1.size();i++){
		a1+=A1[i];
	}
	for(int i=0;i<A2.size();i++){
		if((i+1)%2==1){
			a2+=A2[i];
		}
		else{
			a2-=A2[i];
		}
	}
	a3 = A3.size();
	int sum=0;
	for(int i=0;i<A4.size();i++){
		sum+=A4[i];
	}
	if(A4.size()!=0){
		a4 = sum*1.0/A4.size();	
	}

	
	for(int i=0;i<A5.size();i++){
		if(a5 < A5[i]){
			a5 = A5[i];
		}
	}
	
	if(A1.size()==0){
		printf("N ");
	}
	else if(A1.size()!=0){
		cout<<a1<<" ";
	}
	
	if(A2.size()==0){
		printf("N ");
	}
	else if(A2.size()!=0){
		cout<<a2<<" ";
	}
	
   	if(A3.size()==0){
		printf("N ");
	}
	else if(A3.size()!=0){
		cout<<a3<<" ";
	}
	
	if(A4.size()==0){
		printf("N ");
	}
	else if(A4.size()!=0){
		printf("%.1f ",a4);
	}

	if(A5.size()==0){
		printf("N");
	}
	else if(A5.size()!=0){
		cout<<a5;
	}
	return 0;
} 
