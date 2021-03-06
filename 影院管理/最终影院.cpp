#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>
typedef struct person
{
    char name[10];       //用户名 
    char password[10];    //密码 
    struct person *next;
}user;
  
typedef struct place
{
	char number[20];  //影厅编号
	char name[20];    //影厅名称
	int row;          //座位行数
	int  line;        //座位列数 
	struct place *next;
 }place; 
 
typedef struct movie
{
	char name[20];        //电影名称 
	char number[20];      //电影编号 
	char director[20];    //电影导演 
	char star[20];        //电影主演 
	char language[20];    //电影语言 
	char type[20];        //电影类型 
	char start_time[20];  //开始时间，按照（年-月-日）的格式输入 
	char dead_time[20];    //下架时间
	char day_time[20];    //具体的播放时间  
	float price;          //票价 
	int sale_ticket;      //已卖出的票
	int other_ticket;     //剩下的票 
	int place_num;        //播放厅编号 
	int time;             //电影时长 
	struct movie *next;	
}movie;

int log_on();         //登录系统
void post();           //注册系统 
int sign_out();       //退出系统 
void main_menu();      //主菜单栏 
void open_user_txt();        //将用户名和密码从文件中读入并用链表连接 
void open_movie_txt();       //将影片相关信息用链表连接起来 
void open_place_txt();       //将影厅信息用链表存起来 
int exist(char name[]);       // 判断注册的用户名是否存在

void manager_menu();          //经理端菜单栏 

void film_menu();      //影片查询管理详情目录 
void search_movie();       //查找影片信息
void change_movie();       //修改影片信息 
void add_movie();          //增加影片信息 
void delete_movie();       //删除影片信息 
void all_movie();          //所有影片信息 
void place_menu();      //影厅查询管理详情目录 
void search_place();       //查找影厅信息
void change_place();       //修改影厅信息 
void add_place();          //增加影厅信息 
void delete_place();       //删除影厅信息 
void all_place();          //所有影厅信息 
void show_menu();      //演出查询管理详情目录 
void search_show();       //演出影片信息
void change_show();       //修改演出影片信息 
void add_show();          //增加演出信息 
void delete_show();       //删除演出信息 
void all_show();          //所有演出信息 


void ticket_seller_menu();  //售票员菜单栏

void show_search();            //演出查询 
void find_number();              //根据演出名称/编号查询 
void search_date();              //根据日期查演出 
void ticket_menu();           //影票相关操作 
void search_ticket();            //查票 
void sale_ticket(int a[30][30]); //售票 
void return_ticket();            //退票 
void all_show();              //全部演出 
	 	
	 	
void customer_menu();     //顾客菜单栏

void customer_search_movie_menu();   // 查找自己喜欢的影片 
void find_movie_name();                  //根据电影名称查找 
void find_movie_time();                  //根据电影时间查找 
void find_movie_type();                  //根据电影类型查找 
void recent_movie();                 //近期上映 
void customer_search_ticket();       //查票买票
void customer_search_ticket();         //查票 
void customer_sale_ticket(int a[30][30]);//售票

user *user_head;       //用户名及密码构成的链表的头节点
movie *movie_head;     //影片相关信息用链表连接起来后的头节点 
place *place_head;      //影厅头节点 

  
void open_user_txt()      //将用户名及密码用链表连接起来 
{
	FILE *fp;
	fp = fopen("user","r+");
	if(NULL == fp)
    {
        printf("文件不存在\n");
		exit(1);
    }
    user *p,*q;
    user_head=(user *)malloc(sizeof(user));
	user_head->next =NULL; 
    p=(user *)malloc(sizeof(user));
	p->next =NULL;
	while(fscanf(fp,"%s %s",p->name ,p->password )!=EOF)
	{
		if(user_head->next ==NULL)   user_head->next = p;  //用链表将药品连接起来 
		else  q->next =p;
		q=p;
		p=(user *)malloc(sizeof(user));
		p->next =NULL;
	 }
	 fclose(fp);
}

