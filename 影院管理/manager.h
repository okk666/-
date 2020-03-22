#include"ifndef.h"
#include"prepare.h"
#include"sign_out.h"

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
