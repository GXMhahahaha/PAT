//��д˼·����ͬ����
//�Ѵ�Ҷ����ɿ�ͷ��0.
//��Чλ����ʵ�ֲ����ýضϣ���������һ���ַ�����һ�����ַ���� 
#include <iostream> 
#include <stdio.h>
#include <string>
using namespace std;

string deal(string str,int N,int &exp){
	while(str.length()>0&&str[0]=='0'){//Ҫ��ȥ��ǰ������Ϊ��һ���������Ȳ�Ҫ�ܵ�һλ�����ǲ����㣬ͳһ���� 
		str.erase(str.begin());
	}
		
	if(str[0]=='.'){
		str.erase(str.begin());
		while(str[0]=='0'&&str.length()>0){
			str.erase(str.begin());
			exp--;
		}
	}	
	
	else{
		int i;
		for(i=0;i<str.length()&&str[i]!='.';i++)
			exp++;
		if(i<str.length()){					//���һ�������i==len 
			str.erase(str.begin()+i);
		}
	}
	
	if(str.length()==0){
		exp=0;
		string temp = "0";
		return temp;
	}
	
	string temp;
	for(int i=0;i<N;i++){
		if(i<str.length()){
			temp+=str[i];
		}
		else{
			temp.insert(temp.end(),'0');
		}
	}
	return temp;		
}
	
int main(){
	int N;
	string str1,str2;
	scanf("%d",&N);
	cin>>str1>>str2;
	
	int exp1=0,exp2=0;
	string str3 = deal(str1,N,exp1);
	string str4 = deal(str2,N,exp2);
	
	if(str3==str4&&exp1==exp2){
		cout<<"YES 0."<<str3<<"*10^"<<exp1;
	}
	else 
		cout<<"NO 0."<<str3<<"*10^"<<exp1<<" 0."<<str4<<"*10^"<<exp2;
	
	return 0;
} 
