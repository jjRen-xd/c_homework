#include<stdio.h>
#include<math.h>

void num_1() {
	printf("1. Primes less than 100:\n");
	bool flag = 1;
	for (int i = 2; i <= 100; i++) {
		flag = 1;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				flag = 0;
			}
		}
		static int rows = 0;
		if (flag) {
			printf("%-4d ", i);
			if (++rows == 4) {
				printf("\n");
				rows = 0;
			}
		}
	}
}

void num_2() {
	printf("\n\n2.Alphabetic case-to-case conversion:\n");
	char str[64],ch;
	int len = 0;
	while((ch = getchar()) != '\n' && len<1024) {
		str[len++] = ch;
	}
	str[len] = '\0';
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		else if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
	}
	printf("%s", str);
}

struct stu_score {
	char name[64];
	float all_score[3];
	float max_score = 0;
	float avg_score = 0;
	float min_score = 1024;
};

void score_calc(stu_score & stu) {
	for (int i = 0; i < 3; i++) {
		if (stu.max_score < stu.all_score[i]) {
			stu.max_score = stu.all_score[i];
		}
		if (stu.min_score > stu.all_score[i]) {
			stu.min_score = stu.all_score[i];
		}
		stu.avg_score += stu.all_score[i];
	}
	stu.avg_score /= 3;

	printf("%s:\n", stu.name);
	printf("All score:%.2f %.2f %.2f\n", stu.all_score[0], stu.all_score[1], stu.all_score[2]);
	printf("Avg score:%.2f\n", stu.avg_score);
	printf("Max score:%.2f\n", stu.max_score);
	printf("Min score:%.2f\n\n", stu.min_score);
}
void num_3() {
	printf("\n\n3. Students score calc:");
	stu_score stu1 = { "stu1",{97,98,99} };
	stu_score stu2 = { "stu2",{87,68,79} };
	stu_score stu3 = { "stu3",{59,75,98} };

	score_calc(stu1);
	score_calc(stu2);
	score_calc(stu3);
}

void num_4() {
	printf("\n4. 10-digit sorting:\n");
	int num[10][2], temp;
	for (int i = 0; i < 10; i++) {
		num[i][0] = getchar() - 48;
		num[i][1] = i + 1;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			if (num[j][0] < num[i][0]) {
				temp = num[i][0];
				num[i][0] = num[j][0];
				num[j][0] = temp;

				temp = num[i][1];
				num[i][1] = num[j][1];
				num[j][1] = temp;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%d Position:%d\n", num[i][0], num[i][1]);
	}
}

void num_5() {
	printf("\n5. Reverse order:\n");
	while (int ch = getchar() != '\n') {}
	int num[10], len = 0;
	char ch;
	while ((ch = getchar()) != '\n') {
		num[len++] = ch - 48;
	}
	printf("Length:%d\n", len);
	for (int i = len - 1; i >= 0; i--) {
		printf("%d ", num[i]);
	}
}

int main() {
	num_1();
	num_2();
	num_3();
	num_4();
	num_5();
}


