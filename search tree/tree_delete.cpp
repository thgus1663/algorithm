#include <iostream>

using namespace std;
int cnt = 0;

typedef struct treeRecord
{
	int Data;
	struct treeRecord* Left;
	struct treeRecord* Right;
	struct treeRecord* Parent;
}node;
typedef node* Nptr;

class treeClass
{
public:
	treeClass();
	Nptr treeInsert(Nptr t, int x);
	Nptr GetHead();
	void deleteHead(Nptr t, int x);
	Nptr treeDelete(Nptr t, int x);	
	void Inorder(Nptr t); //중위 
	void Preorder(Nptr t); //전위 
	void Postorder(Nptr t); //후위 
private:
	Nptr Head;
};

treeClass::treeClass()
{
	Head = NULL;
}

Nptr treeClass::GetHead()
{
	return Head;
}

Nptr treeClass::treeInsert(Nptr t, int x)
{
	if (t == NULL)
	{
		Nptr r = new treeRecord;
		r->Data = x; r->Left = NULL; r->Right = NULL;
		t = r;

		if (Head == NULL) {
			t->Parent = NULL;
			Head = t;

		}
		cnt = cnt + 1;
		return r;
	}
	else if (t->Data > x)
	{
		Nptr temp = new treeRecord;
		cnt = cnt + 1;


		temp = treeInsert(t->Left, x);
		temp->Parent = t;
		t->Left = temp;
	}
	else
	{
		Nptr temp = new treeRecord;
		cnt = cnt + 1;

		temp = treeInsert(t->Right, x);
		temp->Parent = t;
		t->Right = temp;
	}
	return t;
}
void treeClass::deleteHead(Nptr t, int x)
{
	Head = treeDelete(t, x);
}

Nptr treeClass::treeDelete(Nptr t, int x)
{

	Nptr temp = new treeRecord;

	if (t == NULL) return NULL;
	else if (x > t->Data) t->Right=treeDelete(t->Right, x);
	else if (x < t->Data) t->Left=treeDelete(t->Left, x);
	else
	{
		//자식노드0개 
		if ((t->Left == NULL) && (t->Right == NULL))
		{
			return NULL;
		}

		//자식노드1개 
		else if (t->Left == NULL)
		{
			return t->Right;
		}

		//자식노드1개
		else if (t->Right == NULL)
		{
			return t->Left;
		}

		//자식노드2개 
		else
		{

			temp = t->Right;			

			while (temp->Left != NULL) temp = temp->Left;

			int minVal = temp->Data;
			treeDelete(Head, minVal);
			t->Data = minVal;

			return t;
		}
	}

	return t;

}


void treeClass::Inorder(Nptr t)
{
	if (t != NULL)
	{
		Inorder(t->Left);
		cout << t->Data << " ";
		Inorder(t->Right);
	}
}

void treeClass::Preorder(Nptr t)
{
	if (t != NULL)
	{
		cout << t->Data << " ";
		Preorder(t->Left);
		Preorder(t->Right);
	}
}

void treeClass::Postorder(Nptr t)
{
	if (t != NULL)
	{

		Postorder(t->Left);
		Postorder(t->Right);
		cout << t->Data << " ";
	}
}

int main(void)
{
	int num;
	cin >> num;

	treeClass TREE;
	int inc;
	for (int i = 0; i < num; i++)
	{
		cin >> inc;
		TREE.treeInsert(TREE.GetHead(), inc);
	}


	int delnum;
	cin >> delnum;

	int *cod = NULL;
	cod = new int[delnum];

	int *del = NULL;
	del = new int[delnum];

	for (int i = 0; i < delnum; i++)
	{
		cin >> cod[i] >> del[i];
	}

	for (int i = 0; i < delnum; i++)
	{
		TREE.deleteHead(TREE.GetHead(), del[i]);
		if (cod[i] == 0) TREE.Preorder(TREE.GetHead());
		else if (cod[i] == 1) TREE.Inorder(TREE.GetHead());
		else TREE.Postorder(TREE.GetHead());
		cout << endl;
	}
}
