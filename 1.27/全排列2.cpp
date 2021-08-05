//全排列
#include <iostream>
using namespace std; 
const int maxn = 100;
int N;
bool visit[maxn]={0};   //此处用hash可以提高速度 
int pp[maxn];
void P(int index){
	if(index == N){
		for(int i=0;i<N;i++){
			cout<<pp[i];
		}
		cout<<endl;
	}
	for(int x=1;x<=N;x++){
		bool flag = false;
		for(int i=0;i<index;i++){
		
			if(visit[x]!=0){
				flag = true;
				break;

			}
		}
		if(flag == false){
			pp[index] = x;
			visit[x] = 1;
			P(index+1);
			visit[x] = 0;			
		}		

	}
}

int main(){
	cin>>N;
	P(0);
	return 0;
} 
