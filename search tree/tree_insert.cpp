#include <iostream>

using namespace std;
int cnt = 0;

typedef struct treeRecord
{
	int Data;
	struct treeRecord* Left;
	struct treeRecord* Right;
}node;
typedef node* Nptr;

class treeClass
{
public:
	treeClass();
	Nptr treeInsert(Nptr t, int x);
	Nptr GetHead();
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
			Head = t;
		}	
		cnt = cnt + 1;
		return r;
	}
	else if (t->Data > x)
	{
		cnt = cnt + 1;
		t->Left=treeInsert(t->Left, x);	
	}
	else
	{
		cnt = cnt + 1;
		t->Right = treeInsert(t->Right, x);	
	}
	return t;
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
	cout << cnt << endl;
}

