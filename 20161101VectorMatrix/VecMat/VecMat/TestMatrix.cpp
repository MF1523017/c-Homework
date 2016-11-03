
#include <assert.h>
#include <iostream>

// �ò����������漰��Vector.h��Matrix.h������ƣ�����Ϥ��������ӿ��������
// ���������ע�͵�ȫ����󲿷ֲ��Դ��룬�Ӷ�������һ��ʼ��������ɺ��ٲ��֣�����̫��������
// ����˼���ķ�ʽΪ����Ӧ��ΪVector��Matrix�ṩʲô�ӿڣ���Щ�ӿ�Ӧ�����ʲô�������������ǵ�ְ��Ϊ�����㣬ʵ�ֺ�ͨ������������֤
// ���ǡ���Ӧ��ΪVector��Matrix�ṩʲô�ӿڣ�����ͨ�����Դ��롱Ϊ�����㣬ͨ����һ�䣬��һ��������ͨ��һ�䣬��ת�Ƶ���һ�������ķ�ʽ
// ǰ���Զ���Ϊ���ģ�����ְ����˼�����̺�ʵ�ֹ����У��������Ʋ�ʵ�֣�����ͨ��������ɹ��ܣ�����ƺ�ʵ�ֵĹ��̺Ͳ��Դ����˳���޹أ�
// ��������Ӳ��Դ����з������ںϳ���ְ�������й�
// �����Թ���Ϊ���ģ����ǹ��ܣ�˼�����̺�ʵ�ֵĹ����У��Բ��Դ������е�˳�����ӹ���
// �����ύVector.h(cpp)��Matrix.h(cpp)�ĸ��ļ����ļ����̶�
#include "Vector.h"
//Vector.h ʵ����+��-��*��-()��==��!=��=��+=��-=�Ȳ�������
#include "Matrix.h"
//������Vector���� Matrix �� Vector��ɣ�ÿһ�ж�Ӧһ��Vector
//������Ҫ��̬�����ڴ棬�����׳��ִ���

