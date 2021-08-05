#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'
const int maxn = 10010;
struct CAR{
	string id;
	int time;
	string original_time;
	bool status;
}car[maxn],valid[maxn];
int N,K;

map<string,int> mp;
int transfer(string _time){
	int hh,mm,ss;
	sscanf(_time.c_str(),"%d:%d:%d",&hh,&mm,&ss);
	int time = ss+mm*60+hh*3600;
	return time;
	
}

bool cmp1(CAR a,CAR b){
	if(a.id != b.id){
		return a.id < b.id;
	}
	else{
		return a.time < b.time;
	}
}

bool cmp2(CAR a,CAR b){
	return a.time < b.time;
}


string trans(int time){
	string temp;
	char c[20];
	int hh,mm,ss;
	hh = time/3600;
	time%=3600;
	mm = time/60;
	time%=60;
	ss = time;
	sprintf(c,"%02d:%02d:%02d",hh,mm,ss);
	temp = c;
	return temp;
}
vector<string> name;
int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		string _id;
		string _time;
		string _status;
		cin>>_id>>_time>>_status;
		car[i].id = _id;
		car[i].original_time = _time;
		car[i].time = transfer(_time);
		if(_status == "in"){
			car[i].status = 0;
		}
		else if(_status == "out"){
			car[i].status = 1;
		}
	}

	sort(car,car+N,cmp1);

	
	int valid_num = 0;
	for(int i=0;i<N-1;i++){
		if(car[i].status==0 && (car[i+1].status==1 && car[i+1].id == car[i].id)){
			valid[valid_num++] = car[i];
			valid[valid_num++] = car[i+1];
			i++;
		}
	}
	
	int i=0;
	while(i<valid_num){
		string id = valid[i].id;
		if(mp.count(id) == 0){
			mp[id] = 0;
		}
		mp[id]+=valid[i+1].time-valid[i].time;
		i+=2;
		
	}


	sort(valid,valid+valid_num,cmp2);
	
	int park_num = 0;
	int lastpos = 0;
	for(int i=0;i<K;i++){
		string _time;
		cin>>_time;
		int cur_time = transfer(_time);
		
		int j = lastpos;
		
		for(;valid[j].time<=cur_time && j<valid_num;j++){					//千万注意查询不能过界 
			if(valid[j].status == 0){
				park_num++;
			}
			else if(valid[j].status == 1){
				park_num--;
			}			
		}
		cout<<park_num<<endl;
		lastpos = j; 
	}
	

	int max = -1;
	for(map<string,int> :: iterator it = mp.begin();it!=mp.end();it++){
		if(it->second > max){
			name.clear();
			name.push_back(it->first);
			max = it->second;
		}
		else if(it->second == max){
			name.push_back(it->first);
		}
	}
	for(int i=0;i<name.size();i++){
		cout<<name[i]<<" ";
	}
	cout<<trans(mp[name[0]])<<endl;
	return 0;
} 