void open_movie_txt()   //将影片相关信息用链表连接起来 
{
	FILE *fw;
	fw = fopen("movie","r+");
	if(NULL == fw)
    {
        printf("文件不存在\n");
		exit(1);
    }
    movie *p,*q;
    movie_head=(movie *)malloc(sizeof(movie));
	movie_head->next =NULL; 
    p=(movie *)malloc(sizeof(movie));
	p->next =NULL;
	while(fscanf(fw,"%s %s %s %s %s %s %s %s %s %f %d %d %d %d",p->name,p->number,p->director,p->star,p->language,p->type,p->start_time,p->dead_time ,p->day_time,&p->price,&p->sale_ticket,&p->other_ticket,&p->place_num,&p->time)!=EOF)
	{
		if(movie_head->next ==NULL)   movie_head->next = p;  //用链表将药品连接起来 
		else  q->next =p;
		q=p;
		p=(movie *)malloc(sizeof(movie));
		p->next =NULL;
	 }
	 fclose(fw);
 }
 
void open_place_txt()      //将影厅信息用链表连接起来 
{
	FILE *fp;
	fp = fopen("place","r+");
	if(NULL == fp)
    {
        printf("文件不存在\n");
		exit(1);
    }
    place *p,*q;
    place_head=(place *)malloc(sizeof(place));
	place_head->next =NULL; 
    p=(place *)malloc(sizeof(place));
	p->next =NULL;
	while(fscanf(fp,"%s %s %d %d",p->number,p->name,&p->row,&p->line)!=EOF)
	{
		if(place_head->next ==NULL)   place_head->next = p;  //用链表将药品连接起来 
		else  q->next =p;
		q=p;
		p=(place *)malloc(sizeof(place));
		p->next =NULL;
	 }
	 fclose(fp);
}

int log_on()       //登录 
{
	open_user_txt();    //将用户名和密码用连边连接起来 
	int flag=1,i;
	char a[10],b[20],c;
	user *p;
	system("cls");
	printf("\n\t\t\t欢迎使用登录系统\n");	
	printf("\n\t\t您有5次输入机会\n");
	for(i=1;i<=5;i++)
	{
		p=user_head->next ; 
		printf("\n\t\t请输入用户名：");
		scanf("%s",a);
		printf("\n\t\t请输入密码：");
		scanf("%s",b);
		while(p!=NULL)
		{
			if(strcmp(p->name,a )==0&&strcmp(p->password ,b)==0)
			{
				flag=0;
				printf("\n\n\t\t登录成功\n\n");
				break;
			}
			p=p->next ;
		}
		if(flag)
		printf("\n\n\t\t登录失败请重新登录！！"); 
		else if(flag==0)	break;
	}
	if(i>=5)
	{
		printf("\n\n\t\t多次登录失败，自动转为注册页面");
		system("pause");
		system("cls");
		post();
		return 0;
	 } 
	 do
	 {
	 	printf("\n\t\t请输入口令(由1位数字组成)");
	 	printf("\n\n\t\t数字1代表经理端，2代表售票员端，3代表顾客端："); 
		fflush(stdin);
		scanf("%c",&c);
		switch(c)
		{
	 		case '1':{ manager_menu();  break;}   
	 		case '2':{ ticket_seller_menu(); break;}
	 		case '3':{ customer_menu();  break;}
	 		default :{
			  			printf("\n\t\t您的口令错误，请重新输入口令:");
			         }
	 	}
	}while(c<='0'||c>='4');       
 }

int exist(char name[])  //  判断注册的用户名是否存在
{
	user *p;            
	p=user_head; 
	while(p!=NULL)
	{
		if(strcmp(p->name ,name)==0)
		{
			return 0;		
		}
		p=p->next ;
	 }
	 return 1; 
}

