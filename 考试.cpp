#include<stdio.h>
#include<malloc.h>
void sort(int Num[5][5]);
int main(){
	int num[5][5] = {
		{5,9,3,3,7},
		{6,7,9,7,3},
		{92,13,65,76,22},
		{6,8,2,7,9},
		{8,9,3,1,7}
	};
	for(int i = 0;i<5;i++){
		for(int j =0;j<5;j++){
			printf("%4d",num[i][j]);
		}
		printf("\n");
	}
	printf("*******************************\n");
	sort(num);
	
	for(int i = 0;i<5;i++){
		for(int j =0;j<5;j++){
			printf("%4d",num[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

void sort(int Num[5][5]){
	int tempNums[25];
	int k = 0;
	for(int i = 0;i<5;i++){
		for(int j = 0;j<5;j++){
			tempNums[k++] = Num[i][j];
		}
	}
	for(int i = 0;i<25;i++){
		for(int j = i;j<25;j++){
			if(tempNums[j] > tempNums[i]){
				int temp = tempNums[i];
				tempNums[i] = tempNums[j];
				tempNums[j] = temp;
			}
		}
	}
	k = 0;
	for(int i = 0;i<5;i++){
		for(int j = 0;j<5;j++){
			Num[i][j] = tempNums[k++];
		}
	}

}
