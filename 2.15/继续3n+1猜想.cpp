//¼ÌÐø3n+1²ÂÏë 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool hashTable[10000] = {0};
int data[110];
priority_queue<int> re;
vector<int> temp;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		data[i] = x;
		while(x!=1){
			
			if(x%2==0){
				x/=2;
				hashTable[x] = 1;
			}
			else{
				x = 3*x+1;
				
					hashTable[x] = 1;		
				

			}
	
		}
		
	}
	
	for(int i=0;i<N;i++){
		int x = data[i];
		if(hashTable[x] == 0){
			re.push(x);
			temp.push_back(x);
		}
	}
	
	
	sort(temp.begin(),temp.end(),cmp);
	for(int i=0;i<temp.size();i++){
		cout<<temp[i];
		if(i<temp.size()-1){
			cout<<" ";
		}
	
	
	}
	
	
//	while(!re.empty()){
//		cout<<re.top();
//		if(re.size()>1){
//			cout<<" ";
//		}
//		re.pop();
//		
//	}
	
	
	
	return 0;
} 