void post()      //注册系统 
{  
	char name[20],pass[20];
	system("cls");
	printf("\n\t\t欢迎使用注册系统\n");
	while(1)
	{
		printf("\n\t\t请输入用户名[不超过10个字符]：");
		scanf("%s",name);
		if(exist(name)==0)
		{
			printf("\n\t\t该用户名已经存在，请重新输入");
			continue;
		}
		if(strlen(name)<=10)
		{
			while(1)
			{
				printf("\n\t\t请输入密码[密码长度为5位]：");
				scanf("%s",pass);
				if(strlen(pass)==5)
				{
					printf("\n\n\t\t注册成功，您的用户名是：%s，密码是:%s\n",name,pass);
					break;
				}
				else printf("\n\t\t您输入的密码长度为%d位,请重新输入（密码长度位5位）：\n",strlen(pass));
			}
			break;
		}
		else 
		{
			printf("\n\t\t您输入的用户长度为%d,请重新输入（不超过10位）:\n\n",strlen(name));
		}
	}
	printf("\n\n系统会自动将用户名和密码存入使用者的文件中！\n");
	FILE *fp;                            //将新用户的昵称和密码保存到用户信息文件中 
	fp = fopen("user","a+");
	if(NULL == fp)
    {
        printf("文件不存在\n");
		exit(1);
	}
	fprintf(fp,"\n%s  %s",name,pass);
	fclose(fp);
	system("pause");
	main_menu();
}
 
int sign_out()   //退出系统 
{
	system("pause");
	system("cls\n");
	printf("\n\n\t\t谢谢您使用本系统！\n");
	printf("\t\t期待您的下次使用！\n\n");
	system("pause");
	return 0; 
}

void main_menu()      //主菜单栏 
{
	system("cls\n");
	char n; 
	printf("\n\t\t-----欢迎来到影院管理系统-----\n\n");
	printf("\t\t***** 1 登录          *****\n");		
	printf("\t\t***** 2 注册          *****\n"); 
	printf("\t\t***** 3 退出系统      *****\n"); 
	do
	{	
		printf("\n\t\t输入您所要进行的功能序号：");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{log_on(); break;}
	 		case '2':{ post();  break; }
	 		case '3':{ sign_out();  break;}
	 		default :{ printf("\n\n\t\t您输入的功能序号不存在，请重新输入：");}
	 	}
	}while(n<='0'||n>='4');
}

void manager_menu()   //经理端菜单栏 
{
	char n;
	system("cls\n");
	printf("\n\n\n\n\n\t\t影院经理端\n\n\n\n\n\n");
	system("\n\n\npause");
	system("cls\n");
	printf("\n\n\t\t***** 1 影片查询管理   *****\n");
	printf("\t\t***** 2 影厅查询管理   *****\n");
	printf("\t\t***** 3 演出查询管理   *****\n");
	printf("\t\t***** 4 退出       *****\n"); 
	do
	{	
		printf("\n\t\t输入您所要进行的功能序号：");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{  film_menu(); break;}
	 		case '2':{  place_menu();break; }
	 		case '3':{  show_menu();break;}
	 		case '4':{  sign_out(); break;}
	 		default :{ printf("\n\n\t\t您输入的功能序号不存在，请重新输入：");}
	 	}
	}while(n<='0'||n>='5');
} 


 
 void film_menu()        //影片查询管理详情目录 
{
	system("pause");
	system("cls\n");
	char n;
	printf("\n\n\n\t影片查询管理详情如下：\n\n");
	printf("\t\t***** 1 查找影片信息   *****\n");
	printf("\t\t***** 2 修改影片信息   *****\n");
	printf("\t\t***** 3 增加影片信息   *****\n");
	printf("\t\t***** 4 删除影片信息   *****\n"); 
	printf("\t\t***** 5 所有影片信息   *****\n");
	printf("\t\t***** 6 返回上一菜单栏   *****\n");
	do
	{	
		printf("\n\t\t输入您所要进行的功能序号：");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{	
		 	case '1':{  search_movie(); break;}
	 		case '2':{  change_movie(); break; }
	 		case '3':{  add_movie();break;}
	 		case '4':{  delete_movie();  break;}
	 		case '5':{  all_movie();	break;}
	 		case '6':{  manager_menu();break;}
	 		default :{ printf("\n\n\t\t您输入的功能序号不存在，请重新输入：");}
	 	}
	}while(n<='0'||n>='7');
}
 
void search_movie()    // 查找影片信息
{
	int flag=1;
	char a[20];
	printf("请输入您所要查找的影片的编号或名称：");
	scanf("%s",a);
	movie *p;
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0)
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
			printf("*******************************************************************"); 
			break;
		}
		p=p->next ;
	}
	if(flag)	printf("该影片暂无！！！");
	film_menu(); 
}

