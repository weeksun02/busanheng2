#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include <time.h>

#define LEN_MIN 15
#define LEN_MAX 50
#define STM_MIN 0
#define STM_MAX 5
#define PROB_MIN 10
#define PROB_MAX 90
#define AGGRO_MIN 0
#define AGGRO_MAX 9
//마동석 이동방향
#define MOVE_LEFT 1
#define MOVE_STAY 0
//좀비의 공격대상
#define ATK_NONE 0
#define ATK_CITIZEN 1
#define ATK_DONGSEOK 2
//마동석 행동
#define ACTION_REST 0
#define ACTION_PROVOKE 1
#define ACTION_PULL 2
void intro();
void enter1();
void enter2();
void enter3();
void busanhang2();
void busanhang3();
void busanhang31();
void sangtea();
void sangtea2();
void moveall();
void sangtea3();
void start();
void start2();
int stamina=6;
int length = 0;
int cprob = 0;
int zprob = 0;
int c = 0;
int z = 0;
int m = 0;
int j = 0;
int space = 0;
int sspace = 0;
int ssspace = 0;
int percent = 0;
char train[50];
char ctizen[50];
char zombie[50];
char ctizom[50];
int main(void) {
	
	//intro();
	enter1();
	enter2();
	enter3();

srand((unsigned int)time(NULL));
z = length - 3;
c = length - 6;
m = length - 2;
space = c - 1;
sspace = z - c-1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
start();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
while (1) {
	percent = rand() % 100 + 1;
		

	moveall();
	
	Sleep(4000); ///sleep없애기!!!
	
	j++;
}

return 0;
}

void stop() {
	if (c == 1) {
		printf("\nSUCCESS!\ncitizen(s) escaped to the next train\n");
		exit(0);
	}
	if (sspace == 0) {
		printf("\nGAME OVER!\nCitizen(s) has(have) been attacked by a zombi\n");
		exit(0);
	}
}
void perccent() {
	if (percent < (100 - cprob)) {
		c -= 1;
	}
	if (percent < zprob) {
		if (j % 2 == 0) {
			z -= 1;
			ssspace += 1;
			
		}
	}
}
void cctizen() {
	
	for (int i = 0; i < c - 1; i++) {
		ctizen[i] = ' ';
	}
	for (int i = 0; i < c - 1; i++) {
		printf("%c", ctizen[i]);
	}
}
void zzombie() {
	
	for (int i = 0; i < ssspace; i++) {
		zombie[i] = ' ';
	}
	for (int i = 0; i < ssspace; i++) {
		printf("%c", zombie[i]);
	}
}
void cctizzom() {
	sspace = z - c-1;
	for (int i = 0; i < sspace; i++) {
		ctizom[i] = ' ';
	}
	for (int i = 0; i < sspace; i++) {
		printf("%c", ctizom[i]);
	}
}
void start2() {
	printf("#");
	cctizen();
	printf("c");
	cctizzom();
	printf("z");
	zzombie();
	printf("m");
	printf("#");

}
void busanhang2() { //두번째 줄 출력하는 함수
	
	perccent();
	printf("#");
	cctizen();
	printf("c");
	cctizzom();
	printf("z");
	zzombie();
	printf("m");
	printf("#");

}

void busanhang3() { //변하지 않는 기차
	for (int i = 1; i <= length; i++) {
		train[i] = '#';
	}
}
void busanhang31() {
	for (int i = 1; i <= length; i++) {
		printf("%c", train[i]);
	}
}
void sangtea() {
	if (percent < (100 - cprob)) { //시민상태출력
		printf("citizen : stay %d -> %d\n", c + 1, c);
	}
	else {
		printf("citizen : stay %d\n", c);
	}
	if (percent < zprob) { 	//좀비상태출력-움직였을때
		sangtea2();
	}
	else { //좀비상태출력-제자리일때
		sangtea3();
	}
}
void sangtea3() {
	if (j % 2 == 0) {
		printf("zombie : stay %d\n",z);
	}
	else {
		printf("zombie : stay %d (Can not move)\n", z);
	}
}
void sangtea2() {
	if (j % 2 == 0) {
		printf("zombie : stay %d -> %d\n", z + 1, z);
	}
	else {
		printf("zombie : stay %d (Can not move)\n", z);
	}
}
void moveall() {
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
	busanhang2();
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
	sangtea();
	stop();
}
void start() {
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
	start2();
	printf("\n");
	busanhang3();
	busanhang31();
	printf("\n");
}
void intro() {
printf("나 ");
Sleep(1000);
printf("잡");
Sleep(1000);
printf("아");
Sleep(1000);
printf("봐");
Sleep(1000);
printf("라");
Sleep(1000);
printf("~!\n");
Sleep(1000);
printf("=====================\n");
printf("= 부산헹 GAME START =\n");
printf("=====================\n");
Sleep(2000);
}
void enter1() {

	while (LEN_MIN > length || LEN_MAX < length) {
		printf("train length(15~50) >>  ");
		scanf_s("%d", &length);
	}	
}
void enter2() {
	
	while (STM_MIN > stamina || stamina > STM_MAX) {
		printf("madongseok stamina(0~5) >> ");
		scanf_s("%d", &stamina);
	}
}
void enter3() {
	while (PROB_MIN > cprob || PROB_MAX < cprob) {
		printf("percentile probability citizen'cp'(10~90) >> ");
		scanf_s("%d", &cprob);
	}
	while (PROB_MIN > zprob || PROB_MAX < zprob) {
		printf("percentile probability zombie'zp'(10~90) >> ");
		scanf_s("%d", &zprob);
	}
}