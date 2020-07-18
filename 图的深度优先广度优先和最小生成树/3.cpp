/*
	ѧ��:17081160 
	����:���ζ���������˹�� 
	רҵ:����ý�弼�� 
	ʱ��: 04/12/18 14:11
	����:ʵ���ĵĵ����� 
*/
#include<iostream>
#include<cstring>//Ϊ����ʹ���ַ������ƺ����ṩ���ļ� 
using namespace std;
 

#define MaxSpotNum 11//�������11�����㣬����������㿪ʼ�������˴�ʹ��11������10 
#define MaxRoad 900//����·���������ֵΪ900�ף��������ڲ������� 

 
typedef struct//����ṹ�� 
{
    char name[30];//�����ַ��;�������
    char number[10];//����������� 
    char detail[200];//�����������ϸ���� 
}InfoType;//��������Ϣ������InfoType�� 
 
typedef struct//����ṹ�� 
{
    int num;//���������� 
    InfoType data;//����������Ϣ
}Spots;//���徰��ṹ�� 
 
typedef struct//����ṹ�� 
{
    Spots Spot[MaxSpotNum];//��Ŷ����һά���� 
    int length[MaxSpotNum][MaxSpotNum];//���·�����ȵĶ�ά���� 
}Graph;//����ͼ 

 
Graph G;//����ȫ�ֱ���,����GΪGraph����
int shortest[MaxSpotNum][MaxSpotNum];//�ö�ά��������ȫ�ֱ���������С·��
int path[MaxSpotNum][MaxSpotNum];//�ö�ά������������·��

void Information();//���������麯��;
void Init();//������ʼ������
void detail();//����������Ϣ�洢�ĺ��� 
void Shortcuts();//��������·�߳��ֺ��� 
void Floyd();//����ʹ�ø��������㷨 
void display(int i,int j);//��ӡ���������·�������·��
//int shortdistance();//Ҫ���ҵ�����������·��


void Information()//ʵ�־����麯�� 
{
	cout<<"\t"<<"������"<<"\t\t"<<"��������"<<"\t\t"<<"������"<<endl; 
	cout<<"\t"<<"  001"<<"\t\t\t"<<"У԰����"<<"\t\t"<<"��У����"<<endl;
	cout<<"\t"<<"  002"<<"\t\t\t"<<"��ѧ¥"<<"\t\t\t"<<"�칫¥"<<endl;
	cout<<"\t"<<"  003"<<"\t\t\t"<<"����¥"<<"\t\t\t"<<"��ѧ¥"<<endl;
	cout<<"\t"<<"  004"<<"\t\t\t"<<"���˳���"<<"\t\t"<<"��ë���"<<endl;
	cout<<"\t"<<"  005"<<"\t\t\t"<<"����¥"<<"\t\t\t"<<"����ѧԺ"<<endl;
	cout<<"\t"<<"  006"<<"\t\t\t"<<"һ������¥"<<"\t\t"<<"ѧ����Ԣ"<<endl;
	cout<<"\t"<<"  007"<<"\t\t\t"<<"�������"<<"\t\t"<<"������ʳ��"<<endl;
	cout<<"\t"<<"  008"<<"\t\t\t"<<"��С��"<<"\t\t\t"<<"ǰ������"<<endl;
	cout<<"\t"<<"  009"<<"\t\t\t"<<"����"<<"\t\t\t"<<"��ʱ��ȡ���"<<endl;
	cout<<"\t"<<"  010"<<"\t\t\t"<<"����"<<"\t\t\t"<<"��һ������"<<endl;//�����ظ��û�����У԰��Ҫ������ 
}
 
