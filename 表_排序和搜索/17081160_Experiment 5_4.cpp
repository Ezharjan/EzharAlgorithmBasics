/*
	姓名:艾孜尔江·艾尔斯兰 
	学号:17081160 
	专业:数字媒体技术 
	时间: 20/12/18 21:17
	描述:实验五的第四道题 
*/

#include <iostream>
using namespace std;
 
class BsTree 
{
	public:
	 	BsTree()//构造函数初始化树根为NULL，表示空树
	 	{
	 		p_root=NULL;//声明并初始化根节点 
	 	}
    	
    	void Insert(int nData)//实现插入数据的功能 
		{
        	Insert(new Node(nData),p_root);//将数据插入其中 
    	}
		
    bool Remove(int nData)//实现删除数据的功能，如果数据不存在，则返回0
	{
        Node*& pFind=Find(nData, p_root);//声明指针型变量 
        if(pFind) 
		{
            Insert(pFind->p_Left,pFind->p_Right);//在查找前需要将节点所处存储空间指向值传入插入函数 
            Node* pNode=pFind;//声明指针Node型变量 
            pFind=pFind->p_Right;//将节点指向的值赋给查询值 
            delete pNode;//直接删除该节点 
            return 1;//存在该数据，返回1 
        }
        return 0;//不存在则返回0 
    }
    
    void Travel()//通过中序遍历呈现数据元素0 
	{
        cout<<'{';
        Travel(p_root);//递归调用 
        cout<<'}'<<endl;
    }
    
	private:
		    class Node//节点类 
			{
    			public:
        			Node(int nData)//初始化节点函数 
					{
						m_nData=nData;
						p_Left=NULL; 
						p_Right=NULL;//将各数据置空，进行初始化 
					}
        		int m_nData;//声明整型变量数据
        		Node* p_Left;//声明节点型变量左边的树
        		Node* p_Right;//声明节点型变量右边的树
    		};
    
			void Insert(Node* pNode, Node*& pTree)//实现插入功能的函数 
			{
        		if(!pTree)     pTree=pNode;//如果不是该节点则将节点的值赋给二叉树的中的数据变量 
        		else if(pNode) 
				{
            		if(pNode->m_nData<pTree->m_nData)//若节点所存储位置的值小于节点的值 
                	Insert(pNode,pTree->p_Left);//插入到二叉树中并做相应的排序比较 
            		else
                	Insert(pNode,pTree->p_Right);//否则将节点和二叉树所指向的存储位置传给实现以插入 
        		}
    		}
    
			Node*&Find(int nData,Node*& pTree) //实现查找功能 
			{
        		if(!pTree)//如果不是二叉树中的数据元素 
       			return pTree;//返回二叉树中原来的数值 
        		
				else
        		if(nData==pTree->m_nData)//否则将存储空间指向的数值赋给数据元素 
            	return pTree;//再返回数值 
        		
				else
        			if(nData<pTree->m_nData)//若数据元素的值是小于二叉树中所指向的数据值 
            		return Find(nData,pTree->p_Left);
					//将左子树的值传入查找函数中查找并返回查找后的结果 
        			else
            		return Find(nData,pTree->p_Right);
					//将右子树的值传入查找函数中查找并返回查找后的结果 
    		}
    
			void Travel(Node*& pTree)//遍历后输出相应的结果给用户呈现 
			{
        		if(pTree) 
				{
            		Travel(pTree->p_Left);//将左节点的值使用递归调用的方式传给遍历函数本身 
            		cout<<'<'<<pTree->m_nData<<'>'; //呈现 
            		Travel(pTree->p_Right);//将右节点的值使用递归的方式传给便利函数本身 
        		}
    		}
    Node* p_root;//声明节点型指针变量树根
};


int main() 
{

	int Maxsize=0;//初始化数据容量大小 
	cout<<"请输入容量大小："<<endl;
	cin>>Maxsize;//用户输入相应的容量大小 
    int a[Maxsize];//声明以用户所输入的容量大小为界的相应的数组变量 
    BsTree A;//声明变量A 
    
	for(int i=0;i<Maxsize;i++)//通过循环让用户自己输入相应的数组中的元素 
    {
    	cout<<"请输入要插入的数据：" ;
		cin>>a[i];//用户输入 
		A.Insert(a[i]);//将输入的元素传给插入函数中以实现数组中每个元素的输入 
	}
	A.Travel ();//将所输入的元素通过遍历的方式呈现出来 
	
	int remove=0;//声明并初始化删除位置变量 
    cout<<"请输入欲删除元素的位置：";
	cin>>remove;//用户输入所要删除的位置 
	if(remove<=Maxsize)
	{
		A.Remove(remove);//将所要铲除的位置的值赋给二叉树中的变量 
		A.Travel();//将所输入的元素通过遍历的方式呈现出来 
		cout<<endl;
	}
		else cout<<"输入数据位置超出范围，请重新输入！"<<endl<<endl; 
			
		cout<<"请添加数据元素："<<endl;
		int x;
		cout<<"要输入的元素个数：";
		cin>>x;
		for(int i=0;i<x;i++)//如果用户想继续插入数据，可以直接根据相应提示插入 
		{
			cout<<"请输入要插入的数据：" ;
			cin>>a[i];//将循环插入数据 
			A.Insert(a[i]);//将所插入的数据传递给插入函数 
		}
		A.Travel();//将所输入的元素通过遍历的方式呈现出来 
    return 0;
}
