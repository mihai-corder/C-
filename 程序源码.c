#include<stdio.h>
#include<stdlib.h>     
#include<malloc.h>  
#include<time.h>

typedef struct node			
{
	char  no[12];			//��� 
	char  name[40];			//���� 
	int  workload;          //����
	struct node *next;		//ָ����һ�ڵ��ָ��
}nod;						//�Զ���ṹ�����

void huiwen();								  //���������
void mainmenu();							  //��ʾ���˵�
void Display(int i);						  //������ʾ�������
void fapaimenu()							  //��ʾ����ϵͳ�˵�	
void deal();								  //ϴ�ƺ���
int fapai(void);							  //����ϵͳ������
void menu(nod *head);                         //��ʾ��Ʒ����ϵͳ���˵�         
nod *create();                                //�������� 
void Input(nod *head);						  //������Ʒ��Ϣ     
void output(nod *head);                       //�����Ʒ��Ϣ 
void chaxun(nod *head);                       //��ѯ��Ʒ�����
void xiugai(nod *head);                       //�޸���Ʒ�����   
void shanchu(nod *head);                      //ɾ����Ʒ��Ϣ 
void paixu(nod *head);		       			  //����Ʒ��������� 
int guanli();								  //��Ʒ������ϵͳ������

void mainmenu()
{	
	printf("\t\t***********************************\n");
	printf("\t\t****      �γ����ϵͳ         ****\n");
	printf("\t\t****    1.������ͳ��           ****\n");
	printf("\t\t****    2.�Զ�����             ****\n");
	printf("\t\t****    3.��Ʒ������ϵͳ     ****\n");
	printf("\t\t****    4.����                 ****\n");
	printf("\t\t****    0.�˳�                 ****\n");
	printf("\t\t***********************************\n");
	printf("\t\t���������ѡ��(0~4):");
}

void huiwen()								//��ӡ����������
{
	int n,a,b,c[100],i=0,k,j;
	printf("�������256���ڵĻ�����:");
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
	printf("\n��������ӡ���!\n��ϵͳ���ܽ��������·�����ϵͳ��\n");
	mainmenu();
}

int poker[51];							//����ȫ�ֱ���

void Display(int i)						//������ʾ�������
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

void deal()									//ϴ�ƺ���
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
			printf("��%d����ҵ���:\n",i/13+1);
		Display(poker[i]);
	}
}

void fapaimenu()				//��ʾ����ϵͳ�˵�
{
	printf("\n\n\t**********************************\n");
	printf("\t****    ��ӭ�����Զ�����ϵͳ  ****\n");
    printf("\t****         1.ϴ�Ʋ�����     ****\n");
    printf("\t****         2.����           ****\n");
    printf("\t****         0.�˳�           ****\n");
	printf("\t**********************************\n");
	printf("\t���������ѡ��(0~2)��\n");
}

