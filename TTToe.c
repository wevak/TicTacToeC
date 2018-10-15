#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
char a[9];
int play_again()
{
	system("cls");
	char c;
	printf("\n\n\tWanna play again(y/n):");
y:	scanf("%c",&c);
	if(c=='y'||c=='Y')
		return 2;
	else if(c=='n'||c=='N')
				exit(0);
	else{ printf("\n\tInvalid choice! Please Enter again:"); goto y;}
	
}
void workspace()
{
	system("cls");
	printf("\t %c | %c | %c\n",a[0],a[1],a[2]);
	printf("\t------------\n");
	printf("\t %c | %c | %c\n",a[3],a[4],a[5]);
	printf("\t------------\n");
	printf("\t %c | %c | %c",a[6],a[7],a[8]);
}
int check(int c)
{
	if(a[c]!=0)
		return 1;
	else 
		return 0;
}
int draw()
{
	int i=0,k=1;
	while(i<9)
	{
		if(a[i]=='X'||a[i]=='O')
		  k++;
		i++;
	}
	if(k==9)
	{
	   printf("\n\tDraw!!");
	   return 1;
	}
	else return 0;
}
char turn(int s)
{
	if(s%2==0)
			return 'X';
		else
			return 'O';
}
int winner(char w)
{
	if(a[0]==w&&a[3]==w&&a[6]==w || a[0]==w&&a[1]==w&&a[2]==w || a[0]==w&&a[4]==w&&a[8]==w || a[1]==w&&a[4]==w&&a[7]==w || a[2]==w&&a[5]==w&&a[8]==w || a[2]==w&&a[4]==w&&a[6]==w || a[6]==w&&a[7]==w&&a[8]==w )
		return 0;
	else
		return 1;
}
void flush(char *h)
{
	int i;
	for(i=0;i<9;i++)
	{
		*h=0;
		h++;	
	}	
}
int main()
{
	system("cls");
	int c,t=0;
	char y,l;
	printf("\tWELCOME TO TIC TAC TOE!");
	getch();
	while(1)
	{
		workspace();
		printf("\n");
		y=turn(t);
		printf("Its %c's Turn.",y);
	m:	printf("\n\nEnter any place from 1-9:");	
		scanf("%d",&c);
		c-=1;
		if(check(c)!=0)
		{
			printf("Cannot overwrite! Please Enter again:"); goto m;
		}
		if(draw()==1)
		{
			workspace();
			printf("\n\tMatch is draw!");
			getch();
			if(play_again()==2)
			{
				flush(a);
				main();
			}
		}
		a[c]=y;
		if(winner(y)==0)
		{  
			printf("\n\n\tWinner is %c",y);
			getch();
			if(play_again()==2)
			{
				flush(a);
				main();
			}
		}
		t++;
	}
}