void Init()//ʵ�ֳ�ʼ���������ٴκ����ڲ���У԰��Ϣ���� 
{
    int i,j;//�������ͼ������Ա����ѭ��ʱʹ�� 
    G.Spot[1].num=1;//����һ�����������о���ı�ų�ʼ��Ϊ1 
	strcpy(G.Spot[1].data.name,"У԰����");//ʹ���ַ������ƺ��������ַ������Ƶ���һ�����������е�name��ַ�ռ� 
    strcpy(G.Spot[1].data.number,"001");//ʹ���ַ�����ֵ��������Ÿ��Ƶ���һ�����������е�number��ַ�ռ� 
    strcpy(G.Spot[1].data.detail,"����������ѧУ�����ţ�У԰��Ӱ�����￪ʼ��");//����Ϣ���Ƶ�detail��ַ�ռ� 
	
    G.Spot[2].num=2;//���ڶ������������о���ı�ų�ʼ��Ϊ2 
    strcpy(G.Spot[2].data.name,"��ѧ¥");//ʹ���ַ������ƺ��������ַ������Ƶ��ڶ������������е�name��ַ�ռ� 
    strcpy(G.Spot[2].data.number,"002");//ʹ���ַ�����ֵ��������Ÿ��Ƶ��ڶ������������е�number��ַ�ռ� 
    strcpy(G.Spot[2].data.detail,"У������Ա�칫¥������ͬѧ��ʵ��¥��");//����Ϣ���Ƶ�detail��ʼ�ĵ�ַ�ռ� 
	
    G.Spot[3].num=3;//�����������������о���ı�ų�ʼ��Ϊ3
    strcpy(G.Spot[3].data.name,"����¥");//ʹ���ַ������ƺ��������ַ������Ƶ����������������е�name��ַ�ռ� 
    strcpy(G.Spot[3].data.number,"003");//ʹ���ַ�����ֵ��������Ÿ��Ƶ����������������е�number��ַ�ռ�
    strcpy(G.Spot[3].data.detail,"�ڿ�ѧ¥���ϲ࣬���ķ�ѧ���ͽ���ѧԺͬѧ�Ͽε�¥��");
	
    G.Spot[4].num=4;//�����ĸ����������о���ı�ų�ʼ��Ϊ4
    strcpy(G.Spot[4].data.name,"���˳���");//ʹ���ַ������ƺ��������ַ������Ƶ����ĸ����������е�name��ַ�ռ� 
    strcpy(G.Spot[4].data.number,"004");//ʹ���ַ�����ֵ��������Ÿ��Ƶ����ĸ����������е�number��ַ�ռ�
    strcpy(G.Spot[4].data.detail,"������¥���࣬2008����˻�ʱ������ë��ݣ�Ŀǰ��ȥ����ë��ᰴСʱ�շѡ�");
	
    G.Spot[5].num=5;//����������������о���ı�ų�ʼ��Ϊ5
    strcpy(G.Spot[5].data.name,"����¥");//ʹ���ַ������ƺ��������ַ������Ƶ���������������е�name��ַ�ռ� 
    strcpy(G.Spot[5].data.number,"005");//ʹ���ַ�����ֵ��������Ÿ��Ƶ���������������е�number��ַ�ռ�
    strcpy(G.Spot[5].data.detail,"�ڿ�ѧ¥���࣬����ѧԺͬѧ�ǵ��鷿��¥��󣬵���ȸ��С�����ȫ��");
	
    G.Spot[6].num=6;//�����������������о���ı�ų�ʼ��Ϊ6
    strcpy(G.Spot[6].data.name,"һ������¥");//ʹ���ַ������ƺ��������ַ������Ƶ����������������е�name��ַ�ռ� 
    strcpy(G.Spot[6].data.number,"006");//ʹ���ַ�����ֵ��������Ÿ��Ƶ����������������е�number��ַ�ռ�
    strcpy(G.Spot[6].data.detail,"17���������ᣬ��������������Ϣʹ�á�");
	
    G.Spot[7].num=7;//�����߸����������о���ı�ų�ʼ��Ϊ7
    strcpy(G.Spot[7].data.name,"�������");//ʹ���ַ������ƺ��������ַ������Ƶ����߸����������е�name��ַ�ռ� 
    strcpy(G.Spot[7].data.number,"007");//ʹ���ַ�����ֵ��������Ÿ��Ƶ����߸����������е�number��ַ�ռ�
    strcpy(G.Spot[7].data.detail,"��һ��¥���࣬�������������У�ڱȽϴ�Ĳ����������㣬��Ϊ������");
	
    G.Spot[8].num=8;//���ڰ˸����������о���ı�ų�ʼ��Ϊ8
    strcpy(G.Spot[8].data.name,"��С��");//ʹ���ַ������ƺ��������ַ������Ƶ��ڰ˸����������е�name��ַ�ռ� 
    strcpy(G.Spot[8].data.number,"008");//ʹ���ַ�����ֵ��������Ÿ��Ƶ��ڰ˸����������е�number��ַ�ռ�
    strcpy(G.Spot[8].data.detail,"��һ������¥���࣬УҽԺ�ԣ���ȥ�����˵�����վ��");
	
    G.Spot[9].num=9;//���ھŸ����������о���ı�ų�ʼ��Ϊ9
    strcpy(G.Spot[9].data.name,"����");//ʹ���ַ������ƺ��������ַ������Ƶ��ھŸ����������е�name��ַ�ռ� 
    strcpy(G.Spot[9].data.number,"009");//ʹ���ַ�����ֵ��������Ÿ��Ƶ��ھŸ����������е�number��ַ�ռ�
    strcpy(G.Spot[9].data.detail,"��������࣬�ź�С����ȥ����ͣ������");
	
    G.Spot[10].num=10;//����ʮ�����������о���ı�ų�ʼ��Ϊ10
    strcpy(G.Spot[10].data.name,"����");//ʹ���ַ������ƺ��������ַ������Ƶ���ʮ�����������е�name��ַ�ռ� 
    strcpy(G.Spot[10].data.number,"010");//ʹ���ַ�����ֵ��������Ÿ��Ƶ���ʮ�����������е�number��ַ�ռ� 
    strcpy(G.Spot[10].data.detail,"�����ǹ�����ͨ�϶�ĵط��������е���վ����·���滹����һ��У����");//ͬ������ 
	
	
    for(i=1;i<=10;i++)//�ڵ�һ�����㵽��ʮ��������ѭ�� 
	{
		for(j=1;j<=10;j++)//�ڲ���ѭ�� 
        {
			G.length[i][j]=MaxRoad;//�����·����ֵ����ÿ��·�� 
        }
    }//��ʼ�����·���ɹ� 
    for(i=1;i<=10;i++)//��һ�������һ������ѭ������ 
    {
		shortest[i][j]=0;//��ÿ������֮������·����ʼ��Ϊ0 
    }//��ʼ�����·���ɹ�
	 
    G.length[1][2]=G.length[2][1]=50;
    G.length[2][3]=G.length[3][2]=50;
    G.length[3][4]=G.length[4][3]=60;
    G.length[4][5]=G.length[5][4]=100;
    G.length[5][6]=G.length[6][5]=100;
    G.length[6][7]=G.length[7][6]=220;
	G.length[6][9]=G.length[9][6]=80; 
    G.length[7][8]=G.length[8][7]=250;
    G.length[8][9]=G.length[9][8]=100;
	G.length[9][10]=G.length[10][9]=150;//ͨ����ÿ��·�����и�ֵ���������������·������ 
	
    G.length[1][1]=G.length[2][2]=G.length[3][3]=G.length[4][4]=G.length[9][9]=0;
    G.length[5][5]=G.length[6][6]=G.length[7][7]=G.length[8][8]= G.length[10][10]=0;//��ͬһ��֮���·����0����   
}
 
