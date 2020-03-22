#include"ifndef.h"
#include"manager.h"
#include"ticket.h"
#include"customer.h"
#include"sign_out.h"

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

user *user_head;       //用户名及密码构成的链表的头节点
movie *movie_head;     //影片相关信息用链表连接起来后的头节点 
place *place_head;      //影厅头节点 

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


