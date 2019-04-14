// link_list.cpp : �w�q�D���x���ε{�����i�J�I�C
//
#include "stdafx.h" 
#include <iostream>
using namespace std;
typedef struct node { //�`�I structure
	unsigned int row;  //�srow
	unsigned int column; //�scolumn
	double data; //�s�ӯx�}����
	struct node *next; //�s�U�@�Ӹ`�I����m
}node, *pnode;
void mattolin(pnode &l,  int r, int c);        /*matric to linked list*/
void printmatric(const pnode &l, int r, int c);    /*print the result matric*/
void destroyList(pnode &l);
//void Multiplemat(const pnode &l1, const pnode &l2, pnode &l3, int r, int c);
void dotProduct(pnode &l3, pnode  &ptrA, pnode &ptrB,int i, int j, int col1);
void Add(pnode &x, int row, int column, int value);
void Insert(pnode &x, int row, int column, int value);
int main()
{
	int row1, col1, row2, col2;

	cin >> row1 >> col1;  //Ū�irow�Bcol
	pnode l1 = NULL, l2 = NULL, l3 = NULL; //�@�}�l�`�I�O�Ū�
		mattolin(l1, row1, col1); //�إ�l1�x�}
		cin >> row2 >> col2;  //Ū�irow�Bcol
		mattolin(l2, row2, col2); //�إ�l2 �x�}
		if (col1 != row2) //��x�}�L�k�ۭ��ɡA�N���έp��
		{
			cout << "The matrix is not match.";
		}
		else
		{
			while(l1!=NULL)
			{
				for (int i = 0; i < row1;i++)
				{
					for (int j = 0; j < col2; j++)
					{
						dotProduct(l3, l1, l2, i, j, col1);
					}
				}
				
			}
			//Multiplemat(l1, l2, l3, row1, col2);
			printmatric(l3, row1, col2);  /*print the result matric*/
		}  
	
	system("pause");  //���{���Ȱ�
	destroyList(l1); //�M��Linked list
	destroyList(l2);
	destroyList(l3);
	return 0;

}


void mattolin(pnode &l, int r, int c)        /*matric to linked list*/
{
	/*if (l != NULL)  //��linked list���O�Ū��ɭ�
	{
		cout << "Linked list is not NULL" << endl;
		system("pause");
		exit(0);
	}*/
	pnode p; //�O�@�Ӹ`�I�A�û����V�̫�@��
	
	l = new node; //���ͤ@�ӷs�`�I �o��l  ???
	l->next = NULL; //�̫�@�ӫ��VNull
	p = l; //��p����assign��null
	int value; //�sŪ�i�Ӫ���
	for (int i = 0;i < r; i++)
	{
		for (int j = 0;j < c; j++)
		{
			cin >> value; //cin�ӼƴN�Orow*col
			if (value!= 0) //�p�G���O0���ܡA���ͤ@�ӷs�`�I�C�Hrow-major�ƪk
			{
				p->next = new node;  //���ͤ@�ӷs�`�I
				p->next->row = i; //��row���Ȧs�i�h
				p->next->column = j; //��col���Ȧs�i�h
				p->next->data = value; //�sdata
				p->next->next = NULL;  //�̫�@�ӫ��Vnull
				p = p->next; //��p�̫ܳ�@��
			}
		}
	}
	if (l == NULL) //�p�GLinked list�O�Ū�
	{
		cout << "Linked list is NULL" << endl;
		system("pause");
		exit(0);
	}
	
}

void dotProduct(pnode & l3, pnode  &l1, pnode &l2,int i1, int j1,int col1) {
	pnode &initB = l2;
	while (l1 != NULL) { //�u�n�Ĥ@�ӯx�}����NULL
		l2 = initB; //�S���sassign�@��ptrB
		int column, row,  value;
		while (l2 != NULL) {
			
			
				if (l1->row == i1&&l2->column == j1) //�p�G����{�b�]�����������
				{
					for (int i = 0; i < col1;i++)
					{
						if (l1->column == l2->row) //�������ۭ�
						{  column = l2->column;
							row = l1->row;
							value = l1->data*l2->data;
							pnode l4;
							Add(l4, i1 ,j1, value);

						}
					}
				}
				l2 = l2->next;
			
		}
		l1 = l1->next;
	}
	
}

void Add(pnode &x, int row, int column, int value) {
	pnode ptr = x;
	while (ptr != NULL) {
		ptr->row = row;
		ptr->column = column;
		ptr->data += value;
			return;
		}
	pnode &l3 = ptr;
	/* We could not find an existing element with given row and column
	Create a new one */
	Insert(l3, row, column, value);
}

void Insert(pnode &x, int row, int column, int value)
{
	pnode l;
	l = new node; 
	l->next = NULL; //�̫�@�ӫ��VNull
	x = l;
	x->next = new node;  //���ͤ@�ӷs�`�I
	x->next->row = row; //��row���Ȧs�i�h
	x->next->column = column; //��col���Ȧs�i�h
	x->next->data = value; //�sdata
	x->next->next = NULL;  //�̫�@�ӫ��Vnull
	x = x->next; //��x�̫ܳ�@��
}



void printmatric(const pnode &l, int r, int c)    /*print the result matric*/
{
	if (l == NULL)  //��O�Ū��A�N���L�x�}�F
	{
		cout << "Linked list is NULL" << endl;
		system("pause");
		exit(0);
	}
	pnode p;
	p = l->next;
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			if (p != NULL) //p1�����Ū���
			{
				if (p->row == i && p->column == j)
				{
					cout << p->data << ' ';
					p = p->next;
					continue;
				}
			}
			cout << "0" << ' ';
		}
		cout << endl;  //��@�w��col�ƴ���
	}
}

void destroyList(pnode &l)
{
	if (l == NULL)
		return;
	pnode p = l->next;
	while (p)
	{
		l->next = p->next;
		delete p;
		p = l->next;
	}
	delete l;
}
