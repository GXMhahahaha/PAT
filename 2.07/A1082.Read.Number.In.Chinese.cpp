#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string c[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string d[5] = {"Shi","Bai","Qian","Wan","Yi"};

string re[20];

int main(){
	string str;
	cin>>str;
	int len = 0;
	if(str[0] == '-'){
		re[len++] = "Fu";
		str.erase(str.begin());
	}
	int left = 0, right = str.length()-1;
	while(right-left>3){
		right-=4;
	}
	
	bool flag = false;
	while(left<str.length()){
		bool isprint = false;
		while(left<=right){
			if(left>0 && str[left] == '0'){
				flag = true;
			}
			else{
				if(flag == true){
					re[len++] = "ling";
					flag = false;
				}
				re[len++] = c[str[left]-'0'];
				isprint = true; 
				
				if(left!=right){
					re[len++] = d[right-left-1];
				}
				
			}
			left++;
		}
		if(isprint == true && right != str.length()-1){
			re[len++] = d[(str.length()-right)/4+2]; 
		}
		right+=4;
		
	}
	
	for(int i=0;i<len;i++){
		cout<<re[i];
		if(i<len-1){
			cout<<" ";
		}
	}

	
	return 0;
} 
