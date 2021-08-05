//A1098 Insertion or Heap Sort
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N;
const int maxn = 110;
vector<int> ori,temp_ori,comp;
int array[maxn];

bool Insertion_Sort(){
	bool flag = false;
	for(int i=1;i<N;i++){
		if(temp_ori == comp && i!=1){
			flag = true;
		}
		int bas = temp_ori[i];
		int j = i-1;
		while(j>=0 && bas<temp_ori[j]){
			temp_ori[j+1] = temp_ori[j];
			j--;
		}
		temp_ori[j+1] = bas;
		if(flag == true){
			return true;
		}

	}
	return false;
}

void AdjustHeap(int head,int tail){
	int i = head;
	int j = 2*i;
	while(j<=tail){
		if(j+1<=tail && array[j+1]>array[j]){
			j = j+1;
		}
		if(array[i] < array[j]){
			swap(array[i],array[j]);
			i = j;
			j = 2*i;
		}
		else{
			break;
		}
	}
	
}

bool isEqual(int array[],vector<int> ori){
	for(int i=0;i<N;i++){
		if(array[i+1]!=comp[i]){
			return false;
		}
	}
	return true;
}

void Heap_Sort(){
	bool flag = false;
	for(int i=N/2;i>=1;i--){
		AdjustHeap(i,N);
	}
	for(int i=N;i>1;i--){
		if(isEqual(array,ori) && i!=N){
			flag = true;
		}
        swap(array[1],array[i]);
		AdjustHeap(1,i-1);
		if(flag == true){
            return;
		}

	}
	return;
	
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		ori.push_back(temp);
	}
	temp_ori = ori;
	
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		comp.push_back(temp);
	}
	
	
	if(Insertion_Sort()){
		printf("Insertion Sort\n");
		for(int i=0;i<N;i++){
			printf("%d",temp_ori[i]);
			if(i<N-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	else{
		for(int i=0;i<N;i++){
			array[i+1] = ori[i];
		}
        printf("Heap Sort\n");
		Heap_Sort();
		
 		for(int i=1;i<=N;i++){
 			printf("%d",array[i]);
 			if(i<=N-1){
 				printf(" ");
 			}
 		}
 		printf("\n");
 	}
	return 0;
}
