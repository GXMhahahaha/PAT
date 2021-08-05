//sharing
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
	char c;
	int next;
}node[100000],head1,head2;

int main(){
	
	int total;
	cin>>head1.next>>head2.next>>total;

	if(head1.next==-1 || head2.next==-1){
		cout<<-1;
		return 0;
	}

	for(int i=0;i<total;i++){
		int add;
		scanf("%d",&add);
		scanf(" %c %d",&node[add].c,&node[add].next);
	}
	int len1 = 0, len2 = 0;
	int i = head1.next, j = head2.next;

	while(node[i].next != -1){
		i = node[i].next;
		len1++;
	}
	
	while(node[j].next != -1){
		j = node[j].next;
		len2++;
	}
	
	
	if(len1 == len2){
		int k1 = head1.next;
		int k2 = head2.next;
		
		while(k1 != -1){
			if(node[k1].c == node[k2].c&&k1==k2){
				//cout<<k1;
				printf("%05d",k1);
				return 0;
			}
			else{
				k1 = node[k1].next;
				k2 = node[k2].next;
			}
		}
		cout<<"-1";
	}
	
	else if(len1>len2){
		int k1 = head1.next;
		//int cal1=len1,cal2=len2;
		while(len1>len2){
			k1 = node[k1].next; 
			len1--;
		}
		int k2 = head2.next;
		
		while(k1 != -1){
			if(node[k1].c == node[k2].c&&k1==k2){
				printf("%05d",k1);
				return 0;
			}
			else{
				k1 = node[k1].next;
				k2 = node[k2].next;
			}
		}
		cout<<"-1";
	}
	
	else if(len1<len2){
		int k2 = head2.next;
		while(len1<len2){
			k2 = node[k2].next;
			len2--;
		}
		int k1 = head1.next;

		while(k1 != -1){
			if(node[k1].c == node[k2].c&&k1==k2){
				printf("%05d",k1);
				return 0;
			}
			else{
				k1 = node[k1].next;
				k2 = node[k2].next;
			}
		}
		cout<<"-1";
	}
	
	return 0;
} 
