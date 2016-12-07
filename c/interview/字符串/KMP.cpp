#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define MAX_SIZE 100
/**
	根据模式子串初始化next数组
	引入next数组意义：匹配失败时，存储需要后移的值
	next[j] = k：表明当模式子串第j个字符与主串匹配失败时，模式子串需要重新
	和主串中该字符进行比较的字符的位置；即模式子串下一次匹配的位置从k开始
*/
void getNext(string substring, int next[]) {
	int j, k;
	
	// 1. init the value
	j = 0;
	k = -1;
	next[0] = -1;
	
	// 2. get the string substring's length
	int length = substring.size();
	
	// 3.calculate the int array next[] 
	while(j < length - 1) {
		if(k == -1 || substring[j] == substring[k]) {
			j++;
			k++;
			next[j] = k;
		} else {
			k = next[k];
		}
	}
}

/**
	KMP算法，实现快速查找子串的位置
	Tn = O(n + m)
	若找到，返回第一次匹配成功的下标；否则返回-1
*/
int KMPIndex(string src, string substring) {
	// 1. init the var value
	int next[MAX_SIZE], i = 0, j = 0;
	
	// 2. get the next array
	getNext(substring, next);
	
	int lengthSrc = src.size();
	int lengthSubstring = substring.size();
	
	// 3.执行匹配与移动操作
	while(i < lengthSrc && j < lengthSubstring) {
		// 字符匹配成功
		if(j == -1 || src[i] == substring[j]) {
			i++;
			j++;
		} else {
			
			// j的值为next[j]，i不变
			j = next[j];
		}
	}
	
	// 4.判断是否匹配成功
	if(j >= lengthSubstring) {
		//返回匹配成功时第一个字母位置
		return i - lengthSubstring;
	}
	return -1;
}
/**
	根据模式子串初始化next数组
	引入next数组意义：匹配失败时，存储需要后移的值
	next[j] = k：表明当模式子串第j个字符与主串匹配失败时，模式子串需要重新
	和主串中该字符进行比较的字符的位置；即模式子串下一次匹配的位置从k开始
	KMP优化之后的getNext2
*/
void getNext2(string substring, int next[]) {
	int j, k;
	
	// 1. init the var value
	j = 0;  // 初始为0
	k = -1; // 初始为-1
	next[0] = -1; // 初始为-1
	
	// 2. get the string substring's length
	int length = substring.size();
	
	// 3.calculate the int array next[] 
	while(j < length - 1) {
		if(k == -1 || substring[j] == substring[k]) {
			j++;
			k++;
			
			// 若值不相等
			if(substring[j] != substring[k]) {
				// 值为k
				next[j] = k;
			} else {// 若值相等
				// 值为k处的值
				next[j] = next[k];
			}
		} else {
			k = next[k];
		}
	}
}

/**
	KMP算法，实现快速查找子串的位置
	Tn = O(n + m)
	若找到，返回第一次匹配成功的下标；否则返回-1
*/
int KMPIndex2(string src, string substring) {
	// 1. init the var value
	int next[MAX_SIZE], i = 0, j = 0;
	
	// 2. get the next array
	getNext2(substring, next);
	
	int lengthSrc = src.size();
	int lengthSubstring = substring.size();
	
	// 3.执行匹配与移动操作
	while(i < lengthSrc && j < lengthSubstring) {
		// 字符匹配成功
		if(j == -1 || src[i] == substring[j]) {
			i++;
			j++;
		} else {
			
			// j的值为next[j]，i不变
			j = next[j];
		}
	}
	
	// 4.判断是否匹配成功
	if(j >= lengthSubstring) {
		//返回匹配成功时第一个字母位置
		return i - lengthSubstring;
	}
	return -1;
}
void testKMPIndex() {
	string src = "acabaabaabcacaabc";
	string substring = "abaabcac";
	cout << KMPIndex(src, substring) << endl;
	cout << KMPIndex(src, "vascass") << endl;
	cout << KMPIndex(src, "acaabc") << endl;
	
	cout << KMPIndex2(src, substring) << endl;
	cout << KMPIndex2(src, "vascass") << endl;
	cout << KMPIndex2(src, "acaabc") << endl;
}
int main() {
	testKMPIndex();
	//testKMPIndex2();
	return 0;
}