void change_movie()   //修改影片信息 
{
	int flag=1;
	char a[20];
	printf("请输入您所要修改的影片的编号或名称：");
	scanf("%s",a);
	movie *p;
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0)
		{
			flag=0;
			system("cls\n");
			printf("\n\n\t该影片信息为：\n\n");
			printf("*******************************************************************"); 
			printf("\n\t\t电影名称：%s\n",p->name);
			printf("\t\t影片编号为：%s\n",p->number);
			printf("\t\t导演：%s\n",p->director );
			printf("\t\t主演：%s\n",p->star );
			printf("\t\t时长：%d\n",p->time );
			printf("\t\t语言：%s\n",p->language );
			printf("\t\t类型：%s\n",p->type );
			printf("\t\t票价：%.2f\n",p->price );	
			printf("*******************************************************************"); 
			printf("\n\n\t请输入您所要修改的名称： ");
			scanf("%s",p->name);
			printf("\t\t请输入您所要修改的影片编号为:");
			scanf("%s",p->number);
			printf("\t\t请输入您所要修改的影片导演:");
			scanf("%s",p->director );
			printf("\t\t请输入您所要修改的影片主演：");
			scanf("%s",p->star);
			printf("\t\t请输入您所要修改的时长：");
			scanf("%d",&p->time);
			printf("\t\t请输入您所要修改的影片语言：");
			scanf("%s",p->language);
			printf("\t\t请输入您所要修改的影片类型:");
			scanf("%s",p->type);
			printf("\t\t请输入您所要修改的票价:");
			scanf("%.2f",&p->price);
			printf("\n\n修改完成！");
			break;	 
		}
		p=p->next ;
	}
	if(flag)	printf("该影片暂无！！！");
	film_menu(); 
}

void add_movie()    //增加影片信息 
{
	movie *p;
	p=movie_head->next ;
	while(1)
	{	
		movie *q;
    	q=(movie *)malloc(sizeof(movie));
		q->next =NULL;
		if(p==NULL)
		{
			movie_head->next=q;
		}
		while(p!=NULL)
		{
			if(p->next ==NULL)
			{	
				p->next =q;
				break;
			}
			p=p->next ;
		}
		printf("\n\n\t\t请输入您所要增加的影片名称： ");
		scanf("%s",q->name);
		printf("\t\t请输入您所要增加的影片编号为:");
		scanf("%s",q->number);
		printf("\t\t请输入您所要增加的影片导演:");
		scanf("%s",q->director );
		printf("\t\t请输入您所要增加的影片主演：");
		scanf("%s",q->star);
		printf("\t\t请输入您所要增加的影片语言：");
		scanf("%s",q->language);
		printf("\t\t请输入您所要增加的影片类型:");
		scanf("%s",q->type);
		printf("\t\t请输入您所要增加的影片的开播时间（年-月-日）：");
		scanf("%s",q->start_time );
		printf("\t\t请输入您所要增加的影片的下架时间（年-月-日）：");
		scanf("%s",q->dead_time  );
		printf("\t\t请输入您所要增加的影片开播的具体时间：");
		scanf("%s",q->day_time );
		printf("\t\t请输入您所要增加的票价:");
		scanf("%f",&q->price);
		printf("\t\t请输入您所要增加的影片的售票数：");
		scanf("%d",&q->sale_ticket );
		printf("\t\t请输入您所要增加的影片所剩的票数：");
		scanf("%d",&q->other_ticket );
		printf("\t\t请输入您所要增加的影片的播放厅编号： ");
		scanf("%d",&q->place_num ); 
		printf("\t\t请输入您所要增加的影片的时长：");
		scanf("%d",&q->time);
		printf("\n\n增加完成！");
		printf("\n\n\t\t系统会将增加的影片自动保存至影片的文件中"); 
		FILE *fp;                            //将影片信息保存至文件中 
		fp = fopen("movie","a+");
		if(NULL == fp)
 		{
       		printf("文件不存在\n");
			exit(1);
		}
		fprintf(fp,"\n%s   %s   %s   %s   %s   %s   %s   %s   %s   %f   %d   %d   %d   %d",q->name,q->number,q->director,q->star,q->language,q->type,q->start_time,q->dead_time ,q->day_time,q->price,q->sale_ticket,q->other_ticket,q->place_num,q->time);
		fclose(fp);
		break;
	 } 
	 printf("\n\n\n");
	 system("pause"); 
	 film_menu();
}

