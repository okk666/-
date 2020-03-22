#include"ifndef.h"
#include"manager.h"
#include"ticket.h"
#include"customer.h"
#include"sign_out.h"

typedef struct person
{
    char name[10];       //�û��� 
    char password[10];    //���� 
    struct person *next;
}user;
  
typedef struct place
{
	char number[20];  //Ӱ�����
	char name[20];    //Ӱ������
	int row;          //��λ����
	int  line;        //��λ���� 
	struct place *next;
 }place; 
 
typedef struct movie
{
	char name[20];        //��Ӱ���� 
	char number[20];      //��Ӱ��� 
	char director[20];    //��Ӱ���� 
	char star[20];        //��Ӱ���� 
	char language[20];    //��Ӱ���� 
	char type[20];        //��Ӱ���� 
	char start_time[20];  //��ʼʱ�䣬���գ���-��-�գ��ĸ�ʽ���� 
	char dead_time[20];    //�¼�ʱ��
	char day_time[20];    //����Ĳ���ʱ��  
	float price;          //Ʊ�� 
	int sale_ticket;      //��������Ʊ
	int other_ticket;     //ʣ�µ�Ʊ 
	int place_num;        //��������� 
	int time;             //��Ӱʱ�� 
	struct movie *next;	
}movie;

user *user_head;       //�û��������빹�ɵ������ͷ�ڵ�
movie *movie_head;     //ӰƬ�����Ϣ�����������������ͷ�ڵ� 
place *place_head;      //Ӱ��ͷ�ڵ� 

int log_on();         //��¼ϵͳ
void post();           //ע��ϵͳ 
int sign_out();       //�˳�ϵͳ 
void main_menu();      //���˵��� 
void open_user_txt();        //���û�����������ļ��ж��벢���������� 
void open_movie_txt();       //��ӰƬ�����Ϣ�������������� 
void open_place_txt();       //��Ӱ����Ϣ����������� 
int exist(char name[]);       // �ж�ע����û����Ƿ����

void manager_menu();          //����˲˵��� 

void film_menu();      //ӰƬ��ѯ��������Ŀ¼ 
void search_movie();       //����ӰƬ��Ϣ
void change_movie();       //�޸�ӰƬ��Ϣ 
void add_movie();          //����ӰƬ��Ϣ 
void delete_movie();       //ɾ��ӰƬ��Ϣ 
void all_movie();          //����ӰƬ��Ϣ 
void place_menu();      //Ӱ����ѯ��������Ŀ¼ 
void search_place();       //����Ӱ����Ϣ
void change_place();       //�޸�Ӱ����Ϣ 
void add_place();          //����Ӱ����Ϣ 
void delete_place();       //ɾ��Ӱ����Ϣ 
void all_place();          //����Ӱ����Ϣ 
void show_menu();      //�ݳ���ѯ��������Ŀ¼ 
void search_show();       //�ݳ�ӰƬ��Ϣ
void change_show();       //�޸��ݳ�ӰƬ��Ϣ 
void add_show();          //�����ݳ���Ϣ 
void delete_show();       //ɾ���ݳ���Ϣ 
void all_show();          //�����ݳ���Ϣ 


void ticket_seller_menu();  //��ƱԱ�˵���

void show_search();            //�ݳ���ѯ 
void find_number();              //�����ݳ�����/��Ų�ѯ 
void search_date();              //�������ڲ��ݳ� 
void ticket_menu();           //ӰƱ��ز��� 
void search_ticket();            //��Ʊ 
void sale_ticket(int a[30][30]); //��Ʊ 
void return_ticket();            //��Ʊ 
void all_show();              //ȫ���ݳ� 
	 	
	 	
void customer_menu();     //�˿Ͳ˵���

void customer_search_movie_menu();   // �����Լ�ϲ����ӰƬ 
void find_movie_name();                  //���ݵ�Ӱ���Ʋ��� 
void find_movie_time();                  //���ݵ�Ӱʱ����� 
void find_movie_type();                  //���ݵ�Ӱ���Ͳ��� 
void recent_movie();                 //������ӳ 
void customer_search_ticket();       //��Ʊ��Ʊ
void customer_search_ticket();         //��Ʊ 
void customer_sale_ticket(int a[30][30]);//��Ʊ

void open_user_txt()      //���û����������������������� 
{
	FILE *fp;
	fp = fopen("user","r+");
	if(NULL == fp)
    {
        printf("�ļ�������\n");
		exit(1);
    }
    user *p,*q;
    user_head=(user *)malloc(sizeof(user));
	user_head->next =NULL; 
    p=(user *)malloc(sizeof(user));
	p->next =NULL;
	while(fscanf(fp,"%s %s",p->name ,p->password )!=EOF)
	{
		if(user_head->next ==NULL)   user_head->next = p;  //������ҩƷ�������� 
		else  q->next =p;
		q=p;
		p=(user *)malloc(sizeof(user));
		p->next =NULL;
	 }
	 fclose(fp);
}

void open_movie_txt()   //��ӰƬ�����Ϣ�������������� 
{
	FILE *fw;
	fw = fopen("movie","r+");
	if(NULL == fw)
    {
        printf("�ļ�������\n");
		exit(1);
    }
    movie *p,*q;
    movie_head=(movie *)malloc(sizeof(movie));
	movie_head->next =NULL; 
    p=(movie *)malloc(sizeof(movie));
	p->next =NULL;
	while(fscanf(fw,"%s %s %s %s %s %s %s %s %s %f %d %d %d %d",p->name,p->number,p->director,p->star,p->language,p->type,p->start_time,p->dead_time ,p->day_time,&p->price,&p->sale_ticket,&p->other_ticket,&p->place_num,&p->time)!=EOF)
	{
		if(movie_head->next ==NULL)   movie_head->next = p;  //������ҩƷ�������� 
		else  q->next =p;
		q=p;
		p=(movie *)malloc(sizeof(movie));
		p->next =NULL;
	 }
	 fclose(fw);
 }
 
void open_place_txt()      //��Ӱ����Ϣ�������������� 
{
	FILE *fp;
	fp = fopen("place","r+");
	if(NULL == fp)
    {
        printf("�ļ�������\n");
		exit(1);
    }
    place *p,*q;
    place_head=(place *)malloc(sizeof(place));
	place_head->next =NULL; 
    p=(place *)malloc(sizeof(place));
	p->next =NULL;
	while(fscanf(fp,"%s %s %d %d",p->number,p->name,&p->row,&p->line)!=EOF)
	{
		if(place_head->next ==NULL)   place_head->next = p;  //������ҩƷ�������� 
		else  q->next =p;
		q=p;
		p=(place *)malloc(sizeof(place));
		p->next =NULL;
	 }
	 fclose(fp);
}

void main_menu()      //���˵��� 
{
	system("cls\n");
	char n; 
	printf("\n\t\t-----��ӭ����ӰԺ����ϵͳ-----\n\n");
	printf("\t\t***** 1 ��¼          *****\n");		
	printf("\t\t***** 2 ע��          *****\n"); 
	printf("\t\t***** 3 �˳�ϵͳ      *****\n"); 
	do
	{	
		printf("\n\t\t��������Ҫ���еĹ�����ţ�");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{log_on(); break;}
	 		case '2':{ post();  break; }
	 		case '3':{ sign_out();  break;}
	 		default :{ printf("\n\n\t\t������Ĺ�����Ų����ڣ����������룺");}
	 	}
	}while(n<='0'||n>='4');
}


