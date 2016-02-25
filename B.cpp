#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h> 
int health=200,attack=10,defend=2,money=0,power=0,h,ph,a,pa,d,pd,m,p,pp,phealth,honor,win=2;
int al[5]={0,0,0,0,0},CD[5]={7,15,0,6,9},k[5]={0,0,0,0,0};
float b[5];
void attacke()
{
	int pp=rand()%100+1;
	if (pp<=16&&pp>3) {p=2;printf("double damage!\n");} else p=1;
	if (pp>=92) {p=0;printf("enemy miss!\n");}
	if (pp<=3) {p=3;printf("triple damage!\n");} 
	if (attack>d) h-=(attack-d)*p;
	if (h<=0) win=1;
}
void heal()
{
	health+=b[1];
}
void learn()
{
	int c;
	power++;
	printf("You have 1 skill points.Please choose one skill.\n");
	printf("1:(active)get damage of 0/10/30/60/100+15%% enemy's max health.CD:7 turns(%d level now)\n",al[0]);
	printf("2:(active)heal your 40/70/100/130/160 health.CD:15 turns(%d level now)\n",al[1]);
	printf("3:(passive)increase your chance to avoid enemy's attack by 3%%/6%%/9%%/12%%/15%%(%d level now)\n",al[2]);
	printf("4:(active)get 1/1/2/3/4 more attacks in a time.CD:6/4/6/8/10 turns(%d level now)\n",al[3]);
	printf("5:(active)get 10/20/30/40/50+10%% enemy's max health damage and heal you 50 per cent of such damage.CD:9 turns(%d level now)\n",al[4]);
	scanf("%d",&c);
	switch (c)
	{
		case 1:if (al[0]<5) al[0]++; else printf("error!\n");break;
		case 2:if (al[1]<5) al[1]++; else printf("error!\n");break;
		case 3:if (al[2]<5) al[2]++; else printf("error!\n");break;
		case 4:if (al[3]<5) al[3]++; else printf("error!\n");break;
		case 5:if (al[4]<5) al[4]++; else printf("error!\n");break;
		default:printf("cancelled\n");
	}
	switch (al[3])
	{
		case 1:CD[3]=6;break;
		case 2:CD[3]=4;break;
		case 3:CD[3]=6;break;
		case 4:CD[3]=8;break;
		case 5:CD[3]=10;break;
	}
}
void preskill()
{
	b[0]=((al[0]-1)*5*al[0]+ph*0.15);
	b[1]=30*al[1]+10;
	b[2]=3*al[2];
	b[3]=(al[3]==1)?1:(al[3]-1);
	b[4]=10*al[4]+ph*0.15;
}
void skill()
{
	int c,i;
	printf("Choose skills\n");
	if (al[0]) printf("1:get %d damage.CD:%d turns(%d level now)\n",(int)b[0],k[0],al[0]);
	if (al[1]) printf("2:heal you %d health.CD:%d turns(%d level now)\n",(int)b[1],k[1],al[1]);
	if (al[2]) printf("3:(passive)increase your chance to avoid enemy's attack by %d percent(%d level now)\n",(int)b[2],al[2]);
	if (al[3]) printf("4:get %d more attacks in a time.CD:%d turns(%d level now)\n",(int)b[3],k[3],al[3]);
	if (al[4]) printf("5:get %d damage and heal you 50 per cent.CD:%d turns(%d level now)\n",(int)b[4],k[4],al[4]);
	scanf("%d",&c);
	switch (c)
	{
		case 1:if (al[0]&&(!k[0])) {h-=b[0];k[0]=CD[0];if (h<=0) win=1;} else printf("error!");break;
		case 2:if (al[1]&&(!k[1])) {heal();k[1]=CD[1];} else printf("error!");break;
		case 3:printf("error!");break;
		case 4:if (al[3]&&(!k[3])) 
		            {
		            	k[3]=CD[3];
		            	for (i=0;i<=b[3];i++)
		            	       attacke();
		            } 
		            else printf("error!");break;
		case 5:if (al[4]&&(!k[4])) {h-=b[4];k[4]=CD[4];health+=b[4]/2;if (h<=0) win=1;} else printf("error!");break;
		default:printf("cancelled");
	}
	printf("\n");
}
void reattack()
{
	int pp=rand()%100+1;
	if (pp<=8&&pp>2) {p=2;printf("enemy double damage!\n");} else p=1;
	if (pp>=87-b[2]) {p=0;printf("miss!\n");}
	if (pp<=2) {p=3;printf("enemy triple damage!\n");}
	if (a>defend) health-=(a-defend)*p;
	if (health<=0) win=0;
}
void shop()
{
	int g;
	printf("Choose stuff\n1:gain 175 health(15 money)\n2:gain 2 attack(3 money)\n3:gain 1 defend(2 money)\n4:gain 4 attack(5 money)\n5:gain 3 defend(4 money)\n6:gain 4 attack & 3 defend(10 money)\n7:gain 7 attack & 5 defend & 50 health(25 money)\n");
	printf("You have %d money  ",money);  
	scanf("%d",&g);
	switch (g)
	{
		case 1:if (money>=15) {health+=175;money-=15;} else printf("error!");break;
		case 2:if (money>=3) {attack+=2;money-=3;} else printf("error!");break;
		case 3:if (money>=2) {defend+=1;money-=2;} else printf("error!");break;
		case 4:if (money>=5) {attack+=4;money-=5;} else printf("error!");break;
		case 5:if (money>=4) {defend+=3;money-=4;} else printf("error!");break;
		case 6:if (money>=10) {attack+=4;defend+=3;money-=10;} else printf("error!");break;
		case 7:if (money>=25) {health+=50;attack+=7;defend+=5;money-=25;} else printf("error!");break; 
		default:printf("cancelled");
	}
	printf("\n");
}
main()
{
	int i,j,order,wave;
	srand(time(NULL));
	printf("Ready? Go! 30 waves!\n\n");
	ph=50;pa=3;pd=0;wave=30;phealth=200;
	for (i=1;i<=wave;i++)
	{
		printf("\n***********The No.%d wave**********\n",i);
		if (i<=25) learn();
		h=rand()%(30*(1+i/4))+ph+10;
		a=rand()%(5*(1+i/8))+pa+1;
		d=rand()%(3*(1+i/8))+pd;
		m=i;
		ph=h;pa=a;pd=d;win=2;
		preskill();
		do
		{
			for (j=0;j<=4;j++)
			      if (k[j]) k[j]--;
		printf("Your situation:health:%d  attack:%d  defend:%d\n",health,attack,defend);
		printf("The enemy's situation:health:%d  attack:%d  defend:%d\n",h,a,d);
		printf("Your turn   1:attack;2:skills   ");
		scanf("%d",&order);
		switch (order)
		{
			case 1:attacke();break;
			case 2:skill();break;
			default:printf("Order error!Lose one turn!");break;
		}
		if (h>0) reattack();
		printf("\n");
	}   while (health>0&&h>0);
		if (win==1) {printf("You win the wave!\n");money+=m;honor++;} else if (win==0) {printf("You lose the wave!\n");health=phealth;}
		attack++;
		shop();
		health+=i*10+pa;
		(phealth+=i*12);
		attack+=rand()%3;
		defend+=rand()%2;
	}
	printf("You succeeded in %d waves out of %d!",honor,wave);
}