void delete_movie()    //删除影片信息 
{
	int flag=1;
	char a[20];
	printf("\n\n\t\t请输入您所要删除的影片的编号或名称：");
	scanf("%s",a);
	movie *p,*q;
	p=movie_head;
	q=movie_head->next ;
	while(q!=NULL)
	{
		if(strcmp(q->number,a)==0||strcmp(q->name ,a)==0)
		{
			flag=0;
			p->next =q->next ;
			free(q);
			printf("已成功删除！");
			break;
		}
		p=q; 
		q=q->next;
	 }
	 if(flag)	printf("\n\n\n\t\t该影片暂时并不存在！");
	 film_menu();
 }
  
void all_movie()     //全部影片 
{
	int i=0;
	movie *p;
	p=movie_head->next;
	while(p!=NULL)
	{
		    printf("*******************************************************************"); 
			printf("\n\t\t电影名称：%s\n",p->name);
			printf("\t\t影片编号为：%s\n",p->number);
			printf("\t\t导演：%s\n",p->director );
			printf("\t\t主演：%s\n",p->star );
			printf("\t\t时长：%d\n",p->time );
			printf("\t\t语言：%s\n",p->language );
			printf("\t\t类型：%s\n",p->type );
			printf("\t\t票价：%.2f\n",p->price );	
			printf("*******************************************************************"); 
			printf("\n\n");
			p=p->next ;
			i++;
			if(i%2==0)
			{
				system("pause");
				system("cls");
			}
	}
	printf("\n\n\n\t\t全部已显示");
	system("pause");
	film_menu();
} 

void place_menu()    //影厅查询目录 
{
	system("pause");
	system("cls\n");
	int n;
	printf("\n\n\n\t影厅查询管理详情如下：\n\n");
	printf("\t\t***** 1 查找影厅信息   *****\n");
	printf("\t\t***** 2 修改影厅信息   *****\n");
	printf("\t\t***** 3 增加影厅信息   *****\n");
	printf("\t\t***** 4 删除影厅信息   *****\n"); 
	printf("\t\t***** 5 所有影厅信息   *****\n");
	printf("\t\t***** 6 返回上一菜单栏   *****\n");
	do
	{	
		printf("\n\t\t输入您所要进行的功能序号：");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 	case '1':{  search_place(); break;}
	 	case '2':{  change_place(); break; }
	 	case '3':{  add_place();break;}
	 	case '4':{  delete_place();  break;}
	 	case '5':{  all_place();	break;}
	 	case '6':{  manager_menu();break;}
	 	default :{ printf("\n\n\t\t您输入的功能序号不存在，请重新输入：");}
	 	}
	}while(n<='0'||n>='7');
}
 
void search_place()      //查找影厅  
{
	int flag=1;
	char a[20];
	printf("请输入您所要查找的影厅的编号或名称：");
	scanf("%s",a);
	place *p;
	p=place_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0)
		{
			flag=0;
			printf("\t\t********************************************************"); 
			printf("\n\t\t放映厅编号：%s\n",p->number );		
			printf("\t\t放映厅名称：%s\n",p->name );
			printf("\t\t0表示可用座位，#表示损坏座位");
			printf("\n\t\t\t\t屏幕\n");
			printf("\t\t");
			for(int i=1 ;i<=p->row ;i++)
			{
				for(int j=1;j<=p->line ;j++)
					printf(" 0 ");
				printf("\n\t\t");
			}
			printf("********************************************************"); 
			break;
		}
		p=p->next ;
	}
	if(flag)	printf("该影厅暂无！！！");
	place_menu(); 
}

