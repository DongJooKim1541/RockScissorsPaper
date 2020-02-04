#include <stdio.h>//콘솔입출력 라이브러리
#include <string.h>//문자열라이브러리
#include <time.h>//시간라이브러리,랜덤함수 사용시 필요
#include <stdlib.h>//c언어 표준라이브러리,난수함수,문자열함수등 포함
#include <windows.h>//슬립,콘솔창 조절등
#include <conio.h>//kbhit등 입출력관련

//함수선언
void gotoxy(int x, int y);
int move_arrow(int me);
int keybord(int me);

/*메인함수*/
int main() {
	/*콘솔크기 조정.XXXX 지우고 가로크기입력. 크기1은 영문자 하나의 가로길이. YYYY 지우고 세로크기 입력. 1은 한 줄을 의미.*/
	system("mode con: cols=100 lines=24");
	/*커서없애기.*/
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);//여기까지는 건드리지 말기!
	
	//변수영역
	int me = 0;
	int computer;
	int all_number = 1;
	int win_number = 0;
	float victory_rate;
	
	gotoxy(40, 11);
	
	Sleep(500);
	printf("가 ");
	Sleep(500);
	printf("위 ");
	Sleep(500);
	printf("바 ");
	Sleep(500);
	printf("위 ");
	Sleep(500);
	printf("보 ");
	Sleep(500);
	printf("게 ");
	Sleep(500);
	printf("임 \n");

	/*아무키나 누르면 넘긴다.*/
	while (_kbhit()) _getch();
	Sleep(1000);
	gotoxy(37, 14);
	printf("아무 키나 누르면 시작합니다!");
	while (1) {
		if (_kbhit()) {
			_getch();
			break;
		}
	}
	while (1) {
		/*화면을 깨끗하게 비움*/
		system("cls");


		/*랜덤함수사용전 초기화*/
		srand(time(NULL));                                

		/*rand()%5 면 0~4 의 수가 랜덤으로 나옵니다. 1~5 하려면 rand()%5+1*/
		computer = rand() % 3;

		//선택지
		gotoxy(35, 8);
		printf("무엇을 내시겠습니까?");
		gotoxy(38, 10);
		printf("가위");
		gotoxy(38, 11);
		printf("바위");
		gotoxy(38, 12);
		printf("보");

		gotoxy(30, 10);
		printf("  ");
		gotoxy(30, 11);
		printf("  ");
		gotoxy(30, 12);
		printf("  ");

		//함수호출
		move_arrow(me);
		me = keybord(me);

		//가위바위보 하기
		if (computer == 0) {
			if (me == 0) {
				system("cls");
				gotoxy(30, 9);
				printf("컴퓨터는 가위, 너도 가위!");
				gotoxy(45, 12);
				printf("Draw!");
			}
			else if (me == 1) {
				system("cls");
				gotoxy(38, 9);
				printf("컴퓨터는 가위, 너는 바위!");
				gotoxy(45, 12);
				printf("You Win!");
				win_number++;
			}
			else {
				system("cls");
				gotoxy(38, 9);
				printf("컴퓨터는 가위, 너는 보!");
				gotoxy(45, 12);
				printf("You Lose!");
			}
		}
		else if (computer == 1) {
			if (me == 0) {
				system("cls");
				gotoxy(38, 9);
				printf("컴퓨터는 바위, 너는 가위!");
				gotoxy(45, 12);
				printf("You Lose!");
			}
			else if (me == 1) {
				system("cls");
				gotoxy(38, 9);
				printf("컴퓨터는 바위, 너도 바위!");
				gotoxy(45, 12);
				printf("Draw!");
			}
			else {
				system("cls");
				gotoxy(38, 9);
				printf("컴퓨터는 바위, 너는 보!");
				gotoxy(45, 12);
				printf("You Win!");
				win_number++;
			}
		}
		else {
			if (me == 0) {
				system("cls");
				gotoxy(38, 9);
				printf("컴퓨터는 보, 너는 가위!");
				gotoxy(45, 12);
				printf("You Win!");
				win_number++;
			}
			else if (me == 1) {
				system("cls");
				gotoxy(38, 9);
				printf("컴퓨터는 보, 너는 바위!");
				gotoxy(45, 12);
				printf("You Lose!");
			}
			else {
				system("cls");
				gotoxy(38, 9);
				printf("컴퓨터는 보, 너도 보!");
				gotoxy(45, 12);
				printf("All Draw!");
			}
		}

		//승률계산
		victory_rate = (float)(win_number) / (float)(all_number);

		gotoxy(55, 1);
		printf("당신의 승률은 %.2f 퍼센트 입니다!", victory_rate * 100);

		all_number++;

		Sleep(4450);

		/*화면을 깨끗하게 비움*/
		system("cls");
	}

	Sleep(100000000);
	return 0;
}

//함수정의

void gotoxy(int x, int y) {
	COORD XY = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}

int move_arrow(int me) {
	gotoxy(30, 10);
	printf("  ");
	gotoxy(30, 11);
	printf("  ");
	gotoxy(30, 12);
	printf("  ");

	gotoxy(30, 10 + me);
	printf("▶");

	return 0;
}

int keybord(int me){
	while (1) {
		int what_key;
		what_key = _getch();

		switch (what_key) {
		case 72:
			if (me > 0) {
				me--;
				move_arrow(me);
			}
			break;
		case 80:
			if (me < 2) {
				me++;
				move_arrow(me);
			}
			break;
		case 13:
			return 0;
		}
	}
	return 0;
}