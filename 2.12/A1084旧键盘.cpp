//A1084 ¾É¼üÅÌ
#include <string>
#include <iostream>

using namespace std;
bool visited[128] = {0};


int main(){
	string original,input;
	cin>>original>>input;
	
	while(input.length()>0){

		char a = original[0];
		char b = input[0];
		if(a == b){
			original.erase(original.begin());
			input.erase(input.begin());
		}
		else{
			if(a>='a' && a<='z'){
				a = a - 'a' + 'A';
			}
			if(visited[a] == 0){
				cout<<a;				
			}

			visited[a] = 1;
			original.erase(original.begin());
		
		}
		
	}

	while(original.length()>0){
		char a = original[0];
	
		if(a>='a' && a<='z'){
			a = a - 'a' + 'A';
		}
		if(visited[a] == 0){
			cout<<a;				
		}
		visited[a] = 1;
		original.erase(original.begin());
	}
	
	return 0;
} 
