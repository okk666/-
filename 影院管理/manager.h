#include"ifndef.h"
#include"prepare.h"
#include"sign_out.h"

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
