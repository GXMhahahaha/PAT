//string迭代器是否是随机迭代器
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	string a;
	map<char,int> m;
	m['b'] = 9;
	m['a'] = 0;

//	cin>>a;
//	int len = a.length();
//	string :: iterator it = a.begin();
//	cout<<*(it+3)<<endl;
//	cout<<a[len-3]<<endl;;
	
	map<char,int> :: iterator it = m.begin();
	cout<<it->first;
	cout<<" "<<(++it)->second;
	return 0;
} 
