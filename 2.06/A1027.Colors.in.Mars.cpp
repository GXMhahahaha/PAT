//A1027.Colors in Mars
#include <iostream>
#include <string>
#include <map>
using namespace std;
int col[6];

int main(){
	int R,G,B;
	cin>>R>>G>>B;
	
	int count = 1;
	do{
		int num;
		num = R%13;
		col[count--] = num;
		R/=13;
		
	}while(R>0);
	
	count = 3;
	do{
		int num;
		num = G%13;
		col[count--] = num;
		G/=13;
		
	}while(G>0);
	
	count = 5;
	do{
		int num;
		num = B%13;
		col[count--] = num;
		B/=13;
		
	}while(B>0);
	
	map<int,char> mp;
	mp[10] = 'A';
	mp[11] = 'B';
	mp[12] = 'C';
	cout<<"#";
	for(int i=0;i<6;i++){
		if(col[i]>9){
			cout<<mp[col[i]];
		}
		else{
			cout<<col[i];
		}
	}
	
	return 0;
}
