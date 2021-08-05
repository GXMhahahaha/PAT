//A1016.Phone Bills
#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

const int maxn = 1010;
struct Phone{
	string record[maxn];
	bool flag[maxn];
	int num = 0;
}phone[maxn];

map<string,bool> mp;



int cost[24];
int main(){
	mp["he"] = 1;
	cout<<mp["he"]<<" "<<mp["asdfa"];
	

	return 0;
} 
