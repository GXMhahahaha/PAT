//PAT A1060 
//删除过程注意不要越界 由于小数点不一定存在而产生的越界删除
//注意是字符之间的比较而不是数字 


#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int len(string str){
	int i;
	for(i=0;i<str.length();i++){
		if(str[i]=='.')
			break;
	}
	return i;
}

void standard(string &str){
	if (str.length()==1) 
		return;
	for(int i=0;i<str.length();i++){
		if(str[0]=='0'&&str[1]=='.')
			break;
		if(str[0]=='0'&&str[1]!='.'){
			while(str[0]=='0'&&str[1]!='.') 
				str.erase(str.begin());
		}
	}

}

int zero_num(string str){  //计算所有0的个数 
	int j=0;
	for(int i=0;i<str.length();i++){
		if (str[i]=='0'){
			j++;
			continue;	
			}
		if(str[i]=='.')
			continue;
		else
			break; 
	}
	return j;
}

bool iszero(string str){
	bool flag=1;
	for(int i=0;i<str.length();i++){
		if(str[i]!='0'&&str[i]!='.'){
			flag=0;
			break;	
		}
	
	}
	return flag;
}
int deal(string &str,int N,int num){
	int exp;
	if(iszero(str))
		return 0;
	if(num==1&&str[0]=='0'&&zero_num(str)==1){
		str.erase(str.begin()+N+2,str.end());
		exp = 0;
	}
	
	if(num==1&&str[0]=='0'&&zero_num(str)>1){
		int temp = zero_num(str);
		str.erase(str.begin(),str.begin()+temp);
		str.insert(str.begin()+1,'.');
		if(str.length()-2>=N){
			str.erase(str.begin()+N+2,str.end());
		}
		else{
			while(str.length()-2<N){
				str.insert(str.end(),'0');
			}
		}

		exp = -(temp-1);
	}
		
	if(num>1||(num==1&&str[0]!='0')){
		if(num<str.length()){
			str.erase(str.begin()+num);	
		}
		
		str.insert(0,"0.");
		if(str.length()-2>N){
				str.erase(str.begin()+N+2,str.end());
			}
			else{
				while(str.length()-2<N){
					str.insert(str.end(),'0');
				}
			}
		exp = num;
	}

	return exp;	
}
		
	

int main(){
	int N;
	string str1,str2;
	scanf("%d",&N);
	cin>>str1>>str2;
	
	if(iszero(str1)) {
		str1.clear();
		str1.insert(str1.begin(),'0');
	}
	
	if(iszero(str2)) {
		str2.clear();
		str2.insert(str2.begin(),'0');
	}			

	standard(str1);
	standard(str2);
	
	int num1 = len(str1);
	int num2 = len(str2);
	
	int exp1 = deal(str1,N,num1);
	int exp2 = deal(str2,N,num2);
	
	
	
	if(exp1==exp2&&str1==str2){
		printf("YES ");
		cout<<str1;
		printf("*10^%d",exp1);
	}
	else{
		printf("NO ");
		cout<<str1;
		printf("*10^%d ",exp1);
		cout<<str2;
		printf("*10^%d",exp2);
	}
	
	return 0;
} 
