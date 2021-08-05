//©╪йтвВн╙╨ебК
#include <iostream>
#include <string>
using namespace std;
const int maxn = 1010;
struct STU{
	string id;
	int las;
}stu[maxn];
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string _id;
		int _fir;
		int _las;
		cin>>_id>>_fir>>_las;
		stu[_fir].id = _id;
		stu[_fir].las = _las;
	}
	int M;
	cin>>M;
	for(int i=0;i<M;i++){
		int pos;
		cin>>pos;
		cout<<stu[pos].id<<" "<<stu[pos].las<<endl;
	}
	return 0;
} 
