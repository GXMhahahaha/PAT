//B1033 旧键盘打字
#include <iostream>
#include <string>

using namespace std;
bool visited[128] = {0};

int main(){
	string original,input;
	cin>>original>>input;
	if(input.size() == 0){						//有可能第一行是空的； 
		cout<<original<<endl;
		return 0;
	}
	for(int i=0;i<original.length();i++){
		char exam = original[i];
		if(exam == '+'){
			for(int i='A';i<='Z';i++){
				visited[i] = 1;
			}
		}
		else if(exam>='A' && exam<='Z'){
			visited[exam] = 1;
			visited[exam-'A'+'a'] = 1;
		} 
	
		else if(exam>='a' && exam<='z'){
			visited[exam] = 1;
			visited[exam-'a'+'A'] = 1;
		}
		else{
	 		visited[exam] = 1;		
		}
	}
	
	for(int i=0;i<input.length();i++){
		if(visited[input[i]] == 0){
			cout<<input[i];
		}
	}
	cout<<endl;
	return 0;
} 
