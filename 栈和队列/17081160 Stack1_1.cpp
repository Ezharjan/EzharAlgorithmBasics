/*
	����:���ζ���������˹�� 
	ѧ��:17081160 
	רҵ:����ý�弼�� 
	����: 19/10/18 15:03
	����:��˳��洢�ṹʵ��ջ�Ļ������� 
*/

#include<iostream>
using namespace std;
const int maxSize = 3;//����˳��ջ�Ĵ�С
template<class elemtype>//����˳��ջ��ģ������
class SeqStack
{
	public:
		SeqStack()
		{
			top=-1;
		} //��ʼ��ջ��ָ��
		void Push(elemtype x);//��ջ��������Ԫ����ջ
		int IsEmpty();
	private:
	elemtype data[maxSize];//���ջ��Ԫ�ص�ָ��
	int top;//ջ��ָ�� 
		
 };
 
template<class elemtype>
void SeqStack<elemtype>::Push(elemtype x)
{   
	if(top==maxSize-1)//�жϵ�ǰ˳��ջ�Ƿ�������ջ
	{
 		throw"ջ��";
    }
 	else
   {
   	top++;//�����ǰ˳��ջ��������ջ��ֵջ�����ƶ�һ����Ԫ
 	data[top]=x;//���µ�ջ��Ԫ�ظ�ֵ
   }
}

template<class elemtype>
int SeqStack<elemtype>::IsEmpty()//ʵ���ж�˳��ջ�Ƿ��ǿ�ջ��ջ�շ���1�����򷵻�0
{
	if(top==-1)//�������Ԫ��Ϊ-1�����ʾ���Ѿ�����ײ� 
 	{
		return 1;//������ 

   	}
	else
  	{
 		return 0;//���򷵻ؼ� 

   	}
}
 
int main()
{
	int m,n,o;
	SeqStack<int> seqStack = SeqStack<int>();//����һ��˳��ջ
	cout << "��ʱջ�Ƿ��ǿ�ջ��" ;
	if(seqStack.IsEmpty()==1)
	{
		cout<<"��"<<endl; 
	}
	else if(seqStack.IsEmpty()==0)
	{
		cout<<"��"<<endl;
	}//�ж��Ƿ��ǿ�ջ
	
  	cout<<"����������ջ��Ԫ�أ� ";
  	cin>>m;
	seqStack.Push(m);//����ջ��Ԫ����ջ
	cout<<"�������������ջ��Ԫ�أ� ";
	cin>>n; 
	cout<<"���ٴ���������ջ��Ԫ�أ� ";
	cin>>o; 
	cout<<"Ԫ����ջ˳��"<<m<<"  "<<n<<"  "<<o<<endl; 
  	cout << "ջ��Ԫ����:" <<o<<endl;//ȡ��ջ��Ԫ��
   	seqStack.Push(o);//��ջ
  	seqStack.Push(n);//��ջ
	seqStack.Push(m);//��ջ
	cout<<"��ջ˳���ǣ�"<<"  "<<o<<"  "<<n<<"  "<<m<<endl;
	cout << "��ʱջ�Ƿ��ǿ�ջ��" ;
	if(seqStack.IsEmpty()==0)
	{
		cout<<"��"<<endl; 
	}
	else if(seqStack.IsEmpty()==1)
	{
		cout<<"��"<<endl;
	}//�ж��Ƿ��ǿ�ջ
	return 0;//��ջ
}
