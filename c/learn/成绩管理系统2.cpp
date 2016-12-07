# include<iostream.h>
# include<string.h>
# include<stdio.h>
# include<stdlib.h>
# include<fstream.h>
#include<windows.h>
//*****定义一个学生原子的的数据结构*****//
class boss
{
public:
	char  *name;// 年龄
    int   idc;//学号
    char  sex; //性别
    float math, eng, comp, totll, aver;//数学，英语，计算机，总分，平均分;
    void show();//*****定义输出函数*****// 
    void setup();//******输入学生数据并判断是否在规定区域内****// 
};
//*********定义一系列对学生的操作**********//
class student
{
private:
 	boss array[100];//*****定义一个数组********// 
 	int stulen;//******保存学生人数******// 
public:
 	student();
 	void change();//******修改学生信息******// 
 	void setnum();//******统计学生信息******// 
 	void input();//******输入学生数据的函数******// 
 	void order();//*****定义排序函数******// 
 	void save();//********定义保存学生数据的函数******// 
 	void Query();//***按一定格式显示所要查询的学生信息***// 
 	void read();//****显示所有学生数据*****// 
 	void add();//*****添加学生数据*****// 
 	void del();//******删除 指定的学生数据*****// 
};

//********对学生数据的初始化（类的构造函数）**********//
student::student()
{
  //用for循环对全部数组中的数据初始化
  	for(int i=0;i<100;i++)
  	{
   		array[i].math=array[i].eng=array[i].comp =array[i].totll =array[i].aver =0;
   		array[i].idc =0;
   		array[i].sex =' ';
   		array[i].name =NULL;
  	}
  	this->stulen =0;
}


//********输入学生的数据，并判断是否在规定数据域内*******//
void boss::setup()
{   
     char  n[20]; 
	 char  s; 
     int   b;
  	//如果输入学号在数据域内，跳出循环并且赋值。
  	//如果不再数据域内，一直循环到输入数据符合数据域为止
  	do {//循环体
	  	cout<<"   学号: ";
      	cin>>b;
      	if(b>100||b<0)
		  	cout<<"input error!!"<<endl<<endl;
   	}
  while (b<0||b>100); //如果值为b<0||b>100,则执行循环体
  idc=b;//赋值

  	//如果输入姓名在数据域内，跳出循环并且赋值。
  	//如果不再数据域内，一直循环到输入数据符合数据域为止
  	do
  	{
   		name=new char[strlen(n)+1];
   		cout<<"   姓名: ";
      	cin>>n;
    	if( strlen(n)>20 || strlen(n)<1) 
     		cout<<"input error!!"<<endl<<endl;
	}
  	while ( strlen(n)>20 || strlen(n)<1 );//如果while语句中条件为真，则执行循环体
  	strcpy(name,n);//赋值，包含在头文件string.h中

  	//如果输入性别在数据域内，跳出循环并且赋值。
  	//如果不再数据域内，一直循环到输入数据符合数据域为止
  	cout<<"   性别(m/f):" ;
  	cin>>s; 
  	while (s!='m' && s!='f')
  	{ 
	   	cout<<"input error!!"<<endl<<endl;
	   	cout<<"   性别(m/f):";
		cin>>s;    
  	}
  	sex=s;


  	float m, e, co;//数学，英语，计算机
  	cout<<"   数学: ";
  	cin>>m;
  	//如果输入数学成绩在数据域内，跳出循环并且赋值。
  	//如果不再数据域内，一直循环到输入数据符合数据域为止
  	while (m<0 || m>100)
  	{ 
	  	cout<<"input error!!"<<endl<<endl;
	  	cout<<"   数学: ";
	  	cin>>m;    
  	}
  	math=m;


  	cout<<"   英语: ";
  	cin>>e;
  	//如果输入英语成绩在数据域内，跳出循环并且赋值。
  	//如果不再数据域内，一直循环到输入数据符合数据域为止
  	while (e<0 || e>100)
  	{ 
		cout<<"input error!!"<<endl<<endl;
		cout<<"   英语: ";
		cin>>e;    
  	}
  	eng=e;
  	cout<<"   计算机: ";
 	cin>>co;
  	//如果输入学好在数据域内，跳出循环并且赋值。
  	//如果不再数据域内，一直循环到输入数据符合数据域为止
  	while (co<0 || co>100)
  	{	 
		cout<<"input error!!"<<endl<<endl;
	   	cout<<"   计算机: ";
	   	cin>>co;    
  	}
  	comp=co;
  	totll=math+eng+comp;//求总分
  	aver=(math+eng+comp)/3;//求平均分
}

 //*******按照规定格式把该学生的数据显示在屏幕上******//
