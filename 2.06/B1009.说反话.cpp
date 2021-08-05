//B1009. Ëµ·´»°
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int main(){
	string str;
	getline(cin,str);
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	reverse(str.begin(),str.end());
	string :: iterator start,final;
	start = str.begin();
	final = str.begin();
	while(final!=str.end()+1){
		while(*final != ' ' && final!=str.end()){
			final++;
		}
		reverse(start,final);
		final++;
		start = final;
		
	}
	cout<<str;

	
	
	return 0;
}
