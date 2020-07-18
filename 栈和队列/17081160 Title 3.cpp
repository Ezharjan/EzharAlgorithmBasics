/*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	日期: 24/10/18 00:47
	描述:编写判断对称性的程序 
*/
#include <iostream>
using namespace std;

class Stack
{
	private:
    	char *top,*base,*content;//声明头指针、底部指针和内容指针 
	public:
    	Stack(int n)//直接在类的内部进行声明和实现，整型栈 
    	{
        	content=new char[n+1];//将新的字符数组赋给内容 
        	base=content;//将内容赋给底部 
        	top=content;//将内容赋给顶部 
    	}
    	
    	Stack(string s)//字符串类型 
    	{
       		content=new char[s.size()+1];//将新的字符数组赋给内容，此处注意调用方式 
        	base=content;//将内容赋给底部 
        	top=content;//将内容赋给顶部 
    	} 
    	
    	bool isEmpty()//直接在类的内部声明和实现判断栈是否为空的函数 
    	{
        	if(top==base)  return 1;//如果底部的值等于顶部的值，则为真空 
        	else           return 0;//如果底部的值不等于顶部的值，则为假空 
    	}
    	
    	void push(char a)//声明并实现压入函数 
    	{
        	*top=a;//将变量a赋给顶部指针 
        	top++;//顶部指针做自加运算，累加 
    	}
    	
    	char Pop()//声明并实现弹出的函数 
    	{
        	return *--top;//返回自减的顶部指针 
    	}
};

int main()
{
    string content;//声明字符串型的内容变量 
    cout<<"请输入需判断对称性的内容:";//提示用户输入内容 
    cin>>content;
    Stack stack(content);//调用功能函数 
    for(int i=0;content[i]!='\0';i++)
    {
        if(stack.isEmpty())  stack.push(content[i]);//如果栈是空的，则可以压入元素 
        else
        {
    		char temp=stack.Pop();//如果栈不是空的，则将栈中的元素弹出到一个临时值中 
            if(temp!=content[i])
            {
                stack.push(temp);//调用压入函数压入暂时变量 
                stack.push(content[i]);//调用压入函数压入内容数组 
            }
        }
    }
    if(stack.isEmpty())    cout<<"所输入内容对称！"<<endl;
    else                   cout<<"所输入内容不对称！"<<endl;
    return 0;
}
