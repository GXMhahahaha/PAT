//A1077.Kuchiguse
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
const int maxn = 110;
string str[maxn];
string suffix;
int main(){
	int N;
	cin>>N;
	getchar();
	int maxlen = -1;
	for(int i=0;i<N;i++){
		getline(cin,str[i]);
		int templen = str[i].length();
		maxlen = max(maxlen,templen);
		reverse(str[i].begin(),str[i].end());
	}
	int com_len = 0;
	bool flag = 0;
	
	for(int i=0;i<maxlen;i++){
		for(int j=0;j<N-1;j++){
			if(str[j][i]!=str[j+1][i]){
				flag = true;
				break;
			}
		}
		if(flag == true){
			break;
		}
		com_len++;
		suffix+=str[0][i];
	}

	if(com_len == 0){
		cout<<"nai"<<endl;
	}
	else{
		reverse(suffix.begin(),suffix.end());
		cout<<suffix<<endl;
	}
	return 0;
}
