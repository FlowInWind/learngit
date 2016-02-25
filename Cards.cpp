#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#define 10 15
//#define 10 10
int a[11],b[11],c[11],wcom,com,T=1,flag=0,S=0,count[4]={10,10,10,10};
void game()
{
	int b1=1,c1=1,i;
	printf("\n");
	if (T==1)
	{
		printf("\nGive a card: ");
		scanf("%d",&wcom);
		printf("\n");
		for (i=1;i<=10;i++)
		{
			if (a[i]==wcom&&wcom>com) 
			{
				printf("A(You): %d\n",a[i]);
				com=a[i];
				S=0;
				a[i]=0;
				if (!--count[1]) flag=1;
				return;
			}
		}
		printf("A(You): Pass!\n");
		S++;
		return;
	}
	else
	{
		if (T==2)
		{
			for (i=1;i<=10;i++)
			{
				if (b[i]>com) 
				{
					printf("B: %d\n",b[i]);
					com=b[i];
					S=0;
					b[i]=0;
					if (!--count[2]) flag=2;
					b1=0;
					return;
				}
			}
			if (b1) 
			{
				printf("B: Pass!\n");
				S++;
				return;
			}
		}
		else
		{
			for (i=1;i<=10;i++)
			{
				if (c[i]>com) 
				{
					printf("C: %d\n",c[i]);
					com=c[i];
					S=0;
					c[i]=0;
					if (!--count[3]) flag=3;
					c1=0;
					return;
				}
			}
			if (c1)
			{
				printf("C: Pass!\n");
				S++;
				return;
			}
		}
	}
}
void main()
{
	srand(time(NULL));
	int i,OK=0;
	flag=0;
	printf("Your cards:\n");
	for (i=1;i<=10;i++)
	{
		a[i]=rand()%10+1;
		b[i]=rand()%10+1;
		c[i]=rand()%10+1;
		printf("%d  ",a[i]);
	}
	printf("\nGive a card: ");
	scanf("%d",&com);
	for (i=1;i<=10;i++)
		if (a[i]==com) 
		{
			a[i]=0;
			OK=1;
			count[1]--;
			break;
		}
	if (!OK)
	{
		com=0;
		printf("A(You): Pass!\n");
	}
	while(1)
	{
		T++;
		if (T==4) T=1;
		if (T==1)
		{
			printf("\n");
			for (i=1;i<=10;i++)
				printf("%d  ",a[i]);
		}
		game();
		printf("Cards in hand:\n");
		printf("A(You): %d    B: %d    C: %d\n",count[1],count[2],count[3]);
		if (S==2)
		{
			S=0;
			com=0;
		}
		if (flag) break;
	}
	switch (flag)
	{
		case 1:printf("You win!\n");break;
		case 2:printf("B wins!\n");break;
		case 3:printf("C wins!\n");break;
	}
}
