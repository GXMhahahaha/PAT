//A1033 To fill or not to fill
#include <stdio.h>
#include <iostream>
#include <algorithm>

#define endl '\n'
using namespace std;
const int maxn = 510;

struct Station{
	double price;
	double dis;
}st[maxn];

bool cmp(Station a,Station b){
	return a.dis < b.dis;
}

int main(){
	double Cmax,D,Davg;
	int N;
	cin>>Cmax>>D>>Davg>>N;
	double Dmax = Cmax*Davg;
	
	for(int i=0;i<N;i++){
		cin>>st[i].price>>st[i].dis;
	}
	
	sort(st,st+N,cmp);
	st[N].dis = D;
	st[N].price = 0;
	
	double cur_pos = 0;
	int on = 0, off = 0;
	double tank = 0;
	double price = 0;

	if(st[0].dis != 0){
		cout<<"The maximum travel distance = 0.00"<<endl;
		return 0;
		
	}

	double dis = 0;
	while(on < N){										//on指代了当前所在位置 
		//on = lastpos;
		bool flag = 0;
		for(off=on+1;off<=N;off++){
			if(st[off].dis-st[on].dis > Dmax){			//off指代了越界位置，它的前一位置是最后一个可行点 
				break;
			}
		}
		if(off == on+1){
			cout<<"The maximum travel distance = ";
			printf("%.2f\n",st[on].dis+(Cmax - tank)*Davg);
			return 0;
		}
		
		
		
		for(int i=on+1;i<off;i++){
			if(st[i].price < st[on].price){
				double volumn = (st[i].dis-st[on].dis)/Davg;
				double add = 0;
		
				if(volumn > tank){
					add = volumn-tank;
				}
		
				tank+=add;
				price+=add*st[on].price;
				on = i;
				tank-=volumn; 
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			continue;
		}
		
		double min = 1e10;
		int minpos;
		for(int i=on+1;i<off;i++){
			if(st[i].price < min){
				min =  st[i].price;
				minpos = i;
			}
		}
		
		
		price+=(Cmax-tank)*st[on].price;
		tank = Cmax;
		double volumn = (st[minpos].dis-st[on].dis)/Davg;
		on = minpos;
		tank-=volumn;
		
	}
	printf("%.2f\n",price);
	
	return 0;
}
