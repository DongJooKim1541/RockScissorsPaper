#include <stdio.h>//�ܼ������ ���̺귯��
#include <string.h>//���ڿ����̺귯��
#include <time.h>//�ð����̺귯��,�����Լ� ���� �ʿ�
#include <stdlib.h>//c��� ǥ�ض��̺귯��,�����Լ�,���ڿ��Լ��� ����
#include <windows.h>//����,�ܼ�â ������
#include <conio.h>//kbhit�� ����°���

//�Լ�����
void gotoxy(int x, int y);
int move_arrow(int me);
int keybord(int me);

/*�����Լ�*/
int main() {
	/*�ܼ�ũ�� ����.XXXX ����� ����ũ���Է�. ũ��1�� ������ �ϳ��� ���α���. YYYY ����� ����ũ�� �Է�. 1�� �� ���� �ǹ�.*/
	system("mode con: cols=100 lines=24");
	/*Ŀ�����ֱ�.*/
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);//��������� �ǵ帮�� ����!
	
	//��������
	int me = 0;
	int computer;
	int all_number = 1;
	int win_number = 0;
	float victory_rate;
	
	gotoxy(40, 11);
	
	Sleep(500);
	printf("�� ");
	Sleep(500);
	printf("�� ");
	Sleep(500);
	printf("�� ");
	Sleep(500);
	printf("�� ");
	Sleep(500);
	printf("�� ");
	Sleep(500);
	printf("�� ");
	Sleep(500);
	printf("�� \n");

	/*�ƹ�Ű�� ������ �ѱ��.*/
	while (_kbhit()) _getch();
	Sleep(1000);
	gotoxy(37, 14);
	printf("�ƹ� Ű�� ������ �����մϴ�!");
	while (1) {
		if (_kbhit()) {
			_getch();
			break;
		}
	}
	while (1) {
		/*ȭ���� �����ϰ� ���*/
		system("cls");


		/*�����Լ������ �ʱ�ȭ*/
		srand(time(NULL));                                

		/*rand()%5 �� 0~4 �� ���� �������� ���ɴϴ�. 1~5 �Ϸ��� rand()%5+1*/
		computer = rand() % 3;

		//������
		gotoxy(35, 8);
		printf("������ ���ðڽ��ϱ�?");
		gotoxy(38, 10);
		printf("����");
		gotoxy(38, 11);
		printf("����");
		gotoxy(38, 12);
		printf("��");

		gotoxy(30, 10);
		printf("  ");
		gotoxy(30, 11);
		printf("  ");
		gotoxy(30, 12);
		printf("  ");

		//�Լ�ȣ��
		move_arrow(me);
		me = keybord(me);

		//���������� �ϱ�
		if (computer == 0) {
			if (me == 0) {
				system("cls");
				gotoxy(30, 9);
				printf("��ǻ�ʹ� ����, �ʵ� ����!");
				gotoxy(45, 12);
				printf("Draw!");
			}
			else if (me == 1) {
				system("cls");
				gotoxy(38, 9);
				printf("��ǻ�ʹ� ����, �ʴ� ����!");
				gotoxy(45, 12);
				printf("You Win!");
				win_number++;
			}
			else {
				system("cls");
				gotoxy(38, 9);
				printf("��ǻ�ʹ� ����, �ʴ� ��!");
				gotoxy(45, 12);
				printf("You Lose!");
			}
		}
		else if (computer == 1) {
			if (me == 0) {
				system("cls");
				gotoxy(38, 9);
				printf("��ǻ�ʹ� ����, �ʴ� ����!");
				gotoxy(45, 12);
				printf("You Lose!");
			}
			else if (me == 1) {
				system("cls");
				gotoxy(38, 9);
				printf("��ǻ�ʹ� ����, �ʵ� ����!");
				gotoxy(45, 12);
				printf("Draw!");
			}
			else {
				system("cls");
				gotoxy(38, 9);
				printf("��ǻ�ʹ� ����, �ʴ� ��!");
				gotoxy(45, 12);
				printf("You Win!");
				win_number++;
			}
		}
		else {
			if (me == 0) {
				system("cls");
				gotoxy(38, 9);
				printf("��ǻ�ʹ� ��, �ʴ� ����!");
				gotoxy(45, 12);
				printf("You Win!");
				win_number++;
			}
			else if (me == 1) {
				system("cls");
				gotoxy(38, 9);
				printf("��ǻ�ʹ� ��, �ʴ� ����!");
				gotoxy(45, 12);
				printf("You Lose!");
			}
			else {
				system("cls");
				gotoxy(38, 9);
				printf("��ǻ�ʹ� ��, �ʵ� ��!");
				gotoxy(45, 12);
				printf("All Draw!");
			}
		}

		//�·����
		victory_rate = (float)(win_number) / (float)(all_number);

		gotoxy(55, 1);
		printf("����� �·��� %.2f �ۼ�Ʈ �Դϴ�!", victory_rate * 100);

		all_number++;

		Sleep(4450);

		/*ȭ���� �����ϰ� ���*/
		system("cls");
	}

	Sleep(100000000);
	return 0;
}

//�Լ�����

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
	printf("��");

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