void change_place()    //修改影厅信息
{
	int flag=1;
	char a[20];
	printf("请输入您所要修改的影厅的编号或名称：");
	scanf("%s",a);
	place *p;
	p=place_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0)
		{
			flag=0;
			printf("\n\n\t\t请输入您所要修改的影厅的编号：");
			scanf("%s",p->number );
			printf("\n\t\t请输入您所要修改的影厅名称：");
			scanf("%s",p->name );
			printf("\n\t\t请输入您所要修改的行数：");
			scanf("%d",&p->row );
			printf("\n\t\t请输入您所要修改的影厅的列数：");
			scanf("%d",&p->line );
			printf("\n\n\n\t\t修改后的样子为：");
			printf("\t\t********************************************************"); 
			printf("\n\t\t放映厅编号：%s\n",p->number );		
			printf("\t\t放映厅名称：%s\n",p->name );
			printf("\t\t0表示可用座位，#表示损坏座位");
			printf("\n\t\t\t\t屏幕\n");
			printf("\t\t");
			for(int i=1 ;i<=p->row ;i++)
			{
				for(int j=1;j<=p->line ;j++)
					printf(" 0 ");
				printf("\n\t\t");
			}
			printf("********************************************************"); 
			printf("\n\n\n\t\t\t修改完成！");
			break;
		}
		p=p->next ;
	} 
	if(flag)	printf("该影厅暂无！！！");
	place_menu(); 
 } 
 
 
void add_place()      //增加影厅
{
	place *p;
	p=place_head->next ;
	while(p!=NULL)
	{
		if(p->next ==NULL)
		{
			printf("\n\n\t\t请输入您所要增加的影厅的编号：");
			scanf("%s",p->number );
			printf("\n\t\t请输入您所要增加的影厅名称：");
			scanf("%s",p->name );
			printf("\n\t\t请输入您所要增加的行数：");
			scanf("%d",&p->row );
			printf("\n\t\t请输入您所要增加的影厅的列数：");
			scanf("%d",&p->line );
			printf("\n\n\n\t\t\t系统会将增加的影厅自动保存至影厅的文件中"); 
			FILE *fp;                            //将影厅信息保存至文件中 
			fp = fopen("place","a+");
			if(NULL == fp)
 		   	{
       		 	printf("文件不存在\n");
				exit(1);
			}
			fprintf(fp,"\n%s %s %d %d",p->number,p->name,p->row,p->line );
			fclose(fp); 
			break;
		}
		p=p->next ; 
	} 
	place_menu(); 
 } 
 
void delete_place()    //删除影厅
{
	int flag=1;
	char a[20];
	printf("\n\n\t\t请输入您所要删除的影厅的编号或名称：");
	scanf("%s",a);
	place *p,*q;
	p=place_head;
	q=place_head->next ;
	while(q!=NULL)
	{
		if(strcmp(q->number,a)==0||strcmp(q->name ,a)==0)
		{
			flag=0;
			p->next =q->next ;
			free(q);
			printf("已成功删除！");
			break;
		}
		p=q; 
		q=q->next;
	 }
	 if(flag)	printf("\n\n\n\t\t该影厅暂时并不存在！");
	 place_menu(); 
} 
 
void all_place()       //全部影厅
{
	place *p;
	p=place_head->next ;
	while(p!=NULL)
	{
		printf("\t\t********************************************************"); 
			printf("\n\t\t放映厅编号：%s\n",p->number );		
			printf("\t\t放映厅名称：%s\n",p->name );
			printf("\t\t0表示可用座位，#表示损坏座位");
			printf("\n\t\t\t\t屏幕\n");
			printf("\t\t");
			for(int i=1 ;i<=p->row ;i++)
			{
				for(int j=1;j<=p->line ;j++)
					printf(" 0 ");
				printf("\n\t\t");
			}
			printf("********************************************************"); 
		printf("\n\n\n\n");
		p=p->next ;
		system("pause");
		system("cls");
	 }
	  place_menu();
 } 
 
