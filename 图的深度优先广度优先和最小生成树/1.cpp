/*
	ѧ��:17081160 
	����:���ζ���������˹�� 
	רҵ:����ý�弼�� 
	ʱ��: 01/12/18 00:58
	����:ʵ���ĵĵ�һ�� 
*/
#include<iostream>
#include<cstdlib>
#define OVERFLOW -2//�������Ϊ-2 
#define MAX 10//�������ֵΪ10 
using namespace std;

typedef struct Node//����ṹ�� 
{
 	int elem;//�������ͱ��� 
 	struct Node *next;//�ö���Ľṹ������nextָ�� 
}Node,*QNode;//����Ϊ�ڵ��Լ������еĽڵ�ָ�� 

typedef struct
{
	QNode front;//�����е��׽ڵ� 
	QNode rear;//�����е�β�ڵ� 
}Queue;//������еĽṹ�� 


typedef struct ArcNode//ͷ�ڵ���Ϊ���Ľṹ������ʾ 
{
 int top_v;//�ñ���ָ��Ķ����λ��
 struct ArcNode *nextarc;//ָ����һ����
}ArcNode;//����ͷ�����Ϊ���ȵĽṹ�� 

typedef struct VNode//��ڵ�
{
	int data;//������Ϣ
 	ArcNode *firstarc;//ָ���һ�������ýڵ�ıߵ�ָ��
}VNode,AdjList[MAX];//�ýṹ�嶨���ڵ���ڽӱ����� 

typedef struct
{
	AdjList vertices;//��ڵ�
	int node_num;//�����ڵ�ĸ���
 	int edge_num;//�����ߵ�����
}Graph;//����ͼ�Ľṹ�� 

int InitQueue(Queue *Q)//ʵ�ֳ�ʼ�����еĹ��ܺ��� 
{
	Q->front=Q->rear=new Node;//ָ��ͷ���Ĵ洢�ռ��ָ��β�ڵ�Ĵ洢�ռ丳���µĽڵ�洢�ռ� 
	if(!Q->front)  exit(OVERFLOW);//�����е�ͷ���洢�ռ�δָ��ͷ��㣬����� 
 	Q->front->next=NULL;//���ÿ�ͷ���ָ��ĵ���һ���ڵ� 
 	return 1;//����ֵΪ�� 
}

int Acces_Que(Queue *Q,int e)//ʵ����Ӳ����Ĺ��ܺ��� 
{
	QNode p=new Node; //��p�ڵ�Ĵ洢�ռ��ʼ��ʹ��ָ��һ����̬�洢�ռ� 
 	if(!p) exit(OVERFLOW);//���pδָ�����ʾ��� 
 	p->elem=e;//��e��ֵ����pָ���Ԫ�� 
 	p->next=NULL;//p����һ���ڵ��ÿ� 
 	Q->rear->next=p;//��p����β�ڵ����һ���ڵ� 
 	Q->rear=p;//��p���������е�β�ڵ� 
 	return 1;//����ֵΪ�� 
}

int Out_fr_Que(Queue *Q,int *e)//ʵ�ֳ��Ӳ����Ĺ��ܺ��� 
{
	QNode p;//�����������еı���p 
 	p=Q->front->next;//���������׽ڵ�ָ�����һ���ڵ��ֵ����p 
 	Q->front->next=p->next;//��pָ�����һ���ڵ��ֵ�����׽ڵ���ָ�����һ���ڵ�ֵ 
 	if(Q->rear==p)  Q->rear=Q->front;//��������β�ڵ��ֵ����p��ֵ��������е��׽ڵ��ֵ����β�ڵ� 
 	*e=p->elem;//��p��ָ�����һ��Ԫ�ص�ֵ�͵�ַ����ָ��e 
 	return 1;//����ֵΪ1 
}

int QueueEmpty(Queue Q)//д���ӿյ��������������������ʱ�����л�ջ�ǿ� 
{
	if(Q.rear==Q.front)  return 1;//���������׽ڵ����β�ڵ㣬������ 
 	else                 return 0;//���򷵻ؼ� 
}

int Locate_node(Graph *G,int v)//ͨ���ú��������ؽڵ�v��ͼ�е�λ��
{
	int i;//�������ͼ����� 
 	for(i=0;i<G->node_num;++i) 
	{
	 	if(G->vertices[i].data==v)  break;//�����е������ڲ�������ֵ���ڽڵ��ֵ������ѭ�� 
   		else                     continue;//�������ִ�� 
	}
 	if(i<G->node_num)             return i;//����������ֵ����ͼ��ָ��Ľڵ��ֵ ������i��ֵ����λ�ɹ� 
 	else                          return -1;//���򷵻�-1 
}

