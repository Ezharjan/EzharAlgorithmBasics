/*
	学号:17081160 
	姓名:艾孜尔江·艾尔斯兰 
	专业:数字媒体技术 
	时间: 04/12/18 14:11
	描述:实验四的第三题 
*/
#include<iostream>
#include<cstring>//为后续使用字符串复制函数提供库文件 
using namespace std;
 

#define MaxSpotNum 11//最多容纳11个景点，由于数组从零开始计数，此处使用11而不是10 
#define MaxRoad 900//定义路径长度最大值为900米，以容纳内部运算量 

 
typedef struct//定义结构体 
{
    char name[30];//声明字符型景点名称
    char number[10];//声明景点号码 
    char detail[200];//声明景点的详细介绍 
}InfoType;//将景点信息包含在InfoType中 
 
typedef struct//定义结构体 
{
    int num;//声明景点编号 
    InfoType data;//声明景点信息
}Spots;//定义景点结构体 
 
typedef struct//定义结构体 
{
    Spots Spot[MaxSpotNum];//存放顶点的一维数组 
    int length[MaxSpotNum][MaxSpotNum];//存放路径长度的二维数组 
}Graph;//定义图 

 
Graph G;//声明全局变量,定义G为Graph类型
int shortest[MaxSpotNum][MaxSpotNum];//用二维数组声明全局变量存贮最小路径
int path[MaxSpotNum][MaxSpotNum];//用二维数组声明存贮路径

void Information();//声明景点简介函数;
void Init();//声明初始化函数
void detail();//声明具体信息存储的函数 
void Shortcuts();//声明游览路线呈现函数 
void Floyd();//声明使用弗洛伊德算法 
void display(int i,int j);//打印两个景点的路径及最短路径
//int shortdistance();//要查找的两景点的最短路径


void Information()//实现景点简介函数 
{
	cout<<"\t"<<"景点编号"<<"\t\t"<<"景点名称"<<"\t\t"<<"景点简介"<<endl; 
	cout<<"\t"<<"  001"<<"\t\t\t"<<"校园南门"<<"\t\t"<<"我校正门"<<endl;
	cout<<"\t"<<"  002"<<"\t\t\t"<<"科学楼"<<"\t\t\t"<<"办公楼"<<endl;
	cout<<"\t"<<"  003"<<"\t\t\t"<<"人文楼"<<"\t\t\t"<<"教学楼"<<endl;
	cout<<"\t"<<"  004"<<"\t\t\t"<<"奥运场馆"<<"\t\t"<<"羽毛球馆"<<endl;
	cout<<"\t"<<"  005"<<"\t\t\t"<<"经管楼"<<"\t\t\t"<<"经管学院"<<endl;
	cout<<"\t"<<"  006"<<"\t\t\t"<<"一号宿舍楼"<<"\t\t"<<"学生公寓"<<endl;
	cout<<"\t"<<"  007"<<"\t\t\t"<<"天天餐厅"<<"\t\t"<<"又名新食堂"<<endl;
	cout<<"\t"<<"  008"<<"\t\t\t"<<"北小门"<<"\t\t\t"<<"前有理发店"<<endl;
	cout<<"\t"<<"  009"<<"\t\t\t"<<"东门"<<"\t\t\t"<<"有时候取快递"<<endl;
	cout<<"\t"<<"  010"<<"\t\t\t"<<"西门"<<"\t\t\t"<<"另一个大门"<<endl;//工整地给用户呈现校园主要景点简介 
}
 
