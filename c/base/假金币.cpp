#include<iostream>
using namespace std;
int m;
//cΪ�������������j�Ž��Ϊ�ٱң����������Ƿ�ì�� 
int jd(int j, int *s, char c)
{
	int i, f;
	m = s[0]<<1;//sΪ������¼�����һ��Ԫ����������� 
	for(i = f = 1; i <= m && f; ) {//�жϱ��γ�������j�Ž�� 
		if(s[i] == j) {
			f = 0;
		} else { 
			i++;
		} 
	}
	//���û��j�Ž����ƽ��ƽ�⣬����j�Ž����ƽƽ�⣬�������ì�� 
	if(!f && c == '=' || f && c != '=') {
		return 0;
	}
	return 1;
}
int main()
{
	int num[100][1001];
	int i, n, j, no, t, k;
	cin>>n>>k;
	char s[1000];
	for(i = 1; i <= k; i++) {
		cin>>m;
		num[i][0] = m;
		for(j = 1; j <= 2 * m; j++) {
			cin>>num[i][j];
		}
		getchar();
		cin>>s[i];
	}/*
	for(i=1;i<=k;i++)
	{
		m=num[i][0];
		for(j=1;j<=2*m;j++)
		{
			cout<<num[i][j]<<" ";
		}
		cout<<endl<<s[i]<<endl;
	}
	cout<<endl;
	*/
	//n golden medals
	for(i = 1,t = 0;i <= n; i++) {
		for(j = 1; j <= k && jd(i, num[j], s[j]); j++); 
		if(j <= k) {
			continue;
		}
		t++;
		if(t > 1) {
			break;
		}
		no = i;
	}
	if(t != 1) { 
		cout<<"0\n";
	} 
	else { 
		cout<<no<<endl;
	} 
	return 0;
}
/*
5 3
2 1 2 3 4
<
1 1 4
=
1 2 5
=
3 2
1 1 2
<
1 1 3
=
*/