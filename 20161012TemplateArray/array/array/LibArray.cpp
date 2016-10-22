// LibArray.cpp : �������̨Ӧ�ó������ڵ㡣

// ʵ�����ݣ�
// 1��ʹ��C����ʵ��һ�����ȿ���������飨������Ҫ�����ݽṹ����������
// 2��ʵ�ִ洢���͵Ĵ��루֮���Ҫ���д����Ӧ�������͵Ĵ��룩
// 3����д��������ͨ�����Գ���
// 4�������ļ��������ļ���֮�⣬�����ļ�����CLibArray.cpp��CLibArray.h�ļ������Լ�������ͬѧ�Լ������������пɷ��飬�ɲ鿴msdn��

// ʵ��Ŀ�ģ�
// 1����Ϥ��ص�ָ�����, ��ϰ��̬�ڴ����ز���.
// 2������C�������ʵ���������ͺ�Χ�����������ϲ����ļ���
// 3��Ϊδ��������ʵ�ֵ�����vector��׼��

// ʵ���ύ��
// ֻ�ύCLibArray.cpp��CLibArray.h
// �����ļ������һ��ѹ���������ʼ�������ʽ���͡��ʼ�������ѹ������һ�¡�
// Email��	esecpp2016@163.com
// �����淶��	����+ѧ��+�ڼ�����ҵ+�ڼ���
// ��ֹʱ�䣺	10��2��24��00ǰ

#include <assert.h>

#include "CLibArray.h"
using std::cout;
using std::endl;
int main(int argc,char **argv)
{
	CArray <int>array;
	// ������Ҫinitial����Ӧ������ȷ�ĳ�ʼ��
	// array_initial(array); 

	//array.recap(10); 
	//assert(array.capacity() == 10); 

	//////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 20; ++i)
	{
		array.append(i);
	}
	assert(array.size() == 20);

	for (int i = 0; i < array.size(); ++i)
	{
		assert(array.at(i) == i);
	}

	//////////////////////////////////////////////////////////////////////////
	CArray<int> array2, array3;
	// array_initial(array2); 
	// array_initial(array3); 

	array2.copy(array);
	assert(array.compare(array2) == true);

	array3.copy(array);
	assert(array.compare(array3) == true);

	//////////////////////////////////////////////////////////////////////////
	array2.insert(2, 3);
	assert(array.compare(array2) == false);

	//////////////////////////////////////////////////////////////////////////
	array3.at(2) = 5;
	assert(array.compare(array3) == false);
	////////////////////////////////////////////////////////////////
	double a[]={ 1,2,3 };
	CArray <double> dArray(3,a);
	CArray<double>dArrayCopy(dArray);//�������������Ŀ������캯����ϵͳ���Զ�����Ĭ�Ͽ������캯����
									//���н����ʾ�����еĶ���dArray,dArrayCopy,dArray1����ͬһ���ڴ��ַ
									//�������û�ж����Լ��������������򲻻ᷢ������
									//������Ƕ������Լ���������������Ĭ�����������ͷ���Դ��ͬ�����⵼��������ʱ��������
	///////////////////////////////////////////////////////////////

	CArray<double>dArray1=dArray;//����ֱ�ӽ��뿽�����캯����
	dArray1.at(2) = 0;//�����ǳ���ƣ���ôdArray1��dArray ͬʱ�ı䣬
	dArrayCopy = dArray;//�������뵽������ֵ������ڣ����û���Զ��忽����ֵ������������ǳ����
	dArray = dArray;//���Ҹ�ֵ
	//////////////////////////////////////////////////////////
	const CArray<double> constArray(dArray);
	cout << constArray[2] << endl;
	CArray<double> notNonstArray = dArray;
	notNonstArray[0] = 9.0;
	cout << notNonstArray << endl;

	//////////////////////////////////////////////////////////////////////////
	// ������Ҫdestroy����Ӧ������ȷ���ڴ��ͷ�
	// array_destroy(array); 
	// array_destroy(array2); 
	// array_destroy(array3); 

	return 0;
}
