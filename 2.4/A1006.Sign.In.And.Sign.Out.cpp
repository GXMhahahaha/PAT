//A1006.Sign In And Sign Out;
#include <cstdio>
#include <iostream>
using namespace std;
#define MAX 235959
#define MIN 000000
int main(){
	int N;
	cin>>N;
	int max = MAX+1;
	int min = MIN-1;
	string fir,las;
	
	for(int i=0;i<N;i++){
		string id;
		int in_h,in_m,in_s;
		int out_h,out_m,out_s;
		cin>>id;
		scanf("%d:%d:%d",&in_h,&in_m,&in_s);
		scanf("%d:%d:%d",&out_h,&out_m,&out_s);
		int intime = in_h*1e4+in_m*1e2+in_s;
		int outime = out_h*1e4+out_m*1e2+out_s;
		if(intime<max){
			fir = id;
			max = intime;
		}
		if(outime>min){
			las = id;
			min = outime;
		}
	}
	cout<<fir<<" "<<las<<endl;
	return 0;
}