int CreateGraph(Graph *G)//���ڽӱ���ʽ����������ͨͼG
{
	int m,n,i,j,k,v1,v2,flag=0; 
 	ArcNode *p1,*q1,*p,*q;//��������Ӧ��ָ�롢����ֵ�ͼ������� 
 	cout<<"�����붥������"; 
 	cin>>m;//�û�������ʾ���� 
 	cout<<"�����������  ";
 	cin>>n;
 	G->node_num=m;//������Ŀ
 	G->edge_num=n;//�ߵ���Ŀ
 	
	 for(i=0;i<G->node_num;++i)
 	{
   		G->vertices[i].data=i+1;//������Ϣ
   		G->vertices[i].firstarc=NULL;//���������ĵ�һ�����ÿ� 
 	}
    cout<<"����������Ϣ�� "<<endl; 

 	for(i=0;i<G->node_num;++i)     cout<<"����"<<G->vertices[i].data<<endl<<endl;
	 //ǰ��Ķ���һ������������ݸ����û�����ĵ���ͨ�������м�������ʽ�������ӣ��û������ֶ����붥�� 
	for(k=0;k<G->edge_num;++k)
 	{
   		cout<<"������"<<k+1<<"����ʼ����������㣬�ÿո������"; 
   		cin>>v1>>v2;//�û�������ʾ�������룬���ÿո���� 
   		i=Locate_node(G,v1);//��;�нڵ��ֵ�������ֵ������λ�����������㲢���������õ��Ľ������i 
   		j=Locate_node(G,v2);//��;�нڵ��ֵ�������ֵ������λ�����������㲢���������õ��Ľ������j 

   		if(i>=0&&j>=0)//��i����0����jҲ����0 
   		{
   	 		++flag;//��������Լ����� 
     		p=new ArcNode;//�������¶�̬�ռ丳��p 
     		p->top_v=j;//��j��ֵ����pָ��Ķ����� 
     		p->nextarc=NULL;//����һ�����ÿ� 
     		
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
    		}//���ϴ���ԭ��ͬ��
   		}
   		else
   		{
    		cout<<"��������û�������ıߣ����������룡" <<endl;
    		k=flag;//������ԼӺ�õ���ĳ��ֵ����k 
   		}

 	}

}

int Firsttop_v(Graph G,int v)//����v�ĵ�һ���ڽӶ���
{
	if(G.vertices[v].firstarc)    return G.vertices[v].firstarc->top_v;
 	else                          return -1;
}

int Nexttop_v(Graph G,int v,int w)//����v�������w����һ���ڽӶ���
{
 	int flag=0;
 	ArcNode *p; 
 	p=G.vertices[v].firstarc;
 	while(p)//��p����ʱ 
 	{
   		if(p->top_v==w)
   		{
    		flag=1;
    		break;
   		}
   	p=p->nextarc;//��p��ָ�����һ���ߵ�ֵ����p 
 	}
 	if(flag&&p->nextarc)			return p->nextarc->top_v;
 	else							return -1;
}

int Visited[MAX];

void DFS(Graph G,int v)//������ȱ���������� 
{
	int w;
 	Visited[v]=1;
    cout<<"����"<<G.vertices[v].data<<"  ";
 	for(w=Firsttop_v(G,v);w>=0;w=Nexttop_v(G,v,w))    if(!Visited[w])    DFS(G,w);
	//������wδ�����ʣ������ݹ������ʵ��������ȱ��� 
}


void DFSTraverse(Graph G)//������ȱ������ 
{
 	int v;
 	for(v=0;v<G.node_num;++v)Visited[v]=0;
 	for(v=0;v<G.node_num;++v)   if(!Visited[v])   DFS(G,v); //������Ƕ������һ������ 
}

void BFSTraverse(Graph G)//������ȱ���
{
 	int v,v1,w;
 	Queue q;//����һ������
 	
 	for(v=0;v<G.node_num;++v)
   	Visited[v]=0;//������û�б����ʹ� 
 	InitQueue(&q);//��ʼ������
 	
 	for(v=0;v<G.node_num;++v)
   	if(!Visited[v])
   	{
    	Visited[v]=1;
    	cout<<"����"<<G.vertices[v].data<<"  ";
    	Acces_Que(&q,v);//����һ���������
    	while(!QueueEmpty(q))//�ж϶��Ƿ�Ϊ�գ���=�Ӳ��ǿյģ���ִ������ѭ�� 
    	{
     		Out_fr_Que(&q,&v1);//��һ���������
     		for(w=Firsttop_v(G,v1);w>=0;w=Nexttop_v(G,v1,w))
      		if(!Visited[w])//��û�б����ʹ� 
      		{
       			Visited[w]=1;//��λ�����ʹ�Ϊ�� 
       			cout<<"����"<<G.vertices[w].data<<"  ";//������������ 
       			Acces_Que(&q,w);//��w��� 
      		}
    	}
   }
}

int main()
{
	Graph G;//����ͼ 
 	CreateGraph(&G);//����ͼ 
 	cout<<endl;
 	cout<<"������������Ľ���ǣ�";
 	DFSTraverse(G);//����������ȱ����Ĺ��ܺ��� 
 	cout<<endl; 
 	cout<<"������������Ľ���ǣ�";
 	BFSTraverse(G);//���ù�����ȱ����Ĺ��ܺ��� 
 	cout<<endl; 
}
