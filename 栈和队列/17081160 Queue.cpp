/*
	����:���ζ���������˹�� 
	ѧ��:17081160 
	רҵ:����ý�弼�� 
	����: 15/10/18 22:09
	����:ʵ�ֶӵĻ������� 
*/ 
#include<iostream>
using namespace std;

class Queue
{
	public:
		Queue(int a);//������������ 
		void Add(int a);//�������Ԫ�صĺ��� 
		void Pop();//������������ 
		void Display();//�������ֺ��� 
		int LenNo(); //�����󳤶ȵĺ��� 
		void clearQueue();
	private:
		int head;//ͷָ��
		int rear;//βָ��λ
		int *s;//�洢�����ָ��
		int MaxSize;//�������
		int Length;//����Ԫ�ظ���
};

Queue::Queue(int a)//�����Ӳ������ʼ��
{
	MaxSize=a;
	s=new int[MaxSize];//���붯̬�ڴ�
	head=0;//��ʼ��ͷ�� 
	rear=0;//��ʼ��β�� 
	Length=0;//��ʼ������ 
}

void Queue::Add(int a)//ʵ����ӹ��� 
{
	if(Length<MaxSize)//�ж��Ƿ�Ϊ����������ǣ���������²��� 
	{
		s[rear]=a;//��a��ֵ���������е�β�� 
		rear++;//β������һ 
		Length++;//��������һ 
	}
	else//������� 
	{
		cout<<"������"<<endl;//��ʾ�û����� 
	}
}

void Queue::Pop()//ʵ�ֳ��ӵĺ��� 
{
	if (Length<=0)//�������С�ڵ���0�����ʾ����û��Ԫ�� 
	{
		cout<<"�ӿգ�"<<endl;//��ʾ�û����ǿյ� 
	}
	else//���򽫵�����ֵ���ز����� 
	{
		cout<<"������ֵΪ�� "<<s[head];//���ֵ�����ֵ 
		head++;//ͷ���������Լ����㣬����һ�� 
		Length--;//���ȼ���һ
	}

}
void Queue::Display()//���ֶ��е�Ԫ�� 
{
	cout<<endl;//Ϊ������ʾ 
	if(Length>0)//������ȴ���0 
	{
		cout<<"�����е�Ԫ���ǣ�";
		if (rear!=head)//�ж����β����ͷ������ȣ�����������Ԫ�ص� 
		{
			for(int i=head;i!=rear;i++)//����ʱ���Լ����㲢��һ���� 
			{
				cout<<s[i]<<",";//���ֶ��е�Ԫ�� 
			}
		}
		
		if(rear==head)//�����ͷ���ڶ�Ϊ 
		{
			int i=head;//����ͷ��ֵ����i 
			for(i=head;i<MaxSize;i++)//i���Լ����� 
			{
				cout<<s[i]<<",";//���ֶ��е�Ԫ�� 
			}	
		}
	}
	
	else
	{
		cout<<"�ӿ�!";
	}
	cout<<endl;
}

int Queue::LenNo()//���ֶӵĳ��ȵĺ��� 
{
	return Length;//���ضӵĳ��� 
}

void Queue::clearQueue()//�ÿնӵĺ��� 
{
	head=0;//��ʼ��ͷ�� 
	rear=0;//��ʼ��β�� 
	Length=0;//��ʼ������ 
}

int main()
{
	cout<<"            �ӵĻ�������" <<endl<<endl;
	int M=0;//��������ʼ��������� 
	cout<<"           ���������������";
	cin>>M;
	Queue queue1(M);//�����ʵ�ֽ����ӵĹ��� 
	char quit='o';//��������ʼ���˳�ʱ�ļ�Ŧ 
	while (quit!='Q')//���û�а���Q��q 
	{
		
		cout<<endl;
		
		cout<<"               1.���"<<endl;
		cout<<"               2.����"<<endl;
		cout<<"               3.����"<<endl;
		cout<<"               4.����"<<endl; 
		cout<<"               5.���" <<endl;
		cout<<"               Q���˳�" <<endl<<endl;
		cout<<"            �밴����ʾѡ��"<<endl;
		cin>>quit;

		if(quit=='1')
		{
			int add=0;//��ʼ�����Ԫ�صı��� 
			cout<<"  ���������Ԫ��:  ";
			cin>>add;//�û�������ӵ�Ԫ�� 
			queue1.Add(add);//������Ӻ���������ӵ�Ԫ�ش���ʵ����ӹ��ܵĺ���  
		}
		if(quit=='2')
		{
			queue1.Pop();//���ó��Ӻ��� 
			queue1.Display();
		}
		if(quit=='3')
		{
			cout<<"  ĿǰԪ�ظ���Ϊ"<<queue1.LenNo()<<endl;
		}
		if(quit=='4')
		{
			queue1.Display();//���ó��ֺ���
		}
		if(quit =='5')
		{
			queue1.clearQueue();//�����ÿպ��� 
			cout<<"              �ÿգ�"<<endl;
		}
		cout<<endl;
	}
    return 0;
}

