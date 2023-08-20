#include<bits/stdc++.h>
using namespace std;
string add_string(string a,string b)
{
     if(a.size() < b.size())
        swap(a, b);

    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');

    for(int i=a.size()-1; i>0; i--)
    {
        if(a[i] > '9')
        {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9')
    {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}
string kam(string s1,string s2)
{
    int n=s1.size();
    if(n==1)
    {
            int i=s1[0]-'0';
            int j=s2[0]-'0';
            return to_string(i*j);
    }
    if (s1.size() < n) {
        s1 = string(n - s1.size(), '0') + s1;
    }
    if (s2.size() < n) {
        s2 = string(n - s2.size(), '0') + s2;
    }

    int half = n / 2;
    string a = s1.substr(0, half);
    string b = s1.substr(half);
    string c = s2.substr(0, half);
    string d = s2.substr(half);
    string e1,e2,e3,e4;
    e1=kam(a,c);
    e2=kam(b,d);
    e3=kam(c,b);
    e4=kam(a,d);
    string e5=add_string(e3,e4);
    for(int i=0;i<s1.size();i++)
    {
        e1+='0';
    }
     for(int i=0;i<s1.size()/2;i++)
    {
        e5+='0';
    }
    string f1=add_string(e1,e5);
    return add_string(f1,e2);

}
int main()
{
    freopen("input.txt","r",stdin);
    string s1,s2;
    cin>>s1>>s2;
    cout<<kam(s1,s2);
    return 0;
}