/*
	����:���ζ���������˹�� 
	ѧ��:17081160 
	רҵ:����ý�弼�� 
	����: 24/10/18 00:47
	����:��д�ж϶Գ��Եĳ��� 
*/
#include <iostream>
using namespace std;

class Stack
{
	private:
    	char *top,*base,*content;//����ͷָ�롢�ײ�ָ�������ָ�� 
	public:
    	Stack(int n)//ֱ��������ڲ�����������ʵ�֣�����ջ 
    	{
        	content=new char[n+1];//���µ��ַ����鸳������ 
        	base=content;//�����ݸ����ײ� 
        	top=content;//�����ݸ������� 
    	}
    	
    	Stack(string s)//�ַ������� 
    	{
       		content=new char[s.size()+1];//���µ��ַ����鸳�����ݣ��˴�ע����÷�ʽ 
        	base=content;//�����ݸ����ײ� 
        	top=content;//�����ݸ������� 
    	} 
    	
    	bool isEmpty()//ֱ��������ڲ�������ʵ���ж�ջ�Ƿ�Ϊ�յĺ��� 
    	{
        	if(top==base)  return 1;//����ײ���ֵ���ڶ�����ֵ����Ϊ��� 
        	else           return 0;//����ײ���ֵ�����ڶ�����ֵ����Ϊ�ٿ� 
    	}
    	
    	void push(char a)//������ʵ��ѹ�뺯�� 
    	{
        	*top=a;//������a��������ָ�� 
        	top++;//����ָ�����Լ����㣬�ۼ� 
    	}
    	
    	char Pop()//������ʵ�ֵ����ĺ��� 
    	{
        	return *--top;//�����Լ��Ķ���ָ�� 
    	}
};

int main()
{
    string content;//�����ַ����͵����ݱ��� 
    cout<<"���������ж϶Գ��Ե�����:";//��ʾ�û��������� 
    cin>>content;
    Stack stack(content);//���ù��ܺ��� 
    for(int i=0;content[i]!='\0';i++)
    {
        if(stack.isEmpty())  stack.push(content[i]);//���ջ�ǿյģ������ѹ��Ԫ�� 
        else
        {
    		char temp=stack.Pop();//���ջ���ǿյģ���ջ�е�Ԫ�ص�����һ����ʱֵ�� 
            if(temp!=content[i])
            {
                stack.push(temp);//����ѹ�뺯��ѹ����ʱ���� 
                stack.push(content[i]);//����ѹ�뺯��ѹ���������� 
            }
        }
    }
    if(stack.isEmpty())    cout<<"���������ݶԳƣ�"<<endl;
    else                   cout<<"���������ݲ��Գƣ�"<<endl;
    return 0;
}
