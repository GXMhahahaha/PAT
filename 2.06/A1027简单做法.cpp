#include <cstdio>
char c[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int main(){
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	printf("#");
	
	if(x<13) printf("0%c",c[x]);
	else printf("%c%c",c[x/13],c[x%13]);
	
		
	if(y<13) printf("0%c",c[y]);
	else printf("%c%c",c[y/13],c[y%13]);
	
		
	if(z<13) printf("0%c",c[z]);
	else printf("%c%c",c[z/13],c[z%13]);
	
	return 0;
}
