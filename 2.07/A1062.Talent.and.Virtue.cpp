//A1062 Talent and Virtue
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int N,L,H;

struct STU{
	int id;
	int vi;
	int ta;
}stu[maxn];

int _rank(STU stu){
	if(stu.ta>=H && stu.vi>=H){
		return 3;
	}
	if(stu.ta<H && stu.vi>=H){
		return 2;
	}
	if(stu.ta<H && stu.vi<H && stu.vi>=stu.ta){
		return 1;
	}
	return 0;
}
bool cmp(STU a,STU b){
	int cal_a = _rank(a);
	int cal_b = _rank(b);
	if(cal_a!=cal_b){
		return cal_a>cal_b;
	}
	else{
		int total_a = a.ta+a.vi;
		int total_b = b.ta+b.vi;
		
		if(total_a!=total_b){
			return total_a>total_b;
		}
		else{
			if(a.vi!=b.vi){
				return a.vi>b.vi;
			}
			else{
				return a.id<b.id;
			}
		}
	}
}


int main(){
	
	cin>>N>>L>>H;
	int count = 0;
	
	for(int i=0;i<N;i++){
		int _id;
		int _vi;
		int _ta;
		cin>>_id>>_vi>>_ta;
		if(_vi>=L && _ta>=L){
			stu[count].id = _id;
			stu[count].ta = _ta;
			stu[count].vi = _vi;
			count++;
		}
	}
	sort(stu,stu+count,cmp);
	cout<<count<<endl;
	for(int i=0;i<count;i++){
		cout<<stu[i].id<<" "<<stu[i].vi<<" "<<stu[i].ta<<endl;
	}
	
	return 0;
} 
