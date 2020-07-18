/*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	日期: 15/10/18 22:09
	描述:实现队的基本操作 
*/ 
#include<iostream>
using namespace std;

class Queue
{
	public:
		Queue(int a);//声明建立队列 
		void Add(int a);//声明添加元素的函数 
		void Pop();//声明弹出函数 
		void Display();//声明呈现函数 
		int LenNo(); //声明求长度的函数 
		void clearQueue();
	private:
		int head;//头指向
		int rear;//尾指向定位
		int *s;//存储数组的指针
		int MaxSize;//最大容量
		int Length;//已有元素个数
};

Queue::Queue(int a)//建立队并将其初始化
{
	MaxSize=a;
	s=new int[MaxSize];//申请动态内存
	head=0;//初始化头部 
	rear=0;//初始化尾部 
	Length=0;//初始化长度 
}

void Queue::Add(int a)//实现添加功能 
{
	if(Length<MaxSize)//判断是否为满，如果不是，则进行如下操作 
	{
		s[rear]=a;//将a的值赋给数组中的尾部 
		rear++;//尾部增加一 
		Length++;//长度增加一 
	}
	else//如果满了 
	{
		cout<<"队满！"<<endl;//提示用户队满 
	}
}

void Queue::Pop()//实现出队的函数 
{
	if (Length<=0)//如果长度小于等于0，则表示对重没有元素 
	{
		cout<<"队空！"<<endl;//提示用户队是空的 
	}
	else//否则将弹出的值返回并呈现 
	{
		cout<<"弹出的值为： "<<s[head];//呈现弹出的值 
		head++;//头部增加做自加运算，增加一项 
		Length--;//长度减少一
	}

}
void Queue::Display()//呈现队中的元素 
{
	cout<<endl;//为便于显示 
	if(Length>0)//如果长度大于0 
	{
		cout<<"队列中的元素是：";
		if (rear!=head)//判断如果尾部与头部不相等，即队中是有元素的 
		{
			for(int i=head;i!=rear;i++)//呈现时做自加运算并逐一呈现 
			{
				cout<<s[i]<<",";//呈现队中的元素 
			}
		}
		
		if(rear==head)//如果队头等于队为 
		{
			int i=head;//将对头的值赋给i 
			for(i=head;i<MaxSize;i++)//i做自加运算 
			{
				cout<<s[i]<<",";//呈现队中的元素 
			}	
		}
	}
	
	else
	{
		cout<<"队空!";
	}
	cout<<endl;
}

int Queue::LenNo()//呈现队的长度的函数 
{
	return Length;//返回队的长度 
}

void Queue::clearQueue()//置空队的函数 
{
	head=0;//初始化头部 
	rear=0;//初始化尾部 
	Length=0;//初始化长度 
}

int main()
{
	cout<<"            队的基本操作" <<endl<<endl;
	int M=0;//声明并初始化最大容量 
	cout<<"           请输入队列容量：";
	cin>>M;
	Queue queue1(M);//定义和实现建立队的功能 
	char quit='o';//声明并初始化退出时的键纽 
	while (quit!='Q')//如果没有按到Q或q 
	{
		
		cout<<endl;
		
		cout<<"               1.添加"<<endl;
		cout<<"               2.出队"<<endl;
		cout<<"               3.长度"<<endl;
		cout<<"               4.呈现"<<endl; 
		cout<<"               5.清空" <<endl;
		cout<<"               Q：退出" <<endl<<endl;
		cout<<"            请按照提示选择："<<endl;
		cin>>quit;

		if(quit=='1')
		{
			int add=0;//初始化添加元素的变量 
			cout<<"  请输入添加元素:  ";
			cin>>add;//用户输入添加的元素 
			queue1.Add(add);//调用添加函数，将添加的元素传给实现添加功能的函数  
		}
		if(quit=='2')
		{
			queue1.Pop();//调用出队函数 
			queue1.Display();
		}
		if(quit=='3')
		{
			cout<<"  目前元素个数为"<<queue1.LenNo()<<endl;
		}
		if(quit=='4')
		{
			queue1.Display();//调用呈现函数
		}
		if(quit =='5')
		{
			queue1.clearQueue();//调用置空函数 
			cout<<"              置空！"<<endl;
		}
		cout<<endl;
	}
    return 0;
}

