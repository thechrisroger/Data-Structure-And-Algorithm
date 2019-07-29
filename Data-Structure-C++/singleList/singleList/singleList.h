/*
* ����C++templateʵ�ֵĵ�������
* ���ߣ�huanzheWu
* ʱ�䣺2016/1/24
*/

# ifndef SINGLE_LIST_HXX
# define SINGLE_LIST_HXX

//�ڵ�ṹ
template <typename T>
class Node
{
public :
	T _value;
	Node* _next;
public:
	Node() = default;
	Node(T value, Node * next)
		: _value(value), _next(next){}
};

//������
template <typename T>
class SingleLink
{
public:
	typedef Node<T>*  pointer;
	SingleLink();
	~SingleLink();

	int size();						 //��ȡ����
	bool isEmpty();					 //�п�

	Node<T>* insert(int index, T t); //��ָ��λ�ý��в���
	Node<T>* insert_head(T t);		 //������ͷ���в���
	Node<T>* insert_last(T t);		 //������β���в���

	Node<T>*  del(int index);		 //��ָ��λ�ý���ɾ��
	Node<T>*  delete_head();		 //ɾ������ͷ
	Node<T>*  delete_last();		 //ɾ������β

	T get(int index);			     //��ȡָ��λ�õ�Ԫ��
	T get_head();					 //��ȡ����ͷԪ��
	T get_last();					 //��ȡ����βԪ��

	Node<T>* getHead();				 //��ȡ����ͷ�ڵ�

private :
	int count;
	Node<T> * phead;				 

private :
	Node<T> * getNode(int index);	  //��ȡָ��λ�õĽڵ�
};

//Ĭ�Ϲ��캯��
template <typename T>
SingleLink<T>::SingleLink()
:count(0), phead(nullptr)
{
	//����ͷ�ڵ�
	phead = new Node<T>();
	phead->_next = nullptr;
};

/*
����ָ��������ǰһ��λ�ýڵ㣬������Ϊ�գ��򷵻�ͷ�ڵ�
*/

template <typename T>
Node<T>* SingleLink<T>::getNode(int index)
{
	if (index > count||index < 0 )
		return nullptr;
	int temp = 0;
	Node<T>* preNode = phead;
	while (temp < index)
	{
		temp++;
		preNode = preNode->_next;
	}
	return preNode;
}
/*
��������
*/
template <typename T>
SingleLink<T>::~SingleLink()
{
	Node<T>* pNode = phead->_next;
	while (nullptr != pNode)
	{
		Node<T>* temp = pNode;
		pNode = pNode->_next;
		delete temp;
	}
	//��������
};

//��������Ĵ�С
template <typename T>
int SingleLink<T>::size()
{
	return count;
};
//�����п�
template <typename T>
bool SingleLink<T>::isEmpty()
{
	return count==0;
};


template<typename T>
Node<T>* SingleLink<T>::getHead()
{
	return phead->_next;
}

/*
��ָ��λ�ò����½ڵ�
*/
template <typename T>
Node<T>* SingleLink<T>::insert(int index, T t)
{
	Node<T> * preNode = getNode(index);
	if (preNode)
	{
		Node<T> *newNode = new Node<T>(t,preNode->_next); //�����½ڵ㣬����ʱָ���ڵ��next�ڵ�
		preNode->_next = newNode;
		count++;
		return newNode;
	}
	return nullptr;
};
/*
��ͷ������
*/
template <typename T>
Node<T>* SingleLink<T>::insert_head(T t)
{
	return insert(0, t);
};
/*
��β�����в���
*/
template <typename T>
Node<T>* SingleLink<T>::insert_last(T t)
{
	return insert(count, t);
};
/*
ɾ������ָ��λ��Ԫ��
*/
template <typename T>
Node<T>* SingleLink<T>::del(int index)
{
	if (isEmpty())
		return nullptr;
	Node<T>* ptrNode = getNode(index);
	Node<T>* delNode = ptrNode->_next;
	ptrNode->_next = delNode->_next;
	count--;
	delete delNode;
	return ptrNode->_next;
};
/*
ɾ��ͷ�ڵ�
*/
template<typename T>
Node<T>* SingleLink<T>::delete_head()
{
	return del(0);
};
/*
ɾ��β�ڵ�
*/
template<typename T>
Node<T>*SingleLink<T>::delete_last()
{
	return del(count);
};
# endif