/*
* content: ѭ������
* Author: huanzheWu
* date: 2016/1/25
* 
*/

# ifndef LOOP_QUEUE_HPP
# define LOPP_QUEUE_HPP
template <typename T>
class LoopQueue
{
public:
	LoopQueue(int c = 10);
	~LoopQueue();
public:
	bool isEmpty();		//���е��п�
	int size();			//���еĴ�С
	bool push(T t);		//�����
	bool pop();			//������
	T front();			//����Ԫ��

private:
	int capacity;
	int begin;
	int end;
	T*  queue;
};

template<typename T>
LoopQueue<T>::LoopQueue(int c = 10)
: capacity(c), begin(0), end(0), queue(nullptr)
{
	queue = new T[capacity];
};

template<typename T>
LoopQueue<T>::~LoopQueue()
{
	delete[]queue;
}

template <typename T>
bool LoopQueue<T>::isEmpty()
{
	if (begin == end)
		return true;
	return false;
};

template<typename T>
int LoopQueue<T>::size()
{
	return (end-begin+capacity)%capacity; //������г���
};

template<typename T>
bool LoopQueue<T>::push(T t)
{
	if (end + 1 % capacity == begin) //�ж϶����Ƿ�����
	{
		return false;
	}
	queue[end] = t;
	end = (end + 1) % capacity;
	return true;
};

template <typename T> 
bool LoopQueue<T>::pop()
{
	if (end == begin) //�ж϶����Ƿ�Ϊ��
	{
		return false;
	}
	begin = (begin + 1) % capacity;
	return true;
};

template <typename T>
T LoopQueue<T>::front()
{
	if (end == begin)
	{
		return false;
	}
	return queue[begin];
};

# endif