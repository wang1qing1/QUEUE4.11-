#pragma once
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define SEQ_INIT_SUZE 10//��ʼ����
#define SEQ_INC_SIZE 2  //
typedef int ElemType;
typedef struct
{
	ElemType* data;
	int capacity;//������
	int cursize;//Ԫ�ظ�����
}Seqlist;
int re_capacity(Seqlist* plist);//����������

int re_cursize(Seqlist* plist);//�����ִ�Ԫ�ظ�����

int add_capacity(Seqlist* plist);//�ж��Ƿ����ݣ�

void Judge_add_capacity(Seqlist* plist);//�ж��Ƿ����ݣ�

void Init(Seqlist* plist);//�ṹ���ʼ����

void Depo_data(Seqlist* plist);//˳���������ݣ�

int Insert_data(Seqlist* plist,int n,int num);//����һ�����ݣ�

void Insert_data_head(Seqlist* plist,int num);//���в��룻

void Insert_data_back(Seqlist* plist,int num);//ĩβ���룻

void print(Seqlist* plist);

int dele_data(Seqlist* plist,int pos);//ɾ��ָ����������ݣ�

int dele_data_data(Seqlist* plist,int val);//ɾ��ָ�����ݣ�

int seek_data(Seqlist* plist,int num);//����һ�����ݣ�

int change_data(Seqlist* plist);//�Ķ�ָ�������ݣ�

void destroy_data(Seqlist* plist);//����˳���

void delete_duplicaate_all(Seqlist* plist,int val);