void Init()//实现初始化函数，再次函数内部将校园信息纳入 
{
    int i,j;//声明整型计数器以便后续循环时使用 
    G.Spot[1].num=1;//将第一个景点数组中景点的编号初始化为1 
	strcpy(G.Spot[1].data.name,"校园南门");//使用字符串复制函数，将字符串复制到第一个景点数据中的name地址空间 
    strcpy(G.Spot[1].data.number,"001");//使用字符串赋值函数将编号复制到第一个景点数据中的number地址空间 
    strcpy(G.Spot[1].data.detail,"南门是我们学校的正门，校园摄影从这里开始。");//将信息复制到detail地址空间 
	
    G.Spot[2].num=2;//将第二个景点数组中景点的编号初始化为2 
    strcpy(G.Spot[2].data.name,"科学楼");//使用字符串复制函数，将字符串复制到第二个景点数据中的name地址空间 
    strcpy(G.Spot[2].data.number,"002");//使用字符串赋值函数将编号复制到第二个景点数据中的number地址空间 
    strcpy(G.Spot[2].data.detail,"校行政官员办公楼，部分同学的实验楼。");//将信息复制到detail开始的地址空间 
	
    G.Spot[3].num=3;//将第三个景点数组中景点的编号初始化为3
    strcpy(G.Spot[3].data.name,"人文楼");//使用字符串复制函数，将字符串复制到第三个景点数据中的name地址空间 
    strcpy(G.Spot[3].data.number,"003");//使用字符串赋值函数将编号复制到第三个景点数据中的number地址空间
    strcpy(G.Spot[3].data.detail,"在科学楼东南侧，是文法学部和建规学院同学上课的楼。");
	
    G.Spot[4].num=4;//将第四个景点数组中景点的编号初始化为4
    strcpy(G.Spot[4].data.name,"奥运场馆");//使用字符串复制函数，将字符串复制到第四个景点数据中的name地址空间 
    strcpy(G.Spot[4].data.number,"004");//使用字符串赋值函数将编号复制到第四个景点数据中的number地址空间
    strcpy(G.Spot[4].data.detail,"在人文楼东侧，2008年奥运会时用作羽毛球馆，目前进去打羽毛球会按小时收费。");
	
    G.Spot[5].num=5;//将第五个景点数组中景点的编号初始化为5
    strcpy(G.Spot[5].data.name,"经管楼");//使用字符串复制函数，将字符串复制到第五个景点数据中的name地址空间 
    strcpy(G.Spot[5].data.number,"005");//使用字符串赋值函数将编号复制到第五个景点数据中的number地址空间
    strcpy(G.Spot[5].data.detail,"在科学楼西侧，经管学院同学们的书房，楼宇不大，但麻雀虽小五脏俱全。");
	
    G.Spot[6].num=6;//将第六个景点数组中景点的编号初始化为6
    strcpy(G.Spot[6].data.name,"一号宿舍楼");//使用字符串复制函数，将字符串复制到第六个景点数据中的name地址空间 
    strcpy(G.Spot[6].data.number,"006");//使用字符串赋值函数将编号复制到第六个景点数据中的number地址空间
    strcpy(G.Spot[6].data.detail,"17级男生宿舍，供男生晚间回寝休息使用。");
	
    G.Spot[7].num=7;//将第七个景点数组中景点的编号初始化为7
    strcpy(G.Spot[7].data.name,"天天餐厅");//使用字符串复制函数，将字符串复制到第七个景点数据中的name地址空间 
    strcpy(G.Spot[7].data.number,"007");//使用字符串赋值函数将编号复制到第七个景点数据中的number地址空间
    strcpy(G.Spot[7].data.detail,"在一号楼东侧，清真餐厅顶部，校内比较大的餐厅，有两层，较为豪华。");
	
    G.Spot[8].num=8;//将第八个景点数组中景点的编号初始化为8
    strcpy(G.Spot[8].data.name,"北小门");//使用字符串复制函数，将字符串复制到第八个景点数据中的name地址空间 
    strcpy(G.Spot[8].data.number,"008");//使用字符串赋值函数将编号复制到第八个景点数据中的number地址空间
    strcpy(G.Spot[8].data.detail,"在一号宿舍楼东侧，校医院旁，出去就是潘道庙公交站。");
	
    G.Spot[9].num=9;//将第九个景点数组中景点的编号初始化为9
    strcpy(G.Spot[9].data.name,"东门");//使用字符串复制函数，将字符串复制到第九个景点数据中的name地址空间 
    strcpy(G.Spot[9].data.number,"009");//使用字符串赋值函数将编号复制到第九个景点数据中的number地址空间
    strcpy(G.Spot[9].data.detail,"东门在最东侧，门很小，出去就是停车场。");
	
    G.Spot[10].num=10;//将第十个景点数组中景点的编号初始化为10
    strcpy(G.Spot[10].data.name,"西门");//使用字符串复制函数，将字符串复制到第十个景点数据中的name地址空间 
    strcpy(G.Spot[10].data.number,"010");//使用字符串赋值函数将编号复制到第十个景点数据中的number地址空间 
    strcpy(G.Spot[10].data.detail,"西门是公共交通较多的地方，这里有地铁站，马路对面还是另一个校区。");//同上所述 
	
	
    for(i=1;i<=10;i++)//在第一个景点到第十个景点中循环 
	{
		for(j=1;j<=10;j++)//内层再循环 
        {
			G.length[i][j]=MaxRoad;//将最大路径的值赋给每个路径 
        }
    }//初始化最大路径成功 
    for(i=1;i<=10;i++)//第一个到最后一个景点循环计数 
    {
		shortest[i][j]=0;//将每个景点之间的最短路径初始化为0 
    }//初始化最短路径成功
	 
    G.length[1][2]=G.length[2][1]=50;
    G.length[2][3]=G.length[3][2]=50;
    G.length[3][4]=G.length[4][3]=60;
    G.length[4][5]=G.length[5][4]=100;
    G.length[5][6]=G.length[6][5]=100;
    G.length[6][7]=G.length[7][6]=220;
	G.length[6][9]=G.length[9][6]=80; 
    G.length[7][8]=G.length[8][7]=250;
    G.length[8][9]=G.length[9][8]=100;
	G.length[9][10]=G.length[10][9]=150;//通过给每条路径进行赋值来定义各个景点间的路径长度 
	
    G.length[1][1]=G.length[2][2]=G.length[3][3]=G.length[4][4]=G.length[9][9]=0;
    G.length[5][5]=G.length[6][6]=G.length[7][7]=G.length[8][8]= G.length[10][10]=0;//将同一点之间的路径归0处理   
}
 
