#include<stdio.h>
#include<stdlib.h>
#include<io.h>
#include<string.h>
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

user *user_head;       //�û��������빹�ɵ������ͷ�ڵ�
movie *movie_head;     //ӰƬ�����Ϣ�����������������ͷ�ڵ� 
place *place_head;      //Ӱ��ͷ�ڵ� 

  
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

int log_on()       //��¼ 
{
	open_user_txt();    //���û����������������������� 
	int flag=1,i;
	char a[10],b[20],c;
	user *p;
	system("cls");
	printf("\n\t\t\t��ӭʹ�õ�¼ϵͳ\n");	
	printf("\n\t\t����5���������\n");
	for(i=1;i<=5;i++)
	{
		p=user_head->next ; 
		printf("\n\t\t�������û�����");
		scanf("%s",a);
		printf("\n\t\t���������룺");
		scanf("%s",b);
		while(p!=NULL)
		{
			if(strcmp(p->name,a )==0&&strcmp(p->password ,b)==0)
			{
				flag=0;
				printf("\n\n\t\t��¼�ɹ�\n\n");
				break;
			}
			p=p->next ;
		}
		if(flag)
		printf("\n\n\t\t��¼ʧ�������µ�¼����"); 
		else if(flag==0)	break;
	}
	if(i>=5)
	{
		printf("\n\n\t\t��ε�¼ʧ�ܣ��Զ�תΪע��ҳ��");
		system("pause");
		system("cls");
		post();
		return 0;
	 } 
	 do
	 {
	 	printf("\n\t\t���������(��1λ�������)");
	 	printf("\n\n\t\t����1������ˣ�2������ƱԱ�ˣ�3����˿Ͷˣ�"); 
		fflush(stdin);
		scanf("%c",&c);
		switch(c)
		{
	 		case '1':{ manager_menu();  break;}   
	 		case '2':{ ticket_seller_menu(); break;}
	 		case '3':{ customer_menu();  break;}
	 		default :{
			  			printf("\n\t\t���Ŀ�������������������:");
			         }
	 	}
	}while(c<='0'||c>='4');       
 }

int exist(char name[])  //  �ж�ע����û����Ƿ����
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

void post()      //ע��ϵͳ 
{  
	char name[20],pass[20];
	system("cls");
	printf("\n\t\t��ӭʹ��ע��ϵͳ\n");
	while(1)
	{
		printf("\n\t\t�������û���[������10���ַ�]��");
		scanf("%s",name);
		if(exist(name)==0)
		{
			printf("\n\t\t���û����Ѿ����ڣ�����������");
			continue;
		}
		if(strlen(name)<=10)
		{
			while(1)
			{
				printf("\n\t\t����������[���볤��Ϊ5λ]��");
				scanf("%s",pass);
				if(strlen(pass)==5)
				{
					printf("\n\n\t\tע��ɹ��������û����ǣ�%s��������:%s\n",name,pass);
					break;
				}
				else printf("\n\t\t����������볤��Ϊ%dλ,���������루���볤��λ5λ����\n",strlen(pass));
			}
			break;
		}
		else 
		{
			printf("\n\t\t��������û�����Ϊ%d,���������루������10λ��:\n\n",strlen(name));
		}
	}
	printf("\n\nϵͳ���Զ����û������������ʹ���ߵ��ļ��У�\n");
	FILE *fp;                            //�����û����ǳƺ����뱣�浽�û���Ϣ�ļ��� 
	fp = fopen("user","a+");
	if(NULL == fp)
    {
        printf("�ļ�������\n");
		exit(1);
	}
	fprintf(fp,"\n%s  %s",name,pass);
	fclose(fp);
	system("pause");
	main_menu();
}
 
