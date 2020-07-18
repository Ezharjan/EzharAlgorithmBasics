/*
	姓名: 艾孜尔江·艾尔斯兰 
	学号: 17081160
	专业: 数字媒体技术 
	日期: 30/09/18 00:51
*/
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct point//使用结构体进行编写，未使用类和对象 
{
	char data;//声明字符型变量 
	struct point *next;//定义next是一个struct point类型的指针 
}*List;

void InitList(List *l)
{
	*l=(List)malloc(sizeof(List));//在内存中给a动态分配node字节空间，用完自动释放
	(*l)->next=NULL;//指针的存储单元指向空值 
}

void Seq(List l)
{
	point *s;//声明s指针为结点类型 
	char c;//声明字符型常量 
	int a=1;//声明并初始化a 
	while(a)//如果情况发生 
	{
		c=getchar();//从键盘上输入一个字符并且将字符赋给c 
		if(c!='\n')//此处表示用户在输入完一组数据后用回车键结束该项的输入，按回车退出输入 
		{
			s=(List)malloc(sizeof(List));//在内存中给a动态分配node字节空间，用完自动释放
			s->data=c;//将c的值赋给s指向的的存储单元 
			s->next=l->next;//将l指向的存储单元赋给s 
			l->next=s;
		}
		else{a=0;}//如果用户没有按回车键，则将a初始化为0 
	}
} 

void Delete(List l)
{
	point *s;
	int i,j=0;
	cout<<endl;
	cout<<"请输入删除位置："<<endl;
	cout<<endl;
	cin>>i;
	s=l;
	while(j<i-1)
	{
		if(s->next->next==NULL)//如果s从第二个开始赋为空 
		{
			cout<<"输入位置不正确！"<<endl;
			cout<<"请输入正确的位置！"<<endl;//提示用户输入有误 
			cout<<endl; 
		}
		s=s->next;
		j++;
	}
	s->next=s->next->next;
	cout<<"删除成功！"<<endl;
	cout<<endl;
}

void Insert(List l)
{
	point *s,*r;
	int i,j=0;
	char c;
	cout<<endl;
	cout<<"请输入插入位置："<<endl;
	cin>>i;
	cout<<endl;
	s=l;
	while(j<i-1)
	{
		if(s->next->next==NULL)
		{
			cout<<"输入位置不正确！"<<endl;
			cout<<endl;
		}
	s=s->next;
	j++;
	}
	cout<<endl;
	cout<<"请输入插入数据："<<endl;
	cin>>c;
	cout<<endl;
	r=(List)malloc(sizeof(List));//在内存中给a动态分配node字节空间，用完自动释放
	r->data=c;
	r->next=s->next;
	s->next=r;
	cout<<"插入成功！"<<endl;
	cout<<endl;
}

void Show(List l)
{
	int i=1;
	cout<<endl;
	cout<<"结果为："<<endl;
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
	InitList(&l);//调用InitList函数 
	cout<<"请输入数据："<<endl;
	Seq(l);//调用Seq函数 
	Show(l);//调用呈现功能 
	Delete(l);//调用删除功能 
	Show(l);//调用呈现功能 
	Insert(l);//调用插入功能 
	Show(l);//调用呈现功能 
}