void detail()//实现景点具体信息的存储 
{
    int m;//声明景点编号的整型常量 
    cout<<"请输入查询景点的编号： "<<endl;//提示用户输入景点编号 
	cin>>m;//用户输入 
	fflush(stdin);//清除缓冲区 
	
    switch(m)//根据用户所输入的编号，对应相应的景点具体信息 
    {
	case 1:
		cout<<"景点编号:  "<<G.Spot[1].data.number<<endl;
		cout<<"景点名称： "<<G.Spot[1].data.name<<endl; 
		cout<<"景点简介： "<<G.Spot[1].data.detail<<endl;
		break;
	case 2:
		cout<<"景点编号:  "<<G.Spot[2].data.number<<endl;
		cout<<"景点名称： "<<G.Spot[2].data.name<<endl; 
		cout<<"景点简介： "<<G.Spot[2].data.detail<<endl;
		break;
	case 3:
		cout<<"景点编号:  "<<G.Spot[3].data.number<<endl;
		cout<<"景点名称： "<<G.Spot[3].data.name<<endl; 
		cout<<"景点简介： "<<G.Spot[3].data.detail<<endl;
		break;
	case 4:
		cout<<"景点编号:  "<<G.Spot[4].data.number<<endl;
		cout<<"景点名称： "<<G.Spot[4].data.name<<endl; 
		cout<<"景点简介： "<<G.Spot[4].data.detail<<endl;
		break;
	case 5:
		cout<<"景点编号:  "<<G.Spot[5].data.number<<endl;
		cout<<"景点名称： "<<G.Spot[5].data.name<<endl; 
		cout<<"景点简介： "<<G.Spot[5].data.detail<<endl;
		break;
	case 6:
		cout<<"景点编号:  "<<G.Spot[6].data.number<<endl;
		cout<<"景点名称： "<<G.Spot[6].data.name<<endl; 
		cout<<"景点简介： "<<G.Spot[6].data.detail<<endl;
		break;
	case 7:
		cout<<"景点编号:  "<<G.Spot[7].data.number<<endl;
		cout<<"景点名称： "<<G.Spot[7].data.name<<endl; 
		cout<<"景点简介： "<<G.Spot[7].data.detail<<endl;
		break;
	case 8:
		cout<<"景点编号:  "<<G.Spot[8].data.number<<endl;
		cout<<"景点名称： "<<G.Spot[8].data.name<<endl; 
		cout<<"景点简介： "<<G.Spot[8].data.detail<<endl;
		break;
	case 9:
		cout<<"景点编号:  "<<G.Spot[9].data.number<<endl;
		cout<<"景点名称： "<<G.Spot[9].data.name<<endl; 
		cout<<"景点简介： "<<G.Spot[9].data.detail<<endl;
		break;
	case 10:
		cout<<"景点编号:  "<<G.Spot[10].data.number<<endl;
		cout<<"景点名称： "<<G.Spot[10].data.name<<endl; 
		cout<<"景点简介： "<<G.Spot[10].data.detail<<endl;
		break;//根据用户所输入的内容，对应地呈现相应景点具体信息 

	default:
		cout<<"输入序号还未编入景点信息！"<<endl;
		break;//当用户输入编号不在1-10的范围内，将提示用户输入有误 
    }
    cout<<endl;
    system("pause");
    system("cls");//刷新屏幕 
}

void Shortcuts()//呈现经典建的路径长度，距离 
{
	cout<<"1-2路径长度为"<<G.length[1][2]<<"米。"<<endl; 
	cout<<"2-3路径长度为"<<G.length[2][3]<<"米。"<<endl; 
	cout<<"3-4路径长度为"<<G.length[3][4]<<"米。"<<endl; 
	cout<<"4-5路径长度为"<<G.length[4][5]<<"米。"<<endl; 
	cout<<"5-6路径长度为"<<G.length[5][6]<<"米。"<<endl; 
	cout<<"6-7路径长度为"<<G.length[6][7] <<"米。"<<endl; 
	cout<<"7-8路径长度为"<<G.length[7][8]<<"米。"<<endl; 
	cout<<"8-9路径长度为"<<G.length[8][9]<<"米。"<<endl;//给用户呈现路径之间的长度 
    system("pause");//待程序执行完成并呈现 
	system("cls");//刷屏 
    fflush(stdin);//清空缓冲区 
}
  
