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
		printf("[%d�� �õ�]�� �ڸ� ���ڸ� �Է��Ͻÿ�:", j);
		
		for(i=0;i<3;i++)
			scanf("%c", &c[i]);

		for(i=0;i<3;i++)
			b[i]=c2i(c[i]);

		if(strike(b[0], b[1], b[2])==3)
			{
			printf("%dS %dB\n", strike(b[0], b[1], b[2]), ball(b[0], b[1], b[2]));
			printf("�����Դϴ�.\n�����մϴ�.\n");
			break;
			}
		else
			printf("�Էµ� �� %d, %d, %d�Դϴ�.\n", b[0], b[1], b[2]);

		if(b[0]<0||b[1]<0||b[2]<0)
			{
			printf("�߸� �Է��ϼ̽��ϴ�.\n�����մϴ�.\n");
			break;
			}
		else
			printf("%dS %dB\n", strike(b[0], b[1], b[2]), ball(b[0], b[1], b[2]));

		if(strike(b[0], b[1], b[2])<3&&j==10)
			{
			printf("������ %d %d %d�����ϴ�.\n", a[0], a[1], a[2]);
			printf("Ƚ�� �ʰ��Դϴ�.\n�����մϴ�.\n");
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