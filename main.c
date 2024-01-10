
#include <stdio.h>
#include <windows.h>
#include <conio.h>

void GotoXY(int x, int y) //커서의 위치를 x, y로 이동하는 함수
{
    COORD Pos;
    Pos.X = x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void racing_car(int now_x,int now_y) {//자동차
    GotoXY(now_x, now_y);
	printf("  ____  \n");
    GotoXY(now_x, now_y+1);
	printf("_|____|_\n");
    GotoXY(now_x, now_y+2);
	printf(" |    | \n");
    GotoXY(now_x, now_y+3);
	printf(" (____) \n");
    GotoXY(now_x, now_y+4);
	printf(" |____| \n");
}

void SetConsoleView()//실행창 가로 세로 정하기
{
    system("mode con:cols=60 lines=45"); //cols=가로 크기 lines=세로 크기
    system("title racing game");// 프로젝트 이름 설정
}


//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }
    return 0;
}

int main() {
    SetConsoleView();

    int racingcar_x = 22;//메인캐릭터 나타나는 위치
    int racingcar_y = 35;

    while (1) {
        racing_car(racingcar_x, racingcar_y);

        int key = GetKeyDown();

        if (key == 'w') {
            racingcar_y--;
            system("cls");
        }
        else if (key == 'a') {
            racingcar_x--;
            system("cls");
        }
        else if (key == 's') {
            racingcar_y++;
            system("cls");
        }
        else if (key == 'd') {
            racingcar_x++;
            system("cls");
        }
    }
}
