//A1016.Phone Bills
#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 1010;
struct REC{
	string name;
	string time;
	int mm,dd,hh,mi;
	bool flag;				//0表示on-line  1表示off-line  
}rec[maxn];

int cost[24];

bool cmp(REC a,REC b){
	if(a.name != b.name){
		return a.name<b.name;
	}
	else if(a.mm != b.mm){
		return a.mm<b.mm;
	}
	else if(a.dd != b.dd){
		return a.dd<b.dd;
	}
	else if(a.hh != b.hh){
		return a.hh<b.hh;
	}
	else if(a.mi != b.mi){
		return a.mi<b.mi;
	}
}

void calculate(REC a,REC b,int &temp_time,int &temp_cost){
	while(a.dd!=b.dd || a.hh!=b.hh || a.mi!=b.mi){
		a.mi++;
		temp_time++;
		temp_cost+=cost[a.hh];
		if(a.mi == 60){
			a.mi = 0;
			a.hh++;
		}
		if(a.hh==24){
			a.hh = 0;
			a.dd++;
		}
	}	
	
}


int main(){
	for(int i=0;i<24;i++){
		cin>>cost[i];
	}
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string _name;
		string _time;
		string _status;
		cin>>_name>>_time>>_status;
		rec[i].name = _name;
		sscanf(_time.c_str(),"%d:%d:%d:%d",&rec[i].mm,&rec[i].dd,&rec[i].hh,&rec[i].mi);
		_time.erase(_time.begin(),_time.begin()+3);
		rec[i].time = _time;
		if(_status == "on-line"){
			rec[i].flag = 0;
		}
		else if(_status == "off-line"){
			rec[i].flag = 1;
		}
	}
	sort(rec,rec+N,cmp);
	
	float total_cost = 0;
	bool is_counted = 0;
	
	
	for(int i=0;i<N;i++){
	
		string _name = rec[i].name;
		if(_name != rec[i+1].name){
			if(is_counted == 1){
				cout<<"Total amount: $";
				printf("%.2f\n",total_cost);
			}
			is_counted = 0;
			total_cost = 0;
			continue;
		}
		
		if(rec[i].flag==0 && rec[i+1].flag==1){
			if(is_counted == 0){
				cout<<_name<<" ";
				printf("%02d\n",rec[i].mm);
				is_counted = 1;
			}
			cout<<rec[i].time<<" "<<rec[i+1].time<<" ";
			int temp_time = 0;
			int temp_cost = 0; 
			calculate(rec[i],rec[i+1],temp_time,temp_cost);
			cout<<temp_time<<" $";
			float cost1 = 0.01*temp_cost;
			printf("%.2f\n",cost1);
			total_cost+=cost1;
		}
		
		
	}
	
	
	return 0;
} 
