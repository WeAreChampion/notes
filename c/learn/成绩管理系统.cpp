# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include <string.h>
# include <conio.h>//����̨����������൱���ļ���
/*stdlib.h��
stdlib.h���涨�����������͡�һЩ���ͨ�ù��ߺ�����
 ��������size_t��wchar_t��div_t��ldiv_t��lldiv_t�� 
 ������EXIT_FAILURE��EXIT_SUCCESS��RAND_MAX��MB_CUR_MAX�ȵȣ�
 ���õĺ�����malloc()��calloc()��realloc()��free()��system()��atoi()��
 atol()��rand()��srand()��exit()�ȵȡ�
*/
//��������
void menu(struct student *parr,int len);
void sore(struct student *parr,int len);
void output(struct student *parr,int *len);
void input(struct student *parr,int len);
void write(struct student *parr,int len);
void read(struct student *parr,int len);
void find(struct student *parr,int len);
void logout(struct student *parr,int len);
void exit(struct student *parr,int len);
void modify(struct student *parr,int len);
void insert(struct student*parr,int *len);

struct student 
{
	int number;//ѧ��
	float score;//�ɼ�
	char name[10];//����
};



int main(void)
{	
	struct student * parr;
	int len = 0;
	char ch = '\0';

	printf("��������Ҫ�����ѧ��������");
	scanf("%d",&len);
	
	parr = (struct student *)malloc((sizeof(struct student) * len));
	
	menu(parr, len);
	printf("���س�������\n");
	while(1)
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t|******************************************|\n");
		printf("\t\t|--------------- ѧ������ϵͳ -------------|\n");
		printf("\t\t|------------ 1.д��ѧ����Ϣ      ---------|\n");
		printf("\t\t|------------ 2.�鿴ȫ��ѧ����Ϣ  ---------|\n");
		printf("\t\t|------------ 3.���ɼ�����        ---------|\n");
		printf("\t\t|------------ 4.��ѧ�Ų���        ---------|\n");
		printf("\t\t|------------ 5.�޸�ѧ����Ϣ      ---------|\n");
		printf("\t\t|------------ 6.���ѧ��          ---------|\n");
		printf("\t\t|------------ 7.����              ---------|\n");
		printf("\t\t|------------ 0.�˳�              ---------|\n");
		printf("\t\t|******************************************|\n");
		printf("\t\t\n");
		scanf(" %c",&ch);

		switch(ch)
		{
			case '1' :	input(parr,len);	break;
			case '2' :	output(parr,&len);	break;
			case '3' :	sore(parr,len);		break;
			case '4' :	find(parr,len);		break;
			case '5' :	modify(parr,len);	break;
			case '6' :	insert(parr,&len);	break;
			case '7' :	write(parr,len);	break;
			case '0' :	exit(parr,len);	break;
			default :	printf("\n\t�������!���س����������˵���");
			getch();
		}
	}
	

	free(parr);

	return 0 ;
}


//�������ܣ�ʵ�ְ��ɼ�����
void sore(struct student *parr,int len)
{
	int i,j;
	struct student t;

		for( i = 0; i < len - 1; i++)
		{
			for(j = 0; j < len; j++)
				if( parr[j+1].score > parr[j].score )
				{
					t = parr[j+1];
					parr[j+1] = parr[j];
					parr[j] = t;
				}

		}
	output(parr,&len);
	return;
}


//�������ܣ���ӡ��Ϣ
void output(struct student *parr,int *len)
{
	int i;
	for(i = 0;i < *len; i++)
		printf("������%s  �ɼ���%.2f  ѧ�ţ�%d\n",parr[i].name,parr[i].score,parr[i].number);
	printf("\n");
	getchar();
	getchar();
	return;
}

//�������ܣ���������
void input(struct student *parr,int len )
{	int i;
	for( i = 0; i < len; i++)
	{
		printf("�������%d��ѧ����Ϣ��",i + 1);

		printf("������");
		scanf("%s",parr[i].name);//name�������� ������ǵ�ַ

		printf("�ɼ�: ");
		scanf("%f",&parr[i].score);

		printf("ѧ�ţ�");
		scanf("%d",&parr[i].number);
	}
	printf("\n");
	return;
}