int sign_out()   //�˳�ϵͳ 
{
	system("pause");
	system("cls\n");
	printf("\n\n\t\tлл��ʹ�ñ�ϵͳ��\n");
	printf("\t\t�ڴ������´�ʹ�ã�\n\n");
	system("pause");
	return 0; 
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

void manager_menu()   //����˲˵��� 
{
	char n;
	system("cls\n");
	printf("\n\n\n\n\n\t\tӰԺ�����\n\n\n\n\n\n");
	system("\n\n\npause");
	system("cls\n");
	printf("\n\n\t\t***** 1 ӰƬ��ѯ����   *****\n");
	printf("\t\t***** 2 Ӱ����ѯ����   *****\n");
	printf("\t\t***** 3 �ݳ���ѯ����   *****\n");
	printf("\t\t***** 4 �˳�       *****\n"); 
	do
	{	
		printf("\n\t\t��������Ҫ���еĹ�����ţ�");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{  film_menu(); break;}
	 		case '2':{  place_menu();break; }
	 		case '3':{  show_menu();break;}
	 		case '4':{  sign_out(); break;}
	 		default :{ printf("\n\n\t\t������Ĺ�����Ų����ڣ����������룺");}
	 	}
	}while(n<='0'||n>='5');
} 


 
 void film_menu()        //ӰƬ��ѯ��������Ŀ¼ 
{
	system("pause");
	system("cls\n");
	char n;
	printf("\n\n\n\tӰƬ��ѯ�����������£�\n\n");
	printf("\t\t***** 1 ����ӰƬ��Ϣ   *****\n");
	printf("\t\t***** 2 �޸�ӰƬ��Ϣ   *****\n");
	printf("\t\t***** 3 ����ӰƬ��Ϣ   *****\n");
	printf("\t\t***** 4 ɾ��ӰƬ��Ϣ   *****\n"); 
	printf("\t\t***** 5 ����ӰƬ��Ϣ   *****\n");
	printf("\t\t***** 6 ������һ�˵���   *****\n");
	do
	{	
		printf("\n\t\t��������Ҫ���еĹ�����ţ�");
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
	 		default :{ printf("\n\n\t\t������Ĺ�����Ų����ڣ����������룺");}
	 	}
	}while(n<='0'||n>='7');
}
 
void search_movie()    // ����ӰƬ��Ϣ
{
	int flag=1;
	char a[20];
	printf("����������Ҫ���ҵ�ӰƬ�ı�Ż����ƣ�");
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
			printf("\n\t\t��Ӱ���ƣ�%s\n",p->name);
			printf("\t\tӰƬ���Ϊ��%s\n",p->number);
			printf("\t\t���ݣ�%s\n",p->director );
			printf("\t\t���ݣ�%s\n",p->star );
			printf("\t\tʱ����%d\n",p->time );
			printf("\t\t���ԣ�%s\n",p->language );
			printf("\t\t���ͣ�%s\n",p->type );
			printf("\t\tƱ�ۣ�%.2f\n",p->price );	
			printf("*******************************************************************"); 
			break;
		}
		p=p->next ;
	}
	if(flag)	printf("��ӰƬ���ޣ�����");
	film_menu(); 
}

void change_movie()   //�޸�ӰƬ��Ϣ 
{
	int flag=1;
	char a[20];
	printf("����������Ҫ�޸ĵ�ӰƬ�ı�Ż����ƣ�");
	scanf("%s",a);
	movie *p;
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0)
		{
			flag=0;
			system("cls\n");
			printf("\n\n\t��ӰƬ��ϢΪ��\n\n");
			printf("*******************************************************************"); 
			printf("\n\t\t��Ӱ���ƣ�%s\n",p->name);
			printf("\t\tӰƬ���Ϊ��%s\n",p->number);
			printf("\t\t���ݣ�%s\n",p->director );
			printf("\t\t���ݣ�%s\n",p->star );
			printf("\t\tʱ����%d\n",p->time );
			printf("\t\t���ԣ�%s\n",p->language );
			printf("\t\t���ͣ�%s\n",p->type );
			printf("\t\tƱ�ۣ�%.2f\n",p->price );	
			printf("*******************************************************************"); 
			printf("\n\n\t����������Ҫ�޸ĵ����ƣ� ");
			scanf("%s",p->name);
			printf("\t\t����������Ҫ�޸ĵ�ӰƬ���Ϊ:");
			scanf("%s",p->number);
			printf("\t\t����������Ҫ�޸ĵ�ӰƬ����:");
			scanf("%s",p->director );
			printf("\t\t����������Ҫ�޸ĵ�ӰƬ���ݣ�");
			scanf("%s",p->star);
			printf("\t\t����������Ҫ�޸ĵ�ʱ����");
			scanf("%d",&p->time);
			printf("\t\t����������Ҫ�޸ĵ�ӰƬ���ԣ�");
			scanf("%s",p->language);
			printf("\t\t����������Ҫ�޸ĵ�ӰƬ����:");
			scanf("%s",p->type);
			printf("\t\t����������Ҫ�޸ĵ�Ʊ��:");
			scanf("%.2f",&p->price);
			printf("\n\n�޸���ɣ�");
			break;	 
		}
		p=p->next ;
	}
	if(flag)	printf("��ӰƬ���ޣ�����");
	film_menu(); 
}

