#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
char num[100], len_Num; //num为字符串中所有数字字符，len_Num为num中字符个数
void Convert(char *str);//转换字符串为数字
int main()
{
	char str[100];
	while(printf("Please input a string :  "), fgets(str, sizeof(str), stdin) != NULL) {
		Convert(str);
	}
	return 0;
}
void Convert(char *str)
{
	//len_str为输入字符串长度，isPosiNum判断是否为负数，result为最后整数
	int len_str, i, isPosiNum = 1, result;
	
	//此数组再将转换后的整数转成字符串，和num数组比较，如果不一样，就溢出了！
    char check[100];
    
    //考虑fgets最后会读入一个换行符
	len_str = strlen(str) - 1; 
	
	assert(len_str > 0); //保证字符串长度
	len_Num = 0;
	isPosiNum = str[0] == '-' ? 0 : 1;
	for(i = 0; i < len_str; i++) {
		if(isdigit(str[i])) { //判断是否是数字字符
			num[len_Num++]=str[i];
		}
	}
	
	sscanf(num, "%d", &result);//转换为整数
	sprintf(check, "%d", result);
	//判断是否溢出 
	if(strcmp(check, num) != 0) {
		printf("溢出，请采用大数处理！\n");
		return;
	}
	if (isPosiNum < 0) {
		printf("-");
	}
	printf("The result is：  %d\n",result);
}
