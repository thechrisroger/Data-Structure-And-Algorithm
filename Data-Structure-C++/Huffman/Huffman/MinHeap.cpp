/*
conetent : С����
author :huanzheWu
date:2016/1/30
*/
# ifndef _Min_HEAP_HCC_
# define _Min_HEAP_HCC_
/*С�����ඨ��*/
template <typename T>
class MinHeap
{
public:
	MinHeap(int cap = 10);
	~MinHeap();
public:
	bool insert(T val);		//��������в���Ԫ��
	bool remove(T data);	//�Ƴ�Ԫ��
	void print();			//��ӡ��
	T getTop();				//��ȡ�Ѷ�Ԫ��
	bool createMinHeap(T a[], int length);//����ָ��������������һ����С��


private:
	int capacity;	//������Ҳ��������Ĵ�С
	int size;		//��СС��Ҳ������������ЧԪ�صĸ���
	T * heap;		//�ײ������
private:
	void filterUp(int index); //��index���ڽڵ㣬�����ڵ������
	void filterDown(int begin, int end); //��begin���ڽڵ㿪ʼ����end���������
};
/*Ĭ�Ϲ��캯��*/
template <typename T>
MinHeap<T>::MinHeap(int cap = 10) //Ĭ�ϵ������СΪ10
:capacity(cap), size(0), heap(nullptr)
{
	heap = new T[capacity];
};
/*��������*/
template<typename T>
MinHeap<T>::~MinHeap()
{
	delete[]heap;
};
/*��ӡС����*/
template <typename T>
void MinHeap<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << heap[i] << " ";
};
/*��ȡ�Ѷ�Ԫ��*/
template <typename T>
T MinHeap<T>::getTop()
{
	if (size != 0)
		return heap[0];
};
/*����Ԫ��*/
template <typename T>
bool MinHeap<T>::insert(T val)
{
	if (size == capacity) //��������������򷵻�false
		return false;
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
};
/*���µ��ϵ�����*/
/*����Ԫ��ʱ��ʹ��*/
template <typename T>
void MinHeap<T>::filterUp(int index)
{
	T value = heap[index];	//����ڵ��ֵ��ͼ�е�12

	while (index > 0) //�����δ������ڵ㣬��������
	{
		int indexParent = (index - 1) / 2;  //����˫�׽ڵ�
		if (value >= heap[indexParent])
			break;
		else
		{
			heap[index] = heap[indexParent];
			index = indexParent;
		}
	}
	heap[index] = value;	//12��������λ��
};

/*����ָ��������������һ����С��*/
template<typename T>
bool MinHeap<T>::createMinHeap(T a[], int length)
{
	if (length > capacity)	//	�ѵ����������Դ���
		return false;
	for (int i = 0; i < length; i++)
	{
		insert(a[i]);
	}
	return true;
};

/*ɾ��Ԫ��*/
template<typename T>
bool MinHeap<T>::remove(T data)
{
	if (size == 0) //������ǿյ�
		return false;
	int index;
	for (index = 0; index < size; index++)  //��ȡֵ�������е�����
	{
		if (heap[index] == data)
			break;
	}
	if (index == size)			//������û�и�ֵ
		return false;

	heap[index] = heap[size - 1]; //ʹ�����һ���ڵ������浱ǰ��㣬Ȼ�������µ�����ǰ��㡣

	filterDown(index, size--);

	return true;
};
/*���ϵ��µ�����*/
/*ɾ��Ԫ��ʱ��ʹ��*/
template<typename T>
void MinHeap<T>::filterDown(int current, int end)
{

	int child = current * 2 + 1; //��ǰ��������

	T value = heap[current];	//���浱ǰ����ֵ

	while (child <= end)
	{
		if (child < end && heap[child] > heap[child + 1])//ѡ�����������н�С�ĺ���
			child++;
		if (value<heap[child])	//�����������������
			break;
		else
		{
			heap[current] = heap[child];	//���ӽڵ㸲�ǵ�ǰ���
			current = child;				//�����ƶ�
			child = child * 2 + 1;
		}
	}
	heap[current] = value;
};

# endif 