void add_movie()    //����ӰƬ��Ϣ 
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
		printf("\n\n\t\t����������Ҫ���ӵ�ӰƬ���ƣ� ");
		scanf("%s",q->name);
		printf("\t\t����������Ҫ���ӵ�ӰƬ���Ϊ:");
		scanf("%s",q->number);
		printf("\t\t����������Ҫ���ӵ�ӰƬ����:");
		scanf("%s",q->director );
		printf("\t\t����������Ҫ���ӵ�ӰƬ���ݣ�");
		scanf("%s",q->star);
		printf("\t\t����������Ҫ���ӵ�ӰƬ���ԣ�");
		scanf("%s",q->language);
		printf("\t\t����������Ҫ���ӵ�ӰƬ����:");
		scanf("%s",q->type);
		printf("\t\t����������Ҫ���ӵ�ӰƬ�Ŀ���ʱ�䣨��-��-�գ���");
		scanf("%s",q->start_time );
		printf("\t\t����������Ҫ���ӵ�ӰƬ���¼�ʱ�䣨��-��-�գ���");
		scanf("%s",q->dead_time  );
		printf("\t\t����������Ҫ���ӵ�ӰƬ�����ľ���ʱ�䣺");
		scanf("%s",q->day_time );
		printf("\t\t����������Ҫ���ӵ�Ʊ��:");
		scanf("%f",&q->price);
		printf("\t\t����������Ҫ���ӵ�ӰƬ����Ʊ����");
		scanf("%d",&q->sale_ticket );
		printf("\t\t����������Ҫ���ӵ�ӰƬ��ʣ��Ʊ����");
		scanf("%d",&q->other_ticket );
		printf("\t\t����������Ҫ���ӵ�ӰƬ�Ĳ�������ţ� ");
		scanf("%d",&q->place_num ); 
		printf("\t\t����������Ҫ���ӵ�ӰƬ��ʱ����");
		scanf("%d",&q->time);
		printf("\n\n������ɣ�");
		printf("\n\n\t\tϵͳ�Ὣ���ӵ�ӰƬ�Զ�������ӰƬ���ļ���"); 
		FILE *fp;                            //��ӰƬ��Ϣ�������ļ��� 
		fp = fopen("movie","a+");
		if(NULL == fp)
 		{
       		printf("�ļ�������\n");
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

void delete_movie()    //ɾ��ӰƬ��Ϣ 
{
	int flag=1;
	char a[20];
	printf("\n\n\t\t����������Ҫɾ����ӰƬ�ı�Ż����ƣ�");
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
			printf("�ѳɹ�ɾ����");
			break;
		}
		p=q; 
		q=q->next;
	 }
	 if(flag)	printf("\n\n\n\t\t��ӰƬ��ʱ�������ڣ�");
	 film_menu();
 }
  
void all_movie()     //ȫ��ӰƬ 
{
	int i=0;
	movie *p;
	p=movie_head->next;
	while(p!=NULL)
	{
		    printf("*******************************************************************"); 
			printf("\n\t\t��Ӱ���ƣ�%s\n",p->name);
			printf("\t\tӰƬ���Ϊ��%s\n",p->number);
			printf("\t\t���ݣ�%s\n",p->director );
			printf("\t\t���ݣ�%s\n",p->star );
			printf("\t\tʱ����%d\n",p->time );
			printf("\t\t���ԣ�%s\n",p->language );
			printf("\t\t���ͣ�%s\n",p->type );
			printf("\t\tƱ�ۣ�%.2f\n",p->price );	
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
	printf("\n\n\n\t\tȫ������ʾ");
	system("pause");
	film_menu();
} 

void place_menu()    //Ӱ����ѯĿ¼ 
{
	system("pause");
	system("cls\n");
	int n;
	printf("\n\n\n\tӰ����ѯ�����������£�\n\n");
	printf("\t\t***** 1 ����Ӱ����Ϣ   *****\n");
	printf("\t\t***** 2 �޸�Ӱ����Ϣ   *****\n");
	printf("\t\t***** 3 ����Ӱ����Ϣ   *****\n");
	printf("\t\t***** 4 ɾ��Ӱ����Ϣ   *****\n"); 
	printf("\t\t***** 5 ����Ӱ����Ϣ   *****\n");
	printf("\t\t***** 6 ������һ�˵���   *****\n");
	do
	{	
		printf("\n\t\t��������Ҫ���еĹ�����ţ�");
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
	 	default :{ printf("\n\n\t\t������Ĺ�����Ų����ڣ����������룺");}
	 	}
	}while(n<='0'||n>='7');
}
 
