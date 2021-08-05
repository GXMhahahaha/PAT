//A1153 Decode Registration Card of PAT
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
const int maxn = 10010;
int N,M;
struct STU1{
	char id[16];
	int grade;
};

struct STU2{
	int site;
	int date;
}stu2[maxn];

vector<STU1> vi[3];
map<char,int> mp;
void Init(){
	mp['T'] = 0;
	mp['A'] = 1;
	mp['B'] = 2;
}

int deSite(char stid[]){
	int ans = 0;
	for(int i=1;i<=3;i++){
		ans = ans*10+stid[i]-'0';
	}
	return ans;	
}

int deDate(char stid[]){
	int ans = 0;
	for(int i=4;i<=9;i++){
		ans = ans*10+stid[i]-'0';
	}
	return ans;
}
int HashT[1100] = 0;
int gradeHashT[1100] = 0;

bool cmp(STU2 a,STU2 b){
	return a.date < b.date;
}

bool cmp1(STU1 a,STU1 b){
	if(a.grade!=b.grade){
		return a.grade > b.grade;
	}
	else{
		return strcmp(a.id,b.id) < 0;
	}
}

int main(){
	Init();
	cin>>N>>M;
	for(int i=0;i<N;i++){
		char stid[16];
		int gr;
		scanf("%s %d",stid,&gr);
		STU1 temp;
		strcpy(temp.id,stid);
		temp.grade = gr;
		vi[mp[stid[0]]].push_back(temp);
		
		int site = deSite(stid);
		HashT[site]++;
		gradeHahshT[site]+=gr;
		
		int date = deDate(stid);
		stu2[i].date = date;
		stu2[i].site = site;
		
	}
	sort(stu2,stu2+N,cmp);
	sort(vi[0].begin(),vi[0].end(),cmp1);
	sort(vi[1].begin(),vi[1].end(),cmp1);
	sort(vi[2].begin(),vi[2].end(),cmp1);
	
	for(int i=0;i<M;i++){
		int type;
		scanf("%d",&type);
		if(type == 1){
			char l;
			scanf("%c",&l);
			int num = mp[l];
			printf("Case %d:1 %c\n",i+1,l);
			for(int j=0;j<vi[num].size();j++){
				printf("%s %d\n",vi[num][j].id,vi[num][j].grade);
			}
			
		}
		else if(type == 2){
			int si;
			scanf("%d",&si);
			printf("Case %d:2 %d\n",i+1,si);
			
		}
		else if(type == 3){
			int da;
			scanf("%d",&da);
			int i,j;
			for(i=0;i<N;i++){
				if(stu2[i].date == da){
					break;
				}
			}
			for(j=i+1;j<N;j++){
				if(stu2[i].date > da){
					break;
				}
			}
			
		}
	}
	
	
	return 0;
}