int fapai(void)					//����ϵͳ������
{
	fapaimenu();
	while(1)
	{
		int key; 
		printf("\n�������������:");
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

void menu(nod *head)                                //��ʾ�˵� 
{
	printf("\n\t\t\t��ӭ������Ʒ������ϵͳ\n");
	printf("\n");
	printf("\t**********************����ָ��*******************************\n");
	printf("\t*    1.��Ʒ��Ϣ¼��      *    2.������Ʒ�����              *\n");
	printf("\t*    3.�޸���Ʒ�����    *    4.ɾ����Ʒ��Ϣ                *\n");
	printf("\t*    5.��ʾ��Ʒ��Ϣ      *    6.��������ӵ׵��߽�������    *\n");
	printf("\t*    7.����                                                 *\n");
	printf("\t*********************0.�˳�**********************************\n");
	printf("\n\t\t���������ѡ�0---7��:\n");
	printf("\n");
	printf("\t���������ѡ��: \n");
}

nod *create()										//��������   
{
	nod *p;
	p = (nod *)malloc(sizeof(struct node));			//Ϊ����̬����ռ�
	if (p == NULL)
	{
		printf("������ʧ��.\n");
		exit(0);
	}
	p->next = NULL;
	return (p);
}

void Input(nod *head)								//¼����Ʒ��Ϣ     
{
	nod *p;
	int i,n;
	printf("�����룺����¼����ٸ���Ʒ��Ϣ: \n ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)					
	{
		p = (nod *)malloc(sizeof(struct node));
		if (p == NULL)								//�жϽڵ��Ƿ񴴽��ɹ�
		{
			printf("��㴴��ʧ��.\n");
			exit(0);
		}
		printf("��������Ʒ:��ţ����ƣ�������\n");
		printf("���:");
		scanf("%s", p->no);
		printf("����:");
		scanf("%s", p->name);
		printf("����:");
		scanf("%d", &p->workload);
		p->next = NULL;
		while (head->next != NULL)
			head = head->next;
		head->next = p;
	}
	printf("������Ʒ��Ϣ¼�������\n");
	printf("�����ѡ����Ĳ�����");
}


void output(nod *head)							//�����Ʒ��Ϣ 
{
	int n = 0;
	nod *p;
	p = head->next;
	if (p == NULL)
	{
		printf("��Ʒ��ϢΪ�գ����Ƚ���¼�������\n");
		printf("������Ʒ��Ϣ���������\n");
		printf("�����ѡ����Ĳ�����");
		return;
	}
	while (p != NULL)							//ѭ��һ�α����������ݣ�ʵ�����					
	{
		n++;
		printf("���: %s\t����:%s\t����:%d\n", p->no, p->name,  p->workload);
		p = p->next;
	}
	printf("������Ʒ��Ϣ���������\n");
	printf("�����ѡ����Ĳ�����");
}

void chaxun(nod *head)							//��ѯ��Ʒ�����  
{
	char a[40];
	int i = -1;
	nod *p;
	p = head;
	printf(" ������Ҫ������Ʒ������ :\n");
	scanf("%s", a);
	while (p->next != NULL)						//ѭ�����������αȽ�
	{
		p = p->next;
		if (strcmp(p->name, a) == 0)			//strcmp�����Ƚ��ַ����Ƿ���ͬ
		{
			i = 1;
			printf("���ҵ�����Ʒ�����\n");
			printf("���:%s\t����:%s\t����:%d,\n", p->no, p->name, p->workload);
		}
	}
	if (i<0)
		printf("û�д���Ʒ��\n");
	printf("������Ʒ�������ѯ������\n");
	printf("�����ѡ����Ĳ�����");
}

void xiugai(nod *head)                           //�޸���Ʒ�����
{
	char no[12];
	int i = -1;
	nod *p;
	p = head;
	printf("������Ҫ�޸���Ʒ�������Ʒ�ı�ţ�\n");
	scanf("%s", no);
	while (p->next != NULL)						//ѭ���������ҳ���Ӧ�����Ʒ��Ϣ
	{
		p = p->next;
		if (strcmp(p->no, no) == 0)
		{
			i = 1;
			printf("�������µĵĿ����:");
			scanf("%d", &p->workload);
		}
	}
	if (i<0)
		printf("û�д���Ʒ��Ϣ��\n");
	printf("������Ʒ������޸Ľ�����\n");
	printf("�����ѡ����Ĳ�����");
}

void shanchu(nod *head)                      //ɾ����Ʒ��Ϣ 
{
	char name[40];
	int i = -1;
	nod *p, *h;
	p = head;
	printf("��������Ҫɾ������Ʒ�����ƣ�\n");
	scanf("%s", name);
	while (p->next != NULL)					//ѭ������
	{
		if (strcmp(name, p->next->name) == 0)
		{
			i = 1;
			h = p->next;
			p->next = p->next->next;
			free(h);						//ʹ��free�����ͷŷ���ռ�
			printf("��ɾ������Ʒ��Ϣ��\n");
			break;
		}
		p = p->next;
	}
	if (i<0)
		printf("û�д���Ʒ��Ϣ��\n");
	printf("������Ʒ��Ϣɾ��������\n");
	printf("�����ѡ����Ĳ�����");
}

void paixu(nod *head)				//����Ʒ�������������
{
    nod *p,*q,*t,*s;				//����ڵ������Ϊ�����Ƚ���׼��
	int z = 0,x,n=1;
    t=NULL;
    while((head->next->next) != t)
    {
        p = head;
        q = head->next;
        while(q->next != t)			//����ѭ��ʵ�ֶ����������
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
    printf("��Ʒ�������С����������:\n");
	printf("����\t����\t�����\n");
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
	while(head->next!=NULL)				//�򵥵��������
	{
		head = head->next;
		x = head->workload;
		z = z + x;
	}
	printf("������ƷĿǰ�ܿ����Ϊ��%d\n",z);
	printf("������Ʒ��������������\n");
	printf("�����ѡ����Ĳ�����");
}

int guanli()								//��Ʒ������ϵͳ������
{
	nod *head;
	head = (nod*)malloc(sizeof(struct node));
	head = create();
	menu(head);
	while (1)
	{
		int e;
		scanf("%d", &e);
		switch (e)                             //����ѡ��
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
				printf("��������밴˵���������ѡ�\n");
			break;
		}
	}
}

int main()						//������
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
				printf("������Ʒ����ʹ��˳�����л����ʹ�ã�\n");
				exit(0);
			default:
				printf("��������밴�չ�������ѡ�");
				break;
		}
	}
}