//B1042 ×Ö·ûÍ³¼Æ
#include <iostream>
#include <string>

using namespace std;
int hashT[128] = {0};

int main(){
	string a;
	getline(cin,a);
	for(int i=0;i<a.length();i++){
		if(a[i] >='A'&& a[i] <='Z'){
			hashT[a[i]-'A'+'a']++;
		}
		else if(a[i] >='a'&& a[i] <='z'){
			hashT[a[i]]++;
		}
	} 
	int max = -1;
	char res;
	for(int i=0;i<128;i++){
		if(hashT[i] > max){
			max = hashT[i];
			res = i;
		}
	}
	cout<<res<<" "<<max<<endl;
	
	return 0;
} 
