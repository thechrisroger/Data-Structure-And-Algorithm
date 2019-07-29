/*
*Author :huanzheWu
*date��2016/1/25
*���������ջʵ��
*/
# ifndef ARRAY_STACK_HPP
# define ARRAY_STACK_HPP

template<typename T>
class ArrayStack
{
public:
	ArrayStack(int s = 10);	//Ĭ�ϵ�ջ����Ϊ10
	~ArrayStack();

public:
	T top();			//��ȡջ��Ԫ��
	void push(T t);		//ѹջ����
	T pop();			//��ջ����
	bool isEmpty();		//�пղ���
	int size();			//��ջ�Ĵ�С

private:
	int count;			//ջ��Ԫ������
	int capacity;		//ջ������
	T * array;			//�ײ�Ϊ����
};

/*���캯��*/
template <typename T>
 ArrayStack<T>::ArrayStack(int s = 10)
	 :count(0), capacity(s), array(nullptr)
 {
	 array = new T[capacity];
 };

 /*��������*/
 template<typename T>
 ArrayStack<T>::~ArrayStack()
 {
	 if (array)
	 {
		 delete[]array;
		 array = nullptr;
	 }
 };

 /*ջ���пղ���*/
 template <typename T>
 bool ArrayStack<T>::isEmpty()
 {
	 return count == 0; //ջԪ��Ϊ0ʱΪջ��
 };

 /*����ջ�Ĵ�С*/
 template <typename  T>
 int ArrayStack<T>::size()
 {
	 return count;
 };

 /*����Ԫ��*/
 template <typename T>
void ArrayStack<T>::push(T t)
 {
	 if (count != capacity)	//���ж��Ƿ�ջ��
	 {
		 array[count++] = t;	
	 }
 };

/*��ջ*/
 template <typename T>
 T ArrayStack<T>::pop()
 {
	 if (count != 0)	//���ж��Ƿ��ǿ�ջ
	 {
		 return array[--count];
	 }
 };

 /*��ȡջ��Ԫ��*/
 template <typename T>
 T ArrayStack<T>::top()
 {
	 if (count != 0)
	 {
		 return array[count - 1];
	 }
 };



# endif 