#include<stdio.h>
#include<stdlib.h>     
#include<malloc.h>  
#include<time.h>

typedef struct node			
{
	char  no[12];			//编号 
	char  name[40];			//名称 
	int  workload;          //数量
	struct node *next;		//指向下一节点的指针
}nod;						//自定义结构体变量

void huiwen();								  //打出回文数
void mainmenu();							  //显示主菜单
void Display(int i);						  //发牌显示输出函数
void fapaimenu()							  //显示发牌系统菜单	
void deal();								  //洗牌函数
int fapai(void);							  //发牌系统主函数
void menu(nod *head);                         //显示商品管理系统主菜单         
nod *create();                                //创建链表 
void Input(nod *head);						  //输入商品信息     
void output(nod *head);                       //输出商品信息 
void chaxun(nod *head);                       //查询商品库存量
void xiugai(nod *head);                       //修改商品库存量   
void shanchu(nod *head);                      //删除商品信息 
void paixu(nod *head);		       			  //对商品库存量排序 
int guanli();								  //商品库存管理系统主函数

void mainmenu()
{	
	printf("\t\t***********************************\n");
	printf("\t\t****      课程设计系统         ****\n");
	printf("\t\t****    1.回文数统计           ****\n");
	printf("\t\t****    2.自动发牌             ****\n");
	printf("\t\t****    3.商品库存管理系统     ****\n");
	printf("\t\t****    4.清屏                 ****\n");
	printf("\t\t****    0.退出                 ****\n");
	printf("\t\t***********************************\n");
	printf("\t\t请输入你的选择(0~4):");
}

void huiwen()								//打印回文数功能
{
	int n,a,b,c[100],i=0,k,j;
	printf("本次输出256以内的回文数:");
	for(n=1;n<256;n++)
	{
		a=n*n;	
		while(a)
			{
				c[i]=a%10;
				i++;
				a=a/10;
			}
		k=c[0];
		if(n*n>10)
			for(j=i-1;j>=0;j--)
				k=k+10*c[j];
		if(n*n==k)
			printf("%d\t",n*n);
			i=0;
	}
	printf("\n回文数打印完毕!\n本系统功能结束，重新返回主系统！\n");
	mainmenu();
}

int poker[51];							//定义全局变量

void Display(int i)						//发牌显示输出函数
{
	switch(i%4)
	{
		case 0:
			printf("H");
			break;
		case 1:
			printf("S");
			break;
		case 2:
			printf("C");
			break;
		case 3:
			printf("D");
			break;
	}
	if(i/4+1<11)
		printf("%d\t",i/4+1); 
	else if(i/4+1==11)
		printf("%c\t",'J'); 
	else if(i/4+1==12)
		printf("%c\t",'Q'); 
	else if(i/4+1==13)
		printf("%c\t",'K'); 
}

void deal()									//洗牌函数
{
	int i,j,temp;
	srand((int)time(0));
	for(i=0;i<52;i++)
	{
		temp=rand()%52;
		for(j=0;j<i;j++)
		{
			if(poker[j]==temp)
				break;
		}
		if(j==i)
			poker[i]=temp;
		else i--;
	}
	for(i=0;i<52;i++)
	{
		if(i%5==0&&i!=0)
			printf("\n");
		if(i%13==0&&i!=0)
			printf("\n\n");
		if(i%13==0)
			printf("第%d个玩家的牌:\n",i/13+1);
		Display(poker[i]);
	}
}

void fapaimenu()				//显示发牌系统菜单
{
	printf("\n\n\t**********************************\n");
	printf("\t****    欢迎进入自动发牌系统  ****\n");
    printf("\t****         1.洗牌并发牌     ****\n");
    printf("\t****         2.清屏           ****\n");
    printf("\t****         0.退出           ****\n");
	printf("\t**********************************\n");
	printf("\t请输入你的选择(0~2)：\n");
}

int fapai(void)					//发牌系统主函数
{
	fapaimenu();
	while(1)
	{
		int key; 
		printf("\n请继续输入命令:");
		scanf("%d",&key);
		switch(key)
		{
		case 1:
			deal();
			break;
		case 0:
			main();
			break;
		case 2:
			system("cls");
			mainmenu();
			fapaimenu();
			break;
		default:
			break;
		}
	}
	return 0;
}

void menu(nod *head)                                //显示菜单 
{
	printf("\n\t\t\t欢迎进入商品库存管理系统\n");
	printf("\n");
	printf("\t**********************操作指南*******************************\n");
	printf("\t*    1.商品信息录入      *    2.查找商品库存量              *\n");
	printf("\t*    3.修改商品库存量    *    4.删除商品信息                *\n");
	printf("\t*    5.显示商品信息      *    6.按库存量从底到高进行排序    *\n");
	printf("\t*    7.清屏                                                 *\n");
	printf("\t*********************0.退出**********************************\n");
	printf("\n\t\t请输入你的选项（0---7）:\n");
	printf("\n");
	printf("\t请输入你的选择: \n");
}

nod *create()										//创建链表   
{
	nod *p;
	p = (nod *)malloc(sizeof(struct node));			//为链表动态分配空间
	if (p == NULL)
	{
		printf("链表创建失败.\n");
		exit(0);
	}
	p->next = NULL;
	return (p);
}

