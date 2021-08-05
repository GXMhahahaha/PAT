//ÖÐÎ»Êý
#include <stdio.h>
#include <iostream>
using namespace std;

const int maxn = 200010;  

//int a[maxn]={0};
//int b[maxn]={0};
//int c[maxn*2]={0};

 int main(){
	
//      for(int i=0;i<maxn;i++){
//           a[i] = 0;
//       }
//      for(int i=0;i<maxn;i++){
//           b[i] = 0;
//       }
//      for(int i=0;i<2*maxn;i++){
//           c[i] = 0;
//       }

     //int a[]
     int *a = (int *)malloc(sizeof(int)*maxn*100);
          for(int i=0;i<maxn*100;i++){
              a[i] = i;
          }
          for(int i=0;i<maxn*100;i++){
              cout<<a[i]<<" "; 
          } 
	return 0;
 } 