int main(int argc, char** argv)
{
	// ͨ������Ԫ�������ʼ�����������ս��õ�3��Ԫ��
	double data1[] = { 3.4, 4.4, 6.0 };
	Vector v(sizeof(data1) / sizeof(double), data1);

	// ȷ���걸�ĳ�ʼ������
	assert(v.size() == sizeof(data1) / sizeof(double));
	for (int idx = 0; idx < sizeof(data1) / sizeof(double); ++idx)
	{
		assert(v[idx] == data1[idx]);
	}
	std::cout << "60" << std::endl;

	// v��ֵӦ���������Ҳ��᲻��������
	assert(v == v);
	assert(!(v != v));
	std::cout << "62" << std::endl;

	// v + v��Ԫ�طֱ���͵Ľ�����൱��ÿ��Ԫ��ֱ����2���
	assert(v + v == v * 2);
	std::cout << "64" << std::endl;

	// v - v��Ԫ�طֱ���͵Ľ�����൱��v����v���෴��
	assert(v - v == v + (-v));
	std::cout << "68" << std::endl;

	// v = 3�Ľ��ʹ������ÿ��Ԫ�ض���Ϊ3����˵���ֱ�ӳ�ʼ��һ��ֻ������Ԫ�أ��ҳ�ʼֵΪ3������
	assert((v = 3) == Vector(sizeof(data1) / sizeof(double), 3));
	std::cout << "70" << std::endl;

	// v + 3�Ľ��ʹ������ÿ��Ԫ�ض�����3����˵���ֱ�ӳ�ʼ��һ��ֻ������Ԫ�أ��ҳ�ʼֵΪ6������
	// �� v - 3��ֱ�ӳ�ʼ��һ��ֻ������Ԫ�أ��ҳ�ʼֵΪ0������
	assert(v + 3 == Vector(sizeof(data1) / sizeof(double), 6));
	assert(v - 3 == Vector(sizeof(data1) / sizeof(double), 0.0));
	std::cout << "74" << std::endl;


	// ���ж���һ����ʮ��Ԫ�أ���ÿ��Ԫ��ֵΪ5������
	Vector v2(10, 5);

	// ȷ������ȷ��ʼ��
	assert(v2.size() == 10);
	for (int idx = 0; idx < v2.size(); ++idx)
	{
		assert(v2[idx] == 5);
	}
	std::cout << "76" << std::endl;

	// ����Ԫ�ظ�������ȵ�������ӣ�����Ϊ����Ч������
	assert(v + v2 == Vector::INVALID_VECTOR);
	std::cout << "77" << std::endl;

	//////////////////////////////////////////////////
	// ͨ������Ԫ�������ʼ������3( ��) X 2(��) ����Ϊ��
	// 1 1 
	// 1 1 
	// 1 1

	double data2[] = { 1, 1, 1, 1, 1, 1 };
	Matrix m1(3, 2, data2);

	// m4����m1���Ա���2����˰�Ԫ�طֱ���˻����õ�3( ��) X 2(��) ����Ϊ��
	// 2 2 
	// 2 2 
	// 2 2
	Matrix m4 = m1 * 2;

	// ȷ��m1��ʼ����ȷ����������˻���ȷ
	assert(m4.rows() == 3);
	assert(m4.cols() == 2);

	for (int r = 0; r < 2; ++r)
	{
		for (int c = 0; c < 2; ++c)
		{
			assert(m4[r][c] == 2);
		}
	}

	std::cout << "81" << std::endl;

	// ��ͬ���������ʼ�����󣬵����������������ͬ����õľ���Ҳ��ͬ
	Matrix m2(6, 1, data2);
	Matrix m3(3, 2, data2);

	// ���m1��m2ͬ����6��1�������в�ͬ����˲����
	assert(m1 != m2);
	// ֻ��m3������������ͬ��Ԫ����ͬ����Ӧ���
	assert(m1 == m3);
	std::cout << "85" << std::endl;

	// ͬ���Ľ������ͨ��ֱ�ӳ�ʼ��ÿ��Ԫ��Ϊһ����ͬ����ֵ�õ�
	assert(m1 == Matrix(3, 2, 1));
	std::cout << "86" << std::endl;


	// m1���֮��Ӧ�õ�һ��3��2�У�Ԫ��ȫΪ2�ľ���
	assert(m1 + m1 == Matrix(3, 2, 2));
	// ������������в�ͬ���޷�ֱ����ӣ�ֻ�ܵõ��Ƿ�����
	//assert(m1 + m2 == Matrix::INVALID_MATRIX);
	std::cout << "88" << std::endl;

	// ͬ����������Ԫ��������൱�ڼ����෴��
	assert(m1 - m1 == m1 + (-m1));
	// �෴���Ľ��Ӧ��ȷ
	assert(-m1 == Matrix(3, 2, -1));
	std::cout << "92" << std::endl;


	// �ڳ˷��У�����������в�����������ֻ�ܵõ��Ƿ�����
	assert(m1 * m1 == Matrix::INVALID_MATRIX);
	// ����˷�������m1����ת�þ���ĳ˻�((3 X 2) X (2 X 3))Ϊ3��3��Ԫ��Ϊ2����
	assert(m1 * m1.trans() == Matrix(3, 3, 2));
	// ����˷�������m1ת�þ�����m1�ĳ˻�((2 X 3) X (3 X 2))Ϊ2��2��Ԫ��Ϊ3����
	assert(m1.trans() * m1 == Matrix(2, 2, 3));
	std::cout << "96" << std::endl;

	// ������ת��Ϊ�����������ˣ�ͬ��Ҫ�������˷�����������v�൱��1X3����Ԫ��Ϊ3����˽��Ϊ1X2����Ԫ��Ϊ9
	assert(Matrix(v) * m1 == Matrix(1, 2, 9));
	// �ı�˳���Ҳ��ͨ��ת�û����һ���˻�����˽��Ϊ2X1����Ԫ��Ϊ9�����൱������һ�������ת��
	assert(m1.trans() * Matrix(v).trans() == Matrix(2, 1, 9));
	std::cout << "100" << std::endl;
	//std::cout << m1 <<std::endl<< v << std::endl;
#if 0
#endif
	system("PAUSE");

	return 0;
}
