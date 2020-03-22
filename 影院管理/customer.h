#include"ifndef.h"
#include"prepare.h"
#include"sign_out.h"

void customer_menu();     //顾客菜单栏

void customer_search_movie_menu();   // 查找自己喜欢的影片 
void find_movie_name();                  //根据电影名称查找 
void find_movie_time();                  //根据电影时间查找 
void find_movie_type();                  //根据电影类型查找 
void recent_movie();                 //近期上映 
void customer_search_ticket();       //查票买票
void customer_search_ticket();         //查票 
void customer_sale_ticket(int a[30][30]);//售票

void customer_menu()      //顾客菜单栏
{
	char n;
	system("cls\n");
	printf("\n\n\n\n\n\t\t顾客端\n\n\n\n\n");
	system("pause");
	system("cls\n");
	printf("\n\n\t\t***** 1 查找喜欢看的影片      *****\n");
	printf("\t\t***** 2  近期上映             *****\n");
	printf("\t\t***** 3  查找电影票并买票     *****\n");
	printf("\t\t***** 4  退出系统             *****\n");
	do
	{	
		printf("\n\t\t输入您所要进行的功能序号：");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 	case '1':{ customer_search_movie_menu(); break;}
	 	case '2':{ recent_movie();  break; }
	 	case '3':{  customer_search_ticket(); break;}
	 	case '4':{  sign_out();  break;} 
	 	default :{ printf("\n\n\t\t您输入的功能序号不存在，请重新输入：");}
	 	}
	}while(n<='0'||n>='5');
 } 
void customer_search_movie_menu()   // 查找自己喜欢的影片 
{
	system("pause");
	system("cls");
	char n; 
	printf("\n\n\n\t\t\t1.根据影片名查找");
	printf("\n\n\t\t\t2.根据演出时间查找");
	printf("\n\n\t\t\t3.根据影片类型查找");
	printf("\n\n\t\t\t4.返回上个菜单栏");
	do
	{	
		printf("\n\t\t输入您所要进行的功能序号：");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{ find_movie_name(); break;}
	 		case '2':{ find_movie_time();  break; }
	 		case '3':{ find_movie_type();  break;}
	 		case '4':{ customer_menu(); break;}
	 		default :{ printf("\n\n\t\t您输入的功能序号不存在，请重新输入：");}
	 	}
	}while(n<='0'||n>='5');	
}

void find_movie_name()   //根据片名查找 
{
	int flag=1;
	char a[20];
	printf("请输入您所要查找的影片的名称：");
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
			printf("\n\t\t电影名称：%s\n",p->name);
			printf("\t\t影片编号为：%s\n",p->number);
			printf("\t\t导演：%s\n",p->director );
			printf("\t\t主演：%s\n",p->star );
			printf("\t\t时长：%d\n",p->time );
			printf("\t\t语言：%s\n",p->language );
			printf("\t\t类型：%s\n",p->type );
			printf("\t\t票价：%.2f\n",p->price );
			printf("\t\t上映时间：%s\n",p->start_time );
			printf("\t\t下架时间：%s\n",p->dead_time );	
			printf("*******************************************************************"); 
			break;
		}
		p=p->next ;
	}
	if(flag)	printf("该影片暂无！！！");
	system("pause");
	system("cls");
	customer_search_movie_menu();
 } 
 
 
void find_movie_time()   //根据时间查找
{
	int flag=1;
	movie *p;
	char a[20]; 
	printf("\n\n\t\t输入所要查找的演出日期（年-月-日）：");
	scanf("%s",a); 
	p=movie_head->next ;
	while(p!=NULL)
	{
		if((strcmp(p->start_time , a)<0||strcmp(p->start_time , a)==0)&&(strcmp(p->dead_time , a)>0||strcmp(p->dead_time , a)==0))
		{
			flag=0;
			system("cls\n");
			printf("*******************************************************************"); 
			printf("\n\t\t电影名称：%s\n",p->name);
			printf("\t\t影片编号为：%s\n",p->number);
			printf("\t\t导演：%s\n",p->director );
			printf("\t\t主演：%s\n",p->star );
			printf("\t\t时长：%d\n",p->time );
			printf("\t\t语言：%s\n",p->language );
			printf("\t\t类型：%s\n",p->type );
			printf("\t\t票价：%.2f\n",p->price );
			printf("\t\t上映时间：%s\n",p->start_time );
			printf("\t\t下架时间：%s\n",p->dead_time );	
			printf("*******************************************************************"); 
		break;		
		}
		p=p->next ;
	}
	if(flag)	printf("暂无影片！！！");
	system("pause");
	system("cls");
	customer_search_movie_menu();
 } 
 
void find_movie_type()           //根据类型查找 
{
	int flag=1;
	char a[20];
	printf("请输入您所要查找的影片的类型：");
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
			printf("\n\t\t电影名称：%s\n",p->name);
			printf("\t\t影片编号为：%s\n",p->number);
			printf("\t\t导演：%s\n",p->director );
			printf("\t\t主演：%s\n",p->star );
			printf("\t\t时长：%d\n",p->time );
			printf("\t\t语言：%s\n",p->language );
			printf("\t\t类型：%s\n",p->type );
			printf("\t\t票价：%.2f\n",p->price );	
			printf("\t\t上映时间：%s\n",p->start_time );
			printf("\t\t下架时间：%s\n",p->dead_time );	
			printf("*******************************************************************"); 
			break;
		}
		p=p->next ;
	}
	if(flag)	printf("该影片暂无！！！");
	system("pause");
	system("cls");
	customer_search_movie_menu();
}
void recent_movie()    //近期的电影 
{
	int i=0; 
	movie *p;
	p=movie_head->next;
	while(p!=NULL)
	{
			i++;
		    printf("*******************************************************************"); 
			printf("\n\t\t电影名称：%s\n",p->name);
			printf("\t\t影片编号为：%s\n",p->number);
			printf("\t\t导演：%s\n",p->director );
			printf("\t\t主演：%s\n",p->star );
			printf("\t\t时长：%d\n",p->time );
			printf("\t\t语言：%s\n",p->language );
			printf("\t\t类型：%s\n",p->type );
			printf("\t\t票价：%.2f\n",p->price );
			printf("\t\t上映时间：%s\n",p->start_time );
			printf("\t\t下架时间：%s\n",p->dead_time );	
			printf("*******************************************************************"); 
			printf("\n\n");
			p=p->next ;
			if(i%2==0)
			{
				system("pause");
				system("cls");
			}
	}
	printf("\n\n\n\t\t全部已显示");
	system("pause");
	customer_menu(); 
}

void customer_search_ticket()     //查票 
{
	int a[30][30];
	int flag=1; 
	char b[20];
	printf("\n\n\t\t输入所要查票的演出厅编号/名称："); 
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
		customer_sale_ticket(a);
		}	
	else printf("该影厅暂无！！！");
	system("pause");
	system("cls");
	customer_menu();
}

void customer_sale_ticket(int a[30][30])       //售票
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
	customer_menu();
}
