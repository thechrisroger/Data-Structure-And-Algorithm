/*
*Author:huanzheWu
*date:2016/1/25
*���������ջʵ��
*/
# ifndef LINK_STACK_HPP
# define LINK_STACK_HPP

/*����ڵ�ṹ*/
template <typename T>
struct Node
{
	Node(T t) :value(t), next(nullptr){};
	Node() :next(nullptr){};

public:
	T value;
	Node<T>* next;
};

/*ջ�ĳ������ݽṹ*/
 template <typename T>
 class LinkStack
 {
 public:
	 LinkStack();
	 ~LinkStack();
 public:
	 
	 bool isEmpty();
	 int size();
	 void push(T t);
	 T pop();
	 T top();

 private:
	 
	 Node<T>* phead;
	 int count;
 };
 /*���캯��*/
 template <typename T>
 LinkStack<T>::LinkStack()
 {
	 phead = new Node<T>();
	 count = 0;
 };
 /*��������*/
 template <typename T>
 LinkStack<T>::~LinkStack()
 {
	 while (phead->next != nullptr)
	 {
		 Node<T>*pnode = phead->next;
		 phead->next = phead->next;
		 delete pnode;
	 }
	 phead = nullptr;
 };

 /*����ջ�Ĵ�С*/
 template <typename T>
 int LinkStack<T>::size()
 {
	 return count;
 };
 /*ջ���пղ���*/
 template <typename T>
 bool LinkStack<T>::isEmpty()
 {
	 return count == 0;
 };
 /*����Ԫ��*/
 template<typename T>
 void LinkStack<T>::push(T t)
 {
	 Node <T> *pnode = new  Node<T>(t);
	 pnode->next = phead->next;
	 phead->next = pnode;
	 count++;
 };
 /*��ջ*/
 template <typename T>
 T LinkStack<T>::pop()
 {
	 if (phead->next != nullptr) //ջ���ж�
	 {
		 Node<T>* pdel = phead->next;
		 phead->next = phead->next->next;
		 T value = pdel->value;
		 delete pdel;
		 count--;
		 return value;
	 }
 };
 /*��ȡջ��Ԫ��*/
template <typename T>
T LinkStack<T>::top()
{
	if (phead->next!=nullptr)
		return phead->next->value;
};

# endif