#include<iostream>
using namespace std;
#defind Max_Block_Size 10
//���ҳ���û��㷨
//find the elem in array by sequential search
int Find(int a[],int length,int elem)
{
	int pos=-1;
	for(int i=0;i<length;i++)
	{
		if(a[i]==elem)
			pos=i;
	}
	return pos;
} 
//��startλ�ô�������Ҳ��ҽ������δʹ�õ� 
int FindPageId(int a[],int blockLength,int page[],int start)
{
	int *position=new int[blockLength];
	for(int i=start;i<s.size();i++)
	{
		for(int j=0;j<blockLength;j++)
		{
			if(Find(a,blockLength,page[i])==-1)
			{
				
			}
		}
	} 
}
int BestChangePage(string s,int blockLength,int a[])
{
	int count=0;//count the page that doesn't in memory 
	int i=0;
	//���±�0��ʼ��blockLengthȱҳ��ֱ�ӵ����ڴ棬д��ҳ�� 
	for(i=0;i<blockLength;i++)
	{
		a[i]=s[i]-'0';
	}
	//�����ң��ҽ������δʹ�õ�ҳ���û�����
	for(int start=i;start<s.size();start++)
	{
		if(Find(a,blockLength,s[i]-'0')==-1)//Not Find
		{
			//Find the 
		}
	} 
}
void TestBest()
{
	
}
int main()
{
	return 0;
}