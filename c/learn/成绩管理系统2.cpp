# include<iostream.h>
# include<string.h>
# include<stdio.h>
# include<stdlib.h>
# include<fstream.h>
#include<windows.h>
//*****����һ��ѧ��ԭ�ӵĵ����ݽṹ*****//
class boss
{
public:
	char  *name;// ����
    int   idc;//ѧ��
    char  sex; //�Ա�
    float math, eng, comp, totll, aver;//��ѧ��Ӣ���������ܷ֣�ƽ����;
    void show();//*****�����������*****// 
    void setup();//******����ѧ�����ݲ��ж��Ƿ��ڹ涨������****// 
};
//*********����һϵ�ж�ѧ���Ĳ���**********//
class student
{
private:
 	boss array[100];//*****����һ������********// 
 	int stulen;//******����ѧ������******// 
public:
 	student();
 	void change();//******�޸�ѧ����Ϣ******// 
 	void setnum();//******ͳ��ѧ����Ϣ******// 
 	void input();//******����ѧ�����ݵĺ���******// 
 	void order();//*****����������******// 
 	void save();//********���屣��ѧ�����ݵĺ���******// 
 	void Query();//***��һ����ʽ��ʾ��Ҫ��ѯ��ѧ����Ϣ***// 
 	void read();//****��ʾ����ѧ������*****// 
 	void add();//*****���ѧ������*****// 
 	void del();//******ɾ�� ָ����ѧ������*****// 
};

//********��ѧ�����ݵĳ�ʼ������Ĺ��캯����**********//
student::student()
{
  //��forѭ����ȫ�������е����ݳ�ʼ��
  	for(int i=0;i<100;i++)
  	{
   		array[i].math=array[i].eng=array[i].comp =array[i].totll =array[i].aver =0;
   		array[i].idc =0;
   		array[i].sex =' ';
   		array[i].name =NULL;
  	}
  	this->stulen =0;
}


//********����ѧ�������ݣ����ж��Ƿ��ڹ涨��������*******//
void boss::setup()
{   
     char  n[20]; 
	 char  s; 
     int   b;
  	//�������ѧ�����������ڣ�����ѭ�����Ҹ�ֵ��
  	//��������������ڣ�һֱѭ�����������ݷ���������Ϊֹ
  	do {//ѭ����
	  	cout<<"   ѧ��: ";
      	cin>>b;
      	if(b>100||b<0)
		  	cout<<"input error!!"<<endl<<endl;
   	}
  while (b<0||b>100); //���ֵΪb<0||b>100,��ִ��ѭ����
  idc=b;//��ֵ

  	//��������������������ڣ�����ѭ�����Ҹ�ֵ��
  	//��������������ڣ�һֱѭ�����������ݷ���������Ϊֹ
  	do
  	{
   		name=new char[strlen(n)+1];
   		cout<<"   ����: ";
      	cin>>n;
    	if( strlen(n)>20 || strlen(n)<1) 
     		cout<<"input error!!"<<endl<<endl;
	}
  	while ( strlen(n)>20 || strlen(n)<1 );//���while���������Ϊ�棬��ִ��ѭ����
  	strcpy(name,n);//��ֵ��������ͷ�ļ�string.h��

  	//��������Ա����������ڣ�����ѭ�����Ҹ�ֵ��
  	//��������������ڣ�һֱѭ�����������ݷ���������Ϊֹ
  	cout<<"   �Ա�(m/f):" ;
  	cin>>s; 
  	while (s!='m' && s!='f')
  	{ 
	   	cout<<"input error!!"<<endl<<endl;
	   	cout<<"   �Ա�(m/f):";
		cin>>s;    
  	}
  	sex=s;


  	float m, e, co;//��ѧ��Ӣ������
  	cout<<"   ��ѧ: ";
  	cin>>m;
  	//���������ѧ�ɼ����������ڣ�����ѭ�����Ҹ�ֵ��
  	//��������������ڣ�һֱѭ�����������ݷ���������Ϊֹ
  	while (m<0 || m>100)
  	{ 
	  	cout<<"input error!!"<<endl<<endl;
	  	cout<<"   ��ѧ: ";
	  	cin>>m;    
  	}
  	math=m;


  	cout<<"   Ӣ��: ";
  	cin>>e;
  	//�������Ӣ��ɼ����������ڣ�����ѭ�����Ҹ�ֵ��
  	//��������������ڣ�һֱѭ�����������ݷ���������Ϊֹ
  	while (e<0 || e>100)
  	{ 
		cout<<"input error!!"<<endl<<endl;
		cout<<"   Ӣ��: ";
		cin>>e;    
  	}
  	eng=e;
  	cout<<"   �����: ";
 	cin>>co;
  	//�������ѧ�����������ڣ�����ѭ�����Ҹ�ֵ��
  	//��������������ڣ�һֱѭ�����������ݷ���������Ϊֹ
  	while (co<0 || co>100)
  	{	 
		cout<<"input error!!"<<endl<<endl;
	   	cout<<"   �����: ";
	   	cin>>co;    
  	}
  	comp=co;
  	totll=math+eng+comp;//���ܷ�
  	aver=(math+eng+comp)/3;//��ƽ����
}

 //*******���չ涨��ʽ�Ѹ�ѧ����������ʾ����Ļ��******//