void search_place()      //����Ӱ��  
{
	int flag=1;
	char a[20];
	printf("����������Ҫ���ҵ�Ӱ���ı�Ż����ƣ�");
	scanf("%s",a);
	place *p;
	p=place_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0)
		{
			flag=0;
			printf("\t\t********************************************************"); 
			printf("\n\t\t��ӳ����ţ�%s\n",p->number );		
			printf("\t\t��ӳ�����ƣ�%s\n",p->name );
			printf("\t\t0��ʾ������λ��#��ʾ����λ");
			printf("\n\t\t\t\t��Ļ\n");
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
	if(flag)	printf("��Ӱ�����ޣ�����");
	place_menu(); 
}

void change_place()    //�޸�Ӱ����Ϣ
{
	int flag=1;
	char a[20];
	printf("����������Ҫ�޸ĵ�Ӱ���ı�Ż����ƣ�");
	scanf("%s",a);
	place *p;
	p=place_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0)
		{
			flag=0;
			printf("\n\n\t\t����������Ҫ�޸ĵ�Ӱ���ı�ţ�");
			scanf("%s",p->number );
			printf("\n\t\t����������Ҫ�޸ĵ�Ӱ�����ƣ�");
			scanf("%s",p->name );
			printf("\n\t\t����������Ҫ�޸ĵ�������");
			scanf("%d",&p->row );
			printf("\n\t\t����������Ҫ�޸ĵ�Ӱ����������");
			scanf("%d",&p->line );
			printf("\n\n\n\t\t�޸ĺ������Ϊ��");
			printf("\t\t********************************************************"); 
			printf("\n\t\t��ӳ����ţ�%s\n",p->number );		
			printf("\t\t��ӳ�����ƣ�%s\n",p->name );
			printf("\t\t0��ʾ������λ��#��ʾ����λ");
			printf("\n\t\t\t\t��Ļ\n");
			printf("\t\t");
			for(int i=1 ;i<=p->row ;i++)
			{
				for(int j=1;j<=p->line ;j++)
					printf(" 0 ");
				printf("\n\t\t");
			}
			printf("********************************************************"); 
			printf("\n\n\n\t\t\t�޸���ɣ�");
			break;
		}
		p=p->next ;
	} 
	if(flag)	printf("��Ӱ�����ޣ�����");
	place_menu(); 
 } 
 
 
