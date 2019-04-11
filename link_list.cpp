// link_list.cpp : ﹚竡北莱ノ祘Α秈翴
//
#include "stdafx.h" 
#include <iostream>
using namespace std;
typedef struct node {
	unsigned int row;
	unsigned int column;
	double data;
	struct node *next;
}node, *pnode;
void mattolin(pnode &l,  int r, int c);        /*matric to linked list*/
//void printmatric(const pnode &l, int r, int c);    /*print the result matric*/


int main()
{
	int row1, col1, row2, col2;

	/*ifstream inFile("infile", ios::in);
	if (!inFile) {
		cerr << "Failed opening" << endl;
		exit(1);
	}*/

	cin >> row1 >> col1;  //弄秈rowcol
	pnode l1 = NULL, l2 = NULL, l3 = NULL;
	for (int j = 0; j < col1*row1; j++) //弄秈场痻皚
	{
		mattolin(l1, row1, col1);
		
	}
	//printmatric(l1, row1, col1);   /*print the result matric*/
	
	system("pause");
	return 0;

}
/*typedef struct node {
	unsigned int row;
	unsigned int column;
	double data;
	struct node *next;
}node, *pnode;*/

void mattolin(pnode &l, int r, int c)        /*matric to linked list*/
{
	if (l != NULL)  //讽linked listぃ琌
	{
		cout << "Linked list is not NULL" << endl;
		system("pause");
		exit(0);
	}
	pnode p; //程
	int i, j;
	l = new node; //玻ネ穝竊翴
	l->next = NULL; //程Null
	p = l;
	int value;
	for (i = 0;i < r; i++)
	{
		for (j = 0;j < c; j++)
		{
			cin >> value; //cin计碞琌row*col
			if (value!= 0.0) //狦ぃ琌0杠玻ネ穝竊翴row-major逼猭
			{
				p->next = new node;  //玻ネ穝竊翴
				p->next->row = i; //рrow秈
				p->next->column = j; //рcol秈
				p->next->data = value; //data
				p->next->next = NULL;  //程null
				p = p->next; //琵p跑程
			}
		}
	}
	if (l == NULL) //狦Linked list琌
	{
		cout << "Linked list is NULL" << endl;
		system("pause");
		exit(0);
	}
	//int i, j;
	//pnode p;
	pnode p1 = l->next; //程竊翴
	for (int i = 0;i < r;i++)
	{
		for (int j = 0;j < c;j++)
		{
			if (p1 != NULL) //p1ぃ杠
			{
				if (p1->row == i && p1->column == j)
				{
					cout << p1->data << ' ';
					p1 = p1->next;
					continue;
				}
			}
			cout << "0" << ' ';
		}
		cout << endl;  //﹚col计传︽
	}
}

/*void Add2mat(const pnode &l1, const pnode &l2, pnode &l3)*/  /*add the two matrices to linked list 3*/
/*{
	if (l1 == NULL || l2 == NULL || l3 != NULL)
	{
		exit(0);
	}
	int i, j;
	pnode p, q, t;
	l3 = new node;
	l3->next = NULL;
	t = l3;
	p = l1->next;
	q = l2->next;
	for (i = 0;i < N;i++)
	{
		for (j = 0;j < N;j++)
		{
			if (p != NULL && q != NULL)
			{
				if (p && q && p->row == i && p->column == j && q->row == i && q->column == j)
				{
					t->next = new node;
					t->next->next = NULL;
					t->next->row = i;
					t->next->column = j;
					t->next->data = p->data + q->data;
					t = t->next;
					p = p->next;
					q = q->next;
				}
				if (p && q && (p->row != i || p->column != j) && (q->row == i && q->column == j))
				{
					t->next = new node;
					t->next->next = NULL;
					t->next->row = i;
					t->next->column = j;
					t->next->data = q->data;
					t = t->next;
					q = q->next;
				}
				if (p && q && (p->row == i && p->column == j) && (q->row != i || q->column != j))
				{
					t->next = new node;
					t->next->next = NULL;
					t->next->row = i;
					t->next->column = j;
					t->next->data = p->data;
					t = t->next;
					p = p->next;
				}
			}
			else if (p != NULL)
			{
				if (p->row == i && p->column == j)
				{
					t->next = new node;
					t->next->next = NULL;
					t->next->row = i;
					t->next->column = j;
					t->next->data = p->data;
					t = t->next;
					p = p->next;
				}
			}
			else if (q != NULL)
			{
				if (q->row == i && q->column == j)
				{
					t->next = new node;
					t->next->next = NULL;
					t->next->row = i;
					t->next->column = j;
					t->next->data = q->data;
					t = t->next;
					q = q->next;
				}
			}
		}
	}
}*/

//void printmatric(const pnode &l, int r, int c)    /*print the result matric*/
//{
//	if (l == NULL) //狦Linked list琌
/*	{
		cout << "Linked list is NULL" << endl;
		system("pause");
		exit(0);
	}
	int i, j;
	pnode p;*/
	/*p = l->next; *///程竊翴
	/*for (i = 0;i < r;i++)
	{
		for (j = 0;j < c;j++)
		{
			if (p != NULL)
			{
				if (p->row == i && p->column == j)
				{
					cout << p->data << ' ';
					p = p->next;
					continue;
				}
			}
			cout << "0.0" << ' ';
		}
		cout << endl;
	}
}*/

/*void destroyList(pnode &l)
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
}*/
/*
void main()
{
	double matric1[N][N] = { { 2.1,0.0,0.0,6.3,3.5 },
	{ 2.1,0.0,0.0,6.3,3.5 },
	{ 2.1,0.0,0.0,6.3,3.5 },
	{ 2.1,0.0,0.0,6.3,3.5 },
	{ 2.1,0.0,0.0,6.3,3.5 } };
	double matric2[N][N] = { { 0.0,5.4,0.0,1.6,2.9 },
	{ 0.0,5.4,0.0,1.6,2.9 },
	{ 0.0,5.4,0.0,1.6,2.9 },
	{ 0.0,5.4,0.0,1.6,2.9 },
	{ 0.0,5.4,0.0,1.6,2.9 } };
	pnode l1 = NULL, l2 = NULL, l3 = NULL;
	mattolin(l1, matric1);
	mattolin(l2, matric2);
	Add2mat(l1, l2, l3);
	printmatric(l3);
	system("pause");
	destroyList(l1);
	destroyList(l2);
	destroyList(l3);
}*/