void Floyd()//使用弗洛伊德算法 
{
    int i,j,k;
    
    for(i=1;i<=10;i++)//计数器循环计数 
    {
		for(j=1;j<=10;j++)//第二层循环 
		{
			shortest[i][j]=G.length[i][j];//将最短的路径赋给最长的路径 
			path[i][j]=0;//路长初始化为0 
		}
    } //初始化数组成功 
    
    for(k=1;k<=10;k++)//计数器循环计数 
    {
		for(i=1;i<=10;i++)//第二层循环 
		{
			for(j=1;j<=10;j++)//第三层循环 
			{
				if(shortest[i][j]>(shortest[i][k]+shortest[k][j]))//如果最短路径长度大于两路径的长度之和 
				{
					shortest[i][j]=shortest[i][k]+shortest[k][j];//将两路径之和的值赋给最短路径 
					path[i][j]=k;//将点的值赋给路径以记录经过的路径 
					path[j][i]=k;//将点的值赋给路径以记录经过的路径
				}
			}			
		}
    }
}
 
void display(int i,int j)//打印两个景点的路径及最短路径*
{         
    int a,b;//声明两个整型变量，便于后续用作景点 
    a=i;  b=j;//将计数器的值赋给两个景点 
    cout<<endl<<endl<<"最短路径是："<<a; //呈现出发点的编号 
	while(path[i][j]!=0)//把i到j的路径上所有经过的景点按顺序打印出来
	{      
			cout<<"-->"<<path[i][j];//呈现每条经过的景点编号 
			if(i<j)//比较两计数器的值 
				j=path[i][j];
			else
				i=path[j][i];
		}
		cout<<"->"<<b<<endl;//呈现目的地编号 
		cout<<a<<"->"<<b<<"的最短路径是："<<shortest[a][b]<<"米。"<<endl;//呈现最短路径的结果 
		system("pause");//输出后暂停一下，以便最短路径输出完毕 
		system("cls");//待二者均输出完毕后，刷新屏幕，用户点击任意键继续使用程序的其他功能 

}
 
int shortdistance()//要查找的两景点的最短路径
{    
    int i,j;//声明整型变量以作输入出发地与目的地编号的值 
    cout<<"请输入出发地编号："; 
	cin>>i;//用户输入出发地点的编号 
	cout<<"请输入目的地编号：";
	cin>>j;//用户输入目的地的编号 
	 
    if(i>10||i<0||j>10||j<0)//如果用户输入的编号不在1-10的范围内 
    {
    	cout<<"输入有误！请重新输入！确保在景点编号范围内！"<<endl<<endl;
	}//提示用户输入错误 
	else//否则 
    {
		Floyd();//函数内调用并运行佛洛依德算法以求出二者间的最短路径 
		display(i,j);//函数内调用并运行呈现出最短路径的函数 
    }
    return 1;//返回值为1，为后续循环呈现打下伏笔 
    fflush(stdin);//清空缓冲区 
}
 

int main()
{
    char k;//声明整型变量k作为用户输入相应的选项 
    Init();//调用初始化函数，对景点信息进行初始化
	 
    cout<<"\t\t"<<"北工大校园游览系统"<<endl; 
    while(1)//当一下字符输入时，程序循环执行相应的命令 
    {   
    	cout<<"\t"<<"1.主要景点信息"<<endl;
    	cout<<"\t"<<"2.具体景点信息查询"<<endl; 
    	cout<<"\t"<<"3.主要游览路线"<<endl; 
    	cout<<"\t"<<"4.查询游览捷径"<<endl;
    	cout<<"\t"<<"5.退出系统"<<endl;
    	cin>>k; //用户输入相应的选项 
		
		switch(k)//根据用户所输入的选项进行判断并选取调用其中合适的函数进行实现 
		{
			case '1'://当用户输入的是1 
				Information();	//调用景点简介信息 
				system("pause");//带程序执行完成并呈现 
				system("cls");//刷屏
				break;
			
			case '2':
				detail();//调用实现景点具体信息的函数	
				break;
				
			case '3':
				Shortcuts();//调用呈现景点之间路径长度的函数 
				break;
				
			case '4':
				shortdistance();//调用求出最短路径的函数（由于该函数内部已经有两个函数，故调用时较为方便 ） 
				break;
				
			case '5':
				cout<<"感谢使用本程序！"<<endl; //在完整退出程序前给用户一个友情的提示 
				exit(0);
		}
    }
    system("pause");//为防止每一步运行完就立刻执行完毕并关闭程序，让函数停顿 
	return 0;
}