void add_place()      //����Ӱ��
{
	place *p;
	p=place_head->next ;
	while(p!=NULL)
	{
		if(p->next ==NULL)
		{
			printf("\n\n\t\t����������Ҫ���ӵ�Ӱ���ı�ţ�");
			scanf("%s",p->number );
			printf("\n\t\t����������Ҫ���ӵ�Ӱ�����ƣ�");
			scanf("%s",p->name );
			printf("\n\t\t����������Ҫ���ӵ�������");
			scanf("%d",&p->row );
			printf("\n\t\t����������Ҫ���ӵ�Ӱ����������");
			scanf("%d",&p->line );
			printf("\n\n\n\t\t\tϵͳ�Ὣ���ӵ�Ӱ���Զ�������Ӱ�����ļ���"); 
			FILE *fp;                            //��Ӱ����Ϣ�������ļ��� 
			fp = fopen("place","a+");
			if(NULL == fp)
 		   	{
       		 	printf("�ļ�������\n");
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
 
void delete_place()    //ɾ��Ӱ��
{
	int flag=1;
	char a[20];
	printf("\n\n\t\t����������Ҫɾ����Ӱ���ı�Ż����ƣ�");
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
			printf("�ѳɹ�ɾ����");
			break;
		}
		p=q; 
		q=q->next;
	 }
	 if(flag)	printf("\n\n\n\t\t��Ӱ����ʱ�������ڣ�");
	 place_menu(); 
} 
 
void all_place()       //ȫ��Ӱ��
{
	place *p;
	p=place_head->next ;
	while(p!=NULL)
	{
		printf("\t\t********************************************************"); 
			printf("\n\t\t��ӳ����ţ�%s\n",p->number );		
			printf("\t\t��ӳ�����ƣ�%s\n",p->name );
			printf("\t\t0��ʾ������λ��#��ʾ����λ");
			printf("\n\t\t\t\t��Ļ\n");
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
 
void show_menu()    //�ݳ���ѯ 
{
	system("pause");
	system("cls\n");
	char n;
	printf("\n\n\n\tӰ����ѯ�����������£�\n\n");
	printf("\t\t***** 1 �����ݳ���Ϣ   *****\n");
	printf("\t\t***** 2 �޸��ݳ���Ϣ   *****\n");
	printf("\t\t***** 3 �����ݳ���Ϣ   *****\n");
	printf("\t\t***** 4 ɾ���ݳ���Ϣ   *****\n"); 
	printf("\t\t***** 5 ������һ�˵���   *****\n");
	do
	{	
		printf("\n\t\t��������Ҫ���еĹ�����ţ�");
		fflush(stdin);
	 	scanf("%c",&n);
		switch(n)
	 	{
	 		case '1':{  search_show(); break;}
	 		case '2':{  change_show(); break; }
	 		case '3':{  add_show();break;}
	 		case '4':{  delete_show();  break;}
	 		case '5':{  manager_menu();break;}
	 		default :{ printf("\n\n\t\t������Ĺ�����Ų����ڣ����������룺");}
	 	}
	}while(n<='0'||n>='6');
 } 
 
void search_show()     //�ݳ����� 
{
	int flag=1;
	movie *p;
	char a[20]; 
	printf("\n\n\t\t������Ҫ���ҵ��ݳ�����/���");
	scanf("%s",a); 
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0) 
		{
			flag=0;
			printf("\n\n\t\t���ƣ�%s",p->name );
			printf("\n\t\t��ţ�%s",p->number );
			printf("\n\t\t��ʼ���ڣ�%s",p->start_time );
			printf("\n\t\t��ֹ���ڣ�%s",p->dead_time );
			printf("\n\t\t����ʱ�䣺%s",p->day_time );
			break;		
		}
		p=p->next ;
	}
	if(flag)	printf("û���������ݳ���");
	show_menu();
}

void change_show()     //�޸��ݳ� 
{
	int flag=1;
	movie *p;
	char a[20]; 
	printf("\n\n\t\t������Ҫ�޸ĵ��ݳ�����/���");
	scanf("%s",a); 
	p=movie_head->next ;
	while(p!=NULL)
	{
		if(strcmp(p->number,a)==0||strcmp(p->name ,a)==0)
		{
			flag=0;
			printf("\n\n\t\t�����޸ĺ����ƣ�");
			scanf("%s",p->name ); 
			printf("\n\t\t�޸ĺ�ı�ţ�");
			scanf("%s",p->number );
			printf("\n\t\t�޸ĺ�Ŀ�ʼ���ڣ�");
			scanf("%s",p->start_time );
			printf("\n\t\t�޸ĺ�Ľ�ֹ���ڣ�");
			scanf("%s",p->dead_time );
			printf("\n\t\t�޸ĺ�ľ���ʱ�䣺");
			scanf("%s",p->day_time );
			printf("\n\n\n\t\t�޸����"); 
			break;	
		}
		p=p->next ;
	}
	if(flag)	printf("û���������ݳ���");
	show_menu();
}

void  add_show()      //�����ݳ� 
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
			printf("\n\n\t����������Ҫ���ӵ�ӰƬ���ƣ� ");
			scanf("%s",q->name);
			printf("\t\t����������Ҫ���ӵ�ӰƬ���Ϊ:");
			scanf("%s",q->number);
			printf("\t\t����������Ҫ���ӵ�ӰƬ�Ŀ���ʱ�䣨��-��-�գ���");
			scanf("%s",q->start_time );
			printf("\t\t����������Ҫ���ӵ�ӰƬ���¼�ʱ�䣨��-��-�գ���");
			scanf("%s",q->dead_time  );
			printf("\t\t����������Ҫ���ӵ�ӰƬ�����ľ���ʱ�䣺");
			scanf("%s",q->day_time );
			printf("\n\n������ɣ�");
			break;
		}
		p=p->next ;
	 } 
	 show_menu();
}

void delete_show()     //ɾ���ݳ�
{
	int flag=1;
	char a[20];
	printf("\n\n\t\t����������Ҫɾ����ӰƬ�ı�Ż����ƣ�");
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
			printf("�ѳɹ�ɾ����");
			break;
		}
		p=q; 
		q=q->next;
	 }
	 if(flag)	printf("\n\n\n\t\t���ݳ���ʱ�������ڣ�");
	 show_menu();
 } 

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
int main()
{
	open_user_txt();    //���û����������������������� 
	open_movie_txt();   //��ӰƬ�����Ϣ�������������� 
	open_place_txt();   //��Ӱ�������Ϣ���������� 
	main_menu();        //��¼��ע��ҳ��
	return 0; 
}

