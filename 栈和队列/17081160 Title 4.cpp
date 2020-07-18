/*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	日期: 21/10/18 23:30 
	描述:编写中缀表达式转换后缀表达式的程序 
*/
#include <cstring> 
#include <iostream> 
#include <cstdlib> 
#define MaxSize  10 
using namespace std;  

 
typedef struct 
{
	char *base;//指向队列的存储空间； 
 	int front;//指向队头元素； 
 	int rear;//指向队尾元素的下一位置； 
}SqQueue;//声明结顺序队列存储构体 
 
typedef struct LNode 
{ 
 	int data; 
 	struct LNode *next; 
}Snode,*LinkStack; //据网络资料得知，此处表示给自定义的数据类型起新的名字 
 
 
void DestroyLinStack(LinkStack &S)//销毁链栈S
{ 
	LinkStack temp=S,p; 
 	while(temp) 
 	{ 
  		p=temp;   
  		temp=temp->next; 
  		free(p); 
 	} 
} 
 
void Push(LinkStack &S,  char x)//入栈
{ 
	LinkStack temp=(LinkStack )malloc(sizeof(Snode )); 
 	temp->data=x; 
 	temp->next=S->next; 
 	S->next=temp; 
} 
 
void Pop(LinkStack &S, char &x)//出栈
{ 
 	LinkStack temp=S->next; 
 	x=temp->data; 
 	S->next=temp->next; 
 	free(temp); 
} 
 
int GetTop(LinkStack &S)//读栈顶元素 
{  
 	int x; 
 	if(S->next) 
  	x=S->next->data; 
 	else 
  	cout<<"栈空！"<<endl; 
 	return x; 
 
} 
 
void Initstack(LinkStack &S)//初始化链栈 
{ 
 	S=(LinkStack )malloc(sizeof(Snode )); 
 	if(!S) 
 	{ 
  		cout<<"错误！！"<<endl; 
  		exit(1); 
 	} 
 	S->next=0; 
} 
 
 
int InitQueue(SqQueue &Q)//队列的初始化 
{
 	Q.front=Q.rear=0; 
 	Q.base=(char *)malloc(MaxSize*sizeof(char)); 
 	if(!Q.base) 
  	exit(1); 
 	Q.base[Q.front]='\0'; 
 	return 1; 
} 
 
int QueueLength(SqQueue Q) //计算队列的长度
{
 	return (Q.rear-Q.front+MaxSize)%MaxSize; 
} 
 
void EnQueue(SqQueue &Q, char x)//入队
{  
 	if(QueueLength(Q)==MaxSize) 
 	{ 
  		cout<<"输入有误！"<<endl; 
 	} 
 	Q.base[Q.rear++]=x; 
} 
 
 
void DispQueue(SqQueue Q)//输出队列的所有元素
{ 
 	int i=0,j=Q.front; 
 	while(i<QueueLength(Q)) 
 	{ 
  		cout<<Q.base[j]; 
  		j++; 
  		i++; 
 	} 
} 
 
void DestroyQueue(SqQueue &Q)//队列的销毁 
{ 
 
 	delete []Q.base; 
 	Q.base=0; 
 	Q.front=Q.rear=0;
} 
 
 
int StackEmpty(LinkStack S)//判断栈是否为空 
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
 
void convertpostexp(char *str,SqQueue &post)//嵌套上述功能函数于其中，实现转化功能 
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
 	char str[MaxSize]; //声明字符型变量数组 
 	cout<<"请注意将输入法改成英文状态！"<<endl; 
 	cout<<"请输入计算表达式并以分号结束："<<endl; 
 	cin>>str; 
 	convertpostexp(str,post); 
 	cout<<"转换成后缀表达式是:"<<endl; 
 	DispQueue(post); 
 	cout<<endl; 
 	DestroyQueue(post); 
}
