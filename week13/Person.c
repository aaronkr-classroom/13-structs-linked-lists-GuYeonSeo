#include <stdio.h>

typedef unsigned short int us;

typedef struct {
	char name[12];
	us age;
	float height;
	float weight;
}Person;

int main(void) {
	Person data; //Person 자료형으로 data 변수를 선언함

	printf("대상자의 정보를 입력하시오\n");
	printf("이름 : ");
	scanf_s("%s", &data.name, sizeof(data.name));

	printf("나이 : ");
	scanf_s("%hu", &data.age);

	printf("키 : ");
	scanf_s("%f", &data.height);

	printf("몸무게 : ");
	scanf_s("%f", &data.weight);

	printf("\n입력한 정보는 다음과 같습니다\n");

	//키와 몸무게는 첫째 자리까지만 보여주기 위해 %.1f 형식으로 출력
	printf("%s : %d세, %.1fcm, %.1fkg\n",
		data.name, data.age, data.height, data.weight);

	return 0;
}