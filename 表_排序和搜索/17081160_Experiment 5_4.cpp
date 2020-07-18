/*
	����:���ζ���������˹�� 
	ѧ��:17081160 
	רҵ:����ý�弼�� 
	ʱ��: 20/12/18 21:17
	����:ʵ����ĵ��ĵ��� 
*/

#include <iostream>
using namespace std;
 
class BsTree 
{
	public:
	 	BsTree()//���캯����ʼ������ΪNULL����ʾ����
	 	{
	 		p_root=NULL;//��������ʼ�����ڵ� 
	 	}
    	
    	void Insert(int nData)//ʵ�ֲ������ݵĹ��� 
		{
        	Insert(new Node(nData),p_root);//�����ݲ������� 
    	}
		
    bool Remove(int nData)//ʵ��ɾ�����ݵĹ��ܣ�������ݲ����ڣ��򷵻�0
	{
        Node*& pFind=Find(nData, p_root);//����ָ���ͱ��� 
        if(pFind) 
		{
            Insert(pFind->p_Left,pFind->p_Right);//�ڲ���ǰ��Ҫ���ڵ������洢�ռ�ָ��ֵ������뺯�� 
            Node* pNode=pFind;//����ָ��Node�ͱ��� 
            pFind=pFind->p_Right;//���ڵ�ָ���ֵ������ѯֵ 
            delete pNode;//ֱ��ɾ���ýڵ� 
            return 1;//���ڸ����ݣ�����1 
        }
        return 0;//�������򷵻�0 
    }
    
    void Travel()//ͨ�����������������Ԫ��0 
	{
        cout<<'{';
        Travel(p_root);//�ݹ���� 
        cout<<'}'<<endl;
    }
    
	private:
		    class Node//�ڵ��� 
			{
    			public:
        			Node(int nData)//��ʼ���ڵ㺯�� 
					{
						m_nData=nData;
						p_Left=NULL; 
						p_Right=NULL;//���������ÿգ����г�ʼ�� 
					}
        		int m_nData;//�������ͱ�������
        		Node* p_Left;//�����ڵ��ͱ�����ߵ���
        		Node* p_Right;//�����ڵ��ͱ����ұߵ���
    		};
    
			void Insert(Node* pNode, Node*& pTree)//ʵ�ֲ��빦�ܵĺ��� 
			{
        		if(!pTree)     pTree=pNode;//������Ǹýڵ��򽫽ڵ��ֵ�������������е����ݱ��� 
        		else if(pNode) 
				{
            		if(pNode->m_nData<pTree->m_nData)//���ڵ����洢λ�õ�ֵС�ڽڵ��ֵ 
                	Insert(pNode,pTree->p_Left);//���뵽�������в�����Ӧ������Ƚ� 
            		else
                	Insert(pNode,pTree->p_Right);//���򽫽ڵ�Ͷ�������ָ��Ĵ洢λ�ô���ʵ���Բ��� 
        		}
    		}
    
			Node*&Find(int nData,Node*& pTree) //ʵ�ֲ��ҹ��� 
			{
        		if(!pTree)//������Ƕ������е�����Ԫ�� 
       			return pTree;//���ض�������ԭ������ֵ 
        		
				else
        		if(nData==pTree->m_nData)//���򽫴洢�ռ�ָ�����ֵ��������Ԫ�� 
            	return pTree;//�ٷ�����ֵ 
        		
				else
        			if(nData<pTree->m_nData)//������Ԫ�ص�ֵ��С�ڶ���������ָ�������ֵ 
            		return Find(nData,pTree->p_Left);
					//����������ֵ������Һ����в��Ҳ����ز��Һ�Ľ�� 
        			else
            		return Find(nData,pTree->p_Right);
					//����������ֵ������Һ����в��Ҳ����ز��Һ�Ľ�� 
    		}
    
			void Travel(Node*& pTree)//�����������Ӧ�Ľ�����û����� 
			{
        		if(pTree) 
				{
            		Travel(pTree->p_Left);//����ڵ��ֵʹ�õݹ���õķ�ʽ���������������� 
            		cout<<'<'<<pTree->m_nData<<'>'; //���� 
            		Travel(pTree->p_Right);//���ҽڵ��ֵʹ�õݹ�ķ�ʽ���������������� 
        		}
    		}
    Node* p_root;//�����ڵ���ָ���������
};


int main() 
{

	int Maxsize=0;//��ʼ������������С 
	cout<<"������������С��"<<endl;
	cin>>Maxsize;//�û�������Ӧ��������С 
    int a[Maxsize];//�������û��������������СΪ�����Ӧ��������� 
    BsTree A;//��������A 
    
	for(int i=0;i<Maxsize;i++)//ͨ��ѭ�����û��Լ�������Ӧ�������е�Ԫ�� 
    {
    	cout<<"������Ҫ��������ݣ�" ;
		cin>>a[i];//�û����� 
		A.Insert(a[i]);//�������Ԫ�ش������뺯������ʵ��������ÿ��Ԫ�ص����� 
	}
	A.Travel ();//���������Ԫ��ͨ�������ķ�ʽ���ֳ��� 
	
	int remove=0;//��������ʼ��ɾ��λ�ñ��� 
    cout<<"��������ɾ��Ԫ�ص�λ�ã�";
	cin>>remove;//�û�������Ҫɾ����λ�� 
	if(remove<=Maxsize)
	{
		A.Remove(remove);//����Ҫ������λ�õ�ֵ�����������еı��� 
		A.Travel();//���������Ԫ��ͨ�������ķ�ʽ���ֳ��� 
		cout<<endl;
	}
		else cout<<"��������λ�ó�����Χ�����������룡"<<endl<<endl; 
			
		cout<<"���������Ԫ�أ�"<<endl;
		int x;
		cout<<"Ҫ�����Ԫ�ظ�����";
		cin>>x;
		for(int i=0;i<x;i++)//����û�������������ݣ�����ֱ�Ӹ�����Ӧ��ʾ���� 
		{
			cout<<"������Ҫ��������ݣ�" ;
			cin>>a[i];//��ѭ���������� 
			A.Insert(a[i]);//������������ݴ��ݸ����뺯�� 
		}
		A.Travel();//���������Ԫ��ͨ�������ķ�ʽ���ֳ��� 
    return 0;
}