/*�������ܣ�������д���ļ�*/
void write(struct student *parr,int len)
{
	int i;//����ѭ��
	FILE *fp = NULL;//�����ļ�ָ��
	fp = fopen("D:\\student.txt","w");//���ļ���ʹ�ļ�ָ��ָ��������д�ķ�ʽ
	if(fp == NULL)//����ļ�û�д򿪣���ʾ�����˳�
	{
		printf("\n\t�ļ�û�д򿪣����������");
		getchar();//�ȴ��û��۲�
		exit(0);//������������
	}
	else
	{
		for(i=0; i<len; i++)//����������д���ļ�
		{
			fprintf(fp, "������%s  �ɼ���%.2f  ѧ�ţ�%d\n",parr[i].name,parr[i].score,parr[i].number);
		}
	}
	printf("�ѽ�ѧ����Ϣ��������D�̸�Ŀ¼�µ�student.txt�ļ��С�\n");
	getch();
	fclose(fp);
	return;
}
/*�������ܣ���ȡ�ļ�����*/
void read(struct student *parr,int len)
{
	int i;
	FILE * fp = NULL;

	fp = fopen("D:\\student.txt","r");//��ֻ���ķ�ʽ���ļ�

	if(fp == NULL)
	{
		printf("���ݶ�ȡʧ��!\n");
		getchar();
		exit(0);
	}
	else
	{
		for(i=0; i<len; i++)
		{
			fscanf(fp,"%s,%d,%.2f\n",parr[i].name,parr[i].number,parr[i].score);
		}
	}

	fclose(fp);
	return;
}

/*�������ܣ���ѧ����ѧ����Ϣ*/
void find(struct student *parr,int len)
{
	int number= 0;  
	int i;
	
	printf("����������Ҫ���ҵ�ѧ�ţ�");
	scanf("%d",&number);
	
	for( i=0; i<len; i++ )
	{
		if(number == parr[i].number)
		{
			printf("������%s  �ɼ���%.2f  ѧ�ţ�%d\n",parr[i].name,parr[i].score,parr[i].number);
		}
		
	}
	getch();
	return;
}

/*�������ܣ�ע��ѧ����Ϣ*/
void logout(struct student *parr,int len)
{
	char ch = '\0';
	find(parr,len);
	printf("��ȷ��Ҫע����ѧ����ȷ���밴 Y���������˵��밴 N ��\n");
	scanf("%d",&ch);

	if((ch == 'Y') || (ch == 'y'))
	{
		
	}
	return;
}

void menu(struct student *parr,int len)
{
	printf("\t\t||=========================================||\n");
	printf("\t\t||-----------------------------------------||\n");
	printf("\t\t||-----------��ӭʹ��ѧ������ϵͳ----------||\n");
	printf("\t\t||-----------------------------------------||\n");
	printf("\t\t||=========================================||\n");
	getchar();
	getchar();
	system("cls");
	return;
}
/*�������ܣ�������������*/
void exit(struct student *parr,int len)
{//	getchar();
	char ch = '\0';

	do
	{
		printf("��ȷ��Ҫ�˳�����y/n��:");
		scanf(" %c",&ch);
	}while((ch != 'Y') && (ch != 'y') && (ch != 'N') && (ch != 'n'));
	if((ch == 'Y') || (ch == 'y'))
	{
		exit(0);
	}
	
	return;
}

/*�������ܣ��޸�ѧ����Ϣ*/
void modify(struct student *parr,int len)
{
	int number = 0;
	char ch = '\0';
	int i;
	printf("��������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%d",&number);

	for( i=0; i<len; i++ )
	{
		if(number == parr[i].number)
		{
			printf("������%s  �ɼ���%.2f  ѧ�ţ�%d\n",parr[i].name,parr[i].score,parr[i].number);
			printf("��ȷ��Ҫ�޸ĸ�ѧ����Ϣ��y/n��");
			scanf(" %c",&ch);
			if(ch == 'y')
			{
				printf("������������");
				scanf("%s",parr[i].name);

				printf("������ɼ���");
				scanf("%f",&parr[i].score);

				printf("������ѧ�ţ�");
				scanf("%d",&parr[i].number);

				printf("������%s  �ɼ���%.2f  ѧ�ţ�%d\n",parr[i].name,parr[i].score,parr[i].number);
				printf("�޸ĳɹ�!");
				getch();
			}
			else
			{
				printf("û���ҵ���ѧ��");
				getch();
				break;
			}
			
		}
		
	}
	return;
}

/*�������ܣ����ѧ��*/
void insert(struct student *parr,int *len)
{
	int number = 0;//���ѧ���ĸ���
	int i;
	printf("��������Ҫ��Ӽ���ѧ����Ϣ��");
	scanf("%d",&number);

	parr = (struct student *)malloc((sizeof(struct student) * (*len+number)));

	for(i=*len; i<*len+number;i++)
	{
		printf("�������%d��ѧ����Ϣ��",i + 1);

		printf("������");
		scanf("%s",parr[i].name);

		printf("�ɼ�: ");
		scanf("%f",&parr[i].score);

		printf("ѧ�ţ�");
		scanf("%d",&parr[i].number);
	}
	output(parr,&*len);
}