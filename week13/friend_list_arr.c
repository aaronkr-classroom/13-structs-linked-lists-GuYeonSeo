#include <stdio.h>

#define MAX_COUNT 5 //친구 등록 가능한 최대 수

typedef char NAME_TYPE[14]; //13자까지 + NULL문자
typedef unsigned short int US;

int AddFriend(NAME_TYPE* p_name, US* p_age,
	float* p_height, float* p_weight, int count) {
	//입력 가능한 최대 수를 넘었는지 체크
	if (count < MAX_COUNT) {
		printf("\n새로운 친구 정보를 입력하세요\n");
		printf("1. 이름 : ");
		scanf_s("%s", *(p_name + count), sizeof(*(p_name + count)));

		printf("2. 나이 : ");
		scanf_s("%hu", p_age + count); //age 배열의 count 위치에 나이를 저장함

		printf("3. 키 : ");
		scanf_s("%f", p_height + count);

		printf("4. 몸무게 : ");
		scanf_s("%f", p_weight + count);

		printf("입력을 완료했습니다\n\n");
		return 1;
	}
	else {//입력 가능한 최대 수를 넘었을 때 오류를 출력
		printf("최대 인원을 초과하여 입력을 할 수 없습니다\n");
		printf("최대 %d명까지만 관리 가능합니다\n\n", MAX_COUNT);
		return 0;
	}
}

void ShowFriendList(NAME_TYPE* p_name, US* p_age,
	float* p_height, float* p_weight, int count) {
	
	if (count > 0) {
		printf("\n등록된 친구 목록\n");
		printf("========================\n");
		for (int i = 0; i < count; i++) {
			printf("%-14s, %3d, %6.2f, 6.2f\n",
				*(p_name + i),
				*(p_age + i),
				*(p_height + i),
				*(p_weight + i));
		}
		printf("========================\n");
	}
	else { //등록된 친구가 없으면 오류를 출력함
		printf("\n등록된 친구가 없습니다\n\n");
	}
}

int main(void) {
	//배열 사용하기
	NAME_TYPE name[MAX_COUNT];
	US age[MAX_COUNT];
	float height[MAX_COUNT];
	float weight[MAX_COUNT];
	int count = 0, menu_num;

	//무한 루프 : 사용자가 3을 누르면 break 문으로 종료시킴
	while (1) {
	//메뉴를 화면에 출력함
		printf("\t[ 메뉴 ]\t\n");
		printf("========================\n");
		printf("1. 친구 추가\n");
		printf("2. 친구 목록 보기\n");
		printf("3. 종료\n");
		printf("========================\n");
		printf("번호 선택 : \n");
		scanf_s("%d", &menu_num);

		//while 문에서 나가야겠다
		if(menu_num == 3) break;

		switch (menu_num) {
		case 1:
			/*
			AddFriend 함수가 1을 반환하면 정상적으로 친구 정보가 추가된 것이다
			따라서 1을 반환했을 때만 등록된 친구 수를 증가시킨다.
			*/
			if (AddFriend(name, age, height, weight, count))
				count++;
			break;
		case 2:
			ShowFriendList(name, age, height, weight, count);
			break;
		default:
			//번호가 유효하지 않은 경우에 오류 메세지를 출력함
			printf("1~3 번호만 선택할 수 있습니다!\n\n");
		}
	}

	return 0;
}