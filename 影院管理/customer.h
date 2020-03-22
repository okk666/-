#include"ifndef.h"
#include"prepare.h"
#include"sign_out.h"

void customer_menu();     //�˿Ͳ˵���

void customer_search_movie_menu();   // �����Լ�ϲ����ӰƬ 
void find_movie_name();                  //���ݵ�Ӱ���Ʋ��� 
void find_movie_time();                  //���ݵ�Ӱʱ����� 
void find_movie_type();                  //���ݵ�Ӱ���Ͳ��� 
void recent_movie();                 //������ӳ 
void customer_search_ticket();       //��Ʊ��Ʊ
void customer_search_ticket();         //��Ʊ 
void customer_sale_ticket(int a[30][30]);//��Ʊ

void customer_menu()      //�˿Ͳ˵���
{
	char n;
	system("cls\n");
	printf("\n\n\n\n\n\t\t�˿Ͷ�\n\n\n\n\n");
	system("pause");
	system("cls\n");
	printf("\n\n\t\t***** 1 ����ϲ������ӰƬ      *****\n");
	printf("\t\t***** 2  ������ӳ             *****\n");
	printf("\t\t***** 3  ���ҵ�ӰƱ����Ʊ     *****\n");
	printf("\t\t***** 4  �˳�ϵͳ             *****\n");
	do
	{	
		printf("\n\t\t��������Ҫ���еĹ�����ţ�");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 	case '1':{ customer_search_movie_menu(); break;}
	 	case '2':{ recent_movie();  break; }
	 	case '3':{  customer_search_ticket(); break;}
	 	case '4':{  sign_out();  break;} 
	 	default :{ printf("\n\n\t\t������Ĺ�����Ų����ڣ����������룺");}
	 	}
	}while(n<='0'||n>='5');
 } 
void customer_search_movie_menu()   // �����Լ�ϲ����ӰƬ 
{
	system("pause");
	system("cls");
	char n; 
	printf("\n\n\n\t\t\t1.����ӰƬ������");
	printf("\n\n\t\t\t2.�����ݳ�ʱ�����");
	printf("\n\n\t\t\t3.����ӰƬ���Ͳ���");
	printf("\n\n\t\t\t4.�����ϸ��˵���");
	do
	{	
		printf("\n\t\t��������Ҫ���еĹ�����ţ�");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{ find_movie_name(); break;}
	 		case '2':{ find_movie_time();  break; }
	 		case '3':{ find_movie_type();  break;}
	 		case '4':{ customer_menu(); break;}
	 		default :{ printf("\n\n\t\t������Ĺ�����Ų����ڣ����������룺");}
	 	}
	}while(n<='0'||n>='5');	
}

void find_movie_name()   //����Ƭ������ 
{
	int flag=1;
	char a[20];
	printf("����������Ҫ���ҵ�ӰƬ�����ƣ�");
	scanf("%s",a);
	movie *p;
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->name ,a)==0)
		{
			flag=0;
			system("cls\n");
			printf("*******************************************************************"); 
			printf("\n\t\t��Ӱ���ƣ�%s\n",p->name);
			printf("\t\tӰƬ���Ϊ��%s\n",p->number);
			printf("\t\t���ݣ�%s\n",p->director );
			printf("\t\t���ݣ�%s\n",p->star );
			printf("\t\tʱ����%d\n",p->time );
			printf("\t\t���ԣ�%s\n",p->language );
			printf("\t\t���ͣ�%s\n",p->type );
			printf("\t\tƱ�ۣ�%.2f\n",p->price );
			printf("\t\t��ӳʱ�䣺%s\n",p->start_time );
			printf("\t\t�¼�ʱ�䣺%s\n",p->dead_time );	
			printf("*******************************************************************"); 
			break;
		}
		p=p->next ;
	}
	if(flag)	printf("��ӰƬ���ޣ�����");
	system("pause");
	system("cls");
	customer_search_movie_menu();
 } 
 
 
void find_movie_time()   //����ʱ�����
{
	int flag=1;
	movie *p;
	char a[20]; 
	printf("\n\n\t\t������Ҫ���ҵ��ݳ����ڣ���-��-�գ���");
	scanf("%s",a); 
	p=movie_head->next ;
	while(p!=NULL)
	{
		if((strcmp(p->start_time , a)<0||strcmp(p->start_time , a)==0)&&(strcmp(p->dead_time , a)>0||strcmp(p->dead_time , a)==0))
		{
			flag=0;
			system("cls\n");
			printf("*******************************************************************"); 
			printf("\n\t\t��Ӱ���ƣ�%s\n",p->name);
			printf("\t\tӰƬ���Ϊ��%s\n",p->number);
			printf("\t\t���ݣ�%s\n",p->director );
			printf("\t\t���ݣ�%s\n",p->star );
			printf("\t\tʱ����%d\n",p->time );
			printf("\t\t���ԣ�%s\n",p->language );
			printf("\t\t���ͣ�%s\n",p->type );
			printf("\t\tƱ�ۣ�%.2f\n",p->price );
			printf("\t\t��ӳʱ�䣺%s\n",p->start_time );
			printf("\t\t�¼�ʱ�䣺%s\n",p->dead_time );	
			printf("*******************************************************************"); 
		break;		
		}
		p=p->next ;
	}
	if(flag)	printf("����ӰƬ������");
	system("pause");
	system("cls");
	customer_search_movie_menu();
 } 
 
