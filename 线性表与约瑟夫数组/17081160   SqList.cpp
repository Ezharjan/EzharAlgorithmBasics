/*
	����: ���ζ���������˹�� 
	ѧ��: 17081160
	רҵ: ����ý�弼�� 
	����: 30/09/18 00:51
*/
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct point//ʹ�ýṹ����б�д��δʹ����Ͷ��� 
{
	char data;//�����ַ��ͱ��� 
	struct point *next;//����next��һ��struct point���͵�ָ�� 
}*List;

void InitList(List *l)
{
	*l=(List)malloc(sizeof(List));//���ڴ��и�a��̬����node�ֽڿռ䣬�����Զ��ͷ�
	(*l)->next=NULL;//ָ��Ĵ洢��Ԫָ���ֵ 
}

void Seq(List l)
{
	point *s;//����sָ��Ϊ������� 
	char c;//�����ַ��ͳ��� 
	int a=1;//��������ʼ��a 
	while(a)//���������� 
	{
		c=getchar();//�Ӽ���������һ���ַ����ҽ��ַ�����c 
		if(c!='\n')//�˴���ʾ�û���������һ�����ݺ��ûس���������������룬���س��˳����� 
		{
			s=(List)malloc(sizeof(List));//���ڴ��и�a��̬����node�ֽڿռ䣬�����Զ��ͷ�
			s->data=c;//��c��ֵ����sָ��ĵĴ洢��Ԫ 
			s->next=l->next;//��lָ��Ĵ洢��Ԫ����s 
			l->next=s;
		}
		else{a=0;}//����û�û�а��س�������a��ʼ��Ϊ0 
	}
} 

void Delete(List l)
{
	point *s;
	int i,j=0;
	cout<<endl;
	cout<<"������ɾ��λ�ã�"<<endl;
	cout<<endl;
	cin>>i;
	s=l;
	while(j<i-1)
	{
		if(s->next->next==NULL)//���s�ӵڶ�����ʼ��Ϊ�� 
		{
			cout<<"����λ�ò���ȷ��"<<endl;
			cout<<"��������ȷ��λ�ã�"<<endl;//��ʾ�û��������� 
			cout<<endl; 
		}
		s=s->next;
		j++;
	}
	s->next=s->next->next;
	cout<<"ɾ���ɹ���"<<endl;
	cout<<endl;
}

void Insert(List l)
{
	point *s,*r;
	int i,j=0;
	char c;
	cout<<endl;
	cout<<"���������λ�ã�"<<endl;
	cin>>i;
	cout<<endl;
	s=l;
	while(j<i-1)
	{
		if(s->next->next==NULL)
		{
			cout<<"����λ�ò���ȷ��"<<endl;
			cout<<endl;
		}
	s=s->next;
	j++;
	}
	cout<<endl;
	cout<<"������������ݣ�"<<endl;
	cin>>c;
	cout<<endl;
	r=(List)malloc(sizeof(List));//���ڴ��и�a��̬����node�ֽڿռ䣬�����Զ��ͷ�
	r->data=c;
	r->next=s->next;
	s->next=r;
	cout<<"����ɹ���"<<endl;
	cout<<endl;
}

void Show(List l)
{
	int i=1;
	cout<<endl;
	cout<<"���Ϊ��"<<endl;
	while(l!=NULL)
	{
		if(i==1){}
		else
		cout<<l->data;
		l=l->next;
		i++;
	}
	cout<<endl;
}

int main()
{
	List l;
	InitList(&l);//����InitList���� 
	cout<<"���������ݣ�"<<endl;
	Seq(l);//����Seq���� 
	Show(l);//���ó��ֹ��� 
	Delete(l);//����ɾ������ 
	Show(l);//���ó��ֹ��� 
	Insert(l);//���ò��빦�� 
	Show(l);//���ó��ֹ��� 
}
