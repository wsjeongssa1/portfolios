#pragma once

/*
�뵵 :		���� �迭 Ŭ�������ø�
�ɹ� ���� :	T Ÿ�� ������
�����Ҵ� ����
�ɹ� �Լ� :	������
���������
�Ҹ���
���Կ�����
[]������ �����ε�
[]������ const �����ε�
get-�����Ҵ� ����
*/
template<typename T>
class BoundCheckArray
{
private:
	T * pAcc;
	int acclen;

	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}

public:
	BoundCheckArray(int len = 100);
	~BoundCheckArray();
	T& operator[](int idx);
	T operator[](int idx) const;
	int GetAcclen() const;

};

/*
��� :		������
Ư�̻��� :	���°�ü �����͸� �����Ҵ�
*/
template<typename T>
inline BoundCheckArray<T>::BoundCheckArray(int len) : acclen(len)
{
	pAcc = new T[len];
}

/*
��� :		�Ҹ���
Ư�̻��� :	���°�ü �����͸� ����
*/
template<typename T>
inline BoundCheckArray<T>::~BoundCheckArray() { delete[] pAcc; }

/*
��� :		���°�ü������ ��ü�� ���� []������ �����ε�
�Ű����� :	[]������ �ε�����
��ȯ :		���°�ü�������� ���۷���
Ư�̻��� :	���ϰ����� ���۰���
*/
template<typename T>
inline T & BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= acclen)								// ���¼� ���� �ʰ� ��
	{
		//cout << "Array index out of bound exeption" << endl;
		exit(1);
	}
	return pAcc[idx];
}

/*
��� :		���°�ü������ ��ü�� ���� []������ �����ε� (���ȭ)
�Ű����� :	[]������ �ε�����
��ȯ :		���°�ü������
Ư�̻��� :	���ϰ����� ���ۺҰ���
*/
template<typename T>
inline T  BoundCheckArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= acclen)								// ���¼� ���� �ʰ� ��
	{
		//cout << "Array index out of bound exeption" << endl;
		exit(1);
	}
	return pAcc[idx];
}

/*
��� :		 get - �����Ҵ� ����
�Ű����� :	 ����
��ȯ :		 �����Ҵ� ����
Ư�̻��� :	 ����
*/
template<typename T>
inline int BoundCheckArray<T>::GetAcclen() const { return acclen; }