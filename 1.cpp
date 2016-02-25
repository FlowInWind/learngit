#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h> 
int spade[13],heart[13],diamond[13],club[13],player[4]={0,0,0,0};
main()
{
	int i,j,k,p;
	srand(time(NULL));
	for (i=0;i<=12;i++)
	{
		do
			spade[i]=rand()%4;
		while (player[spade[i]]==13);
		player[spade[i]]++;
	}
	for (i=0;i<=12;i++)
	{
		do
			heart[i]=rand()%4;
		while (player[heart[i]]==13);
		player[heart[i]]++;
	}
	for (i=0;i<=12;i++)
	{
		do
			diamond[i]=rand()%4;
		while (player[diamond[i]]==13);
		player[diamond[i]]++;
	}
	for (i=0;i<=12;i++)
	{
		do
			club[i]=rand()%4;
		while (player[club[i]]==13);
		player[club[i]]++;
	}
	for (k=0;k<=3;k++)
	{
		p=0;
		switch (k)
		{
			case 0:printf("            south            \n");break;
			case 1:printf("            west            \n");break;
			case 2:printf("            north            \n");break;
			case 3:printf("            east            \n");break;
		}
		for (i=0;i<=3;i++)
		{
			switch (i)
			{
				case 0:printf("SPADE:       ");break;
				case 1:printf("HEART:       ");break;
				case 2:printf("DIAMOND:     ");break;
				case 3:printf("CLUB:        ");break;
			}
			for (j=12;j>=0;j--)
			{
				if (i==0)
				{
					if (spade[j]!=k) continue;
					switch (j)
					{
						case 12:printf("A  ");p+=4;break;
						case 11:printf("K  ");p+=3;break;
						case 10:printf("Q  ");p+=2;break;
						case 9:printf("J  ");p+=1;break;
						case 8:printf("10 ");break;
						default:printf("%d  ",j+2);
					}
				}
				if (i==1)
				{
					if (heart[j]!=k) continue;
					switch (j)
					{
						case 12:printf("A  ");p+=4;break;
						case 11:printf("K  ");p+=3;break;
						case 10:printf("Q  ");p+=2;break;
						case 9:printf("J  ");p+=1;break;
						case 8:printf("10 ");break;
						default:printf("%d  ",j+2);
					}
				}
				if (i==2)
				{
					if (diamond[j]!=k) continue;
					switch (j)
					{
						case 12:printf("A  ");p+=4;break;
						case 11:printf("K  ");p+=3;break;
						case 10:printf("Q  ");p+=2;break;
						case 9:printf("J  ");p+=1;break;
						case 8:printf("10 ");break;
						default:printf("%d  ",j+2);
					}
				}
				if (i==3)
				{
					if (club[j]!=k) continue;
					switch (j)
					{
						case 12:printf("A  ");p+=4;break;
						case 11:printf("K  ");p+=3;break;
						case 10:printf("Q  ");p+=2;break;
						case 9:printf("J  ");p+=1;break;
						case 8:printf("10 ");break;
						default:printf("%d  ",j+2);
					}
				}
			}
			printf("\n");
		}
		printf("            %dhcp\n\n",p);
	}
}