void boss::show()
{ 
  	cout.setf(ios::left);//������������
  	cout.width(9);//�����ֶο��
  	cout<<""<<idc<<"     ";//���ѧ��
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

//**************����ѧ��������***********************//
void student::input() 
{ 
  	int n;
  	cout<<endl<<"���뽫Ҫ¼���ѧ����Ŀ: ";
  	cin>>n;            
  	int j; 
  	//ͨ��ѭ������Ҫ������ѧ��������ѧ�������ݡ�
  	for(j=0; j<n; j++)
  	{
   		cout<<" ����ѧ����Ϣ "<<j<<endl;
   		array[j].setup();
  	}
  	this->stulen=n;  //ѧ��������ֵ
  	//ѧ��������ʾ��ʽ
  	system("cls");//********�����Ļ�ϵ���Ϣ********// 
  	cout<<endl<<"----------------------------- ѧ����Ϣ�� ------------------------------------"<<endl;
  	cout<<endl<<"      ѧ��     ����   �Ա�      ��ѧ     Ӣ��     �����      �ܷ�     ƽ����"<<endl;

  	//ͨ��ѭ���������ѧ�����ݡ�
  	for(j=0; j<n; j++) 
  	{
   		array[j].show();
  	}
  	cout<<endl;
  	cout<<"      �Ƿ񱣴棿 (Y/N): ";
  	char Y;
  	cin>>Y;
  	system("cls");//********�����Ļ�ϵ���Ϣ********//
}


//**************����һ����ʽ��ʾ��Ҫ��ѯѧ������Ϣ��**************//
void student::Query()
{
   	int x , i;
   	cout<<endl<<"    ����Ҫ��ѯѧ����ѧ��: ";
   	cin>>x;
   	cout<<endl<<"      ѧ��     ����   �Ա�      ��ѧ     Ӣ��     �����      �ܷ�     ƽ����"<<endl;
   	for(i=0;i<this->stulen ;i++)//for(i=0;i<=this->stulen ;i++)
   	{  
	   	if (x==array[i].idc)
	   	{
		   	cout.setf(ios::left);//ָ����������ڱ����Χ��������� 
           	cout.width(9);//*****ָ������Ϊ6*****// 
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
//ͳ���ܷ��ڲ�ͬ�����ε�����
void student::setnum()
{
	int m,ii=0,i,tt,n;
 	cout<<"ͳ�Ʒ�Χ:"<<endl;
 	cin>>m>>n;
	if(m>n)
	{
  		tt=m;m=n;n=tt;
  	}
 	 cout<<endl<<"      ѧ��     ����   �Ա�      ��ѧ     Ӣ��     �����      �ܷ�     ƽ����"<<endl;
 	for(i=0;i<this->stulen;i++)
 	{
	 	if(array[i].totll>=m&&array[i].totll<=n)
	 	ii++;
	 	array[i].show();//�����������Ϣ
	 }
	 cout<<"�˷�Χ�ڵ�������Ϊ��"<<ii<<endl; 
	 system("pause");
}
//*******************����ѧ������**************************//
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
  	//ͨ��ѭ�������е�ѧ�����ݱ�����list.txt��ߡ�
  	for(i=0; i<this->stulen; i++)
  	{
   		outfile<<array[i].idc<<" "<<array[i].name<<" "<<array[i].sex<<" "<<
      	array[i].math<<" "<<array[i].eng<<" "<<array[i].comp<<" "<<array[i].totll<<" "<<array[i].aver<<endl;
  	}
    outfile.close();
}


 //*************��ʾ����ѧ������*********************//
void student::read()
{
  	int i; 
  	system("cls");//****�����������Ļ�ϵ���Ϣ******// 
  	cout<<endl<<"----------------------------- ѧ����Ϣ�� ------------------------------------"<<endl;
  	cout<<endl<<"      ѧ��     ����   �Ա�      ��ѧ     Ӣ��     �����      �ܷ�     ƽ����"<<endl;

  	for(i=0; i<this->stulen; i++) 
  	{
   		array[i].show();
  	}
  	system("pause");
}
//*******************���һ��ѧ��������****************//
void student::add()
{ 
  	int i, d=this->stulen ;  
  	cout<<"����Ҫ���ѧ������Ϣ��"<<endl;
  	array[d].setup();
	cout<<endl<<"----------------------------- ѧ����Ϣ�� ------------------------------------"<<endl;
  	cout<<endl<<"      ѧ��     ����   �Ա�      ��ѧ     Ӣ��     �����      �ܷ�     ƽ����"<<endl;    
  	for(i=0; i<=d; i++)
  	{
		array[i].show();  
  	}
  	system("pause");
  	ofstream fout("f3.dat",ios::app);//�������ʽ���ļ���д���������ӵ��ļ�ĩβ// 
  	if(!fout)
  	{
	  	cout<<"Cannot open output file!\n,";
  	}
  	//����ӵ�ѧ��������ӵ�f3.dat���ȥ��
  	fout<<array[d].idc<<" "<<array[d].name<<" "<<array[d].sex<<" "<<
  	array[d].math<<" "<<array[d].eng<<" "<<array[d].comp<<" "<<array[d].totll<<" "<<array[d].aver<<endl;
  	fout.close();
}
void student::change()
{
	int i,yy,aa,cc,dd,ee;
	char s[20],bb[10];
 	cout<<"������Ҫ�޸�ѧ����������";
	cin>>s; 
	for(i=0;i<stulen;i++)
	if(strcmp(array[i].name,s)==0)//���ʱ���غ���Ϊ0
	{
 		cout<<"         -------������Ҫ�޸ĵ���Ϣ------"<<endl;
 		cout<<"         -------1.�޸�ѧ��------------"<<endl;
		cout<<"         -------2.�޸�����----------"<<endl;
		cout<<"         -------3.�޸���ѧ�ɼ�------"<<endl;
		cout<<"         --- ---4.�޸�Ӣ��ɼ�-------"<<endl;
		cout<<"         -------5.�޸ļ�����ɼ�-----"<<endl<<endl;
		cout<<"\t\t��ѡ������: "; 
		cin>>yy ;
		cout<<endl<<"\t\t�������޸ĺ������: ";
		switch(yy)
		{
			//�޸ĳɼ���ͬʱ��ƽ���ɼ�ҲҪ�޸�
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
//*********************ɾ��ָ������ѧ��������*******************//
void student::del()
{
  	int i,p;  
  	char x[8];
  	cout<<"    ����Ҫɾ��ѧ�����֣�"<<endl;
  	cin>>x;
  	//ͨ��forѭ������Ҫɾ��ѧ��������
  	for(i=0; i<this->stulen; i++)
  	{
	  	if(strcmp(array[i].name,x)==0)//�Ƚ����ַ����Ĵ�С������ȷ���ֵΪ0 
	  	{   
		  	p=i;
          	cout<<endl<<"ѧ��     ����      �Ա�     ��ѧ     Ӣ��     �����       �ܳɼ�      ƽ���ɼ�"<<endl;
          	cout<<array[i].idc<<"     "<<array[i].name<<"       "<<
			  array[i].sex<<"       "<<array[i].math<<"       "<<array[i].eng<<
			  "       "<<array[i].comp<<"           "<<array[i].totll<<"          "<<array[i].aver<<endl;
          	break;
	  	}      
      	else continue;
  	}
  	cout<<endl<<"----------------------------- ѧ����Ϣ�� ------------------------------------"<<endl;
  	cout<<endl<<"        ѧ��     ����   �Ա�      ��ѧ     Ӣ��     �����      �ܷ�     ƽ����"<<endl;   
  	//ɾ����֮��Ӧ�ðѺ����������ǰ�ƣ���Ҫɾ�������ݸ���,����ѧ�����ȼ�1
  	this->stulen--;
  	for(i=0;i<this->stulen;i++)
  	{
	  	array[i]=array[i+1];
  	}
  	this->read ();//��ȡѧ������ 
  	cout<<"   ɾ���ɹ�!"<<endl;
} 
//***********��ѧ���ɼ�����******************//
void student::order()
{
  	boss temp;
  	int k,j,h=stulen;
  	//�����㷨��
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
    cout<<"         �ɼ�������"<<endl;
    cout<<" ѧ��    �Ա�    ����       ��ѧ      Ӣ��     �����    �ܳɼ�   ����"<<endl;
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
//********************ѡ��˵���*****************//
void menu()
{
 	cout<<"\n\n";
 	cout<<"------------------ ѧ���ɼ�ϵͳ -----------------"<<endl<<endl;
 	cout<<"\t\t1.¼���뱣��ѧ����Ϣ.\n";
 	cout<<"\t\t2.��ȡѧ����Ϣ.\n";
 	cout<<"\t\t3.ɾ��ѧ����Ϣ.\n";
 	cout<<"\t\t4.׷��ѧ����Ϣ.\n";
 	cout<<"\t\t5.��ѯѧ����Ϣ.\n";
 	cout<<"\t\t6.��ʾ�ɼ�����.\n";
 	cout<<"\t\t7.ѧ����Ϣͳ��.\n";
 	cout<<"\t\t8.�޸�ѧ����Ϣ.\n";
 	cout<<"\t\t9.�˳�ϵͳ......\n\n\n";
 	cout<<"\t\t��ѡ������: ";
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
	    	cout<<endl<<"                ��������˳�....   "<<endl;
	    	exit(0);
	   		default:
	    	cout<<"Bad input!!\n";
	        break;
	  	}
	}
	return 0;
}


