/*
프로젝트 이름 별이 빛나는 밤 랜덤 위치 값에 *이 출력하도록 한다.
1.반복문 이전에 랜덤값을 조성한다.즉 함수 srand를 먼저 정의한다.
2.반복문을 사용하여 랜덤한 위치에 별을 생성한다.
3.반복 횟수에 따라 그 횟수와 일치하는 배열의 요소에 별의 위치를 저장한다.
4.반복횟수가 3이되면 차례대로 별을 지우고 continue를 이용하여 반복횟수가 0이 될때동안 반복을 반복하고 0이되면 다시 처음 반복문으로 되돌아간다.
*/



#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	return printf("*");
}

void ugotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	return printf(" ");
}


int main(void)
{
	int starx, stary,i=0,i2=0;
	int arr[3][2],arr2[3][2];//1열은 x좌표 2열은 y좌표이다.
	
	srand(time(NULL));
	while (1)
	{
		while (i < 3)
		{
			if ((i2<=3))//i2가 3이라면 1번이상 반복을 하였기 때문에 다시 3개의 별이 찍혔을 것이다. 그것을 지우기 위해 3이하라는 조건을 달았다.
			{
				if(i2==3)//i2가 3이면 0으로 초기화한다.
					i2 = 0;//0번째 요소에 저장된 위치부터 별을 지우기 위해서이다.
				ugotoxy(arr2[i2][0], arr2[i2][1]);
				i2++;
				Sleep(1000);
			}
			
			arr[i][0] = rand()%50;//배열에 랜덤x좌표값을 저장한다.
			arr[i][1] = rand()%30;//배열에 랜덤y좌표값을 저장한다.
			gotoxy(arr[i][0], arr[i][1]);//랜덤 좌표값에 별을 찍는다.
			i++;//배열의 n+1요소에 좌표값을 저장하기 위해 i에 1을 더한다.
			Sleep(1000);
		}
		i = 0;//다시 i를 초기화해준다.
		i2 = 0;
		for (int j = 0; j < 3; j++)
		{
			ugotoxy(arr[j][0], arr[j][1]);//j를 이용하여 0번째 요소부터 3번째 요소까지 저장된 별에 위치에 찾아가서 공백문자를 대신 삽입한다.
			Sleep(1000);
	/*
	별이 없어짐과 동시에 다시 별이 생기도록 하였다.
	*/
			arr2[i2][0] = rand()%50;//arr2라는 배열에 랜덤x좌표값을 저장하도록 하였다.
			arr2[i2][1] = rand()%30;//arr2라는 배열에 랜덤y좌표값을 저장하도록 하였다.
			gotoxy(arr2[i2][0], arr2[i2][1]);//랜덤 x,y좌표에 가서 별을 찍는다.
			i2++;//n번째 요소는 저장되었으니 n+1번째 요소로 저장되도록 i2을 1 증가하였다.
			Sleep(1000);
		}

	}
}