void detail()//ʵ�־��������Ϣ�Ĵ洢 
{
    int m;//���������ŵ����ͳ��� 
    cout<<"�������ѯ����ı�ţ� "<<endl;//��ʾ�û����뾰���� 
	cin>>m;//�û����� 
	fflush(stdin);//��������� 
	
    switch(m)//�����û�������ı�ţ���Ӧ��Ӧ�ľ��������Ϣ 
    {
	case 1:
		cout<<"������:  "<<G.Spot[1].data.number<<endl;
		cout<<"�������ƣ� "<<G.Spot[1].data.name<<endl; 
		cout<<"�����飺 "<<G.Spot[1].data.detail<<endl;
		break;
	case 2:
		cout<<"������:  "<<G.Spot[2].data.number<<endl;
		cout<<"�������ƣ� "<<G.Spot[2].data.name<<endl; 
		cout<<"�����飺 "<<G.Spot[2].data.detail<<endl;
		break;
	case 3:
		cout<<"������:  "<<G.Spot[3].data.number<<endl;
		cout<<"�������ƣ� "<<G.Spot[3].data.name<<endl; 
		cout<<"�����飺 "<<G.Spot[3].data.detail<<endl;
		break;
	case 4:
		cout<<"������:  "<<G.Spot[4].data.number<<endl;
		cout<<"�������ƣ� "<<G.Spot[4].data.name<<endl; 
		cout<<"�����飺 "<<G.Spot[4].data.detail<<endl;
		break;
	case 5:
		cout<<"������:  "<<G.Spot[5].data.number<<endl;
		cout<<"�������ƣ� "<<G.Spot[5].data.name<<endl; 
		cout<<"�����飺 "<<G.Spot[5].data.detail<<endl;
		break;
	case 6:
		cout<<"������:  "<<G.Spot[6].data.number<<endl;
		cout<<"�������ƣ� "<<G.Spot[6].data.name<<endl; 
		cout<<"�����飺 "<<G.Spot[6].data.detail<<endl;
		break;
	case 7:
		cout<<"������:  "<<G.Spot[7].data.number<<endl;
		cout<<"�������ƣ� "<<G.Spot[7].data.name<<endl; 
		cout<<"�����飺 "<<G.Spot[7].data.detail<<endl;
		break;
	case 8:
		cout<<"������:  "<<G.Spot[8].data.number<<endl;
		cout<<"�������ƣ� "<<G.Spot[8].data.name<<endl; 
		cout<<"�����飺 "<<G.Spot[8].data.detail<<endl;
		break;
	case 9:
		cout<<"������:  "<<G.Spot[9].data.number<<endl;
		cout<<"�������ƣ� "<<G.Spot[9].data.name<<endl; 
		cout<<"�����飺 "<<G.Spot[9].data.detail<<endl;
		break;
	case 10:
		cout<<"������:  "<<G.Spot[10].data.number<<endl;
		cout<<"�������ƣ� "<<G.Spot[10].data.name<<endl; 
		cout<<"�����飺 "<<G.Spot[10].data.detail<<endl;
		break;//�����û�����������ݣ���Ӧ�س�����Ӧ���������Ϣ 

	default:
		cout<<"������Ż�δ���뾰����Ϣ��"<<endl;
		break;//���û������Ų���1-10�ķ�Χ�ڣ�����ʾ�û��������� 
    }
    cout<<endl;
    system("pause");
    system("cls");//ˢ����Ļ 
}

