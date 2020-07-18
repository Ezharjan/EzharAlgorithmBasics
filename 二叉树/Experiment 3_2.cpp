/*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	时间: 2/11/18 00:55
	描述:实验三第二题 
*/

#include <iostream>
#include<cstring>//为后续使用到的strlen()函数做铺垫 
#include<stack>//为后续直接调用栈来存储数据做铺垫 
#include<malloc.h> //动态分配内存空间函数头文件
#define MAXSIZE 30//用户可以根据需求字符串长度，这里定义最大长度为30 
using namespace std;

typedef struct node//声明结构体节点 
{
    char x;//声明二叉树内部的数据常量为字符型
    struct node *left_child,*right_child;//使用结构体声明二叉树的结构，左孩子和右孩子
}Bitree;//二叉树的结构 

void creat_Bitree(char *s,Bitree *&root)//创建二叉树，声明字符型常量s为 
{
    int i=1;//声明并初始化整型变量i 
    bool t=0;//声明布尔型变量t，用来判断从右边开始的字符 
    stack<Bitree*> m;//直接调用栈函数用来存放结点，节点类型是Bitree类型 
    stack<char> n;//直接调用栈函数存放分隔符，该用法得益于栈的头文件 
    Bitree *p,*q;//声明p指针和q指针变量，其中q作为临时存储数据而存在 
    root->x=s[0];//将存储空间传给数组中的第一个元素 
    root->left_child=NULL;//将左孩子初始化为空 
    root->right_child=NULL;//将有孩子初始化为空 
    m.push(root);//压入根节点，入栈 
     
    while(i<strlen(s))//strlen()函数所作的仅仅是一个计数器的工作，
	//它从内存的某个位置开始扫描;
	//可以是字符串开头，中间某个位置，甚至是某个不确定的内存区域。 
	//直到碰到第一个字符串结束符'\0'为止，然后返回计数器值(长度不包含"\0")。
	//这里表示当i小于字符串长度时进行循环 
    {
        if(s[i]=='(')//如果字符串数组s[i]输入的是右括弧 
        {
            n.push(s[i]);//调用压入栈的函数 
            t=0;//令右边指向的布尔型变量t为假 
        }    
        else if(s[i]==',')//如果字符串数组s[i]输入的是逗号    
        {
            t=1;//令右边指向的布尔型变量为真 
        }
        else if(s[i]==')')//如果字符串数组s[i]输入的是左括弧
        {
            m.pop();//根节点出栈 
            n.pop();//根节点出栈 
        }
        else if(isalpha(s[i]))//C/C++内部的功能函数；
		//判断字符是否为英文字母；
		//若为英文字母，返回非0:若为小写字母则返回为2；若为大写字母则返回1。
		//若不是字母，返回0。
        {
            p=(Bitree *)malloc(sizeof(Bitree));//动态分配存储空间，空间大小为Bitree 
            p->x=s[i];//将p的存储空间传给字符型数组 
            p->left_child=NULL;//初始化左孩子为空 
            p->right_child=NULL;//初始化右孩子为空 
            q=m.top();//调用出栈函数并将出栈的顶部元素赋给q 
            if(t==1)//如果在右边的情况是真的    
            {
                q->right_child=p;//将p的值赋给q指向的右孩子存储空间
				cout<<"       ";  
                cout<<q->x<<"的右孩子是"<<s[i]<<endl;//输出右孩子节点的值 
            }
            else//如果不在右边 
            {
                q->left_child=p;//将p的值赋给q指向的左孩子存储空间
				cout<<"       "; 
                cout<<q->x<<"的左孩子是"<<s[i]<<endl;//输出左孩子节点的值 
            }
            if(s[i+1]=='(')//如果后一个输入的为右括弧 
                m.push(p);//执行出栈功能，调用出栈函数 
        }
        i++;//i做自加运算以保证可以连续不停地输入 
    }    
}

void inOrder_recursion(Bitree *root)//递归中序遍历
{
	if(root!=NULL)//如果根节点部位空 
    {
        inOrder_recursion(root->left_child);//递归调用，左孩子节点进入 
        cout<<root->x<<" ";//输出x 
        inOrder_recursion(root->right_child);//递归调用，右孩子节点进入 
    }
} 

int Nodes(Bitree *root)//求所有节点个数的算法 
{   
	int num1,num2;//声明两个变量 
    if(root==NULL)//如果根节点为空 
	return 0;//返回0 
    else  return Nodes(root->left_child)+Nodes(root->right_child)+1;//否则返回节点个数 
}//此程序习得于课程中的PPT第二节 


int main()
{
    char s[MAXSIZE];//声明字符串数组 
    cout<<"请输入形如A(B,C(D,E))形式的字符串，并按回车结束！" <<endl; 
    if(scanf("%s",s)==1)
    //scanf()函数返回的是此函数读取到的参数个数。
    //当scanf("%s",s)正常读取到一个字符串时
	//（不论串的长短如何），scanf()函数的值总是1。这是c++里自带的一个函数。 
    {
		Bitree *root=(Bitree *)malloc(sizeof(Bitree));//动态分配存储空间
        creat_Bitree(s,root);
        cout<<"       ";//为界面美观起见
        cout<<"递归方式输出的中序遍历为：  ";
        inOrder_recursion(root);//递归调用方式
		cout<<endl; 
		cout<<"       "<<"总结点个数为："<<Nodes(root)<<"个。"<<endl;//输出节点数 
    }
    return 0;
}
