/*
	学号:17081160 
	姓名:艾孜尔江·艾尔斯兰 
	专业:数字媒体技术 
	时间: 01/12/18 00:58
	描述:实验四的第一题 
*/
#include<iostream>
#include<cstdlib>
#define OVERFLOW -2//定义溢出为-2 
#define MAX 10//定义最大值为10 
using namespace std;

typedef struct Node//定义结构体 
{
 	int elem;//声明整型变量 
 	struct Node *next;//用定义的结构体声明next指针 
}Node,*QNode;//定义为节点以及队列中的节点指针 

typedef struct
{
	QNode front;//队列中的首节点 
	QNode rear;//队列中的尾节点 
}Queue;//定义队列的结构体 


typedef struct ArcNode//头节点作为弧的结构体来表示 
{
 int top_v;//该边所指向的顶点的位置
 struct ArcNode *nextarc;//指向下一条边
}ArcNode;//定义头结点作为弧度的结构体 

typedef struct VNode//表节点
{
	int data;//顶点信息
 	ArcNode *firstarc;//指向第一条依附该节点的边的指针
}VNode,AdjList[MAX];//用结构体定义表节点和邻接表数组 

typedef struct
{
	AdjList vertices;//表节点
	int node_num;//声明节点的个数
 	int edge_num;//声明边的条数
}Graph;//定义图的结构体 

int InitQueue(Queue *Q)//实现初始化队列的功能函数 
{
	Q->front=Q->rear=new Node;//指向头结点的存储空间和指向尾节点的存储空间赋予新的节点存储空间 
	if(!Q->front)  exit(OVERFLOW);//当队列的头部存储空间未指向头结点，则溢出 
 	Q->front->next=NULL;//将置空头结点指向的的下一个节点 
 	return 1;//返回值为真 
}

int Acces_Que(Queue *Q,int e)//实现入队操作的功能函数 
{
	QNode p=new Node; //将p节点的存储空间初始化使其指向一个动态存储空间 
 	if(!p) exit(OVERFLOW);//如果p未指向，则表示溢出 
 	p->elem=e;//将e的值赋给p指向的元素 
 	p->next=NULL;//p想下一个节点置空 
 	Q->rear->next=p;//将p赋给尾节点的下一个节点 
 	Q->rear=p;//将p赋给队列中的尾节点 
 	return 1;//返回值为真 
}

int Out_fr_Que(Queue *Q,int *e)//实现出队操作的功能函数 
{
	QNode p;//声明队列中中的变量p 
 	p=Q->front->next;//将队列中首节点指向的下一个节点的值赋给p 
 	Q->front->next=p->next;//将p指向的下一个节点的值赋给首节点所指向的下一个节点值 
 	if(Q->rear==p)  Q->rear=Q->front;//若队列中尾节点的值等于p的值，则队列中的首节点的值赋给尾节点 
 	*e=p->elem;//将p所指向的下一个元素的值和地址赋给指针e 
 	return 1;//返回值为1 
}

int QueueEmpty(Queue Q)//写出队空的条件，当下列情况发生时，队列或空或非空 
{
	if(Q.rear==Q.front)  return 1;//若队列中首节点等于尾节点，返回真 
 	else                 return 0;//否则返回假 
}

int Locate_node(Graph *G,int v)//通过该函数来返回节点v在图中的位置
{
	int i;//声明整型计数器 
 	for(i=0;i<G->node_num;++i) 
	{
	 	if(G->vertices[i].data==v)  break;//若所有点数组内部的数据值等于节点的值，跳出循环 
   		else                     continue;//否则继续执行 
	}
 	if(i<G->node_num)             return i;//当计数器的值等于图所指向的节点的值 ，返回i的值，定位成功 
 	else                          return -1;//否则返回-1 
}

