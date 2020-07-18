 /*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	时间: 11/11/18 00:21
	描述:实验三第三题 
*/

#include<iostream>
#define MAXSIZE 256
using namespace std;

typedef string *STR;//声明结构体字符串指针 

typedef struct HNode//结构体声明 
{
	unsigned freq;//声明无符号的频率变量 
	bool add;//判断是否加入Huffman树
	int left_child,right_child;//声明整型的左、右孩子节点 
	
	void Init(unsigned &e,int L=-1,int R=-1, bool input=0)//初始化函数 
	{//在结构体中定义一个空函数，内部分别有无符号的变量、整型变量和布尔型变量 
		freq=e;//将无符号变量e赋给频率变量以初始化 
		left_child=L;//将左节点的空值赋给左孩子节点以初始化 
		right_child=R;//将右节点的空值赋给右孩子节点以初始化 
		add=input;//将加入进去的内容进行初始化 
	} 

	HNode()//哈夫曼树的节点函数也做初始化 
	{
		freq=0;//初始化出现频率 
		add=0;//初始化加入的量 
		left_child=-1;//将左孩子节点初始化指向最底部 
		right_child=-1;//将有孩子节点初始化指向最底部 
	}
}*HuffTree;//以上内容时指针HuffTree的内部结构 


void INcode(HuffTree &node,int &k,STR &Code,string &s,
            int i,int leaf,unsigned *G)//声明并定义输入函数 
{
	if (k<leaf)//若K的值小于叶子结点的值 
	{
		Code[G[k]]=s.substr(0,i);//substr是C++里自带的复制子字符串的函数
			return;//必须加上返回，否则无法执行相应的传值操作，运行将无法继续 
	}
	s[i]='0';//编码中的数字为零和壹，故将0赋给字符串数组 
	INcode(node,node[k].left_child,Code,s,i+1,leaf,G);//递归调用，将新的量传递进入自身 
	s[i]='1';//编码中的数字为零和壹，故将1赋给字符串数组
	INcode(node,node[k].right_child,Code,s,i+1,leaf,G);//递归调用 
}

void Searcher(HuffTree &node,int n,int &fir,int &sec)//搜索函数 
{//搜索出现频率最低的节点 
	unsigned Minimal;
	for (int k=0;k<2;k++)
	{
		Minimal=100;//随意赋值给最小出现量 
		int t=0;//初始化 
		
		for(int i=0;i<n;i++)//i在0到n范围内做自加运算 
		{
			if(node[i].add)continue;//调用增加节点的量，如果在树中增加新的节点，则继续 
			if (node[i].freq<Minimal)//如果出现频率少于最少出现次数 
			{
				Minimal=node[i].freq;//将频率的值赋给 
				t=i;//将计数器的值传给t 
			}
		}
		
		node[t].add=1;//调用增加情况为真 
		if(k==0) fir=t;//将t中计数器的值赋给第一个节点 
		else     sec=t;//其余情况则赋给第二个节点 
	}
}

void Creat(HuffTree &node,unsigned *G,int &num)//声明和定义创建树的空函数 
{
		int i;
		for(i=0;i<num;i++)//计数器在0和num之间进行自加运算 
		{ 
			node[i].Init(G[i]);//调用初始化函数使内部置空 
		}	
		for (i=num;i<2*num-1;i++)//计数器将从num开始一直做自加运算到两倍的num减一 
		{
			int x,y;//声明整型变量x和y 
			Searcher(node,i,x,y);//使用查找函数并将节点的值、计数器的值和x、y的值传入 
			unsigned e=node[x].freq+node[y].freq;//将e进行初始化，表示其节点数目 
			node[i].Init(e,x,y);//调用初始化函数使其内部元素为新的量 
		}
}

void HFM(string &input, STR &Code, int &n)//声明并定义实现编码解码的空函数 
{
	unsigned FEQ[MAXSIZE]={0},G[MAXSIZE]={0};//声明并初始化成组数据和频率数据 
	unsigned M[MAXSIZE];//声明内部运算的量为无符号的 
	int i,num=0;//声明并对计数器和数值初始化 
	for(i=0;i<n;i++)//在0到n之间做自加运算 
		FEQ[(input[i]+256)%256]++;//根据网络提示，出现的频率在编码时需队输入的数字
		//相加后与256进行取余操作并在此基础上进行自加运算 
	for(i=0;i<MAXSIZE;i++)//计数器在0到最大容量的范围内进行自加运算 
	{
		if (FEQ[i])//出现频率的数组 
		{
			G[num]=i;//记录节点中所存的字符代码
			M[num++]=FEQ[i];//将频率数组的值赋给输入值存储数组 
		}
	}
	HuffTree Node=new HNode[2*num-1];
	Creat(Node,M,num);//函数内部调用以将输入的值传给函数 
	Code=new string[MAXSIZE];//编码时使用心得存储字符串数组 
	string STR;//声明字符串型的变量 
	STR.resize(MAXSIZE);//C++内部string类中的函数，以调整源字符串长度为n 
	int nod=2*num-2;//将运算好的值赋给节点 
	INcode(Node,nod,Code,STR,0,num,G);//函数内部调用输入函数以将新的值传递给内部变量 
	cout<<"输入的字符总数为："<<num<<endl;//呈现输入字符总数 
	//cout << "字符序号"<< "出现频率"<<endl;
	for(i=0;i<num;i++) cout<<"第"<<i+1<<"个字符出现了"<<M[i]<<"次！"<<endl;
	
	cout<<"该串字符对应的编码如下："<<endl;
	for(i=0;i<n;i++)   cout<<Code[(input[i]+256)%256];//呈现编好的码 
	cout<<endl;//由于编码时会调用code函数循环对每一个都循环进行，故需要重新输出一个换行 
	cout<<"请将解码字符按照格式输入:"<<endl;
	string add;//声明字符串变量，因为我们在前面已经定义过1和0是字符型 
	cin>>add;//输入解码的字符串，按照0和1输入 

	int k=2*num-2;//声明并初始化变量k 
	string Display;
	for(i=0;i<=add.length();i++)//在长度范围内循环自加 
	{
		if(k<num)//如果小于字符数目 
		{
			char s=(char)G[k];//将数组中的元素强行转换为字符型 
			Display+=s;//输出的值为s加自身 
			k=2*num-2;//k的值改变 
		}
		if      (add[i]=='0')    k=Node[k].left_child;//如果输入的是0，则左孩子的值赋给k 
		else if(add[i] =='1')	k = Node[k].right_child;//如果是1，在将右孩子的值赋给k 
	}
	cout<<"哈夫曼树解码结果如下："<<endl;
	cout<<Display<<endl;//呈现解码结果 
}

int main()
{
	string add;//声明输入的变量为字符串 
	string *Code;//声明指针型输入码 
	cout<<"请输入需要编码的字符：";
	cin>>add;//用户输入字符 
	int num=add.length();//将字符串长度赋给num以便后续输出次数时使用 
	HFM(add, Code, num);//由于主要的编码过程均在HFM函数中已经调用过
					   //此处直接只调用HFM函数即可，并将用户输入的值传入其中以实现编码 
}
