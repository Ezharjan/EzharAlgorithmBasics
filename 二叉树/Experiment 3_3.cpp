 /*
	����:���ζ���������˹�� 
	ѧ��:17081160 
	רҵ:����ý�弼�� 
	ʱ��: 11/11/18 00:21
	����:ʵ���������� 
*/

#include<iostream>
#define MAXSIZE 256
using namespace std;

typedef string *STR;//�����ṹ���ַ���ָ�� 

typedef struct HNode//�ṹ������ 
{
	unsigned freq;//�����޷��ŵ�Ƶ�ʱ��� 
	bool add;//�ж��Ƿ����Huffman��
	int left_child,right_child;//�������͵����Һ��ӽڵ� 
	
	void Init(unsigned &e,int L=-1,int R=-1, bool input=0)//��ʼ������ 
	{//�ڽṹ���ж���һ���պ������ڲ��ֱ����޷��ŵı��������ͱ����Ͳ����ͱ��� 
		freq=e;//���޷��ű���e����Ƶ�ʱ����Գ�ʼ�� 
		left_child=L;//����ڵ�Ŀ�ֵ�������ӽڵ��Գ�ʼ�� 
		right_child=R;//���ҽڵ�Ŀ�ֵ�����Һ��ӽڵ��Գ�ʼ�� 
		add=input;//�������ȥ�����ݽ��г�ʼ�� 
	} 

	HNode()//���������Ľڵ㺯��Ҳ����ʼ�� 
	{
		freq=0;//��ʼ������Ƶ�� 
		add=0;//��ʼ��������� 
		left_child=-1;//�����ӽڵ��ʼ��ָ����ײ� 
		right_child=-1;//���к��ӽڵ��ʼ��ָ����ײ� 
	}
}*HuffTree;//��������ʱָ��HuffTree���ڲ��ṹ 


void INcode(HuffTree &node,int &k,STR &Code,string &s,
            int i,int leaf,unsigned *G)//�������������뺯�� 
{
	if (k<leaf)//��K��ֵС��Ҷ�ӽ���ֵ 
	{
		Code[G[k]]=s.substr(0,i);//substr��C++���Դ��ĸ������ַ����ĺ���
			return;//������Ϸ��أ������޷�ִ����Ӧ�Ĵ�ֵ���������н��޷����� 
	}
	s[i]='0';//�����е�����Ϊ���Ҽ���ʽ�0�����ַ������� 
	INcode(node,node[k].left_child,Code,s,i+1,leaf,G);//�ݹ���ã����µ������ݽ������� 
	s[i]='1';//�����е�����Ϊ���Ҽ���ʽ�1�����ַ�������
	INcode(node,node[k].right_child,Code,s,i+1,leaf,G);//�ݹ���� 
}

void Searcher(HuffTree &node,int n,int &fir,int &sec)//�������� 
{//��������Ƶ����͵Ľڵ� 
	unsigned Minimal;
	for (int k=0;k<2;k++)
	{
		Minimal=100;//���⸳ֵ����С������ 
		int t=0;//��ʼ�� 
		
		for(int i=0;i<n;i++)//i��0��n��Χ�����Լ����� 
		{
			if(node[i].add)continue;//�������ӽڵ��������������������µĽڵ㣬����� 
			if (node[i].freq<Minimal)//�������Ƶ���������ٳ��ִ��� 
			{
				Minimal=node[i].freq;//��Ƶ�ʵ�ֵ���� 
				t=i;//����������ֵ����t 
			}
		}
		
		node[t].add=1;//�����������Ϊ�� 
		if(k==0) fir=t;//��t�м�������ֵ������һ���ڵ� 
		else     sec=t;//��������򸳸��ڶ����ڵ� 
	}
}

void Creat(HuffTree &node,unsigned *G,int &num)//�����Ͷ��崴�����Ŀպ��� 
{
		int i;
		for(i=0;i<num;i++)//��������0��num֮������Լ����� 
		{ 
			node[i].Init(G[i]);//���ó�ʼ������ʹ�ڲ��ÿ� 
		}	
		for (i=num;i<2*num-1;i++)//����������num��ʼһֱ���Լ����㵽������num��һ 
		{
			int x,y;//�������ͱ���x��y 
			Searcher(node,i,x,y);//ʹ�ò��Һ��������ڵ��ֵ����������ֵ��x��y��ֵ���� 
			unsigned e=node[x].freq+node[y].freq;//��e���г�ʼ������ʾ��ڵ���Ŀ 
			node[i].Init(e,x,y);//���ó�ʼ������ʹ���ڲ�Ԫ��Ϊ�µ��� 
		}
}

