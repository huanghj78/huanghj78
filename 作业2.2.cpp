#include <stdio.h>
int main(){
	int count = 0;
	int i = 0;
	int a = 0;
	int b = 0;
	int temp = 0;
	scanf("%d",&count);
	for (i = 0;i < count;i++){
		scanf("%d %d",&a,&b);
		if(a<b){
			temp = a;
			a = b;
			b = temp;
		} 
		while (b != 0){
			temp = a%b;
			printf("%d\n",temp); 
			a = b;
			b = temp;
		}
		printf("%d\n",a);
	} 
	return 0;
}
