/*
	姓名: 艾孜尔江·艾尔斯兰 
	学号: 17081160
	专业: 数字媒体技术 
	日期: 28/09/18 17:32
*/
#include<cstdlib>//为下文使用malloc函数所引出该头文件 
#include<iostream>
using namespace std;
  
typedef struct node 
{
    int data;    
	struct node *next;
}node, *LinkList;
 
void Input(LinkList &a,int n) 
{
    a=(node*)malloc(sizeof(node)); //在内存中给a动态分配node字节空间，用完用free函数进行释放 
	//这里使用到malloc函数,malloc函数被调用时，
	//它会沿空闲链表寻找一个可以满足需求的内存块，
	//然后把所需大小的内存块分配给用户，剩下的返回到链表上。 
	//因为malloc返回的是不确定类型的指针，因此返回前必须经过类型的强制转换。 
    node *p=a,*q;//地址交换 
    cout<<"开始人员序号为："; 
    for(int i=0;i<n-1;i++)//循环做自加运算 
	{
       	p->data=i+1;//将i+1赋给p指针所在存储单元的值 
       	q=(node*)malloc(sizeof(node));//把返回类型void*强制转换为node* 
       	//(sizeof(node)获取node类型所占足空间的大小 
       	p->next=q;//将q赋给p指向下一个存储单元的值 
       	p=q;//交换 
		cout<<i+1<<"  ";//呈现输入的序列 
    }
    cout<<""<<n<<endl;//呈现输入的序列    	
    p->data=n;//将n的值赋给p指针所在存储单元的值 
    p->next=a;//将a的值赋给p指针谁在存储单元的值 
 }
 
 void Josephus(LinkList &a,int s,int m)//插入功能 
{
    node *nowPoint=a,*prePoint=a;//将地址进行赋值 
    cout<<"最终求解得出：  ";//呈现结果 
    while (nowPoint->next!=nowPoint)//如果结点指向的下一个存储单元地址不是结点本身 
	{ 
		for(int i=0;i<s-1;i++)//循环做自加运算 
			{
       			prePoint=nowPoint;//将现在的结点赋给先前的结点的值 
       			nowPoint=nowPoint->next;//将现在的结点值赋给现在结点指向的下一个存储单元 
    		}
    	prePoint->next=nowPoint->next;//将下一个存储单元的现时结点赋给前一个结点的位置 
    	cout<<nowPoint->data<<"  ";//呈现结点的数 
    	free(nowPoint);//释放内存空间，于上方的malloc相对应 
    	nowPoint=prePoint->next;//先前的结点单元指向现时的结点 
    }
}

int main()   
{
    int n,m,s;//声明总人数，间隔数和其实点 
    LinkList a;//声明开始值 
    
	cout<<"求解约瑟夫问题  "<<endl; 
    cout<<"请输入总人数：  "<<endl;
    cin>>n;
    cout<<"请输入起始点："<<endl;
    cin>>s;
	cout<<"请输入报数间隔：  "<<endl;
    cin>>m;
    Input(a,n);//调用相应的输入函数 
    Josephus(a,s,m);//运算后呈现求得的最终结果 
     
    return 0;
}
