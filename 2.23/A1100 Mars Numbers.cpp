//A1100 Mars Numbers   火星文的个位0不会输出 
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#define endl '\n'
using namespace std;

string unitDigit[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string,int> unitMar;
map<string,int> tenMar;

void Init(){
	unitMar["tret"] = 0;
	unitMar["jan"] = 1;
	unitMar["feb"] = 2;
	unitMar["mar"] = 3;
	unitMar["apr"] = 4;
	unitMar["may"] = 5;
	unitMar["jun"] = 6;
	unitMar["jly"] = 7;
	unitMar["aug"] = 8;
	unitMar["sep"] = 9;
	unitMar["oct"] = 10;
	unitMar["nov"] = 11;
	unitMar["dec"] = 12;
	
	tenMar["tret"] = 0;
	tenMar["tam"] = 1;
	tenMar["hel"] = 2;
	tenMar["maa"] = 3;
	tenMar["huh"] = 4;
	tenMar["tou"] = 5;
	tenMar["kes"] = 6;
	tenMar["hei"] = 7;
	tenMar["elo"] = 8;
	tenMar["syy"] = 9;
	tenMar["lok"] = 10;
	tenMar["mer"] = 11;
	tenMar["jou"] = 12;

}

string tenTothirteen(int num){
	string ans;
	do{
		ans+=num%13+'0';
		num/=13;
	}while(num>0);
	reverse(ans.begin(),ans.end());
	return ans;

}

int thirteenToten(int num[],int count){
	int ans = 0;
	for(int i=0;i<count;i++){
		ans = ans*13+num[i];
	}
	return ans;
}

int main(){
	int N;
	cin>>N;
	getchar();
	Init();
	for(int i=0;i<N;i++){
		string str;
		getline(cin,str);
		if(str[0]>='0' && str[0]<='9'){
			int num;
			sscanf(str.c_str(),"%d",&num);
			string ans = tenTothirteen(num);
			for(int i=0;i<ans.length();i++){
				if(i!=ans.length()-1){
					cout<<tenDigit[ans[i]-'0'];
					if(i<ans.length()-2 || ((i==ans.length()-2) && ans[i+1] != '0')){
						cout<<" ";
					}
				}
				else if(i==ans.length()-1){
					if(ans[i]!='0'){
						cout<<unitDigit[ans[i]-'0'];
					}
					else if(ans[i]=='0' && ans.length()==1){
						cout<<unitDigit[ans[i]-'0'];
					}
				}
				
			}
			cout<<endl;
		}
		else{
			int num[10];
			int pos = 0;
			int count = 0;
			
			while(pos<str.length()-3){
				num[count++] = tenMar[str.substr(pos,3)];
				pos+=4;
			}
			
			if(unitMar.count(str.substr(pos,3)) == 0){
				num[count++] = tenMar[str.substr(pos,3)];
				num[count++] = 0;
			}
			else{
				num[count++] = unitMar[str.substr(pos,3)];	
			}

			cout<<thirteenToten(num,count)<<endl;
		}

	}
	
	
	return 0;
}
