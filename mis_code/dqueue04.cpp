#include<iostream>
#include<queue>
using namespace std;
#if 0
������queue<��������> ��������
��ӣ�q.push(x); ��x�ӵ����е�ĩ�ˡ�
���ӣ�q.pop(); �������еĵ�һ��Ԫ�أ����᷵�ر�����Ԫ�ص�ֵ��
���ʶ���Ԫ�أ�q.front()�������类ѹ����е�Ԫ�ء�
���ʶ�βԪ�أ�q.back()�������ѹ����е�Ԫ�ء�
�ж϶��пգ�q.empty()�������п�ʱ������true��
���Ԫ�ظ�����q.size()��
#endif
#include <iostream>
#include <queue>
using namespace std;
int testQueue04()
{
	//����
	queue<int> q;
	//Ԫ�����
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	//��ö��д�С
	cout << q.size() << endl;
	//�����Ƿ�Ϊ��
	cout << q.empty() << endl;
	//���ʶ���
	cout << q.front() << endl;
	//���ʶ�β
	cout << q.back() << endl;
	//������ǰ����Ԫ��
	q.pop();
	return 0;
}