void Shortcuts()//���־��佨��·�����ȣ����� 
{
	cout<<"1-2·������Ϊ"<<G.length[1][2]<<"�ס�"<<endl; 
	cout<<"2-3·������Ϊ"<<G.length[2][3]<<"�ס�"<<endl; 
	cout<<"3-4·������Ϊ"<<G.length[3][4]<<"�ס�"<<endl; 
	cout<<"4-5·������Ϊ"<<G.length[4][5]<<"�ס�"<<endl; 
	cout<<"5-6·������Ϊ"<<G.length[5][6]<<"�ס�"<<endl; 
	cout<<"6-7·������Ϊ"<<G.length[6][7] <<"�ס�"<<endl; 
	cout<<"7-8·������Ϊ"<<G.length[7][8]<<"�ס�"<<endl; 
	cout<<"8-9·������Ϊ"<<G.length[8][9]<<"�ס�"<<endl;//���û�����·��֮��ĳ��� 
    system("pause");//������ִ����ɲ����� 
	system("cls");//ˢ�� 
    fflush(stdin);//��ջ����� 
}
  
void Floyd()//ʹ�ø��������㷨 
{
    int i,j,k;
    
    for(i=1;i<=10;i++)//������ѭ������ 
    {
		for(j=1;j<=10;j++)//�ڶ���ѭ�� 
		{
			shortest[i][j]=G.length[i][j];//����̵�·���������·�� 
			path[i][j]=0;//·����ʼ��Ϊ0 
		}
    } //��ʼ������ɹ� 
    
    for(k=1;k<=10;k++)//������ѭ������ 
    {
		for(i=1;i<=10;i++)//�ڶ���ѭ�� 
		{
			for(j=1;j<=10;j++)//������ѭ�� 
			{
				if(shortest[i][j]>(shortest[i][k]+shortest[k][j]))//������·�����ȴ�����·���ĳ���֮�� 
				{
					shortest[i][j]=shortest[i][k]+shortest[k][j];//����·��֮�͵�ֵ�������·�� 
					path[i][j]=k;//�����ֵ����·���Լ�¼������·�� 
					path[j][i]=k;//�����ֵ����·���Լ�¼������·��
				}
			}			
		}
    }
}
 
