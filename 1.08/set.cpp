//unordered_set 迭代器不能回走，不能加减整数
 
#include <iostream>
#include <set>
using namespace std; 

int main(){
	set<int> a;
	a.insert(60);
	a.insert(20);
	a.insert(30);
	a.insert(40);
	a.insert(70);
	a.insert(20);
	set <int> ::iterator it;
	for(set <int> ::iterator it = a.begin();it != a.end();it++){
		cout<<*it<<" ";
	}
	set <int> :: iterator point;
	it = a.end();
	point =  --it;
	cout<<endl<<*point;
	
		
	
	return 0;
}
