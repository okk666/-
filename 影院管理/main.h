#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prepare.h"
#include"ifndef.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	open_user_txt();    //���û����������������������� 
	open_movie_txt();   //��ӰƬ�����Ϣ�������������� 
	open_place_txt();   //��Ӱ�������Ϣ���������� 
	main_menu();        //��¼��ע��ҳ��
	return 0; 
}
