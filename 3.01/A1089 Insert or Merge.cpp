//A1089 Insert or Merge
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int N;
const int maxn = 110;
int ori[maxn],temp_ori[maxn],comp[maxn];

int addition[maxn];
bool isEqual(int a[],int b[]){
	for(int i=0;i<N;i++){
		if(a[i]!=b[i]){
			return false;
		}
	}
	return true;
}

bool Insertion_Sort(){
	bool flag = false;
	for(int i=1;i<N;i++){
		if(isEqual(temp_ori,comp) && i!=1){
			flag = true;
		}
		
		int temp = temp_ori[i];
		int j = i-1;
		while(temp < temp_ori[j] && j>=0){
			temp_ori[j+1] = temp_ori[j];
			j--;
		}
		temp_ori[j+1] = temp;
		
		if(flag == true){
			return true;
			
		}
		
	}
	return false;
	
}

void Print(){
	for(int i=0;i<N;i++){
		printf("%d",temp_ori[i]);
		if(i<N-1){
			printf(" ");
		}
	}
	cout<<endl;
}

void merge(int l1,int r1,int l2,int r2){
	int i = l1;
	int head = l1;
	while(l1<=r1 && l2<=r2){
		if(temp_ori[l1] < temp_ori[l2]){
			addition[i++] = temp_ori[l1++];
		}
		else{
			addition[i++] = temp_ori[l2++];
		}
	}
	while(l1<=r1){
		addition[i++] = temp_ori[l1++];
	}
	while(l2<=r2){
		addition[i++] = temp_ori[l2++];
	}
	for(int j=head;j<=r2;j++){
		temp_ori[j] = addition[j];
	}
	
}


void Merge_Sort(){
	int step = 1;
	bool flag = false;
	while(step<N){
		if(step!=1 && isEqual(temp_ori,comp)){
			flag = true;
		}
		int firstL = 0;
		int firstR = firstL+step-1;
		int secondL = firstR+1;
		int secondR = min(secondL+step-1,N-1);
		while(secondL < N){
			merge(firstL,firstR,secondL,secondR);

			firstL = secondR+1;
			firstR = firstL+step-1;
			secondL = firstR+1;
			secondR = min(secondL+step-1,N-1);
			
		}
	
		if(flag==true){
			Print();
			return;
		}
		step*=2;
		
	}	
}


int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%d",&ori[i]);
		temp_ori[i] = ori[i];
	}
	for(int i=0;i<N;i++){
		scanf("%d",&comp[i]);
	}
	
	if(Insertion_Sort()){
		cout<<"Insertion Sort"<<endl;
		Print();
	}
	else{
		for(int i=0;i<N;i++){
			temp_ori[i] = ori[i];
		}
		cout<<"Merge Sort"<<endl;
		Merge_Sort();
		
	}
	
	return 0;
}

