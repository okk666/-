#include"ifndef.h"
#include"prepare.h"
#include"sign_out.h" 

void ticket_seller_menu();  //��ƱԱ�˵���

void show_search();            //�ݳ���ѯ 
void find_number();              //�����ݳ�����/��Ų�ѯ 
void search_date();              //�������ڲ��ݳ� 
void ticket_menu();           //ӰƱ��ز��� 
void search_ticket();            //��Ʊ 
void sale_ticket(int a[30][30]); //��Ʊ 
void return_ticket();            //��Ʊ 
void all_show();              //ȫ���ݳ� 
	 		 	
void ticket_seller_menu()     //��ƱԱ�˵��� 
{
	char n;
	system("cls\n");
	printf("\n\n\n\n\n\t\tϵͳ����Ա��\n\n\n\n\n\n");
	system("pause");
	system("cls\n");
	printf("\n\n\t\t***** 1 �ݳ���ѯ   *****\n");
	printf("\t\t***** 2 Ʊ�����   *****\n");
	printf("\t\t***** 3 �ݳ��ƻ�   *****\n");
	printf("\t\t***** 4 �˳�       *****\n");
	do
	{	
		printf("\n\t\t��������Ҫ���еĹ�����ţ�");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{ show_search();	break; }
			case '2':{ ticket_menu();  break; }
	 		case '3':{ all_show();   break;}
	 		case '4':{ sign_out();break;} 
	 		default :{ printf("\n\n\t\t������Ĺ�����Ų����ڣ����������룺");}
	 	}
	}while(n<='0'||n>='5');	
}


void show_search()   //��ѯ�ݳ��˵��� 
{   
	system("pause");
	system("cls");
	char n;
	printf("\n\t\t1.ӰƬ���/����\n\t\t2.����\n\t\t3.������һ�˵�");
	do
	{	
		printf("\n\t\t��������Ҫ���еĹ�����ţ�");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{ find_number();  break;} 
			case '2':{ search_date();  break; }
	 		case '3':{ ticket_seller_menu(); break;}
	 		default :{ printf("\n\n\t\t������Ĺ�����Ų����ڣ����������룺");}
	 	}
	}while(n<='0'||n>='4');	
}

void find_number()       //���ݳ���Ų���
{ 
	movie *p;
	char a[20]; 
	printf("\n\n\t\t������Ҫ���ҵ��ݳ�����/���");
	scanf("%s",a); 
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name,a)==0) 
		{
			printf("\n\n\t\t���ƣ�%s",p->name );
			printf("\n\t\t��ţ�%s",p->number );
			printf("\n\t\t��ʼ���ڣ�%s",p->start_time );
			printf("\n\t\t��ֹ���ڣ�%s",p->dead_time );
			printf("\n\t\t����ʱ�䣺%s",p->day_time );
			break;		
		}
		p=p->next ;
	}
	system("pause");
	show_search();
 } 
 
void search_date()   //�����ڲ��� 
{
	movie *p;
	char a[20]; 
	printf("\n\n\t\t������Ҫ���ҵ��ݳ�����");
	scanf("%s",a); 
	p=movie_head->next ;
	while(p!=NULL)
	{
		if((strcmp(p->start_time , a)<0||strcmp(p->start_time , a)==0)&&(strcmp(p->dead_time , a)>0||strcmp(p->dead_time , a)==0))
		{
			printf("\n\n\t\t���ƣ�%s",p->name );
			printf("\n\t\t��ţ�%s",p->number );
			printf("\n\t\t��ʼ���ڣ�%s",p->start_time );
			printf("\n\t\t��ֹ���ڣ�%s",p->dead_time );
			printf("\n\t\t����ʱ�䣺%s",p->day_time );
			break;		
		}
		p=p->next ;
	}
	system("pause");
	show_search();
}

void ticket_menu()      //Ʊ����� 
{
	system("pause");
	system("cls");
	printf("\n\n\t\t1.���ҵ�ӰƱ����Ʊ");
	printf("\n\t\t2.�����ϸ��˵�");
	char n;
	do
	{	
		printf("\n\t\t��������Ҫ���еĹ�����ţ�");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{ search_ticket();  break;}
	 		case '2':{  ticket_seller_menu(); break;}
	 		default :{ printf("\n\n\t\t������Ĺ�����Ų����ڣ����������룺");}
	 	}
	}while(n<='0'||n>='3');
}

void search_ticket()     //��Ʊ 
{
	int a[30][30];
	int flag=1; 
	char b[20];
	printf("\n\n\t\t������Ҫ��Ʊ���ݳ������/����"); 
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
		sale_ticket(a);
		}	
	else printf("��Ӱ�����ޣ�����");
	system("pause");
	system("cls");
	ticket_menu(); 
}

void sale_ticket(int a[30][30])       //��Ʊ
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
	ticket_menu();
}
 
void all_show()      //�����ݳ� 
{
	int flag=1;
	char a[20];
	movie *p;
	p=movie_head->next;
	printf("\n\n\t\t��������������(��-��-��):");
	scanf("%s",a);
	while(p!=NULL)
	{
		if((strcmp(p->start_time , a)<0||strcmp(p->start_time , a)==0)&&(strcmp(p->dead_time , a)>0||strcmp(p->dead_time , a)==0))
		{
			flag=0;
			printf("\n\n***********************************************************************************");
			printf("\n\t\t�ݳ�����:%s",p->name);
			printf("\n\t\t�ݳ�ʱ�䣺%s",p->day_time);
			printf("\n\t\t�ݳ���ʼ���ڣ�%s",p->start_time );
			printf("\n\t\t�ݳ��������ڣ�%s",p->dead_time );
			printf("\n\t\t�۸�%.2f",p->price );
			printf("\n***********************************************************************************");
		}
		p=p->next ;
	}
	if(flag)	printf("\n\n\t\t����û���ݳ���");
	system("pause");
	system("cls");
	ticket_seller_menu();
}

