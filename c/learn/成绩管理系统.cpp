# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include <string.h>
# include <conio.h>//控制台输入输出，相当于文件流
/*stdlib.h：
stdlib.h里面定义了五种类型、一些宏和通用工具函数。
 类型例如size_t、wchar_t、div_t、ldiv_t和lldiv_t； 
 宏例如EXIT_FAILURE、EXIT_SUCCESS、RAND_MAX和MB_CUR_MAX等等；
 常用的函数如malloc()、calloc()、realloc()、free()、system()、atoi()、
 atol()、rand()、srand()、exit()等等。
*/
//函数声明
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
	int number;//学号
	float score;//成绩
	char name[10];//姓名
};



int main(void)
{	
	struct student * parr;
	int len = 0;
	char ch = '\0';

	printf("请输入需要存入的学生人数：");
	scanf("%d",&len);
	
	parr = (struct student *)malloc((sizeof(struct student) * len));
	
	menu(parr, len);
	printf("按回车键继续\n");
	while(1)
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t|******************************************|\n");
		printf("\t\t|--------------- 学生管理系统 -------------|\n");
		printf("\t\t|------------ 1.写入学生信息      ---------|\n");
		printf("\t\t|------------ 2.查看全部学生信息  ---------|\n");
		printf("\t\t|------------ 3.按成绩排序        ---------|\n");
		printf("\t\t|------------ 4.按学号查找        ---------|\n");
		printf("\t\t|------------ 5.修改学生信息      ---------|\n");
		printf("\t\t|------------ 6.添加学生          ---------|\n");
		printf("\t\t|------------ 7.保存              ---------|\n");
		printf("\t\t|------------ 0.退出              ---------|\n");
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
			default :	printf("\n\t输入错误!按回车键返回主菜单！");
			getch();
		}
	}
	

	free(parr);

	return 0 ;
}


//函数功能：实现按成绩排序
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


//函数功能：打印信息
void output(struct student *parr,int *len)
{
	int i;
	for(i = 0;i < *len; i++)
		printf("姓名：%s  成绩：%.2f  学号：%d\n",parr[i].name,parr[i].score,parr[i].number);
	printf("\n");
	getchar();
	getchar();
	return;
}

//函数功能：输入数据
void input(struct student *parr,int len )
{	int i;
	for( i = 0; i < len; i++)
	{
		printf("请输入第%d个学生信息：",i + 1);

		printf("姓名：");
		scanf("%s",parr[i].name);//name是数组名 本身就是地址

		printf("成绩: ");
		scanf("%f",&parr[i].score);

		printf("学号：");
		scanf("%d",&parr[i].number);
	}
	printf("\n");
	return;
}

/*函数功能：将数据写入文件*/
void write(struct student *parr,int len)
{
	int i;//控制循环
	FILE *fp = NULL;//定义文件指针
	fp = fopen("D:\\student.txt","w");//打开文件并使文件指针指向它，以写的方式
	if(fp == NULL)//如果文件没有打开，提示错误并退出
	{
		printf("\n\t文件没有打开！程序结束！");
		getchar();//等待用户观察
		exit(0);//结束整个程序
	}
	else
	{
		for(i=0; i<len; i++)//将数据依次写入文件
		{
			fprintf(fp, "姓名：%s  成绩：%.2f  学号：%d\n",parr[i].name,parr[i].score,parr[i].number);
		}
	}
	printf("已将学生信息保存在了D盘根目录下的student.txt文件中。\n");
	getch();
	fclose(fp);
	return;
}
/*函数功能：读取文件数据*/
void read(struct student *parr,int len)
{
	int i;
	FILE * fp = NULL;

	fp = fopen("D:\\student.txt","r");//以只读的方式打开文件

	if(fp == NULL)
	{
		printf("数据读取失败!\n");
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

/*函数功能：按学号找学生信息*/
void find(struct student *parr,int len)
{
	int number= 0;  
	int i;
	
	printf("请您输入需要查找的学号：");
	scanf("%d",&number);
	
	for( i=0; i<len; i++ )
	{
		if(number == parr[i].number)
		{
			printf("姓名：%s  成绩：%.2f  学号：%d\n",parr[i].name,parr[i].score,parr[i].number);
		}
		
	}
	getch();
	return;
}

/*函数功能：注销学生信息*/
void logout(struct student *parr,int len)
{
	char ch = '\0';
	find(parr,len);
	printf("您确定要注销该学生吗？确定请按 Y，返回主菜单请按 N ！\n");
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
	printf("\t\t||-----------欢迎使用学生管理系统----------||\n");
	printf("\t\t||-----------------------------------------||\n");
	printf("\t\t||=========================================||\n");
	getchar();
	getchar();
	system("cls");
	return;
}
/*函数功能：结束整个程序*/
void exit(struct student *parr,int len)
{//	getchar();
	char ch = '\0';

	do
	{
		printf("您确定要退出！（y/n）:");
		scanf(" %c",&ch);
	}while((ch != 'Y') && (ch != 'y') && (ch != 'N') && (ch != 'n'));
	if((ch == 'Y') || (ch == 'y'))
	{
		exit(0);
	}
	
	return;
}

/*函数功能：修改学生信息*/
void modify(struct student *parr,int len)
{
	int number = 0;
	char ch = '\0';
	int i;
	printf("请您输入要修改的学生的学号：");
	scanf("%d",&number);

	for( i=0; i<len; i++ )
	{
		if(number == parr[i].number)
		{
			printf("姓名：%s  成绩：%.2f  学号：%d\n",parr[i].name,parr[i].score,parr[i].number);
			printf("您确定要修改该学生信息（y/n）");
			scanf(" %c",&ch);
			if(ch == 'y')
			{
				printf("请输入姓名：");
				scanf("%s",parr[i].name);

				printf("请输入成绩：");
				scanf("%f",&parr[i].score);

				printf("请输入学号：");
				scanf("%d",&parr[i].number);

				printf("姓名：%s  成绩：%.2f  学号：%d\n",parr[i].name,parr[i].score,parr[i].number);
				printf("修改成功!");
				getch();
			}
			else
			{
				printf("没有找到该学生");
				getch();
				break;
			}
			
		}
		
	}
	return;
}

/*函数功能：添加学生*/
void insert(struct student *parr,int *len)
{
	int number = 0;//添加学生的个数
	int i;
	printf("请输入您要添加几个学生信息：");
	scanf("%d",&number);

	parr = (struct student *)malloc((sizeof(struct student) * (*len+number)));

	for(i=*len; i<*len+number;i++)
	{
		printf("请输入第%d个学生信息：",i + 1);

		printf("姓名：");
		scanf("%s",parr[i].name);

		printf("成绩: ");
		scanf("%f",&parr[i].score);

		printf("学号：");
		scanf("%d",&parr[i].number);
	}
	output(parr,&*len);
}