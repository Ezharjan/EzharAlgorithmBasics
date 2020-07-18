/*
	����:���ζ���������˹�� 
	ѧ��:17081160 
	רҵ:����ý�弼�� 
	����: 19/10/18 20:22
	����:����ʽ�洢�ṹʵ��ջ�Ļ������� 
*/
#define maxSize 5
#include<iostream>
using namespace std;

template<class T>//��ģ�� 
struct LkNode
{
	T data;
	LkNode* next;
};//�ṹ�� 

template<class T>
class Stack
{
	public:
		Stack();//����ջ�����캯����
		//���������������˴��·�Ӧ��ʹ��һ�����ٵĺ��������ٹ��캯�� 
		bool IsEmpty();//�жϺ����Ƿ��ǿյ� 
		void push(const T& data);//����Ԫ�أ�����ջ�Ķ��壬ֻ�����ڶ������в��� 
		void pop();//��ջ 
		T& GetTop();//��ȡջ��Ԫ�� 

	private://˽�г�Ա 
		LkNode<T> *head;//ͷָ�� 
		LkNode<T> *top;//����ָ�� 
		int length;//�������� 

};

template <class T>
Stack<T>::Stack()//���캯��������ջ 
{
	head=NULL;//��ʼ��ջ�е�ͷָ�� 
	top=NULL;//��ʼ������Ԫ�� 
	length=0;//��ʼ������ 
	cout<<"   ����ջ��"<<endl;//��ʼ��֮����ʾ�û�ջ�Ѿ����� 
}

template <class T>
bool Stack<T>::IsEmpty()//�ж�ջ�Ƿ�Ϊ�� 
{
	if(head==NULL)//���ͷָ��ָ����ǿյ� 
		return 1;//�򷵻�1 
	else
		return 0;//���򷵻�0����ʾջ���ǿյ� 

}

template <class T>
void Stack<T>::push(const T& data)//ʵ����ջ���� 
{
	if(!head)//���������ͷ�� 
	{
		head=new LkNode<T>;//��ʹ���·���Ľڵ� 
		head->data=data;//�����ݸ���ָ����һ��ͷ�������� 
		head->next=NULL;//�ÿ�ָ�����һ��Ԫ�� 
		top=head;//ʹ��ͷ����β����� 
		length++;//�����ۼ� 
		cout<<"Ԫ�ص���ջ˳����:   "<<top->data;//�û�����Ԫ�� 
	}
	
	else
	{
		LkNode<T> *p=new LkNode<T>;//����ģ���д洢�����ݽ��и�ֵ 
		p->data=data;//���������ݸ���Pָ��Ĵ洢�ռ� 
		p->next=NULL;//�ÿ� 
		top->next=p;//��P��������ָ��Ĵ洢�ռ� 
		top=p;
		length++;
		cout<<"  "<<top->data;//�������Ԫ�� 
	}
} 

template <class T>
void Stack<T>::pop()
{
	if(!IsEmpty())//��ջ���� 
	{
	LkNode<T> *p=head;//����ջ��Ԫ��ָ��p��ָ�� 
	if(p==top)//���p��ֵ�Ͷ���ֵһ�� 
	{
		head=NULL;//�ÿ�ͷ��Ԫ�� 
		top=NULL;//�ÿն���Ԫ�� 
	}
	else
	{
		while(p->next!=top)//�����������ѭ�� 
		{
			p=p->next;
		}
		top=p;
		p=top->next;
	}
	delete p;//ֱ��ɾ��p 
	length--;//������Ӧ�ļ�һ 
	}
}

template <class T>
T& Stack<T>::GetTop()//��ȡջ��Ԫ�صĹ��� 
{
	if(!IsEmpty())  return top->data;//���ջ��Ԫ�ز��ǿյģ��򷵻�ջ��Ԫ�� 
}

int main()
{
	int data;
	int a[maxSize];
	Stack<int> x;
	for(int i=0;i<=maxSize-1;i++)//��ʾ�û�������ջԪ�� 
	{
		cout<<"��������ջԪ�أ�"; 
		cin>>a[i];//�û�����������ջԪ�� 
	}
	 
	for(int i=0;i<maxSize;i++)
	{
		x.push(a[i]);//����ѹ��ջ�ĺ��� 
	} 
	cout<<endl;//��Ϊ�����û��۲� 
	cout<<"Ԫ�صĳ�ջ˳���ǣ�"; 	
	while(!x.IsEmpty())
	 {
		 data=x.GetTop();
		 cout<<"  "<<data;
		 x.pop();
	 }
	 cout<<endl<<"    ջ�գ�"<<endl; 
}
