#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS
#include"data.h"
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define SEQ_INIT_SUZE 10//��ʼ����
#define SEQ_INC_SIZE 2  //
typedef int ElemType;
ElemType* data1 = NULL;
int re_capacity(Seqlist* plist)//����������
{
	assert(plist);
	return plist->capacity;
}
int re_cursize(Seqlist* plist)//�����ִ�Ԫ�ظ�����
{
	assert(plist);
	return plist->cursize;
}
int add_capacity(Seqlist* plist)//�ж��Ƿ����ݣ�
{
	assert(plist);
	if (re_capacity(plist) == re_cursize(plist))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Judge_add_capacity(Seqlist* plist)//�ж��Ƿ����ݣ�
{
	if (add_capacity(plist))
	{
		ElemType* data = (ElemType*)realloc(plist->data, plist->capacity * SEQ_INC_SIZE);
		plist->capacity *= SEQ_INC_SIZE;
		if (NULL == data)
		{
			printf("����ʧ��");
		}
		//free(plist->data);
		//plist->data = data1;
	}
}
void Init(Seqlist* plist)//�ṹ���ʼ����
{
	assert(plist);
	plist->capacity = SEQ_INIT_SUZE;//��ʼ�������ó�10��
	plist->cursize = 0;//���ڻ�û�д������ݣ����Ե�ǰ˳���������Ϊ0��
	plist->data = (ElemType*)malloc(sizeof(ElemType) * plist->capacity);//��̬Ϊ˳����ٿ�������10��int���͵Ŀռ䣬
	if (plist->data == NULL) //�������ʧ�� ,malloc�ͻ᷵��NULL����ָ�룩��                                         
	{                        //���˳���ռ䶼û�п��ٳ���������͸����ò���������ֱ��ʹ��
		exit(-1);            //exit��-1��������������
	}
}
void Depo_data(Seqlist* plist)//˳���������ݣ�
{
	assert(plist);
	for (int i = 0; i < 6; i++)
	{
		plist->data[i] = i;
		plist->cursize++;
	}
}
int Insert_data(Seqlist* plist,int n,int num)//����һ�����ݣ�
{
	//n�����������ݵ�λ�ã�num������Ҫ�������ݵ�λ�ã�
	assert(plist);
	if (n > plist->cursize - 1 || n < 0)
	{//�жϣ����ǲ����λ���ǲ��������ǵ���Ч���ݵķ�Χ���棻
		printf("����λ�ô���\n");//�������������Ǿ���ʾ�������������������
		return 0;
	}
	for (int i = plist->cursize - 1; i >= n; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[n] = num;
	plist->cursize++;
	Judge_add_capacity(plist);
}
void Insert_data_head(Seqlist* plist,int num)//���в��룻
{
	assert(plist);
	for (int i = plist->cursize - 1; i >= 0; i--)
	{
		plist->data[i + 1] = plist->data[i];
	}
	plist->data[0] = num;
	plist->cursize++;
	Judge_add_capacity(plist);
}
void Insert_data_back(Seqlist* plist,int num)//ĩβ���룻
{
	assert(plist);
	plist->data[plist->cursize] = num;
	plist->cursize++;
	Judge_add_capacity(plist);
}
void print(Seqlist* plist)
{
	assert(plist);
	for (int i = 0; i < plist->cursize; i++)
	{
		printf("%d ", plist->data[i]);
	}
	printf("\n");
	printf("�ִ�Ԫ������%d\n", plist->cursize);
	printf("˳���������%d\n", plist->capacity);
}
int dele_data(Seqlist* plist,int pos)//ɾ��ָ����������ݣ�
{
	assert(plist);
	if (pos > plist->cursize || pos < 0)
	{
		printf("ɾ������\n");
		return 0;
	}
	for (int i = pos; i < plist->cursize - 1; i++)
	{
		plist->data[i] = plist->data[i + 1];
	}
	plist->cursize--;
}
int dele_data_data(Seqlist* plist,int val)//ɾ��ָ�����ݣ�
{
	assert(plist);
	if ((seek_data (plist,val))> plist->cursize || (seek_data(plist, val) < 0))
	{
		printf("ɾ������\n");
		return 0;
	}
	for (int i = seek_data(plist, val); i < plist->cursize - 1; i++)
	{
		plist->data[i] = plist->data[i + 1];
	}
	plist->cursize--;
}
int seek_data(Seqlist* plist,int num)//����һ�����ݣ�
{
	assert(plist);
	int i = 0;
	for (i = 0; i <= plist->cursize - 1; i++)
	{
		if (plist->data[i] == num)
		{
			return i;
		}
	}
	return -1;
}
int change_data(Seqlist* plist)//�Ķ�ָ�������ݣ�
{
	assert(plist);
	int pos = 0;
	ElemType num;
	printf("��������Ҫ�޸ĵ����ݵ��±� pos ,�͸Ķ�������� num \n");
	scanf("%d %d", &pos, &num);
	if (pos > plist->cursize || pos < 0)
	{
		printf("�޸Ĵ���\n");
		return 0;
	}
	plist->data[pos] = num;
}
void destroy_data(Seqlist* plist)//����˳���
{
	assert(plist);
	free(plist->data);
	plist->data = NULL;
}
//void delete_duplicaate_all(Seqlist*plist,int val)//����ʾ��������δ֪
//{
//	for (int i = 0; i < plist->cursize; i++)
//	{
//		if (plist->data[i] == val)
//		{
//			dele_data_data(plist, val);
//		}
//	}
//}
//void delete_duplicaate_all(Seqlist* plist, int val)//����ʾ��������δ֪
//{
//	assert(plist);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < plist->cursize; i++)
//	{
//		if (plist->data[i] != val)
//		{
//			plist->data[j++] = plist->data[i];
//		}
//		else
//		{
//			plist->cursize--;
//		}
//	}
//	
//}

void delete_duplicaate_all(Seqlist* plist, int val)
{
	assert(plist);
	int i = 0;
	int j = 0;
	for (i = 0; i < plist->cursize ; i++)
	{
		if (plist->data[i] != val)
		{
			plist->data[j++] = plist->data[i];
		}
	}
	plist->cursize = j;
}
