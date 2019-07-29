#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

//����������Ľڵ�ṹ
template <typename T>
struct BSNode
{
	BSNode(T t)
	: value(t), lchild(nullptr), rchild(nullptr){}
	
	BSNode() = default;

	T value;
	BSNode<T>* lchild;
	BSNode<T>* rchild;
	BSNode<T>* parent;
};

//�����������
template <typename T>
class BSTree
{
public:
	BSTree();
	~BSTree();

	void preOrder();	//ǰ�����������
	void inOrder();		//�������������
	void postOrder();	//�������������
	//void layerOrder();	//��α���������

	BSNode<T>* search_recursion(T key);		//�ݹ�ؽ��в���
	BSNode<T>* search_Iterator(T key);		//�����ؽ��в���

	T search_minimun(); //������СԪ��
	T search_maximum(); //�������Ԫ��

	BSNode<T>* successor  (BSNode<T>* x);	//����ָ���ڵ�ĺ�̽ڵ�
	BSNode<T>* predecessor(BSNode<T>* x);	//����ָ���ڵ��ǰ���ڵ�

	void insert(T key);	//����ָ��ֵ�ڵ�
	void remove(T key);	//ɾ��ָ��ֵ�ڵ�
	void destory();		//���ٶ�����
	void print();		//��ӡ������


private:
	BSNode<T>* root; //���ڵ�
private:
	BSNode<T>* search(BSNode<T>* & p, T key); 
	void remove(BSNode<T>*  p, T key);		  
	void preOrder(BSNode<T>* p);
	void inOrder(BSNode<T>* p);
	void postOrder(BSNode<T>* p);
	T search_minimun(BSNode<T>* p); 
	T search_maximum(BSNode<T>* p); 
	void destory(BSNode<T>* &p);		
	
};

/*Ĭ�Ϲ��캯��*/
template <typename T>
BSTree<T>::BSTree() :root(nullptr){};

/*��������*/
template <typename T>
BSTree<T>::~BSTree()
{
	destory(root);
};
/*���뺯��*/
template <typename T>
void BSTree<T>::insert(T key)
{
	BSNode<T>* pparent = nullptr;
	BSNode<T>* pnode = root;

	while (pnode != nullptr)		//Ѱ�Һ��ʵĲ���λ��
	{
		pparent = pnode;
		if (key > pnode->value)
			pnode = pnode->rchild;
		else if (key < pnode->value)
			pnode = pnode->lchild;
		else
			break;
	}

	pnode = new BSNode<T>(key);
	if (pparent == nullptr)			//����ǿ���
	{
		root = pnode;				//���½ڵ�Ϊ��
	}
	else
	{
		if (key > pparent->value)	
		{
			pparent->rchild = pnode;//�����½ڵ�Ϊ�丸�ڵ����
		}
		else
			pparent->lchild = pnode;//���Һ�
	}
	pnode->parent = pparent;		//ָ���½ڵ�ĸ��ڵ�

};

/*����ָ��Ԫ�صĽڵ㣨�ǵݹ飩*/
template <typename T>
BSNode<T>* BSTree<T>::search_Iterator(T key)
{
	BSNode<T> * pnode = root;
	while (pnode != nullptr)
	{
		if (key == pnode->value)	//�ҵ�
			return pnode;
		if (key > pnode->value)		//�ؼ��ֱȽڵ�ֵ���ڽڵ�����������
			pnode = pnode->rchild;
		else
			pnode = pnode->lchild; //�ؼ��ֱȽڵ�ֵС���ڽڵ�����������
	}
	return nullptr;
};

/*����ָ��Ԫ�صĽڵ㣨�ݹ飩*/
template <typename T>
BSNode<T>* BSTree<T>::search_recursion(T key)
{
	return search(root, key);		
};

/*private:search()*/
/*�ݹ���ҵ����ڲ�ʵ��*/
template <typename T>
BSNode<T>* BSTree<T>::search(BSNode<T>* & pnode, T key)
{
	if (pnode == nullptr)
		return nullptr;
	if (pnode->value == key)
		return pnode;
	//cout << "-->" << pnode->value << endl; //�����������·��
	if (key > pnode->value)
		return search(pnode->rchild, key);
	return search(pnode->lchild, key);
};

