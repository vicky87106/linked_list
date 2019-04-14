// link_list.cpp : 定義主控台應用程式的進入點。
//
#include "stdafx.h" 
#include <iostream>
using namespace std;
typedef struct node { //節點 structure
	unsigned int row;  //存row
	unsigned int column; //存column
	double data; //存該矩陣的值
	struct node *next; //存下一個節點的位置
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

	cin >> row1 >> col1;  //讀進row、col
	pnode l1 = NULL, l2 = NULL, l3 = NULL; //一開始節點是空的
		mattolin(l1, row1, col1); //建立l1矩陣
		cin >> row2 >> col2;  //讀進row、col
		mattolin(l2, row2, col2); //建立l2 矩陣
		if (col1 != row2) //當矩陣無法相乘時，就不用計算
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
	
	system("pause");  //讓程式暫停
	destroyList(l1); //清除Linked list
	destroyList(l2);
	destroyList(l3);
	return 0;

}


void mattolin(pnode &l, int r, int c)        /*matric to linked list*/
{
	/*if (l != NULL)  //當linked list不是空的時候
	{
		cout << "Linked list is not NULL" << endl;
		system("pause");
		exit(0);
	}*/
	pnode p; //令一個節點，永遠指向最後一個
	
	l = new node; //產生一個新節點 這個l  ???
	l->next = NULL; //最後一個指向Null
	p = l; //把p的值assign給null
	int value; //存讀進來的值
	for (int i = 0;i < r; i++)
	{
		for (int j = 0;j < c; j++)
		{
			cin >> value; //cin個數就是row*col
			if (value!= 0) //如果不是0的話，產生一個新節點。以row-major排法
			{
				p->next = new node;  //產生一個新節點
				p->next->row = i; //把row的值存進去
				p->next->column = j; //把col的值存進去
				p->next->data = value; //存data
				p->next->next = NULL;  //最後一個指向null
				p = p->next; //讓p變最後一個
			}
		}
	}
	if (l == NULL) //如果Linked list是空的
	{
		cout << "Linked list is NULL" << endl;
		system("pause");
		exit(0);
	}
	
}

void dotProduct(pnode & l3, pnode  &l1, pnode &l2,int i1, int j1,int col1) {
	pnode &initB = l2;
	while (l1 != NULL) { //只要第一個矩陣不為NULL
		l2 = initB; //又重新assign一個ptrB
		int column, row,  value;
		while (l2 != NULL) {
			
			
				if (l1->row == i1&&l2->column == j1) //如果等於現在跑到對應的元素
				{
					for (int i = 0; i < col1;i++)
					{
						if (l1->column == l2->row) //對應項相乘
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
	l->next = NULL; //最後一個指向Null
	x = l;
	x->next = new node;  //產生一個新節點
	x->next->row = row; //把row的值存進去
	x->next->column = column; //把col的值存進去
	x->next->data = value; //存data
	x->next->next = NULL;  //最後一個指向null
	x = x->next; //讓x變最後一個
}



void printmatric(const pnode &l, int r, int c)    /*print the result matric*/
{
	if (l == NULL)  //當是空的，就不印矩陣了
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
			if (p != NULL) //p1不為空的話
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
		cout << endl;  //到一定的col數換行
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
