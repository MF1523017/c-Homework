// LibArray.cpp : 定义控制台应用程序的入口点。

// 实验内容：
// 1：使用C语言实现一个长度可扩充的数组（包含必要的数据结构及函数）；
// 2：实现存储整型的代码（之后会要求改写成适应任意类型的代码）
// 3：所写程序需能通过测试程序
// 4：除本文件（测试文件）之外，其他文件（如CLibArray.cpp及CLibArray.h文件）、以及工程由同学自己建立。过程中可翻书，可查看msdn。

// 实验目的：
// 1：熟悉相关的指针操作, 复习动态内存的相关操作.
// 2：理解C程序如何实现数据类型和围绕数据类型上操作的集合
// 3：为未来理解类实现的数组vector做准备

// 实验提交：
// 只提交CLibArray.cpp及CLibArray.h
// 所有文件打包成一个压缩包，以邮件附件形式发送。邮件主题与压缩包名一致。
// Email：	esecpp2016@163.com
// 命名规范：	姓名+学号+第几次作业+第几版
// 截止时间：	10月2日24：00前

#include <assert.h>

#include "CLibArray.h"
using std::cout;
using std::endl;
int main(int argc,char **argv)
{
	CArray <int>array;
	// 不再需要initial，但应该有正确的初始化
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
	CArray<double>dArrayCopy(dArray);//如果不定义合理的拷贝构造函数，系统会自动调用默认拷贝构造函数，
									//运行结果显示，所有的对象dArray,dArrayCopy,dArray1共用同一个内存地址
									//如果我们没有定义自己的析构函数，则不会发生错误
									//如果我们定义了自己的析构函数（与默认析构函数释放资源不同），这导致析构的时候发生错误，
	///////////////////////////////////////////////////////////////

	CArray<double>dArray1=dArray;//这里直接进入拷贝构造函数内
	dArray1.at(2) = 0;//如果是浅复制，那么dArray1和dArray 同时改变，
	dArrayCopy = dArray;//这里会进入到拷贝赋值运算符内，如果没有自定义拷贝赋值运算符，则进行浅拷贝
	dArray = dArray;//自我赋值
	//////////////////////////////////////////////////////////
	const CArray<double> constArray(dArray);
	cout << constArray[2] << endl;
	CArray<double> notNonstArray = dArray;
	notNonstArray[0] = 9.0;
	cout << notNonstArray << endl;

	//////////////////////////////////////////////////////////////////////////
	// 不再需要destroy，但应该有正确的内存释放
	// array_destroy(array); 
	// array_destroy(array2); 
	// array_destroy(array3); 

	return 0;
}

