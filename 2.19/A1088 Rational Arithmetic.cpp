//A1088 Rational Arithmetic
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

char c[4] = {'+','-','*','/'};

ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}

void change(int a1,int b1,ll& inte1,ll& fenzi1,ll& fenmu1){
	ll divi = gcd(abs(a1),abs(b1));
	fenzi1 = a1/divi;
	fenmu1 = b1/divi;
	inte1 = fenzi1/fenmu1;
	fenzi1 %= fenmu1;
}



char temp[100];
void clear(){
	for(int i=0;i<100;i++){
		temp[i] = '\0';
	}
}

string print(ll inte,ll fenzi,ll fenmu){
	
	string ans;
	if(inte == 0){
		if(fenzi == 0){
			ans = "0";
			//cout<<"0"<<endl;
		}
		else{
			if(fenzi<0){
				sprintf(temp,"(%lld/%lld)",fenzi,fenmu);
				ans = temp;
				clear();
				//cout<<"("<<fenzi<<"/"<<fenmu<<")"<<endl;
			}
			else if(fenzi>0){
				sprintf(temp,"%lld/%lld",fenzi,fenmu);
				ans = temp;
				clear();
				//cout<<fenzi<<"/"<<fenmu<<endl;
			}
		}
	}
	else{
		if(inte < 0){
			//cout<<"("<<inte;
			sprintf(temp,"(%lld",inte);
			ans = temp;
			clear();
			if(fenzi == 0){
				//cout<<")";
				ans+=")";
			}
			else{
				sprintf(temp," %lld/%lld)",abs(fenzi),abs(fenmu));
				string ad = temp;
				ans += ad;
				clear();
				//cout<<" "<<abs(fenzi)<<"/"<<fenmu<<")";
			}
	
		}
		else{
			sprintf(temp,"%lld",inte);
			ans = temp;
			clear();
			//cout<<inte;
			if(fenzi != 0){
				sprintf(temp," %lld/%lld",abs(fenzi),abs(fenmu));
				string ad = temp;
				ans+=ad;
				//cout<<" "<<abs(fenzi)<<"/"<<fenmu;
				clear();
			}
		}
	}
	return ans;
}

void Output(string a,string b,int index){
	cout<<a<<" "<<c[index]<<" "<<b<<" "<<"="<<" ";
}

void add(int a1,int a2,int b1,int b2,ll& inte,ll& fenzi,ll& fenmu){
	fenmu = b1*b2;
	fenzi = b1*a2+b2*a1;
	ll temp = gcd(abs(fenmu),abs(fenzi));
	fenmu/=temp;
	fenzi/=temp;
	inte = fenzi/fenmu;
	fenzi%=fenmu;	
}

void multi(int a1,int a2,int b1,int b2,ll& inte,ll& fenzi,ll& fenmu){
	fenzi = a1*a2;
	fenmu = b1*b2;
	ll temp = gcd(abs(fenmu),abs(fenzi));
	fenmu/=temp;
	fenzi/=temp;
	inte = fenzi/fenmu;
	fenzi%=fenmu;
}
int main(){
	int a1,b1,a2,b2;
	scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
	
	ll inte1;
	ll fenzi1,fenmu1;

	ll inte2;
	ll fenzi2,fenmu2;
	
	ll inte;
	ll fenmu;
	ll fenzi;
	
	//add
	change(a1,b1,inte1,fenzi1,fenmu1);
//	cout<<inte1<<fenzi1<<fenmu1<<endl;
	string num1 = print(inte1,fenzi1,fenmu1);
	
	change(a2,b2,inte2,fenzi2,fenmu2);
	string num2 = print(inte2,fenzi2,fenmu2);
	
	Output(num1,num2,0);

	add(a1,a2,b1,b2,inte,fenzi,fenmu);
	string ans = print(inte,fenzi,fenmu);
	cout<<ans<<endl;
	
	//sub
	change(a1,b1,inte1,fenzi1,fenmu1);
	num1 = print(inte1,fenzi1,fenmu1);
	
	change(a2,b2,inte2,fenzi2,fenmu2);
	num2 = print(inte2,fenzi2,fenmu2);
	
	Output(num1,num2,1);

	add(a1,-a2,b1,b2,inte,fenzi,fenmu);
	ans = print(inte,fenzi,fenmu);
	cout<<ans<<endl;
	
	//mul
	change(a1,b1,inte1,fenzi1,fenmu1);
	num1 = print(inte1,fenzi1,fenmu1);
	
	change(a2,b2,inte2,fenzi2,fenmu2);
	num2 = print(inte2,fenzi2,fenmu2);
	
	Output(num1,num2,2);
	multi(a1,a2,b1,b2,inte,fenzi,fenmu);
	ans = print(inte,fenzi,fenmu);	
	cout<<ans<<endl;
	
	
	//div
	
	change(a1,b1,inte1,fenzi1,fenmu1);
	num1 = print(inte1,fenzi1,fenmu1);
	
	change(a2,b2,inte2,fenzi2,fenmu2);
	num2 = print(inte2,fenzi2,fenmu2);
	
	Output(num1,num2,3);
	if(a2>0){
		multi(a1,b2,b1,a2,inte,fenzi,fenmu);
	}
	else if(a2 < 0){
		multi(a1,-b2,b1,-a2,inte,fenzi,fenmu);
	}
	else if(a2 == 0){
		cout<<"Inf"<<endl;
		return 0;
	}
	
	ans = print(inte,fenzi,fenmu);	
	cout<<ans<<endl;

	return 0;
}
