

//01 - ���Ӷ�1 ������к�����(20��)
//�����������{ -2, 11, -4, 13, -5, -2 }������������{ 11, -4, 13 }�����ĺ�20����Ҫ�����д���򣬼�������������е�������к͡�
//
//����ּ�ڲ��Ը��ֲ�ͬ���㷨�ڸ�����������µı��֡�������������ص����£�
//
//����1���������ȼۣ����Ի�����ȷ�ԣ�
//����2��10^2�����������
//����3��10^3�����������
//����4��10^4�����������
//����5��10^5�����������
//�����ʽ :
//
//�����1�и���������KK(\le 100000��100000)����2�и���KK������������Կո�ָ���
//
//�����ʽ :
//
//��һ�������������к͡��������������������Ϊ�����������0��
//
//�������� :
//
//6
//- 2 11 - 4 13 - 5 - 2
//������� :
//
//	 20

#include <iostream>
using namespace std;
#include <vector>

#define max(a,b)    (((a) > (b)) ? (a) : (b))

int GetMaxSubsum(vector<int> vec_);

int main()
{
	int k;
	int num;
	int ret = 0;
	vector<int> vec;
	while (cin>>k)
	{
		for (int i = 0; i < k;i++)
		{
			cin >> num;
			vec.push_back(num);
		}
		
		ret = GetMaxSubsum(vec);
		cout << ret << endl;
		vec.clear();
	}
	return 0;
}

int GetMaxSubsum(vector<int> vec_)
{
	int tempSum = 0;
	int ret_sum = 0;
	if (vec_.size()<=0)
	{
		return 0;
	}
	else
	{
		tempSum = vec_[0];
		ret_sum = vec_[0];
		for (int i = 1; i < vec_.size();i++)
		{
			tempSum = (tempSum < 0) ? vec_[i] : (tempSum + vec_[i]);
			ret_sum = max(tempSum,ret_sum);
		}
		return ret_sum;
	}
	return ret_sum;
}