#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prepare.h"
#include"ifndef.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	open_user_txt();    //将用户名和密码用连边连接起来 
	open_movie_txt();   //将影片相关信息用链表连接起来 
	open_place_txt();   //将影厅相关信息用链表连接 
	main_menu();        //登录或注册页面
	return 0; 
}
