// link_list.cpp : 定義主控台應用程式的進入點。
//
#include "stdafx.h" 
#include <iostream>
using namespace std;
typedef struct node { //save structure
	unsigned int row;  //save row
	unsigned int column; //save column
	double data; //存該矩陣的值 . save data
	struct node *next; //存下一個節點的位置 save the next node position
}node, *pnode;
void mattolin(pnode &l,  int r, int c);        /*matric to linked list*/
void printmatric(const pnode &l, int r, int c);    /*print the result matric*/
void destroyList(pnode &l);
void dotProduct(pnode & l3, pnode  &l1, pnode &l2, int row1, int col2);

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
			//while(l1!=NULL)
			//{			
						dotProduct(l3, l1, l2, row1,col2);		
			//}
			
			//printmatric(l3, row1, col2);  /*print the result matric*/
		}  
	
	system("pause");  
	destroyList(l1); //destroy Linked list
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
	p = l; //將l assign給p
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

void dotProduct(pnode & l3, pnode  &l1, pnode &l2,int row1,int col2) {
	if (l1 == NULL||l2==NULL)  //當是空的，就不印矩陣了
	{
		cout << "Linked list is NULL" << endl;
		system("pause");
		exit(0);
	}
	pnode p;
	p = l1->next;
	
	pnode q;
	q = l2->next;
	
	pnode r; //令一個節點，永遠指向最後一個
	l3= new node; 
	l3->next = NULL; //最後一個指向Null
	r = l3; //將l assign給r

	int a[100][100];
	for (int i = 0;i < 100;i++)//歸零
	{
		for (int j = 0;j < 100;j++)
		{
			a[i][j] = 0;
		}
	}
	while (p != NULL) { //只要第一個矩陣不為NULL .if the first matrix isn't null
		q = l2; //又重新assign一個ptrB .assign q again
		int column, row;
		int value = 0;
		while (q != NULL) {
			
			
			if (p->column == q->row) //如果有對應項. if it has Corresponding item
			{  column = q->column;
				row = p->row;
				value = p->data*q->data;
				a[row][column] += value;
			//	cout << value;
			
				/*int has_r = 0;
				while (r != NULL)
				{
					//如果l3裡面已經有對應的元素位置，就直接存在那裡面
					//if it the element has already in a linked list, then save the value there
					if (r->row == row&&r->column == column)
					{
						r->data += value;
						has_r = 1;
						break;
					}
					r = r->next;
				}
				if (has_r == 0)
					//if the element hasn't in the linked list, then create a new node in l3
				{//建立一個新節點，把值存進l3

					r->next = new node;  //產生一個新節點
					r->next->row = row; //把row的值存進去
					r->next->column = column; //把col的值存進去
					r->next->data = value; //存data
					r->next->next = NULL;  //最後一個指向null
					r = r->next; //讓p變最後一個
				}*/
			}
				
				
				q = q->next;
			
		}
		p = p->next;
	}//end while

	for (int i = 0;i < row1;i++)
	{
		for (int j = 0;j < col2;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
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
