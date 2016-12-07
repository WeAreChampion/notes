#include<iostream>
using namespace std;
#defind Max_Block_Size 10
//最佳页面置换算法
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
//从start位置处往后查找查找将来最久未使用的 
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
	//从下标0开始到blockLength缺页，直接调入内存，写入页表 
	for(i=0;i<blockLength;i++)
	{
		a[i]=s[i]-'0';
	}
	//向后查找，找将来最久未使用的页面置换出来
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