void HFM(string &input, STR &Code, int &n)//����������ʵ�ֱ������Ŀպ��� 
{
	unsigned FEQ[MAXSIZE]={0},G[MAXSIZE]={0};//��������ʼ���������ݺ�Ƶ������ 
	unsigned M[MAXSIZE];//�����ڲ��������Ϊ�޷��ŵ� 
	int i,num=0;//�������Լ���������ֵ��ʼ�� 
	for(i=0;i<n;i++)//��0��n֮�����Լ����� 
		FEQ[(input[i]+256)%256]++;//����������ʾ�����ֵ�Ƶ���ڱ���ʱ������������
		//��Ӻ���256����ȡ��������ڴ˻����Ͻ����Լ����� 
	for(i=0;i<MAXSIZE;i++)//��������0����������ķ�Χ�ڽ����Լ����� 
	{
		if (FEQ[i])//����Ƶ�ʵ����� 
		{
			G[num]=i;//��¼�ڵ���������ַ�����
			M[num++]=FEQ[i];//��Ƶ�������ֵ��������ֵ�洢���� 
		}
	}
	HuffTree Node=new HNode[2*num-1];
	Creat(Node,M,num);//�����ڲ������Խ������ֵ�������� 
	Code=new string[MAXSIZE];//����ʱʹ���ĵô洢�ַ������� 
	string STR;//�����ַ����͵ı��� 
	STR.resize(MAXSIZE);//C++�ڲ�string���еĺ������Ե���Դ�ַ�������Ϊn 
	int nod=2*num-2;//������õ�ֵ�����ڵ� 
	INcode(Node,nod,Code,STR,0,num,G);//�����ڲ��������뺯���Խ��µ�ֵ���ݸ��ڲ����� 
	cout<<"������ַ�����Ϊ��"<<num<<endl;//���������ַ����� 
	//cout << "�ַ����"<< "����Ƶ��"<<endl;
	for(i=0;i<num;i++) cout<<"��"<<i+1<<"���ַ�������"<<M[i]<<"�Σ�"<<endl;
	
	cout<<"�ô��ַ���Ӧ�ı������£�"<<endl;
	for(i=0;i<n;i++)   cout<<Code[(input[i]+256)%256];//���ֱ�õ��� 
	cout<<endl;//���ڱ���ʱ�����code����ѭ����ÿһ����ѭ�����У�����Ҫ�������һ������ 
	cout<<"�뽫�����ַ����ո�ʽ����:"<<endl;
	string add;//�����ַ�����������Ϊ������ǰ���Ѿ������1��0���ַ��� 
	cin>>add;//���������ַ���������0��1���� 

	int k=2*num-2;//��������ʼ������k 
	string Display;
	for(i=0;i<=add.length();i++)//�ڳ��ȷ�Χ��ѭ���Լ� 
	{
		if(k<num)//���С���ַ���Ŀ 
		{
			char s=(char)G[k];//�������е�Ԫ��ǿ��ת��Ϊ�ַ��� 
			Display+=s;//�����ֵΪs������ 
			k=2*num-2;//k��ֵ�ı� 
		}
		if      (add[i]=='0')    k=Node[k].left_child;//����������0�������ӵ�ֵ����k 
		else if(add[i] =='1')	k = Node[k].right_child;//�����1���ڽ��Һ��ӵ�ֵ����k 
	}
	cout<<"�����������������£�"<<endl;
	cout<<Display<<endl;//���ֽ����� 
}

int main()
{
	string add;//��������ı���Ϊ�ַ��� 
	string *Code;//����ָ���������� 
	cout<<"��������Ҫ������ַ���";
	cin>>add;//�û������ַ� 
	int num=add.length();//���ַ������ȸ���num�Ա�����������ʱʹ�� 
	HFM(add, Code, num);//������Ҫ�ı�����̾���HFM�������Ѿ����ù�
					   //�˴�ֱ��ֻ����HFM�������ɣ������û������ֵ����������ʵ�ֱ��� 
}
