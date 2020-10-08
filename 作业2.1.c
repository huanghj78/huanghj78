#include <stdio.h>
int main(){
	int a = 0;
	float b = 0.0;
	scanf("%d %f",&a,&b);
	printf("%5d\n",a);
	printf("%05d\n",a);
	printf("%-5d\n",a);
	printf("%010.4f\n",b);
	return 0;
} 
