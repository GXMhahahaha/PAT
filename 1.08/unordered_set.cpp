//unordered_set ���������ܻ��ߣ����ܼӼ�����
 
#include <iostream>
#include <unordered_set>
using namespace std; 

int main(){
	unordered_set<int> a;
	a.insert(60);
	a.insert(20);
	a.insert(30);
	a.insert(40);
	a.insert(70);
	a.insert(20);
	unordered_set <int> ::iterator it;
	for(unordered_set <int> ::iterator it = a.begin();it != a.end();it++){
		cout<<*it<<" ";
	}
	unordered_set <int> :: iterator point;
	it = a.begin();
	point = ++ it;
	cout<<endl<<*point;
	
		
	
	return 0;
}
