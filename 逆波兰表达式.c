#include <stdio.h>
#include <stdlib.h>
#define left_bracket 1
#define right_bracket 11
#define add_sub 2
#define mul_div 3
#define MAX 50
typedef struct node {
	char a;
	struct node* next;
}node;
node* init_stack() {
	node* top;
	top = (node*)malloc(sizeof(node));
	top->next = NULL;
	return top;
}
node* push(node* top, char a) {
	node* p;
	p = (node*)malloc(sizeof(node));
	if (!p) {
		printf("ERROR\n");
		return;
	}
	else {
		p->a = a;
		p->next = top->next;
		top->next = p;
	}
	return top;
}
node* pop(node* top) {
	node* p;
	char a;
	if (top->next == NULL) {
		printf("ERROR\n");
		return;
	}
	else {
		p = top->next;
		a = p->a;
		top->next = p->next;
		free(p);
		return top;
	}
}
int sort(char a) {
	switch ((int)a) {
		case 40:
			return left_bracket;
		case 41:
			return right_bracket; 
		case 43:
			return add_sub;
		case 45:
			return add_sub;
		case 42:
			return mul_div;
		case 47:
			return mul_div;
		default:
			break;
	}
}

int main() {
	int flag = 0;
	char c;
	int s1,s2;
	int i = 0;
	char out[MAX]={'\0'};
	node* top;
	top = init_stack();
	printf("Please input :\n");
	c = getchar();
	while (c != '\n') { 
		if (c >= '0' && c <= '9') {//数字直接输出 
			out[i] = c;
			i++;
			flag = 0;
		}
		else {//操作符 
			if(flag == 0){
				out[i] = ' ';//区别多个多位数字 
				i++;
				flag = 1;
			}
			if (top->next == NULL) {//空栈直接入栈 
				top = push(top,c);
			}
			else {
				s1 = sort(c);
				if (s1 == right_bracket) {//右括号，出栈直至遇到左括号 
					s2 = sort(top->next->a);
					while (s2 != left_bracket) {
						out[i] = top->next->a;
						top = pop(top);
						s2 = sort(top->next->a);
						i++;
						out[i] = ' ';//分隔符号 
						i++;
					}
					top = pop(top);//here
				}
				else{
					if (s1 == left_bracket) {//左括号直接入栈 
					top = push(top,c);
					}
					else{//加减乘除 
						s1 = sort(c);
						s2 = sort(top->next->a);
						if(s2 != left_bracket){//栈顶不是左括号 
							if (s1 > s2) {
							top = push(top, c);
							}
							else {
								while (top->next != NULL && top->next->a != '(') {
									out[i] = top->next->a;
									top = pop(top);
									//s2 = sort(top->next->a);
									i++;
									out[i] = ' ';//分隔符号 
									i++;
									/*if(top->next == NULL || top->next->a == '('){
										break;
									}*/
								}
								top = push(top, c);	
								//printf("it is %c",top->next->a);
							}
						}
						else{//栈顶是左括号 
							top = push(top, c);
						} 
					}	
				}
				
			}
		}
		c = getchar();
	}
	out[i] = ' ';//分隔符号 
	i++;
	while (top->next != NULL) {
		out[i] = top->next->a;
		top = pop(top);
		i++;
		out[i] = ' ';//分隔符号 
		i++;
	}
	i = 0;
	for(i;i<MAX;i++) {
			printf("%c", out[i]); 
	}
	return 0;

}

