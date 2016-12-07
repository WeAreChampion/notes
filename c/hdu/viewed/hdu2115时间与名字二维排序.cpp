#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Info
{
    string time;
    string name;
};
bool Comp(const Info a, const Info b)
{
    if(a.time != b.time ) { 
        return a.time < b.time;
    } 
    else { 
        return a.name < b.name ;
    } 

}
int main()
{
    int n, ca = 0;
    vector<Info> v;
    while(cin>>n && n) {
        v.clear();
        ca++;
        if(ca > 1) { 
            cout<<endl;
        } 
        Info info;
        string a, b;
        int i;
        for(i = 0; i < n; i++) {
            cin>>a>>b;
            info.name = a;
            info.time = b;
            v.push_back(info);
        }
       	//sort by Comp method 
        sort(v.begin(), v.end(), Comp);
        cout<<"Case #"<<ca<<endl;
        int kk = 1, t = 1;
        for(i = 0; i < n - 1; i++) {
            cout<<v[i].name<<" "<<kk<<endl;
            if(v[i].time == v[i + 1].time) {
                kk = kk;
                t++;
            } else {
                kk = kk + t;
                t = 1;
            }
        }
        if(v[i].time == v[i - 1].time) { 
            cout<<v[i].name<<" "<<kk<<endl;
        } 
        else { 
            cout<<v[i].name<<" "<<n<<endl;
        } 
    }
	return 0;
}