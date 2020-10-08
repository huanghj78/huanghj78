#include <stdio.h>
int main(){
	int count = 0;
	int i = 0;
	int year;
	scanf("%d",&count);
	for (i = 0;i < count;i++){
		scanf("%d",&year);
		if(year%400 == 0){
			printf("Yes\n");
		}
		else{
			if(year%4 == 0 && year%100 != 0){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
	}
	return 0;
}
