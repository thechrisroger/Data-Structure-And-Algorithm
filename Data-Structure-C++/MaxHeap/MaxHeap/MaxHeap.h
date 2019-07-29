/*
conetent : �󶥶�
author :huanzheWu
date:2016/1/30
*/

# ifndef _MAX_HEAP_HCC_
# define _MAX_HEAP_HCC_
/*�󶥶��ඨ��*/
template <typename T>
class MaxHeap
{
public:
	MaxHeap(int cap = 10);
	~MaxHeap();
public:
	bool insert(T val);		//��������в���Ԫ��
	bool remove(T data);	//�Ƴ�Ԫ��
	void print();			//��ӡ��
	T getTop();				//��ȡ�Ѷ�Ԫ��
	bool createMaxHeap(T a[], int size);//����ָ��������������һ������

private:
	int capacity;	//������Ҳ��������Ĵ�С
	int size;		//�Ѵ�С��Ҳ������������ЧԪ�صĸ���
	T * heap;		//�ײ������
private:
	void filterUp(int index); //��index���ڽڵ㣬�����ڵ������
	void filterDown(int begin ,int end ); //��begin���ڽڵ㿪ʼ����end���������
};
/*Ĭ�Ϲ��캯��*/
template <typename T>
MaxHeap<T>::MaxHeap(int cap = 10) //Ĭ�ϵ������СΪ10
:capacity(cap), size(0), heap(nullptr)
{
	heap = new T[capacity];
};
/*��������*/
template<typename T>
MaxHeap<T>::~MaxHeap()
{
	delete[]heap;
};
/*��ӡ�󶥶�*/
template <typename T>
void MaxHeap<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << heap[i] << " ";
};
/*��ȡ�Ѷ�Ԫ��*/
template <typename T>
T MaxHeap<T>::getTop()
{
	if (size != 0)
		return heap[0];
};
/*����Ԫ��*/
template <typename T>
bool MaxHeap<T>::insert(T val)
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
void MaxHeap<T>::filterUp(int index)
{
	T value = heap[index];	//����ڵ��ֵ��ͼ�е�12

	while (index > 0) //�����δ������ڵ㣬��������
	{
		int indexParent = (index -1)/ 2;  //����˫�׽ڵ�
		if (value< heap[indexParent])
			break;
		else 
		{
			heap[index] = heap[indexParent];
			index = indexParent;
		}
	}
	heap[index] = value;	//12��������λ��
};

/*����ָ��������������һ������*/
template<typename T>
bool MaxHeap<T>::createMaxHeap(T a[], int size)
{
	if (size > capacity)	//	�ѵ����������Դ���
		return false;
	for (int i = 0; i < size; i++)
	{
		insert(a[i]);
	}
	return true;
};

/*ɾ��Ԫ��*/
template<typename T>
bool MaxHeap<T>::remove(T data)
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

	filterDown(index,size--);   

	return true;
};
/*���ϵ��µ�����*/
/*ɾ��Ԫ��ʱ��ʹ��*/
template<typename T>
void MaxHeap<T>::filterDown(int current,int end)
{

	int child = current * 2 + 1; //��ǰ��������

	T value = heap[current];	//���浱ǰ����ֵ

	while (child <= end)
	{
		if (child < end && heap[child] < heap[child+1])//ѡ�����������нϴ�ĺ���
			child++;
		if (value>heap[child])	//�����������������
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