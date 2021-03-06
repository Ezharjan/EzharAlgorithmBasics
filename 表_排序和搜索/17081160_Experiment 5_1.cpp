/*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	时间: 10/12/18 20:07
	描述:实验五的第一道题 
*/

#include <iostream>
using namespace std;

int Search(int a[],const int low,const int high,int x)//实现折半搜索的函数，函数内传入四个变量�		 
{
   int t=0;//将最后要求得的值进行初始化 
   if(low<=high)//当最后low==high时，表示搜索成功，返回t，如果未找到则返回t=0
   {
    	t=(low+high)/2;//将运算后的值赋给t 
    	if(a[t]<x)          {t=Search(a,t+1,high,x);}//如果数组中的数值小于x，则向后进行查找 
    	else if(a[t]>x)     t=Search(a,low,t-1,x);//如果数组中的数值大于x，则向前进行查找 
   }
   return t;//返回t
}

int main()
{
	int b;//声明最大容量
	cout<<"请输入表的容量："<<endl; 
	cin>>b;//用户输入最大容量 
	int *Maxsize=new int[b];//声明动态数组，让用户输入数组中的数据 
	for(int i=0;i<b;i++)//根据用户自己给定的容量，用户相应地输入数组中的数据 
	{
		cout<<"请输入第"<<i+1<<"个位置处的数字："<<endl;//提示用户输入数据 
		cin>>Maxsize[i];//用户输入数组中个各个数据 
	}
    int x;//声明未知整型变量，用于用户输入需要查找的数据
	cout<<endl; 
	cout<<"输入要查找的数字:";
 	cin>>x;//用户输入需要查找的数据 
 	int k=Search(Maxsize,0,b,x);//将用户所输入的数据传到搜索函数中并将搜索函数所得到的返回值赋给k 
 	if(k==0) cout<<"数据中不存在元素"<<x<<"!请重新输入欲搜索的数据！"<<endl;
	 //为便于函数进行相应的判断，若K 是0，据前所述未查到 
 	else//若但会值的不是0，则呈现用户该元素所处的具体位置 
 	cout<<x<<"的位置在顺序表的第"<<k+1<<"处。"<<endl;
}


