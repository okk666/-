#include"ifndef.h"
#include"prepare.h"
#include"sign_out.h" 

void ticket_seller_menu();  //售票员菜单栏

void show_search();            //演出查询 
void find_number();              //根据演出名称/编号查询 
void search_date();              //根据日期查演出 
void ticket_menu();           //影票相关操作 
void search_ticket();            //查票 
void sale_ticket(int a[30][30]); //售票 
void return_ticket();            //退票 
void all_show();              //全部演出 
	 		 	
void ticket_seller_menu()     //售票员菜单栏 
{
	char n;
	system("cls\n");
	printf("\n\n\n\n\n\t\t系统管理员端\n\n\n\n\n\n");
	system("pause");
	system("cls\n");
	printf("\n\n\t\t***** 1 演出查询   *****\n");
	printf("\t\t***** 2 票务管理   *****\n");
	printf("\t\t***** 3 演出计划   *****\n");
	printf("\t\t***** 4 退出       *****\n");
	do
	{	
		printf("\n\t\t输入您所要进行的功能序号：");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{ show_search();	break; }
			case '2':{ ticket_menu();  break; }
	 		case '3':{ all_show();   break;}
	 		case '4':{ sign_out();break;} 
	 		default :{ printf("\n\n\t\t您输入的功能序号不存在，请重新输入：");}
	 	}
	}while(n<='0'||n>='5');	
}


void show_search()   //查询演出菜单栏 
{   
	system("pause");
	system("cls");
	char n;
	printf("\n\t\t1.影片编号/名称\n\t\t2.日期\n\t\t3.返回上一菜单");
	do
	{	
		printf("\n\t\t输入您所要进行的功能序号：");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{ find_number();  break;} 
			case '2':{ search_date();  break; }
	 		case '3':{ ticket_seller_menu(); break;}
	 		default :{ printf("\n\n\t\t您输入的功能序号不存在，请重新输入：");}
	 	}
	}while(n<='0'||n>='4');	
}

void find_number()       //按演出编号查找
{ 
	movie *p;
	char a[20]; 
	printf("\n\n\t\t输入所要查找的演出名称/编号");
	scanf("%s",a); 
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name,a)==0) 
		{
			printf("\n\n\t\t名称：%s",p->name );
			printf("\n\t\t编号：%s",p->number );
			printf("\n\t\t开始日期：%s",p->start_time );
			printf("\n\t\t截止日期：%s",p->dead_time );
			printf("\n\t\t具体时间：%s",p->day_time );
			break;		
		}
		p=p->next ;
	}
	system("pause");
	show_search();
 } 
 
void search_date()   //按日期查找 
{
	movie *p;
	char a[20]; 
	printf("\n\n\t\t输入所要查找的演出日期");
	scanf("%s",a); 
	p=movie_head->next ;
	while(p!=NULL)
	{
		if((strcmp(p->start_time , a)<0||strcmp(p->start_time , a)==0)&&(strcmp(p->dead_time , a)>0||strcmp(p->dead_time , a)==0))
		{
			printf("\n\n\t\t名称：%s",p->name );
			printf("\n\t\t编号：%s",p->number );
			printf("\n\t\t开始日期：%s",p->start_time );
			printf("\n\t\t截止日期：%s",p->dead_time );
			printf("\n\t\t具体时间：%s",p->day_time );
			break;		
		}
		p=p->next ;
	}
	system("pause");
	show_search();
}

void ticket_menu()      //票务管理 
{
	system("pause");
	system("cls");
	printf("\n\n\t\t1.查找电影票及买票");
	printf("\n\t\t2.返回上个菜单");
	char n;
	do
	{	
		printf("\n\t\t输入您所要进行的功能序号：");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{ search_ticket();  break;}
	 		case '2':{  ticket_seller_menu(); break;}
	 		default :{ printf("\n\n\t\t您输入的功能序号不存在，请重新输入：");}
	 	}
	}while(n<='0'||n>='3');
}

void search_ticket()     //查票 
{
	int a[30][30];
	int flag=1; 
	char b[20];
	printf("\n\n\t\t输入所要查票的演出厅编号/名称"); 
	scanf("%s",b);
	place *p;
	p=place_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,b)==0||strcmp(p->name ,b)==0)
		{
			flag=0;
			printf("\t\t********************************************************"); 
			printf("\n\t\t放映厅编号：%s\n",p->number );		
			printf("\t\t放映厅名称：%s\n",p->name );
			printf("\t\t0表示可选座位，#表示损坏座位，1表示已售座位");
			printf("\n\t\t\t\t屏幕\n");
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
	else printf("该影厅暂无！！！");
	system("pause");
	system("cls");
	ticket_menu(); 
}

void sale_ticket(int a[30][30])       //售票
{ 
	int b,c; 
	while(1)
	{
		printf("\n\n\t\t输入所选择的座位行数：");
		scanf("%d",&b);
		printf("\n\t\t输入所选择的座位列数:");
		scanf("%d",&c);
		if(a[b][c]==0)
		{
			a[b][c]=1;
			printf("\n\t\t购买成功！");
		}
		printf("\n\n\t\t是否继续购票1(是)/2(不是)：");
		int n;
		scanf("%d",&n);
		if(n==2)	break;
		else {continue;} 
	}
	system("pause");
	system("cls");
	ticket_menu();
}
 
void all_show()      //所有演出 
{
	int flag=1;
	char a[20];
	movie *p;
	p=movie_head->next;
	printf("\n\n\t\t请输入今天的日期(年-月-日):");
	scanf("%s",a);
	while(p!=NULL)
	{
		if((strcmp(p->start_time , a)<0||strcmp(p->start_time , a)==0)&&(strcmp(p->dead_time , a)>0||strcmp(p->dead_time , a)==0))
		{
			flag=0;
			printf("\n\n***********************************************************************************");
			printf("\n\t\t演出名称:%s",p->name);
			printf("\n\t\t演出时间：%s",p->day_time);
			printf("\n\t\t演出开始日期：%s",p->start_time );
			printf("\n\t\t演出结束日期：%s",p->dead_time );
			printf("\n\t\t价格：%.2f",p->price );
			printf("\n***********************************************************************************");
		}
		p=p->next ;
	}
	if(flag)	printf("\n\n\t\t近期没有演出！");
	system("pause");
	system("cls");
	ticket_seller_menu();
}

