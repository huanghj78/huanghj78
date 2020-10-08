#include <stdio.h>
int main(){
	int n = 0;
	int i = 0;
	int j = 0;
	scanf("%d",&n);
	for (i = 0;i < n;i++){
		for(j = 0;j <= i;j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0;i < n;i++){
		for(j = 0;j < n-i-1;j++){
			printf(" ");
		}
		for(j = 0;j < 2*i+1;j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0;i < n;i++){
		for(j = 0;j < i;j++){
			printf(" ");
		}
		for(j = 0;j < 2*(n-i)-1;j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	for (i = 0;i < n;i++){
		for(j = 0;j < n-i-1;j++){
			printf(" ");
		}
		if(i == 0){
			printf("*\n");
		}		
		else{
			if(i < n-1){
				printf("*");
				for(j = 0;j < 2*i-1;j++){
					printf(" ");
				}
				printf("*");
				printf("\n");
			}
			else{
				for(j = 0;j < 2*n -1;j++){
					printf("*"); 
				}
				printf("\n");
			}
	    }
	}
	printf("\n");
	return 0;
}