void show_menu()    //演出查询 
{
	system("pause");
	system("cls\n");
	char n;
	printf("\n\n\n\t影厅查询管理详情如下：\n\n");
	printf("\t\t***** 1 查找演出信息   *****\n");
	printf("\t\t***** 2 修改演出信息   *****\n");
	printf("\t\t***** 3 增加演出信息   *****\n");
	printf("\t\t***** 4 删除演出信息   *****\n"); 
	printf("\t\t***** 5 返回上一菜单栏   *****\n");
	do
	{	
		printf("\n\t\t输入您所要进行的功能序号：");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{  search_show(); break;}
	 		case '2':{  change_show(); break; }
	 		case '3':{  add_show();break;}
	 		case '4':{  delete_show();  break;}
	 		case '5':{  manager_menu();break;}
	 		default :{ printf("\n\n\t\t您输入的功能序号不存在，请重新输入：");}
	 	}
	}while(n<='0'||n>='6');
 } 
 
void search_show()     //演出查找 
{
	int flag=1;
	movie *p;
	char a[20]; 
	printf("\n\n\t\t输入所要查找的演出名称/编号");
	scanf("%s",a); 
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0) 
		{
			flag=0;
			printf("\n\n\t\t名称：%s",p->name );
			printf("\n\t\t编号：%s",p->number );
			printf("\n\t\t开始日期：%s",p->start_time );
			printf("\n\t\t截止日期：%s",p->dead_time );
			printf("\n\t\t具体时间：%s",p->day_time );
			break;		
		}
		p=p->next ;
	}
	if(flag)	printf("没有这样的演出！");
	show_menu();
}

void change_show()     //修改演出 
{
	int flag=1;
	movie *p;
	char a[20]; 
	printf("\n\n\t\t输入所要修改的演出名称/编号");
	scanf("%s",a); 
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0)
		{
			flag=0;
			printf("\n\n\t\t输入修改后名称：");
			scanf("%s",p->name ); 
			printf("\n\t\t修改后的编号：");
			scanf("%s",p->number );
			printf("\n\t\t修改后的开始日期：");
			scanf("%s",p->start_time );
			printf("\n\t\t修改后的截止日期：");
			scanf("%s",p->dead_time );
			printf("\n\t\t修改后的具体时间：");
			scanf("%s",p->day_time );
			printf("\n\n\n\t\t修改完成"); 
			break;	
		}
		p=p->next ;
	}
	if(flag)	printf("没有这样的演出！");
	show_menu();
}

void  add_show()      //增加演出 
{
	movie *p;
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(p->next ==NULL)
		{
			movie *q;
    		q=(movie *)malloc(sizeof(movie));
			q->next =NULL;
			p->next =q;
			printf("\n\n\t请输入您所要增加的影片名称： ");
			scanf("%s",q->name);
			printf("\t\t请输入您所要增加的影片编号为:");
			scanf("%s",q->number);
			printf("\t\t请输入您所要增加的影片的开播时间（年-月-日）：");
			scanf("%s",q->start_time );
			printf("\t\t请输入您所要增加的影片的下架时间（年-月-日）：");
			scanf("%s",q->dead_time  );
			printf("\t\t请输入您所要增加的影片开播的具体时间：");
			scanf("%s",q->day_time );
			printf("\n\n增加完成！");
			break;
		}
		p=p->next ;
	 } 
	 show_menu();
}

void delete_show()     //删除演出
{
	int flag=1;
	char a[20];
	printf("\n\n\t\t请输入您所要删除的影片的编号或名称：");
	scanf("%s",a);
	movie *p,*q;
	p=movie_head;
	q=movie_head->next ;
	while(q!=NULL)
	{
		if(strcmp(q->number,a)==0||strcmp(q->name ,a)==0)
		{
			flag=0;
			p->next =q->next ;
			free(q);
			printf("已成功删除！");
			break;
		}
		p=q; 
		q=q->next;
	 }
	 if(flag)	printf("\n\n\n\t\t该演出暂时并不存在！");
	 show_menu();
 } 

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
int main()
{
	open_user_txt();    //将用户名和密码用连边连接起来 
	open_movie_txt();   //将影片相关信息用链表连接起来 
	open_place_txt();   //将影厅相关信息用链表连接 
	main_menu();        //登录或注册页面
	return 0; 
}

