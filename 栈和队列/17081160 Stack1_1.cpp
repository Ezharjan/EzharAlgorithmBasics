/*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	日期: 19/10/18 15:03
	描述:用顺序存储结构实现栈的基本操作 
*/

#include<iostream>
using namespace std;
const int maxSize = 3;//设置顺序栈的大小
template<class elemtype>//定义顺序栈的模板类型
class SeqStack
{
	public:
		SeqStack()
		{
			top=-1;
		} //初始化栈顶指针
		void Push(elemtype x);//入栈操作，将元素入栈
		int IsEmpty();
	private:
	elemtype data[maxSize];//存放栈顶元素的指针
	int top;//栈顶指针 
		
 };
 
template<class elemtype>
void SeqStack<elemtype>::Push(elemtype x)
{   
	if(top==maxSize-1)//判断当前顺序栈是否已是满栈
	{
 		throw"栈满";
    }
 	else
   {
   	top++;//如果当前顺序栈不满，则栈顶值栈向上移动一个单元
 	data[top]=x;//给新的栈顶元素赋值
   }
}

template<class elemtype>
int SeqStack<elemtype>::IsEmpty()//实现判断顺序栈是否是空栈：栈空返回1，否则返回0
{
	if(top==-1)//如果顶部元素为-1，则表示它已经到达底部 
 	{
		return 1;//返回真 

   	}
	else
  	{
 		return 0;//否则返回假 

   	}
}
 
int main()
{
	int m,n,o;
	SeqStack<int> seqStack = SeqStack<int>();//创建一个顺序栈
	cout << "此时栈是否是空栈：" ;
	if(seqStack.IsEmpty()==1)
	{
		cout<<"是"<<endl; 
	}
	else if(seqStack.IsEmpty()==0)
	{
		cout<<"否"<<endl;
	}//判断是否是空栈
	
  	cout<<"请输入欲入栈的元素： ";
  	cin>>m;
	seqStack.Push(m);//欲入栈的元素入栈
	cout<<"请继续输入欲入栈的元素： ";
	cin>>n; 
	cout<<"请再次输入欲入栈的元素： ";
	cin>>o; 
	cout<<"元素入栈顺序："<<m<<"  "<<n<<"  "<<o<<endl; 
  	cout << "栈顶元素是:" <<o<<endl;//取出栈顶元素
   	seqStack.Push(o);//出栈
  	seqStack.Push(n);//出栈
	seqStack.Push(m);//出栈
	cout<<"出栈顺序是："<<"  "<<o<<"  "<<n<<"  "<<m<<endl;
	cout << "此时栈是否是空栈：" ;
	if(seqStack.IsEmpty()==0)
	{
		cout<<"是"<<endl; 
	}
	else if(seqStack.IsEmpty()==1)
	{
		cout<<"否"<<endl;
	}//判断是否是空栈
	return 0;//出栈
}