void Input(nod *head)								//录入商品信息     
{
	nod *p;
	int i,n;
	printf("请输入：你想录入多少个商品信息: \n ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)					
	{
		p = (nod *)malloc(sizeof(struct node));
		if (p == NULL)								//判断节点是否创建成功
		{
			printf("结点创建失败.\n");
			exit(0);
		}
		printf("请输入商品:编号，名称，数量：\n");
		printf("编号:");
		scanf("%s", p->no);
		printf("名称:");
		scanf("%s", p->name);
		printf("数量:");
		scanf("%d", &p->workload);
		p->next = NULL;
		while (head->next != NULL)
			head = head->next;
		head->next = p;
	}
	printf("本次商品信息录入结束！\n");
	printf("请继续选择你的操作：");
}


void output(nod *head)							//输出商品信息 
{
	int n = 0;
	nod *p;
	p = head->next;
	if (p == NULL)
	{
		printf("商品信息为空，请先进行录入操作！\n");
		printf("本次商品信息输出结束！\n");
		printf("请继续选择你的操作：");
		return;
	}
	while (p != NULL)							//循环一次遍历链表内容，实现输出					
	{
		n++;
		printf("编号: %s\t名称:%s\t数量:%d\n", p->no, p->name,  p->workload);
		p = p->next;
	}
	printf("本次商品信息输出结束！\n");
	printf("请继续选择你的操作：");
}

void chaxun(nod *head)							//查询商品库存量  
{
	char a[40];
	int i = -1;
	nod *p;
	p = head;
	printf(" 请输入要查找商品的名称 :\n");
	scanf("%s", a);
	while (p->next != NULL)						//循环遍历，依次比较
	{
		p = p->next;
		if (strcmp(p->name, a) == 0)			//strcmp函数比较字符串是否相同
		{
			i = 1;
			printf("已找到该商品库存量\n");
			printf("编号:%s\t名称:%s\t数量:%d,\n", p->no, p->name, p->workload);
		}
	}
	if (i<0)
		printf("没有此商品！\n");
	printf("本次商品库存量查询结束！\n");
	printf("请继续选择你的操作：");
}

void xiugai(nod *head)                           //修改商品库存量
{
	char no[12];
	int i = -1;
	nod *p;
	p = head;
	printf("请输入要修改商品库存量商品的编号：\n");
	scanf("%s", no);
	while (p->next != NULL)						//循环遍历，找出对应编号商品信息
	{
		p = p->next;
		if (strcmp(p->no, no) == 0)
		{
			i = 1;
			printf("请输入新的的库存量:");
			scanf("%d", &p->workload);
		}
	}
	if (i<0)
		printf("没有此商品信息！\n");
	printf("本次商品库存量修改结束！\n");
	printf("请继续选择你的操作：");
}

void shanchu(nod *head)                      //删除商品信息 
{
	char name[40];
	int i = -1;
	nod *p, *h;
	p = head;
	printf("请输入你要删除的商品的名称：\n");
	scanf("%s", name);
	while (p->next != NULL)					//循环遍历
	{
		if (strcmp(name, p->next->name) == 0)
		{
			i = 1;
			h = p->next;
			p->next = p->next->next;
			free(h);						//使用free函数释放分配空间
			printf("已删除该商品信息。\n");
			break;
		}
		p = p->next;
	}
	if (i<0)
		printf("没有此商品信息！\n");
	printf("本次商品信息删除结束！\n");
	printf("请继续选择你的操作：");
}

void paixu(nod *head)				//对商品库存量进行排序
{
    nod *p,*q,*t,*s;				//定义节点变量，为后续比较做准备
	int z = 0,x,n=1;
    t=NULL;
    while((head->next->next) != t)
    {
        p = head;
        q = head->next;
        while(q->next != t)			//二次循环实现多个遍历对象
        {
            if((q->workload) > (q->next->workload))
            {
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = q;
                q = p->next;
            }
            q = q->next;
            p = p->next;
        }
        t = q;
    }
    printf("商品库存量从小到大结果如下:\n");
	printf("排名\t名称\t库存量\n");
    s=head->next;
    while(s!=NULL)
    {
        if(s->next!=NULL)
        {
            printf("%d\t%s\t%d\n",n,s->name,s->workload);
            s=s->next;
        }
        else
        {
            printf("%d\t%s\t%d\n",n,s->name,s->workload);
            s=s->next;
        }
		n++;
    }
	while(head->next!=NULL)				//简单的数据相加
	{
		head = head->next;
		x = head->workload;
		z = z + x;
	}
	printf("所有商品目前总库存量为：%d\n",z);
	printf("本次商品库存量排序结束！\n");
	printf("请继续选择你的操作：");
}

int guanli()								//商品库存管理系统主函数
{
	nod *head;
	head = (nod*)malloc(sizeof(struct node));
	head = create();
	menu(head);
	while (1)
	{
		int e;
		scanf("%d", &e);
		switch (e)                             //功能选择
		{
			case 1:
				Input( head);
				break;
			case 2:
				chaxun(head);
				break;
			case 3:
				xiugai(head);
				break;
			case 4:
				shanchu(head);
				break;
			case 5:
				output(head);
				break;
			case 6:
				paixu(head);
				break;
			case 7:
				system("cls");
				mainmenu();
				menu(head);
				break;
			case 0:
				main();
				break;
			default:
				printf("输入错误！请按说明输入你的选项！\n");
			break;
		}
	}
}

int main()						//主函数
{
	mainmenu();
	while(1)
	{
		int a;
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				huiwen();
				break;
			case 2:
				fapai();
				break;
			case 3:
				guanli();
				break;
			case 4:
				system("cls");
				mainmenu();
				break;
			case 0:
				printf("本次设计方案就此退出，感谢您的使用！\n");
				exit(0);
			default:
				printf("输入错误，请按照规则输入选项！");
				break;
		}
	}
}