//简单计算器
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;
const int maxn =100;

map<char,int> op;

struct NODE{
	int num;
	char oper;
	bool flag; 				//0表示数字 1表示符号 
}node[maxn];

stack <char> s1;
stack <double> s2;

int midToback(string &a){
	int i = 0;
	while(a.length()!=0){
		if(a[0]>='0'&&a[0]<='9'){
			int temp = 0; int pow = 10;
			while(a[0]>='0'&&a[0]<='9'&&a.length()!=0){
				node[i].num = temp*pow+(a[0]-'0');
				temp = node[i].num;
				a.erase(a.begin()); 
			}
			node[i].flag = 0;
			i++; 
		}
		
		else if(a[0]=='('){
			s1.push(a[0]);
			a.erase(a.begin());
		}
		
		else if(a[0]==')'){
				a.erase(a.begin());
			
			while(s1.top()!='('){
		
				node[i].oper = s1.top();
				node[i].flag = 1;
				i++;
				s1.pop();
			}
			s1.pop();
		}
		else{
		
			if(s1.empty()){
				s1.push(a[0]);
				a.erase(a.begin());
			}
			else{
			
				if(op[a[0]] > op[s1.top()]){
					s1.push(a[0]);
					a.erase(a.begin());
				}
				
				else{
					while(!s1.empty()){
						if(op[a[0]] <= op[s1.top()]){
							node[i].oper = s1.top();
							node[i].flag = 1;
							i++;
							s1.pop();	
						}
						else
							break; 
						
						
					}
					s1.push(a[0]);
					a.erase(a.begin());	
				}	
			}
		
		}
	
	}
	while(!s1.empty()){
		node[i].oper = s1.top();
		node[i].flag = 1;
		i++;
		s1.pop();
	}
	return i;
}

double calculate(NODE node[],int len){
	int i = 0;
	while(i<len){
		if(node[i].flag==0){
			s2.push(node[i].num);
			i++;
		}
		else{
			double temp2 = s2.top()*1.0;
			s2.pop();
			double temp1 = s2.top()*1.0;
			s2.pop();
			if (node[i].oper == '+'){
				s2.push(temp1 + temp2);
			}
			else if (node[i].oper == '-'){
				s2.push(temp1 - temp2);
			}	
			else if (node[i].oper == '*'){
				s2.push(temp1 * temp2);
			}
			else if (node[i].oper == '/'){
				s2.push(temp1 / temp2);
			}
			i++;	
		}	
	}
	return s2.top();
	
}


int main(){
	string a;
	cout<<"输入表达式，中间不要有空格"<<endl;
	cin>>a;
	op['('] = 0;
	op['+'] = 1; op['-'] = 1;
	op['*'] = 2; op['/'] = 2;

 	int len = midToback(a);

 	for(int i=0;i<len;i++){
 		if(node[i].flag == 0){
 			cout<<node[i].num;
		 }
		 else{
		 	cout<<node[i].oper;
		 }
	 }
	
	printf("\n%.2f",calculate(node,len));

	
	
	return 0;
} 