int CreateGraph(Graph *G)//以邻接表形式创建无向连通图G
{
	int m,n,i,j,k,v1,v2,flag=0; 
 	ArcNode *p1,*q1,*p,*q;//声声明相应的指针、顶点值和计数器等 
 	cout<<"请输入顶点数："; 
 	cin>>m;//用户按照提示输入 
 	cout<<"请输入边数：  ";
 	cin>>n;
 	G->node_num=m;//顶点数目
 	G->edge_num=n;//边的数目
 	
	 for(i=0;i<G->node_num;++i)
 	{
   		G->vertices[i].data=i+1;//顶点信息
   		G->vertices[i].firstarc=NULL;//将量顶点间的第一个弧置空 
 	}
    cout<<"输出顶点的信息： "<<endl; 

 	for(i=0;i<G->node_num;++i)     cout<<"顶点"<<G->vertices[i].data<<endl<<endl;
	 //前面的顶点一定，后面的数据根据用户输入的点数通过数组中计数的形式不断增加，用户不必手动输入顶点 
	for(k=0;k<G->edge_num;++k)
 	{
   		cout<<"请输入"<<k+1<<"条起始顶点结束顶点，用空格隔开："; 
   		cin>>v1>>v2;//用户根据提示进行输入，并用空格隔开 
   		i=Locate_node(G,v1);//将途中节点的值和输入的值传给定位函数进行运算并将运算所得到的结果赋给i 
   		j=Locate_node(G,v2);//将途中节点的值和输入的值传给定位函数进行运算并将运算所得到的结果赋给j 

   		if(i>=0&&j>=0)//若i大于0并且j也大于0 
   		{
   	 		++flag;//标记量做自加运算 
     		p=new ArcNode;//将弧的新动态空间赋给p 
     		p->top_v=j;//将j的值赋给p指向的顶部点 
     		p->nextarc=NULL;//将下一个边置空 
     		
			if(!G->vertices[i].firstarc)
  			G->vertices[i].firstarc=p;
     		else
    		{
      		for(p1=G->vertices[i].firstarc;p1->nextarc;p1=p1->nextarc);
      		p1->nextarc=p;
    		}

    		q=new ArcNode;
     		q->top_v=i;
     		q->nextarc=NULL;
     		if(!G->vertices[j].firstarc)
  			G->vertices[j].firstarc=q;
     		else
    		{
 				for(q1=G->vertices[j].firstarc;q1->nextarc;q1=q1->nextarc);
          		q1->nextarc=q; 
    		}//以上代码原理同上
   		}
   		else
   		{
    		cout<<"输入有误！没有这样的边！请重新输入！" <<endl;
    		k=flag;//标记器自加后得到的某个值赋给k 
   		}

 	}

}

int Firsttop_v(Graph G,int v)//返回v的第一个邻接顶点
{
	if(G.vertices[v].firstarc)    return G.vertices[v].firstarc->top_v;
 	else                          return -1;
}

int Nexttop_v(Graph G,int v,int w)//返回v中相对于w的下一个邻接顶点
{
 	int flag=0;
 	ArcNode *p; 
 	p=G.vertices[v].firstarc;
 	while(p)//当p成立时 
 	{
   		if(p->top_v==w)
   		{
    		flag=1;
    		break;
   		}
   	p=p->nextarc;//将p所指向的下一个边的值赋给p 
 	}
 	if(flag&&p->nextarc)			return p->nextarc->top_v;
 	else							return -1;
}

int Visited[MAX];

void DFS(Graph G,int v)//深度优先遍历进行输出 
{
	int w;
 	Visited[v]=1;
    cout<<"顶点"<<G.vertices[v].data<<"  ";
 	for(w=Firsttop_v(G,v);w>=0;w=Nexttop_v(G,v,w))    if(!Visited[w])    DFS(G,w);
	//若顶点w未被访问，函数递归调用以实现深度优先遍历 
}


void DFSTraverse(Graph G)//深度优先遍历输出 
{
 	int v;
 	for(v=0;v<G.node_num;++v)Visited[v]=0;
 	for(v=0;v<G.node_num;++v)   if(!Visited[v])   DFS(G,v); //函数内嵌套如上一个函数 
}

void BFSTraverse(Graph G)//广度优先遍历
{
 	int v,v1,w;
 	Queue q;//定义一个队列
 	
 	for(v=0;v<G.node_num;++v)
   	Visited[v]=0;//若顶点没有被访问过 
 	InitQueue(&q);//初始化队列
 	
 	for(v=0;v<G.node_num;++v)
   	if(!Visited[v])
   	{
    	Visited[v]=1;
    	cout<<"顶点"<<G.vertices[v].data<<"  ";
    	Acces_Que(&q,v);//将第一个顶点入队
    	while(!QueueEmpty(q))//判断对是否为空，若=队不是空的，则执行以下循环 
    	{
     		Out_fr_Que(&q,&v1);//第一个顶点出对
     		for(w=Firsttop_v(G,v1);w>=0;w=Nexttop_v(G,v1,w))
      		if(!Visited[w])//若没有被访问过 
      		{
       			Visited[w]=1;//复位至访问过为真 
       			cout<<"顶点"<<G.vertices[w].data<<"  ";//输出顶点的名称 
       			Acces_Que(&q,w);//将w入队 
      		}
    	}
   }
}

int main()
{
	Graph G;//声明图 
 	CreateGraph(&G);//创建图 
 	cout<<endl;
 	cout<<"深度优先搜索的结果是：";
 	DFSTraverse(G);//调用深度优先遍历的功能函数 
 	cout<<endl; 
 	cout<<"广度优先搜索的结果是：";
 	BFSTraverse(G);//调用广度优先遍历的功能函数 
 	cout<<endl; 
}
