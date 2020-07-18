/*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	时间: 12/12/18 00:57
	描述:实验五的第二道题 
*/

#include<iostream>
#include<list>//直接调用库中实现双向链表的函数 
#define Maxsize 100 
using namespace std;

void disp(list<int> List);//声明具有呈现功能的空函数 

void disp(list<int> List)//将库文件中的双线链表函数套入，实现呈现功能的函数 
{
	list<int>::iterator a;//声明双向链表中的迭代器a 
	for(a=List.begin(); a!=List.end(); a++)//从表的首节点开始进行搜索，以呈现表中的所有元素 
	cout<<*a<<" ";//呈现数组中数据元素的位置呈现出来 
	cout<<endl;//空行，以便后续观察方便 
}

int Search(list<int> List,int key)//将库文件中的双向连表函数套入，实现搜索功能的函数 
{
	list<int>::iterator b;//声明双向链表中的迭代器b 
	int i=1;//声明并初始化i 
	for(b=List.begin(); b!= List.end(); b++)//同样做类似于查找的循环工作 
	{	
		if(key==*b)  return i;//而此时则是在得到数据元素在表中的位置后将地址传出 
	    i++;//为达到表的尾部，计数器仍然做自加运算
	}
	return 0;
}

int main()
{
	list<int> L;//引用出L  
	int m[Maxsize];//生声明并初始化数组 
	int i=0;//初始化上面使用的过字母i 
	cout<<"请输入链表节点数据，按0退出。"<<endl<<endl;
	
	do 
	{
		cout<<"第"<<i+1<<"个节点的数据为：";//在输入元素的过程中提示用户所输入元素所在的位置 
		cin>>m[i++];//用户不停地输入数组中的数据元素，根据所提示的位置进行输入 
	} while(m[i-1]!=0);//当用户点击0的时候将跳出循环，结束本程序的功能 
	
	for(int j=0;j<i-1;j++)//在查找时做相应一个循环 
	{
		L.push_back(m[j]);//将查找到的结果推出 
	}
	L.sort();//从头文件中直接调用排序函数，为输入的元素进行排序，简单快捷，方便高效 
	cout<<"单链表节点顺序为："<<endl;
	disp(L);//将L的值传给具有呈现功能的函数 
	int n,x;
	cout<<endl;
	do
	{
		cout<<"1:查找； 2:退出。"<<endl;
		cin>>n;//用户输入相应的选项 
		if(n==1)//当输入的选项为1 
		{
			cout<<"请输入要查找的数："<<endl;
			cin>>x;//再次输入所要查找的数据元素 
			if(Search(L,x))//调用相应的功能函数 
			{
				cout<<"欲查找的节点为单链表的第"<<Search(L,x)<<"个节点。"<<endl<<endl<<endl;
			}//将节点的位置给用户进行呈现 
			else
			cout<<"输入数据不存在！请重新输入！"<<endl<<endl<<endl;
		}
	}while(n!=2);//当用户选择输入2的时候停止循环，将会退出本程序 
} 
