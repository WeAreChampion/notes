#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STEP 20
/*
	1.index: 0���ǣ�1����2���ˣ�3��ũ��
	2.value��0��������1���԰�
	3.ũ����ӣ��ǳ�����Բˣ�һ��ֻ��Я��һ�֣�
		�������������� 
	4.a[i][j]ȡֵΪ0 ���� 1����ʾ��i�ι���ʱj���ڵ�λ�á�
	5.b[i]��ʾ��i�ι���ʱ����Я���Ķ�������ũ��ÿ�ζ�����
		�ڴ��ϣ����в��ü�¼�����Ǵ���ֻ��ũ��һ���ˡ� 
		
	���ԣ��Ƿ�ȫ�����ӵ������ת��Ϊ�ж�a[i][0], a[i][1],
		a[i][2],a[i][3]�Ƿ�ȫΪ1�������֮���Ƿ�Ϊ4������
		���е������ܷ���һ��ͽ�ת�����Ǹ��Ե�a[i][j]�Ƿ�
		��ȵ������ˡ� 
*/
int a[MAX_STEP][4];
int b[MAX_STEP];
//Я������Ʒ 
char *name[] = 
{
	"����",
	"����",
	"����",
	"����"
};
//iStep ��ʾ�ݹ����. 
void search(int iStep)
{
	int i;
 	//������԰����ݹ��������������н� 
 	if(a[iStep][0] + a[iStep][1] + a[iStep][2] + a[iStep][3] == 4){
  		for(i = 0; i < iStep; i++) {
  			//��־λ��Ϊ0���ʾ���԰�ȥ��ͬʱ���Я���Ķ��� 
   			if(a[i][3] == 0) {
    			printf("%s���԰�\n", name[b[i] + 1]);
   			} else {//Ϊ1���ʾ�ر���
    			printf("%s�ر���\n", name[b[i] + 1]);
   			}
  		}
  		printf("\n");
  		return;
 	}
 	//���ӹ����Ƿ���ֹ������ֹ���ֱ�ӽ��� 
 	for(i = 0; i < iStep; i++) {
  		if(memcmp(a[i], a[iStep], sizeof(a[i])) == 0) {
   			return;
  		}
 	}
 	//�򲻺�ũ��һ������Ͳ�һ������Ǻ���һ��
 	//	�ݹ������
	 
 	if(a[iStep][1] != a[iStep][3] 
	 	&& (a[iStep][2] == a[iStep][1] 
	 	|| a[iStep][0] == a[iStep][1])) {
  		return;
 	}
 	//û�г��ֹ����򽫹��Ӻ�ִ���һ���Ľ����¼������ 
 	//��������һ��������
 	//�����������ǰ�Ƿ�ִ�й����������Լ�����
	//	�Ķ����Լ�����λ�ú���ǰ��ȫ��ͬ��
	for(i = -1; i <= 2; i++) {
	  	b[iStep] = i;
	  	//�ı���Ե�״̬���ر�������ȥ�԰� 
	  	//copy array a[iStep] -> a[iStep + 1]
	  	memcpy(a[iStep + 1], a[iStep], sizeof(a[iStep + 1]));
	  	
	  	//change a[iStep + 1][3] value = 1 - a[iStep + 1][3];
	  	a[iStep + 1][3] = 1 - a[iStep + 1][3];
	  	//i == -1ʱ��������һ������ 
 		if (i == -1) {
	   		search(iStep + 1);
	  	} else if (a[iStep][i] == a[iStep][3]) {//ũ��͵�ǰ��Ʒһ����� 
   			//����״̬��ͬ 
			a[iStep + 1][i] = a[iStep + 1][3];
			//��һ�� 
			search(iStep + 1);
  		}
 	}
}
int main()
{
	search(0);
	return 0;
}