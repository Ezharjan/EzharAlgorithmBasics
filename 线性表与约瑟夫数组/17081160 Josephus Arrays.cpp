/*
	姓名: 艾孜尔江·艾尔斯兰 
	学号: 17081160
	专业: 数字媒体技术 
	日期: 29/09/18 23:59
*/
#include <iostream>
#include<cstdlib>
using namespace std;
const int Max=50;//声明固定不变的最大值，用户可根据参与容量进行改写

template <class T>//类模板，该句源于《数据结构》P60及《面向对象C++》P352 

class Josephus//使用类进行编写 
{
	private://声明私有成员
		int n,s,m;//n为游戏总人数、s为从第s个人开始报数、 m为游戏人数间隔
		T in[Max], out[Max];//声明两个数组，来分别存放进入的序列和最终出去的序列
	
	public:
	Josephus()//此处的名称必须跟上面的类名一致 
	{
		cout<<"求解约瑟夫问题"<<endl;//提示用户此程序是用来求解约瑟夫问题的 
		cout<<"请输入总人数：   "<<endl;//提示用户输入参与总人数 
  		cin>>n;//用户输入总人数 
  		cout<<"请输入起始点：   "<<endl;//提示用户输入起始报数点 
  		cin>>s;//用户输入起始报数点 
  		cout<<"请输入报数间隔： "<<endl;//提示用户输入报数间隔 
		cin>>m;//用户输入报数间隔 
		for(int i=0;i<n;i++)//给输进的数进行编号
		{
			in[i]=i+1;//因为数组中的第一个位置从0开始，故向后移一位 
		} 
	}
		void Show_in()//声明呈现输入的函数
		{
			for(int i=0;i<n;i++)//根据用户输入的数目，依次呈现报数的数目 
			{
			cout<<in[i]<<"   ";//报数之间确保有间隔以便后期方便观察 
			}
			cout<<endl;
		}
	
		void Show_out()//声明呈现输出的函数 
		{
			for(int i=0;i<n;i++)
			{
			cout<<out[i]<<"   ";
			}
			cout<<endl;
		}
		
	void Start()//声明运算的函数
	{
		int count=0,address=0,j=0;//声明并初始化计数器、地点指向和搜索器 
		s=s-1;//起始点应当是该数本身 
		while(count<n)
		{
			if(in[s]!=0)j++;//当输入的总人数不为0时，搜索器加一往后搜索 
	
			if(j==m)//如果搜索器找到间隔之后被点到的那个数
			{
				out[address]=in[s];
				in[s]=0;//再删除该数，表示该人去世
				count++;//计数器一直前进计数
				address++;//地点指向一直运作
				j=0;//第一步运作结束，赋0给搜索器，初始化搜索器 
			} 
		
			s++;//向后加一 
			if(s==n) s=0;//如果游戏结束，则初始化以停止游戏 
		}
	}
};  


int main()
{ 
	Josephus<int> A;//从类模板中直接调用 
	cout<<"开始人员序号：";
	A.Show_in(); //调用类模板中已经写好的呈现输入的函数 
	A.Start();//调用运算函数 
	cout<<"最终求解得出：";
	A.Show_out(); //调用呈现函数 
} 
