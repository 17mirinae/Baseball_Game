#include "Baseball_Game.h"

void input(void)
{
	int i, j;
	int b[3];
	char c[3];

	srand(time(NULL));

	makeball();

	for(j=1;j<=10;j++)
	{
		printf("[%d차 시도]세 자리 숫자를 입력하시오:", j);
		
		for(i=0;i<3;i++)
			scanf("%c", &c[i]);

		for(i=0;i<3;i++)
			b[i]=c2i(c[i]);

		if(strike(b[0], b[1], b[2])==3)
			{
			printf("%dS %dB\n", strike(b[0], b[1], b[2]), ball(b[0], b[1], b[2]));
			printf("정답입니다.\n종료합니다.\n");
			break;
			}
		else
			printf("입력된 건 %d, %d, %d입니다.\n", b[0], b[1], b[2]);

		if(b[0]<0||b[1]<0||b[2]<0)
			{
			printf("잘못 입력하셨습니다.\n종료합니다.\n");
			break;
			}
		else
			printf("%dS %dB\n", strike(b[0], b[1], b[2]), ball(b[0], b[1], b[2]));

		if(strike(b[0], b[1], b[2])<3&&j==10)
			{
			printf("정답은 %d %d %d였습니다.\n", a[0], a[1], a[2]);
			printf("횟수 초과입니다.\n종료합니다.\n");
			}

	while(getchar()!='\n');
	}
}
int c2i(char c)
{
	int i;

	for(i=0;i<3;i++){
		if(c<'0'||c>'9')
			return -1;
		else
		{
			c-='0';
			return c;
		}
	}
}
int ball(int b1, int b2, int b3)
{
	int ba=0;

	if(b1==a[1])
		ba++;
	else if(b1==a[2])
		ba++;

	if(b2==a[0])
		ba++;
	else if(b2==a[2])
		ba++;

	if(b3==a[0])
		ba++;
	else if(b3==a[1])
		ba++;

	return ba;
}
int strike(int b1, int b2, int b3)
{
	int st=0;

	if(a[0]==b1)
		st++;
	if(a[1]==b2)
		st++;
	if(a[2]==b3)
		st++;

	return st;
}
void makeball()
{
	int i;

	while(1)
	{
		for(i=0;i<3;i++){
			a[i]=rand()%10;}

	if((a[0]!=a[1])&&(a[1]!=a[2])&&(a[0]!=a[2]))
	break;
	}
}