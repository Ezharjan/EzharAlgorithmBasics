/*
	����: ���ζ���������˹�� 
	ѧ��: 17081160
	רҵ: ����ý�弼�� 
	����: 28/09/18 17:32
*/
#include<cstdlib>//Ϊ����ʹ��malloc������������ͷ�ļ� 
#include<iostream>
using namespace std;
  
typedef struct node 
{
    int data;    
	struct node *next;
}node, *LinkList;
 
void Input(LinkList &a,int n) 
{
    a=(node*)malloc(sizeof(node)); //���ڴ��и�a��̬����node�ֽڿռ䣬������free���������ͷ� 
	//����ʹ�õ�malloc����,malloc����������ʱ��
	//�����ؿ�������Ѱ��һ����������������ڴ�飬
	//Ȼ��������С���ڴ�������û���ʣ�µķ��ص������ϡ� 
	//��Ϊmalloc���ص��ǲ�ȷ�����͵�ָ�룬��˷���ǰ���뾭�����͵�ǿ��ת���� 
    node *p=a,*q;//��ַ���� 
    cout<<"��ʼ��Ա���Ϊ��"; 
    for(int i=0;i<n-1;i++)//ѭ�����Լ����� 
	{
       	p->data=i+1;//��i+1����pָ�����ڴ洢��Ԫ��ֵ 
       	q=(node*)malloc(sizeof(node));//�ѷ�������void*ǿ��ת��Ϊnode* 
       	//(sizeof(node)��ȡnode������ռ��ռ�Ĵ�С 
       	p->next=q;//��q����pָ����һ���洢��Ԫ��ֵ 
       	p=q;//���� 
		cout<<i+1<<"  ";//������������� 
    }
    cout<<""<<n<<endl;//�������������    	
    p->data=n;//��n��ֵ����pָ�����ڴ洢��Ԫ��ֵ 
    p->next=a;//��a��ֵ����pָ��˭�ڴ洢��Ԫ��ֵ 
 }
 
 void Josephus(LinkList &a,int s,int m)//���빦�� 
{
    node *nowPoint=a,*prePoint=a;//����ַ���и�ֵ 
    cout<<"�������ó���  ";//���ֽ�� 
    while (nowPoint->next!=nowPoint)//������ָ�����һ���洢��Ԫ��ַ���ǽ�㱾�� 
	{ 
		for(int i=0;i<s-1;i++)//ѭ�����Լ����� 
			{
       			prePoint=nowPoint;//�����ڵĽ�㸳����ǰ�Ľ���ֵ 
       			nowPoint=nowPoint->next;//�����ڵĽ��ֵ�������ڽ��ָ�����һ���洢��Ԫ 
    		}
    	prePoint->next=nowPoint->next;//����һ���洢��Ԫ����ʱ��㸳��ǰһ������λ�� 
    	cout<<nowPoint->data<<"  ";//���ֽ����� 
    	free(nowPoint);//�ͷ��ڴ�ռ䣬���Ϸ���malloc���Ӧ 
    	nowPoint=prePoint->next;//��ǰ�Ľ�㵥Ԫָ����ʱ�Ľ�� 
    }
}

int main()   
{
    int n,m,s;//���������������������ʵ�� 
    LinkList a;//������ʼֵ 
    
	cout<<"���Լɪ������  "<<endl; 
    cout<<"��������������  "<<endl;
    cin>>n;
    cout<<"��������ʼ�㣺"<<endl;
    cin>>s;
	cout<<"�����뱨�������  "<<endl;
    cin>>m;
    Input(a,n);//������Ӧ�����뺯�� 
    Josephus(a,s,m);//����������õ����ս�� 
     
    return 0;
}
