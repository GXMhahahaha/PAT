//二分法求方程的根
#include <stdio.h>
#include <math.h>

const double e = 1e-5;
double sol(){
	double low = 1, high = 2;
	while(low <= high){
		double mid = (low+high)/2;
		if(fabs(mid*mid-2)<= e){
			return mid;
		}
		if ( mid*mid-2 > e){
			high = mid;
		}
		if( mid*mid-2 < -e){
			low = mid;
		}
		
	}
}
int main(){
	double s = sol(); 	
	printf("%lf",s);
	
	return 0;
} 