void boss::show()
{ 
  	cout.setf(ios::left);//输出数据左对齐
  	cout.width(9);//设置字段宽度
  	cout<<""<<idc<<"     ";//输出学号
  	cout.width(10);
  	cout<<name;
  	cout.width(10);
  	cout<<sex;
  	cout.width(9);
  	cout<<math;
  	cout.width(9);
  	cout<<eng;
  	cout.width(11);
  	cout<<comp;
  	cout.width(10);
  	cout<<totll<<aver<<endl;  
}

//**************输入学生的数据***********************//
void student::input() 
{ 
  	int n;
  	cout<<endl<<"输入将要录入的学生数目: ";
  	cin>>n;            
  	int j; 
  	//通过循环输入要求输入学生个数的学生的数据。
  	for(j=0; j<n; j++)
  	{
   		cout<<" 输入学生信息 "<<j<<endl;
   		array[j].setup();
  	}
  	this->stulen=n;  //学生个数赋值
  	//学生数据显示格式
  	system("cls");//********清除屏幕上的信息********// 
  	cout<<endl<<"----------------------------- 学生信息表 ------------------------------------"<<endl;
  	cout<<endl<<"      学号     姓名   性别      数学     英语     计算机      总分     平均分"<<endl;

  	//通过循环输出所有学生数据。
  	for(j=0; j<n; j++) 
  	{
   		array[j].show();
  	}
  	cout<<endl;
  	cout<<"      是否保存？ (Y/N): ";
  	char Y;
  	cin>>Y;
  	system("cls");//********清除屏幕上的信息********//
}


//**************按照一定格式显示所要查询学生的信息。**************//
void student::Query()
{
   	int x , i;
   	cout<<endl<<"    输入要查询学生的学号: ";
   	cin>>x;
   	cout<<endl<<"      学号     姓名   性别      数学     英语     计算机      总分     平均分"<<endl;
   	for(i=0;i<this->stulen ;i++)//for(i=0;i<=this->stulen ;i++)
   	{  
	   	if (x==array[i].idc)
	   	{
		   	cout.setf(ios::left);//指定输出数据在本域宽范围内向左对齐 
           	cout.width(9);//*****指定宽域为6*****// 
           	cout<<""<<array[i].idc<<"     ";
           	cout.width(10);
           	cout<<array[i].name;
           	cout.width(10);
           	cout<<array[i].sex;
           	cout.width(9);
           	cout<<array[i].math;
           	cout.width(9);
           	cout<<array[i].eng;
           	cout.width(11);
           	cout<<array[i].comp;
           	cout.width(10);
           	cout<<array[i].totll<<array[i].aver<<endl;
	   	}
   	}
  	system("pause");
}
//统计总分在不同分数段的人数
void student::setnum()
{
	int m,ii=0,i,tt,n;
 	cout<<"统计范围:"<<endl;
 	cin>>m>>n;
	if(m>n)
	{
  		tt=m;m=n;n=tt;
  	}
 	 cout<<endl<<"      学号     姓名   性别      数学     英语     计算机      总分     平均分"<<endl;
 	for(i=0;i<this->stulen;i++)
 	{
	 	if(array[i].totll>=m&&array[i].totll<=n)
	 	ii++;
	 	array[i].show();//输出其所有信息
	 }
	 cout<<"此范围内的总人数为："<<ii<<endl; 
	 system("pause");
}
//*******************保存学生数据**************************//
void student::save() 
{
  	int i;
  	ofstream outfile;
  	outfile.open("f3.dat",ios::trunc);
  	if(!outfile)
  	{
   	cerr<<"open error!"<<endl;
   	exit(1);
  	}
  	//通过循环把所有的学生数据保存在list.txt里边。
  	for(i=0; i<this->stulen; i++)
  	{
   		outfile<<array[i].idc<<" "<<array[i].name<<" "<<array[i].sex<<" "<<
      	array[i].math<<" "<<array[i].eng<<" "<<array[i].comp<<" "<<array[i].totll<<" "<<array[i].aver<<endl;
  	}
    outfile.close();
}


 //*************显示所有学生数据*********************//
