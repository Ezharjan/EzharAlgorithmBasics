/*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	时间: 15/12/18 17:02
	描述:实验五的第三道题 
*/

#include<iostream>
//#define Max 12//为方便测试将容量定义为12 
using namespace std;

typedef struct
{
	int data,a;//结构体中所包含的代表数据元素的整型变量 
}store;//定义结构体 

int Hash(int Max)//实现散列表的功能函数， 
{  
	store num[Max];//声明存储的数据元素形式，其中，最大容量由用户输入 
	int i;//声明整型的计数器 
	for(i=0;i<Max;i++)//计数器从零开始做自加运算，直到等于最大容量时退出循环 
	{
		num[i].a=0;//初始化数组中的数据元素 
	}
		cout<<"输入"<<Max<<"个小于"<<Max<<"的整数："<<endl; 
	
	for(i=0;i<Max;i++)
	{
		int got,pre;
		cin>>got;//在容量范围内根据要求输入元素 
		pre=got/2;//根据题目给定的散列函数，将所输入的元素代进该公式中并将结果的值赋给需要呈现的变量 
		while(num[pre].a!=0)//代入数组中，当数组中的数据不是0的时候进行循环 
		{
			pre++;//不停地做自加运算 
			pre=pre%Max;//对所要呈现的变量进行取余操作并重新赋值 
		}
		num[pre].data=got;//将用户所输入的值赋给数组中的数据元素 
		num[pre].a=1;//将1赋给已查找过的元素 
	 } 
	 cout<<"使用散列法进行存储的数据元素排布如下："<<endl;
	 for(i=0;i<Max;i++)//使用循环将所有元素进行呈现 
	 {
	 	cout<<"  "<<num[i].data;
	 }
}


int main()
{
	int Max;//声明容量大小 
	cout<<"请输入存储容量："<<endl;
	cin>>Max;//用户输入容量 
	Hash(Max);//将用户输入的容量值传给函数，以判定容量大小 
} 