void display(int i,int j)//��ӡ���������·�������·��*
{         
    int a,b;//�����������ͱ��������ں����������� 
    a=i;  b=j;//����������ֵ������������ 
    cout<<endl<<endl<<"���·���ǣ�"<<a; //���ֳ�����ı�� 
	while(path[i][j]!=0)//��i��j��·�������о����ľ��㰴˳���ӡ����
	{      
			cout<<"-->"<<path[i][j];//����ÿ�������ľ����� 
			if(i<j)//�Ƚ�����������ֵ 
				j=path[i][j];
			else
				i=path[j][i];
		}
		cout<<"->"<<b<<endl;//����Ŀ�ĵر�� 
		cout<<a<<"->"<<b<<"�����·���ǣ�"<<shortest[a][b]<<"�ס�"<<endl;//�������·���Ľ�� 
		system("pause");//�������ͣһ�£��Ա����·�������� 
		system("cls");//�����߾������Ϻ�ˢ����Ļ���û�������������ʹ�ó������������ 

}
 
int shortdistance()//Ҫ���ҵ�����������·��
{    
    int i,j;//�������ͱ������������������Ŀ�ĵر�ŵ�ֵ 
    cout<<"����������ر�ţ�"; 
	cin>>i;//�û���������ص�ı�� 
	cout<<"������Ŀ�ĵر�ţ�";
	cin>>j;//�û�����Ŀ�ĵصı�� 
	 
    if(i>10||i<0||j>10||j<0)//����û�����ı�Ų���1-10�ķ�Χ�� 
    {
    	cout<<"�����������������룡ȷ���ھ����ŷ�Χ�ڣ�"<<endl<<endl;
	}//��ʾ�û�������� 
	else//���� 
    {
		Floyd();//�����ڵ��ò����з��������㷨��������߼�����·�� 
		display(i,j);//�����ڵ��ò����г��ֳ����·���ĺ��� 
    }
    return 1;//����ֵΪ1��Ϊ����ѭ�����ִ��·��� 
    fflush(stdin);//��ջ����� 
}
 

int main()
{
    char k;//�������ͱ���k��Ϊ�û�������Ӧ��ѡ�� 
    Init();//���ó�ʼ���������Ծ�����Ϣ���г�ʼ��
	 
    cout<<"\t\t"<<"������У԰����ϵͳ"<<endl; 
    while(1)//��һ���ַ�����ʱ������ѭ��ִ����Ӧ������ 
    {   
    	cout<<"\t"<<"1.��Ҫ������Ϣ"<<endl;
    	cout<<"\t"<<"2.���徰����Ϣ��ѯ"<<endl; 
    	cout<<"\t"<<"3.��Ҫ����·��"<<endl; 
    	cout<<"\t"<<"4.��ѯ�����ݾ�"<<endl;
    	cout<<"\t"<<"5.�˳�ϵͳ"<<endl;
    	cin>>k; //�û�������Ӧ��ѡ�� 
		
		switch(k)//�����û��������ѡ������жϲ�ѡȡ�������к��ʵĺ�������ʵ�� 
		{
			case '1'://���û��������1 
				Information();	//���þ�������Ϣ 
				system("pause");//������ִ����ɲ����� 
				system("cls");//ˢ��
				break;
			
			case '2':
				detail();//����ʵ�־��������Ϣ�ĺ���	
				break;
				
			case '3':
				Shortcuts();//���ó��־���֮��·�����ȵĺ��� 
				break;
				
			case '4':
				shortdistance();//����������·���ĺ��������ڸú����ڲ��Ѿ��������������ʵ���ʱ��Ϊ���� �� 
				break;
				
			case '5':
				cout<<"��лʹ�ñ�����"<<endl; //�������˳�����ǰ���û�һ���������ʾ 
				exit(0);
		}
    }
    system("pause");//Ϊ��ֹÿһ�������������ִ����ϲ��رճ����ú���ͣ�� 
	return 0;
}

