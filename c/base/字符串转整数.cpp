#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
char num[100], len_Num; //numΪ�ַ��������������ַ���len_NumΪnum���ַ�����
void Convert(char *str);//ת���ַ���Ϊ����
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
	//len_strΪ�����ַ������ȣ�isPosiNum�ж��Ƿ�Ϊ������resultΪ�������
	int len_str, i, isPosiNum = 1, result;
	
	//�������ٽ�ת���������ת���ַ�������num����Ƚϣ������һ����������ˣ�
    char check[100];
    
    //����fgets�������һ�����з�
	len_str = strlen(str) - 1; 
	
	assert(len_str > 0); //��֤�ַ�������
	len_Num = 0;
	isPosiNum = str[0] == '-' ? 0 : 1;
	for(i = 0; i < len_str; i++) {
		if(isdigit(str[i])) { //�ж��Ƿ��������ַ�
			num[len_Num++]=str[i];
		}
	}
	
	sscanf(num, "%d", &result);//ת��Ϊ����
	sprintf(check, "%d", result);
	//�ж��Ƿ���� 
	if(strcmp(check, num) != 0) {
		printf("���������ô�������\n");
		return;
	}
	if (isPosiNum < 0) {
		printf("-");
	}
	printf("The result is��  %d\n",result);
}
