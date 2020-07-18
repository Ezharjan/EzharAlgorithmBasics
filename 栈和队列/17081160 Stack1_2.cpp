/*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	日期: 19/10/18 20:22
	描述:用链式存储结构实现栈的基本操作 
*/
#define maxSize 5
#include<iostream>
using namespace std;

template<class T>//类模板 
struct LkNode
{
	T data;
	LkNode* next;
};//结构体 

template<class T>
class Stack
{
	public:
		Stack();//生成栈，构造函数；
		//根据书中所述，此处下方应当使用一个销毁的函数来销毁构造函数 
		bool IsEmpty();//判断函数是否是空的 
		void push(const T& data);//插入元素，根据栈的定义，只允许在顶部进行操作 
		void pop();//出栈 
		T& GetTop();//获取栈顶元素 

	private://私有成员 
		LkNode<T> *head;//头指针 
		LkNode<T> *top;//顶部指针 
		int length;//声明长度 

};

template <class T>
Stack<T>::Stack()//构造函数，生成栈 
{
	head=NULL;//初始化栈中的头指针 
	top=NULL;//初始化顶部元素 
	length=0;//初始化长度 
	cout<<"   生成栈！"<<endl;//初始化之后提示用户栈已经生成 
}

template <class T>
bool Stack<T>::IsEmpty()//判断栈是否为空 
{
	if(head==NULL)//如果头指针指向的是空的 
		return 1;//则返回1 
	else
		return 0;//否则返回0，表示栈不是空的 

}

template <class T>
void Stack<T>::push(const T& data)//实现入栈操作 
{
	if(!head)//如果不是在头部 
	{
		head=new LkNode<T>;//则使用新分配的节点 
		head->data=data;//将数据赋给指向下一个头部的数据 
		head->next=NULL;//置空指向的下一个元素 
		top=head;//使起头部与尾部相等 
		length++;//长度累加 
		cout<<"元素的入栈顺序是:   "<<top->data;//用户输入元素 
	}
	
	else
	{
		LkNode<T> *p=new LkNode<T>;//将类模板中存储的数据进行赋值 
		p->data=data;//将输入数据赋给P指向的存储空间 
		p->next=NULL;//置空 
		top->next=p;//将P赋给顶部指向的存储空间 
		top=p;
		length++;
		cout<<"  "<<top->data;//输出顶部元素 
	}
} 

template <class T>
void Stack<T>::pop()
{
	if(!IsEmpty())//出栈功能 
	{
	LkNode<T> *p=head;//将出栈的元素指向p的指针 
	if(p==top)//如果p的值和顶部值一样 
	{
		head=NULL;//置空头部元素 
		top=NULL;//置空顶部元素 
	}
	else
	{
		while(p->next!=top)//否则进行如下循环 
		{
			p=p->next;
		}
		top=p;
		p=top->next;
	}
	delete p;//直接删除p 
	length--;//长度相应的减一 
	}
}

template <class T>
T& Stack<T>::GetTop()//获取栈顶元素的功能 
{
	if(!IsEmpty())  return top->data;//如果栈顶元素不是空的，则返回栈顶元素 
}

int main()
{
	int data;
	int a[maxSize];
	Stack<int> x;
	for(int i=0;i<=maxSize-1;i++)//提示用户输入入栈元素 
	{
		cout<<"请输入入栈元素："; 
		cin>>a[i];//用户挨个输入入栈元素 
	}
	 
	for(int i=0;i<maxSize;i++)
	{
		x.push(a[i]);//调用压入栈的函数 
	} 
	cout<<endl;//仅为便于用户观察 
	cout<<"元素的出栈顺序是："; 	
	while(!x.IsEmpty())
	 {
		 data=x.GetTop();
		 cout<<"  "<<data;
		 x.pop();
	 }
	 cout<<endl<<"    栈空！"<<endl; 
}
