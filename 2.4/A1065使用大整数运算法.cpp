//A+B and C 使用大整数运算
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct BIGN{
	int num[30] = {0};
	int len = 0;
	bool sign = 1;		//0表示负数，1表示正数 
};
BIGN change(string str){
	BIGN temp;
	if(str[0] == '-'){
		temp.sign = 0;
		str.erase(str.begin());
	}
	else{
		temp.sign = 1;
	}
	
	int j=0;
	for(int i=str.length()-1;i>=0;i--){
		temp.num[j++] = str[i]-'0';
	}
	temp.len = str.length();
	return temp;
}

int abs_compare(BIGN A,BIGN B){
	if(A.len>B.len){
		return 0;			//0表示A大于B 
	}
	else if(A.len<B.len){
		return 1;			//1 表示A小于B 
	}
	else if(A.len == B.len){
		for(int i=A.len-1;i>=0;i--){
			if(A.num[i] > B.num[i]){
				return 0;
			}
			else if(A.num[i] < B.num[i]){
				return 1;
			}
		}
		return 2;  			//2表示	A等于B 
	} 
}

BIGN add(BIGN A,BIGN B){
	BIGN C;
	int carry = 0;
	for(int i=0;i<A.len||i<B.len;i++){
		int temp = A.num[i] + B.num[i] + carry;
		carry = temp/10;
		C.num[i] = temp%10;
		C.len = i+1;
	}
	if(carry!=0){
		C.num[C.len++] = carry;
	}
	C.sign = 1;
	return C;
}


BIGN sub(BIGN A,BIGN B){
	BIGN C;
	int flag =  abs_compare(A,B);
	if(flag == 2){
		C.num[0] = 0;
		C.len = 1;
		C.sign = 1;
		return C;
	}
	else if(flag == 0){
		for(int i=0;i<A.len;i++){
			if(A.num[i]>=B.num[i]){
				C.num[i] = A.num[i] - B.num[i];
			}
			else if(A.num[i]<B.num[i]){
				
				A.num[i+1]--;
				C.num[i] = A.num[i]+10 - B.num[i];
			}
		}
		C.len = A.len;
		for(int i=C.len-1;i>=0;i--){
			if(C.num[i]!=0){
				break;
			}
			else{
				C.len--;
			}
		}
		C.sign = 1;
	}
	else if(flag == 1){
		C = sub(B,A);
		C.sign = 0;
	}
	return C;
}

bool compare(BIGN a,BIGN b){
	if(a.sign==1&&b.sign==0){
		return 1;
	}
	else if(a.sign==0&&b.sign==1){
		return 0;
	}
	else if(a.sign==1&&b.sign==1){
		int flag = abs_compare(a,b);
		if(flag == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(a.sign==0&&b.sign==0){
		int flag = abs_compare(a,b);
		if(flag == 1){
			return 1;
		}
		else{
			return 0;
		}
	}
}

int main(){
	string strA,strB,strC;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>strA>>strB>>strC;
		BIGN A = change(strA);
		BIGN B = change(strB);
		BIGN C = change(strC);
		BIGN SUM;
		if(A.sign==1&&B.sign==1){
			SUM = add(A,B);
		}
		else if(A.sign==1&&B.sign==0){
			SUM = sub(A,B);
		}
		else if(A.sign==0&&B.sign==1){
			SUM = sub(B,A);
		}
		else if(A.sign==0&&B.sign==0){
			SUM = add(A,B);
			SUM.sign = 0;
		}
		bool flag = compare(SUM,C);
		if(flag == 0){
			cout<<"Case #"<<i+1<<": false"<<endl;
		}
		else if(flag == 1){
			cout<<"Case #"<<i+1<<": true"<<endl;
		}
	}


	return 0;
} 