void student::read()
{
  	int i; 
  	system("cls");//****清屏，清除屏幕上的信息******// 
  	cout<<endl<<"----------------------------- 学生信息表 ------------------------------------"<<endl;
  	cout<<endl<<"      学号     姓名   性别      数学     英语     计算机      总分     平均分"<<endl;

  	for(i=0; i<this->stulen; i++) 
  	{
   		array[i].show();
  	}
  	system("pause");
}
//*******************添加一个学生的数据****************//
void student::add()
{ 
  	int i, d=this->stulen ;  
  	cout<<"输入要添加学生的信息："<<endl;
  	array[d].setup();
	cout<<endl<<"----------------------------- 学生信息表 ------------------------------------"<<endl;
  	cout<<endl<<"      学号     姓名   性别      数学     英语     计算机      总分     平均分"<<endl;    
  	for(i=0; i<=d; i++)
  	{
		array[i].show();  
  	}
  	system("pause");
  	ofstream fout("f3.dat",ios::app);//以输出方式打开文件，写入的数据添加到文件末尾// 
  	if(!fout)
  	{
	  	cout<<"Cannot open output file!\n,";
  	}
  	//把添加的学生数据添加到f3.dat里边去。
  	fout<<array[d].idc<<" "<<array[d].name<<" "<<array[d].sex<<" "<<
  	array[d].math<<" "<<array[d].eng<<" "<<array[d].comp<<" "<<array[d].totll<<" "<<array[d].aver<<endl;
  	fout.close();
}
void student::change()
{
	int i,yy,aa,cc,dd,ee;
	char s[20],bb[10];
 	cout<<"请输入要修改学生的姓名：";
	cin>>s; 
	for(i=0;i<stulen;i++)
	if(strcmp(array[i].name,s)==0)//相等时返回函数为0
	{
 		cout<<"         -------请输入要修改的信息------"<<endl;
 		cout<<"         -------1.修改学号------------"<<endl;
		cout<<"         -------2.修改姓名----------"<<endl;
		cout<<"         -------3.修改数学成绩------"<<endl;
		cout<<"         --- ---4.修改英语成绩-------"<<endl;
		cout<<"         -------5.修改计算机成绩-----"<<endl<<endl;
		cout<<"\t\t请选择功能项: "; 
		cin>>yy ;
		cout<<endl<<"\t\t请输入修改后的数据: ";
		switch(yy)
		{
			//修改成绩的同时，平均成绩也要修改
 			case 1:cin>>aa;array[i].idc=aa;break;
 			case 2:cin>>bb;strcpy(array[i].name,bb);break;
 			case 3:cin>>cc;array[i].math=cc;
	 		       array[i].totll=array[i].math+array[i].eng+array[i].comp;
					array[i].aver=(array[i].math+array[i].eng+array[i].comp)/3;break;
 			case 4:cin>>dd;array[i].eng=dd;
 			array[i].totll=array[i].math+array[i].eng+array[i].comp;
					array[i].aver=(array[i].math+array[i].eng+array[i].comp)/3;break;
 			case 5:cin>>ee;array[i].comp=ee;
			 array[i].totll=array[i].math+array[i].eng+array[i].comp;
			array[i].aver=(array[i].math+array[i].eng+array[i].comp)/3;break;
 		}
 	} 
	system("pause"); 
}
//*********************删除指定名字学生的数据*******************//
void student::del()
{
  	int i,p;  
  	char x[8];
  	cout<<"    输入要删除学生名字："<<endl;
  	cin>>x;
  	//通过for循环查找要删除学生的姓名
  	for(i=0; i<this->stulen; i++)
  	{
	  	if(strcmp(array[i].name,x)==0)//比较两字符串的大小，若相等返回值为0 
	  	{   
		  	p=i;
          	cout<<endl<<"学号     姓名      性别     数学     英语     计算机       总成绩      平均成绩"<<endl;
          	cout<<array[i].idc<<"     "<<array[i].name<<"       "<<
			  array[i].sex<<"       "<<array[i].math<<"       "<<array[i].eng<<
			  "       "<<array[i].comp<<"           "<<array[i].totll<<"          "<<array[i].aver<<endl;
          	break;
	  	}      
      	else continue;
  	}
  	cout<<endl<<"----------------------------- 学生信息表 ------------------------------------"<<endl;
  	cout<<endl<<"        学号     姓名   性别      数学     英语     计算机      总分     平均分"<<endl;   
  	//删除了之后，应该把后面的数据往前移，把要删除的数据覆盖,并且学生长度减1
  	this->stulen--;
  	for(i=0;i<this->stulen;i++)
  	{
	  	array[i]=array[i+1];
  	}
  	this->read ();//读取学生数据 
  	cout<<"   删除成功!"<<endl;
} 
//***********把学生成绩排序******************//
void student::order()
{
  	boss temp;
  	int k,j,h=stulen;
  	//排序算法。
  	for(j=0; j<h-1; j++)
  	{
		for(k=0; k<h-1-j; k++)
    	{
	   		if(array[k].totll < array[k + 1].totll)
	   		{
		   		temp=array[k];   array[k] = array[k+1];   array[k+1] =temp;
	   		}
		}
  	}
    cout<<"         成绩排名："<<endl;
    cout<<" 学号    性别    姓名       数学      英语     计算机    总成绩   名次"<<endl;
    for(k=0; k<stulen; k++)
    {     
     	cout<<"     ";
     	cout.setf(ios::left);
      	cout.width(6);
  		cout<<array[k].idc;
	  	cout.width(8);
	  	cout<<array[k].sex;
	  	cout.width(10);	
     	cout<<array[k].name;
     	cout.width(9);
     	cout<<array[k].math;
     	cout.width(9);
     	cout<<array[k].eng;
	 	cout.width(11);
	 	cout<<array[k].comp;
	 	cout.width(10); 
     	cout<<array[k].totll<<k+1<<endl;
  	}
  	system("pause");
}
//********************选择菜单。*****************//
void menu()
{
 	cout<<"\n\n";
 	cout<<"------------------ 学生成绩系统 -----------------"<<endl<<endl;
 	cout<<"\t\t1.录入与保存学生信息.\n";
 	cout<<"\t\t2.读取学生信息.\n";
 	cout<<"\t\t3.删除学生信息.\n";
 	cout<<"\t\t4.追加学生信息.\n";
 	cout<<"\t\t5.查询学生信息.\n";
 	cout<<"\t\t6.显示成绩名次.\n";
 	cout<<"\t\t7.学生信息统计.\n";
 	cout<<"\t\t8.修改学生信息.\n";
 	cout<<"\t\t9.退出系统......\n\n\n";
 	cout<<"\t\t请选择功能项: ";
}
//---------------------------------------------------------------------------------------
int main()
{      
 	student a; 
 	while(1)
 	{ 
	  	int num;
	  	system("cls");
	  	menu();
	  	cin>>num;
	  	switch(num)
	  	{
	   		case 1:
	    	system("cls");    a.input();a.save();break;
	   		case 2:
	    	system("cls");    a.read(); break;  
	   		case 3:
	   		system("cls");    a.del(); break;
	   		case 4:
	    	system("cls");    a.add();break;
	   		case 5: 
	    	system("cls");    a.Query();break;
	   		case 6:
	    	system("cls");    a.order();break;
	   		case 7:
	    	system("cls");	  a.setnum();break;
			case 8:
			system("cls");    a.change();break;	 
	   		case 9:
	    	cout<<endl<<"                按任意键退出....   "<<endl;
	    	exit(0);
	   		default:
	    	cout<<"Bad input!!\n";
	        break;
	  	}
	}
	return 0;
}


