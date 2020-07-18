/*
	����:���ζ���������˹�� 
	ѧ��:17081160 
	רҵ:����ý�弼�� 
	����: 21/10/18 23:30 
	����:��д��׺���ʽת����׺���ʽ�ĳ��� 
*/
#include <cstring> 
#include <iostream> 
#include <cstdlib> 
#define MaxSize  10 
using namespace std;  

 
typedef struct 
{
	char *base;//ָ����еĴ洢�ռ䣻 
 	int front;//ָ���ͷԪ�أ� 
 	int rear;//ָ���βԪ�ص���һλ�ã� 
}SqQueue;//������˳����д洢���� 
 
typedef struct LNode 
{ 
 	int data; 
 	struct LNode *next; 
}Snode,*LinkStack; //���������ϵ�֪���˴���ʾ���Զ���������������µ����� 
 
 
void DestroyLinStack(LinkStack &S)//������ջS
{ 
	LinkStack temp=S,p; 
 	while(temp) 
 	{ 
  		p=temp;   
  		temp=temp->next; 
  		free(p); 
 	} 
} 
 
void Push(LinkStack &S,  char x)//��ջ
{ 
	LinkStack temp=(LinkStack )malloc(sizeof(Snode )); 
 	temp->data=x; 
 	temp->next=S->next; 
 	S->next=temp; 
} 
 
void Pop(LinkStack &S, char &x)//��ջ
{ 
 	LinkStack temp=S->next; 
 	x=temp->data; 
 	S->next=temp->next; 
 	free(temp); 
} 
 
int GetTop(LinkStack &S)//��ջ��Ԫ�� 
{  
 	int x; 
 	if(S->next) 
  	x=S->next->data; 
 	else 
  	cout<<"ջ�գ�"<<endl; 
 	return x; 
 
} 
 
void Initstack(LinkStack &S)//��ʼ����ջ 
{ 
 	S=(LinkStack )malloc(sizeof(Snode )); 
 	if(!S) 
 	{ 
  		cout<<"���󣡣�"<<endl; 
  		exit(1); 
 	} 
 	S->next=0; 
} 
 
 
int InitQueue(SqQueue &Q)//���еĳ�ʼ�� 
{
 	Q.front=Q.rear=0; 
 	Q.base=(char *)malloc(MaxSize*sizeof(char)); 
 	if(!Q.base) 
  	exit(1); 
 	Q.base[Q.front]='\0'; 
 	return 1; 
} 
 
int QueueLength(SqQueue Q) //������еĳ���
{
 	return (Q.rear-Q.front+MaxSize)%MaxSize; 
} 
 
void EnQueue(SqQueue &Q, char x)//���
{  
 	if(QueueLength(Q)==MaxSize) 
 	{ 
  		cout<<"��������"<<endl; 
 	} 
 	Q.base[Q.rear++]=x; 
} 
 
 
void DispQueue(SqQueue Q)//������е�����Ԫ��
{ 
 	int i=0,j=Q.front; 
 	while(i<QueueLength(Q)) 
 	{ 
  		cout<<Q.base[j]; 
  		j++; 
  		i++; 
 	} 
} 
 
void DestroyQueue(SqQueue &Q)//���е����� 
{ 
 
 	delete []Q.base; 
 	Q.base=0; 
 	Q.front=Q.rear=0;
} 
 
 
int StackEmpty(LinkStack S)//�ж�ջ�Ƿ�Ϊ�� 
{
 	return (S->next==0); 
} 
 
int Priority(char oper) 
{ 
 	switch(oper) 
 	{ 
 		case '(': 
  		return 0; 
		case '+': 
 		case '-': 
  		return 1; 
 		case '*': 
 		case '/': 
  		return 2; 
 	} 
} 
 
void convertpostexp(char *str,SqQueue &post)//Ƕ���������ܺ��������У�ʵ��ת������ 
{ 
 	char c,t; 
 	int i=0,k=strlen(str); 
 	LinkStack S; 
 	Initstack(S); 
 	Push(S,'('); 
 	InitQueue(post); 
 	while(i<k || !StackEmpty(S)) 
 	{ 
  		c=*str++; 
  		switch(c) 
  		{ 
  			case '0': 
  			case '1': 
  			case '2': 
  			case '3': 
  			case '4': 
  			case '5': 
  			case '6': 
  			case '7': 
  			case '8': 
  			case '9': 
   			EnQueue(post, c); 
   			break; 
  			case '(': 
   			Push(S,c); 
   			break; 
  			case ')': 
  			case ';': 
   			do
			{ 
    			Pop(S,t); 
    			if(t!='(') 
     			EnQueue(post, t); 
   			}while(t!='(' && !StackEmpty(S)); 
   			break; 
  			case '+': 
  			case '-': 
  			case '*': 
  			case '/': 
   			while(Priority(c)<=Priority(GetTop(S))) 
   			{ 
    			Pop(S,t); 
    			EnQueue(post, t); 
   			} 
   			Push(S,c); 
   			break; 
  		} 
		i++; 
	} 
	DestroyLinStack(S); 
} 
 
 
int main() 
{ 
 	SqQueue post; 
 	char str[MaxSize]; //�����ַ��ͱ������� 
 	cout<<"��ע�⽫���뷨�ĳ�Ӣ��״̬��"<<endl; 
 	cout<<"�����������ʽ���ԷֺŽ�����"<<endl; 
 	cin>>str; 
 	convertpostexp(str,post); 
 	cout<<"ת���ɺ�׺���ʽ��:"<<endl; 
 	DispQueue(post); 
 	cout<<endl; 
 	DestroyQueue(post); 
}