/*ɾ��ָ���ڵ�*/
template <typename T>
void BSTree<T>::remove(T key)
{
	remove(root, key);
};
/*ɾ��ָ���ڵ�*/
/*�ڲ�ʹ�ú���*/
template <typename T>
void BSTree<T>::remove(BSNode<T>* pnode, T key)
{
	if (pnode != nullptr)
	{
		if (pnode->value == key)
		{
			BSNode<T>* pdel=nullptr;
		
			if (pnode->lchild == nullptr || pnode->rchild == nullptr)
				pdel = pnode;					//�������������ɾ�ڵ�ֻ��������������������û�к���
			else 
				pdel = predecessor(pnode);      //���һ����ɾ�ڵ�ͬʱ��������������ɾ���ýڵ��ǰ��

			//��ʱ����ɾ�ڵ�ֻ��һ�����ӣ���û�к��ӣ�.����ú���ָ��
			BSNode<T>* pchild=nullptr;
			if (pdel->lchild != nullptr)
				pchild = pdel->lchild;
			else
				pchild = pdel->rchild;

			//�ú���ָ��ɾ���ڵ�ĸ��ڵ�
			if (pchild != nullptr)
				pchild->parent = pdel->parent;

			//���Ҫɾ���Ľڵ���ͷ�ڵ㣬ע�����root��ֵ
			if (pdel->parent == nullptr) 
				root = pchild;			

			//���Ҫɾ���Ľڵ㲻��ͷ�ڵ㣬Ҫע���������˫�׽ڵ�ָ���µĺ��ӽڵ�
			else if (pdel->parent->lchild==pdel)
			{
				pdel->parent->lchild = pchild;
			}
			else
			{
				pdel->parent->rchild = pchild;
			}
			
			if (pnode->value != pdel->value)
				pnode->value = pdel->value;
			delete pdel;
		}
		//���еݹ�ɾ��
		else if (key > pnode->value)
		{
			remove(pnode->rchild, key);
		}
		else remove(pnode->lchild, key);
	}
};
/*Ѱ����ǰ���ڵ�*/
/*
һ���ڵ��ǰ���ڵ���3�������
1. �����������������������ڵ�Ϊ��ǰ���ڵ�
2. ��û������������������Ϊ�����������丸�ڵ�Ϊ��ǰ���ڵ�
3. ��û������������������Ϊ��������������ǰ���ڵ�Ϊ����һ��ӵ���������ĸ��ڵ㡱
*/
template <typename T>
BSNode<T>* BSTree<T>::predecessor(BSNode<T>* pnode)
{
	if (pnode->lchild != nullptr)
	{
		pnode = pnode->lchild;
		while (pnode->rchild != nullptr)
		{
			pnode = pnode->rchild;
		}
		return pnode;
	}

	BSNode<T>* pparent = pnode->parent;
	while (pparent != nullptr && pparent->lchild == pnode)//�������ѭ�������ǵ��������������Ϊ�ڶ������
	{
		pnode = pparent;
		pparent = pparent->parent;
	}
	return pparent;
};

/*Ѱ�����̽ڵ�*/
/*
һ�����к�̽ڵ�������
1. �����������������̽ڵ�Ϊ��������������ڵ�
2. ��û��������������������һ�����ӣ����̽ڵ�Ϊ����˫��
3. ��û��������������������һ���Һ��ӣ������̽ڵ�Ϊ���������ӵ�������ڵ㡱
*/
template <typename T>
BSNode<T>* BSTree<T>::successor(BSNode<T>* pnode)
{
	if (pnode->rchild != nullptr)
	{
		pnode = pnode->rchild;
		while (pnode->lchild != nullptr)
		{
			pnode = pnode->lchild;
		}
		return pnode;
	}

	BSNode<T>* pparent = pnode->parent;
	while (pparent!=nullptr&& pparent->rchild == pnode)
	{
		pnode = pparent;
		pparent = pparent->parent;
	}
	return pparent;
};


/*ǰ������㷨*/
template <typename T>
void BSTree<T>::preOrder()
{
	preOrder(root);
};
template <typename T>
void BSTree<T>::preOrder(BSNode<T> *p)
{
	if (p != nullptr)
	{
		cout << p->value << endl;
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
};
/*��������㷨*/
template <typename T>
void BSTree<T>::inOrder()
{
	inOrder(root);
};
template<typename T>
void BSTree<T>::inOrder(BSNode<T>* p)
{
	if (p != nullptr)
	{
		inOrder(p->lchild);
		cout << p->value << endl;
		inOrder(p->rchild);
	}
};
/*��������㷨*/
template <typename T>
void BSTree<T>::postOrder()
{
	postOrder(root);
};
template <typename T>
void BSTree<T>::postOrder(BSNode<T>* p)
{
	if (p != nullptr)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout << p->value<<endl;
	}
};
/*Ѱ����СԪ��*/
template <typename T>
T BSTree<T>::search_minimun()
{
	return search_minimun(root);
};
template <typename T>
T BSTree<T>::search_minimun(BSNode<T>* p)
{
	if (p->lchild != nullptr)
		return search_minimun(p->lchild);
	return p->value;
};

/*Ѱ�����Ԫ��*/
template <typename T>
T BSTree<T>::search_maximum()
{
	return search_maximum(root);
};
template <typename T>
T BSTree<T>::search_maximum(BSNode<T>*p)
{
	if (p->rchild != nullptr)
		return search_maximum(p->rchild);
	return p->value;
};

/*���ٶ�����*/
template<typename T>
void BSTree<T>::destory()
{
	destory(root);
};
template <typename T>
void BSTree<T>::destory(BSNode<T>* &p)
{
	if (p != nullptr)
	{
		if (p->lchild != nullptr)
			destory(p->lchild);
		if (p->rchild != nullptr)
			destory(p->rchild);
		delete p;
		p = nullptr;
	}

};
#endif 