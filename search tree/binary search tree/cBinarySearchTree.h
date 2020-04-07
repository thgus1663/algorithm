#include "cNode.h"
#include <iostream>
using namespace std;

template <typename T>
class cBinarySearchTree {
	friend class cNode<T>;
public:
	cBinarySearchTree();
	~cBinarySearchTree();
	void treeInsert(T x);
	void treeDelete(T x);
	void treePrint();
private:


	cNode<T>* treeInsert(cNode<T>* t, T x);

	void treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p);

	cNode<T>* deleteNode(cNode<T>* r);

	void treePrint(cNode<T>* t, int step);
	
	cNode<T>* root;
};


template <typename T>
cBinarySearchTree<T>::cBinarySearchTree()
{
	root = NULL;
}

template <typename T>
cBinarySearchTree<T>::~cBinarySearchTree()
{
	deleteNode(root);
	delete root;
}

template <typename T>
cNode<T>* cBinarySearchTree<T>::treeInsert(cNode<T>* t, T x)
{
	if (t == NULL)
	{
		cNode<T>* r = new cNode<T>;
		r->key = x; r->left = NULL; r->right = NULL;
		return r;
	}
	else if (t->key > x)
	{
		t->left = treeInsert(t->left, x);
	}
	else
	{
		t->right = treeInsert(t->right, x);
	}
	return t;
}

template <typename T>
void cBinarySearchTree<T>::treeInsert(T x) {
	root = treeInsert(root, x);
}


template <typename T>
void cBinarySearchTree<T>::treeDelete(cNode<T>* t, cNode<T>* r, cNode<T>* p)
{
	//r 위치, p위치
	if (p == NULL) root = deleteNode(r);
	else
	{
		if (p->key > r->key) p->left = deleteNode(r);
		else p->right = deleteNode(r);
	}
}

template <typename T>
cNode<T>* cBinarySearchTree<T>::deleteNode(cNode<T>* r)
{
	cNode<T>* temp = new cNode<T>;

	//자식노드0개 
	if ((r->left == NULL) && (r->right == NULL))
	{
		return NULL;
	}

	//자식노드1개 
	else if (r->left == NULL)
	{
		return r->right;
	}

	//자식노드1개
	else if (r->right == NULL)
	{
		return r->left;
	}

	//자식노드2개 
	else
	{
		temp = r->right;

		while (temp->left != NULL) temp = temp->left;

		int minVal = temp->key;
		treeDelete(minVal);
		r->key = minVal;
		return r;
	}
}

template <typename T>
void cBinarySearchTree<T>::treeDelete(T x) {
	cNode<T>* r = root;
	cNode<T>* p = NULL;


	while (r->key != x && r != NULL)
	{
		if (r->key > x)
		{
			p = r;
			r = r->left;
		}
		else
		{
			p = r;
			r = r->right;
		}
	}

	if (r != NULL) treeDelete(root, r, p);
}

template <typename T>
void cBinarySearchTree<T>::treePrint()
{
	//중간 왼 오

	treePrint(root, 0);




}

template <typename T>
void cBinarySearchTree<T>::treePrint(cNode<T>* t, int step)
{
	

	if (t != NULL)
	{
		for (int i = 1; i <= step; i++) cout << " ";
		cout << t->key << endl;

		treePrint(t->left, step + 4);
		treePrint(t->right, step + 4);
	}
	
}
