#include<iostream> 
#include<string> 
#include<set> 
using namespace std;
int main()
{
	set<string> st;
	string s = "";
	char c;
	// 输入以#号结束
	while((c = getchar()) != '#') {
		
		// 累加到string中
		s += c;
		
		// 判断字符c是否为空行
		while(c != '\n') {
			while((c = getchar()) != ' ' && c != '\n') { 
				s += c;
			} 
			
			// 插入到set中，有去重效果
			if(s.length()) {
				st.insert(s);
			}
			s = "";
		}
		cout << st.size() << endl;
		st.clear();
	}
	return 0;
}
/*
you are my friend
#
*/