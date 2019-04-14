// link_list.cpp : �w�q�D���x���ε{�����i�J�I�C
//
#include "stdafx.h" 
#include <iostream>
using namespace std;
typedef struct node { //save structure
	unsigned int row;  //save row
	unsigned int column; //save column
	double data; //�s�ӯx�}���� . save data
	struct node *next; //�s�U�@�Ӹ`�I����m save the next node position
}node, *pnode;
void mattolin(pnode &l,  int r, int c);        /*matric to linked list*/
void printmatric(const pnode &l, int r, int c);    /*print the result matric*/
void destroyList(pnode &l);
void dotProduct(pnode & l3, pnode  &l1, pnode &l2, int row1, int col2);

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
	/*if (l != NULL)  //��linked list���O�Ū��ɭ�
	{
		cout << "Linked list is not NULL" << endl;
		system("pause");
		exit(0);
	}*/
	pnode p; //�O�@�Ӹ`�I�A�û����V�̫�@��
	l = new node; //���ͤ@�ӷs�`�I �o��l  ???
	l->next = NULL; //�̫�@�ӫ��VNull
	p = l; //�Nl assign��p
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

void dotProduct(pnode & l3, pnode  &l1, pnode &l2,int row1,int col2) {
	if (l1 == NULL||l2==NULL)  //��O�Ū��A�N���L�x�}�F
	{
		cout << "Linked list is NULL" << endl;
		system("pause");
		exit(0);
	}
	pnode p;
	p = l1->next;
	
	pnode q;
	q = l2->next;
	
	pnode r; //�O�@�Ӹ`�I�A�û����V�̫�@��
	l3= new node; 
	l3->next = NULL; //�̫�@�ӫ��VNull
	r = l3; //�Nl assign��r

	int a[100][100];
	for (int i = 0;i < 100;i++)//�k�s
	{
		for (int j = 0;j < 100;j++)
		{
			a[i][j] = 0;
		}
	}
	while (p != NULL) { //�u�n�Ĥ@�ӯx�}����NULL .if the first matrix isn't null
		q = l2; //�S���sassign�@��ptrB .assign q again
		int column, row;
		int value = 0;
		while (q != NULL) {
			
			
			if (p->column == q->row) //�p�G��������. if it has Corresponding item
			{  column = q->column;
				row = p->row;
				value = p->data*q->data;
				a[row][column] += value;
			//	cout << value;
			
				/*int has_r = 0;
				while (r != NULL)
				{
					//�p�Gl3�̭��w�g��������������m�A�N�����s�b���̭�
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
				{//�إߤ@�ӷs�`�I�A��Ȧs�il3

					r->next = new node;  //���ͤ@�ӷs�`�I
					r->next->row = row; //��row���Ȧs�i�h
					r->next->column = column; //��col���Ȧs�i�h
					r->next->data = value; //�sdata
					r->next->next = NULL;  //�̫�@�ӫ��Vnull
					r = r->next; //��p�̫ܳ�@��
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
