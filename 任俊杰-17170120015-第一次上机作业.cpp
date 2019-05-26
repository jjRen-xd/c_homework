#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

#define MAX_SIZE 1024
void flush(FILE *fp);

void num_1();
void num_2();
void num_3();
void num_4();

int main(){
	while(1){
		printf("\n\nChoice num:\n1.\n2.\n3.\n4.\n");
	    char choice;
		choice = getchar();
		switch(choice){
			case '1':
				while(int ch = getchar() != '\n'){}
				num_1();
				break;
			case '2':
				while(int ch = getchar() != '\n'){}
				num_2();
				break;
			case '3':
				while(int ch = getchar() != '\n'){}
				num_3();
				break;
			case '4':
				while(int ch = getchar() != '\n'){}
				num_4();
				break;
			default:
				break;
		}
	}
	return 0;
}

void num_1(){
	printf("Num1:\n");
	char *str = (char *)malloc(sizeof(char)*(MAX_SIZE+1));
	gets(str);
	for(int i = 0;*(str+i) != '\0';i++){
		if(*(str+i) == ' '){
			for(int j = strlen(str);j>i;j--){
				str[j+2] = str[j]; 
			}
			*(str+i) = '%';
			*(str+i+1) = '2';
			*(str+i+2) = '0';
		}
	}
	printf("%s",str);
	free(str);
}

void num_2(){
	printf("\nNum2:\n");
	unsigned int num[MAX_SIZE];
	unsigned int len;
	
	printf("your size:");
	scanf("%d",&len);
	printf("input nums:");

	for(int i = 0;i<len;i++){
		scanf("%d",&num[i]);
	}
	while(int ch = getchar() != '\n'){}
	int temp;
	for(int i = 0;i<len;i++){
		for(int j = i;j<len;j++){
			if(num[j]<num[i]){
				temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}
		}
	}

	printf("min_4:");
	for(int i = 0;i<4;i++){
		printf("%d",num[i]);
	}
}

void num_3(){
	printf("\nNum3:\n");
	int sum = 0;
	for(int i = 0;i<=500;i++){
		if(i%13 == 0 || i%17 == 0){
			sum += i;
		}
	}
	printf("%d",sum);
}


void num_4(){
	printf("\nNum4:\n");
	printf("Choice your car:\n1.XiaLi\n2.FuKang\n3.SangTaNa\n");
    char choice;
	scanf("%c",&choice);
	while(int ch = getchar() != '\n'){}
	float dis,money = 0;
	printf("distance:");
	scanf("%f",&dis);

	switch(choice){
		case '1':
			money = (dis<3)?(3+dis*7):(3+3*7+(dis-3)*2.1);
			break;
		case '2':
			money = (dis<3)?(3+dis*8):(3+3*8+(dis-3)*2.4);
			break;
		case '3':
			money = (dis<3)?(3+dis*9):(3+3*9+(dis-3)*2.7);
			break;
		default:
			break;
	}
	printf("\nmoney:%.2f",money);
	while(int ch = getchar() != '\n'){}
}