void find_movie_type()           //�������Ͳ��� 
{
	int flag=1;
	char a[20];
	printf("����������Ҫ���ҵ�ӰƬ�����ͣ�");
	scanf("%s",a);
	movie *p;
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->type ,a)==0)
		{
			flag=0;
			system("cls\n");
			printf("*******************************************************************"); 
			printf("\n\t\t��Ӱ���ƣ�%s\n",p->name);
			printf("\t\tӰƬ���Ϊ��%s\n",p->number);
			printf("\t\t���ݣ�%s\n",p->director );
			printf("\t\t���ݣ�%s\n",p->star );
			printf("\t\tʱ����%d\n",p->time );
			printf("\t\t���ԣ�%s\n",p->language );
			printf("\t\t���ͣ�%s\n",p->type );
			printf("\t\tƱ�ۣ�%.2f\n",p->price );	
			printf("\t\t��ӳʱ�䣺%s\n",p->start_time );
			printf("\t\t�¼�ʱ�䣺%s\n",p->dead_time );	
			printf("*******************************************************************"); 
			break;
		}
		p=p->next ;
	}
	if(flag)	printf("��ӰƬ���ޣ�����");
	system("pause");
	system("cls");
	customer_search_movie_menu();
}
void recent_movie()    //���ڵĵ�Ӱ 
{
	int i=0; 
	movie *p;
	p=movie_head->next;
	while(p!=NULL)
	{
			i++;
		    printf("*******************************************************************"); 
			printf("\n\t\t��Ӱ���ƣ�%s\n",p->name);
			printf("\t\tӰƬ���Ϊ��%s\n",p->number);
			printf("\t\t���ݣ�%s\n",p->director );
			printf("\t\t���ݣ�%s\n",p->star );
			printf("\t\tʱ����%d\n",p->time );
			printf("\t\t���ԣ�%s\n",p->language );
			printf("\t\t���ͣ�%s\n",p->type );
			printf("\t\tƱ�ۣ�%.2f\n",p->price );
			printf("\t\t��ӳʱ�䣺%s\n",p->start_time );
			printf("\t\t�¼�ʱ�䣺%s\n",p->dead_time );	
			printf("*******************************************************************"); 
			printf("\n\n");
			p=p->next ;
			if(i%2==0)
			{
				system("pause");
				system("cls");
			}
	}
	printf("\n\n\n\t\tȫ������ʾ");
	system("pause");
	customer_menu(); 
}

void customer_search_ticket()     //��Ʊ 
{
	int a[30][30];
	int flag=1; 
	char b[20];
	printf("\n\n\t\t������Ҫ��Ʊ���ݳ������/���ƣ�"); 
	scanf("%s",b);
	place *p;
	p=place_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,b)==0||strcmp(p->name ,b)==0)
		{
			flag=0;
			printf("\t\t********************************************************"); 
			printf("\n\t\t��ӳ����ţ�%s\n",p->number );		
			printf("\t\t��ӳ�����ƣ�%s\n",p->name );
			printf("\t\t0��ʾ��ѡ��λ��#��ʾ����λ��1��ʾ������λ");
			printf("\n\t\t\t\t��Ļ\n");
			printf("\t\t");
			for(int i=1 ;i<=p->row ;i++)
			{
				for(int j=1;j<=p->line ;j++)
					{
						printf(" 0 ");
						a[i][j]=0;
					}
				printf("\n\t\t");
			}
			printf("********************************************************"); 
			break;
		}
		p=p->next ;
	}
	if(flag==0)
	{
		customer_sale_ticket(a);
		}	
	else printf("��Ӱ�����ޣ�����");
	system("pause");
	system("cls");
	customer_menu();
}

void customer_sale_ticket(int a[30][30])       //��Ʊ
{ 
	int b,c; 
	while(1)
	{
		printf("\n\n\t\t������ѡ�����λ������");
		scanf("%d",&b);
		printf("\n\t\t������ѡ�����λ����:");
		scanf("%d",&c);
		if(a[b][c]==0)
		{
			a[b][c]=1;
			printf("\n\t\t����ɹ���");
		}
		printf("\n\n\t\t�Ƿ������Ʊ1(��)/2(����)��");
		int n;
		scanf("%d",&n);
		if(n==2)	break;
		else {continue;} 
	}
	system("pause");
	system("cls");
	customer_menu();
}
