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
		if (c >= '0' && c <= '9') {//����ֱ����� 
			out[i] = c;
			i++;
			flag = 0;
		}
		else {//������ 
			if(flag == 0){
				out[i] = ' ';//��������λ���� 
				i++;
				flag = 1;
			}
			if (top->next == NULL) {//��ջֱ����ջ 
				top = push(top,c);
			}
			else {
				s1 = sort(c);
				if (s1 == right_bracket) {//�����ţ���ջֱ������������ 
					s2 = sort(top->next->a);
					while (s2 != left_bracket) {
						out[i] = top->next->a;
						top = pop(top);
						s2 = sort(top->next->a);
						i++;
						out[i] = ' ';//�ָ����� 
						i++;
					}
					top = pop(top);//here
				}
				else{
					if (s1 == left_bracket) {//������ֱ����ջ 
					top = push(top,c);
					}
					else{//�Ӽ��˳� 
						s1 = sort(c);
						s2 = sort(top->next->a);
						if(s2 != left_bracket){//ջ������������ 
							if (s1 > s2) {
							top = push(top, c);
							}
							else {
								while (top->next != NULL && top->next->a != '(') {
									out[i] = top->next->a;
									top = pop(top);
									//s2 = sort(top->next->a);
									i++;
									out[i] = ' ';//�ָ����� 
									i++;
									/*if(top->next == NULL || top->next->a == '('){
										break;
									}*/
								}
								top = push(top, c);	
								//printf("it is %c",top->next->a);
							}
						}
						else{//ջ���������� 
							top = push(top, c);
						} 
					}	
				}
				
			}
		}
		c = getchar();
	}
	out[i] = ' ';//�ָ����� 
	i++;
	while (top->next != NULL) {
		out[i] = top->next->a;
		top = pop(top);
		i++;
		out[i] = ' ';//�ָ����� 
		i++;
	}
	i = 0;
	for(i;i<MAX;i++) {
			printf("%c", out[i]); 
	}
	return 0;

}

