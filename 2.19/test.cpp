//A1089 Insert or Merge
#include <iostream>
#include <stdio.h>
#include <vector>
#define endl '\n'
using namespace std;
const int maxn = 110;
int N;
vector<int> list;
vector<int> sorted_list;
vector<int> midd;
int ans[maxn];

bool Insertion_Sort(){
	bool flag = false;
	int step = 0;
	for(int i=1;i<=N;i++){
		for(int j=i-1;j>=0;j--){
			if(sorted_list[i]>sorted_list[j]){
				int temp = sorted_list[i];
				for(int k=i-1;k>=j+1;k--){
					sorted_list[k+1] = sorted_list[k];
				}
				sorted_list[j+1] = temp;
				break;
			}
		}
		if(flag == 1 && step>1){
			cout<<"Insertion Sort"<<endl;
			for(int l=1;l<=N;l++){
				printf("%d",sorted_list[l]);
				if(l<=N-1){
					printf(" ");
				}
			}
			printf("\n");
			return 1;
		}
		if(midd == sorted_list){
			flag = 1;
		}
		step++;
	}
	return 0;
}



void Merge(int low1,int high1,int low2,int high2){
	for(int i=0;i<N;i++){
		ans[i] = sorted_list[i];
	}
	int i,j,k;
	for(i=low1,j=low2,k=low1;i<=high1 && j<=high2;k++){
		if(ans[i] < ans[j]){
			sorted_list[k] = ans[i++];
		}
		else{
			sorted_list[k] = ans[j++];
		}
	}
	while(i<=high1){
		sorted_list[k++] = ans[i++];
	}
	while(j<=high2){
		sorted_list[k++] = ans[j++];
	}
}


void Merge_sort(){
	int left_min = 0,left_max = 0,right_min = 0,right_max = 0;
	int len = 1;
	bool flag = 0;
	int step = 0;
	for(int len=1;len<=N;len*=2){
		for(left_min = 0;left_min <= N-len;left_min = right_max+1){
			left_max = left_min+len-1;
			right_min = left_max+1;
			int temp = right_min+len-1;
			if(temp<=N-1){
				right_max = temp;
			}
			else{
				right_max = N-1;
			}
			Merge(left_min,left_max,right_min,right_max);
			
		}
		
		if(flag == 1 && step > 1){
			cout<<"Merge Sort"<<endl;
			for(int i=0;i<N;i++){
				cout<<sorted_list[i];
				if(i<N-1){
					cout<<" ";
				}
			}
			cout<<endl;
			return;
		}					
		if(sorted_list == midd){
			flag = 1;
		}
		step++;
		
	}
	
} 

int main(){
	cin>>N;
	sorted_list.push_back(-1);
	list.push_back(-1);
	midd.push_back(-1);
	
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		sorted_list.push_back(temp);
		list.push_back(temp);
	}

	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		midd.push_back(temp);
	}
	bool flag = Insertion_Sort();
	if(flag == 0){
		sorted_list = list;
		sorted_list.erase(sorted_list.begin());
		midd.erase(midd.begin());

		Merge_sort();	
	}
	return 0;
}

