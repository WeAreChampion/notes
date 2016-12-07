#include<iostream>
using namespace std;
#include<string>
/**
	使用动态规划求解最长重复子串
*/
string getMaxSameString(string src) {
	string s = "";
	
	/** 
		index 最优结果开始下标
		length 最优结果长度
		length1 当前最优长度
	*/
	int index = 0, length = 0, length1;
	int i = 0, j, k;
	int times = src.size();
	
	//i
	while(i < times) {
		
		// j初始指向i的后一个
		j = i + 1;
		
		// j
		while(j < times) {
			
			// 相等
			if(src[i] == src[j]) {
				// 初始化当前最优长度
				length1 = 1;
				
				// 从1开始依次寻找最长相同串，当前最优长度累加
				for(k = 1; src[i + k] == src[j + k]; k++) {
					length1++;
				}
				
				// 当前最优长度大于最优长度，更新
				if(length1 > length) {
					index = i;
					length = length1;
				}
				
				//j point to j + length1；j指向j+length1
				j = j + length1;
			} else {// 不相等，j指向下一个
				j++;
			}
		}// end for j
		
		i++;
	}// end for i
	
	cout << "index : " << index << endl;
	cout << "length : " << length << endl;
	
	length = index + length;
	for(i = index; i < length; i++) {
		s += src[i];
	}
	return s;
}
void testGetMaxSameString() {
	string src = "abcdaeabcdefgabcdeeabcd";
	cout << getMaxSameString(src) << endl;
}
int main() {
	testGetMaxSameString();
	return 0;
}