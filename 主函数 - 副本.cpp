#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"data.h"
int main()
{
	Seqlist plist = { 0 };
	Init(&plist);
	Depo_data(&plist);//��� 0,1,2,3,4,5;cursize=6
	print(&plist);
	Insert_data_back(&plist, 100);//β��100��cursize=7
	print(&plist);
	Insert_data_head(&plist, 100);//ͷ��100��cursize=8
	print(&plist);
	Insert_data(&plist, 2, 100);//�м��100��cursize=9
	print(&plist);
	Insert_data(&plist, 2, 100);//�м��100��cursize=10���ﵽ����������
	print(&plist);
	dele_data(&plist, 2);//ɾ���±�Ϊ2�����ݣ�
	print(&plist);
	int tep=seek_data(&plist, 3);//����3���±ꣻ
	printf("�±�Ϊ��%d\n", tep);
	/*Insert_data(&plist);
	print(&plist);
	Insert_data(&plist);
	print(&plist);
	Insert_data(&plist);
	print(&plist);
	Insert_data(&plist);
	print(&plist);
	delete_duplicaate_all(&plist,100);
	print(&plist);*/
	/*Init(&plist);
	Depo_data(&plist);
	print(&plist);
	Insert_data(&plist);
	print(&plist);
	Insert_data_head(&plist);
	print(&plist);
	Insert_data_back(&plist);
	print(&plist);
	seek_data(&plist);
	dele_data(&plist);
	print(&plist);
	change_data(&plist);
	print(&plist);
	destroy_data(&plist);*/
	return 0;
}