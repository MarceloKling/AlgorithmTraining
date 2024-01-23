#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//������ѵ,ʱ�临�Ӷ�O(mn)
bool StringContain(string &a,string &b)
{
    for(int i=0; i<b.size(); i++)
    {
        int j;
        for(j =0; (j<a.size() && a[j]!=b[i]); ++j);
        if(j>=a.size())
        {
            return false;
        }
    }
    return true;
}

//�������ѯ��O(mlogm)+O(nlogn)+O(m+n)
bool StringContainWithSort(string &a,string &b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int pa=0,pb =0; pb<b.size();)
    {
        while((pa<a.size()) && (a[pa] < b[pb]))
        {
            ++pa;
        }
        if(pa>=a.size() || a[pa]>b[pb])
        {
            return false;
        }
        ++pb;
    }
    return true;
}

//������ˣ������,ǰ16����˱�ᳬ��loglong��Χ O(m+n)
bool StringContainPrime(string &a,string &b)
{
    const int p[26]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,
                      47,53,59,61,67,72,73,79,83,89,97,101
                     };
    int f = 1;
    for(int i=0; i<a.size(); ++i)
    {
        int x = p[a[i]-'A'];
        if(f%x)
        {
            f*=x;
        }
    }
    for(int i=0; i<b.size(); ++i)
    {
        int x= p[b[i]-'A'];
        if(f%x)
        {
            return false;
        }
    }
    return true;
}

//ɢ�б���� ʱ�临�Ӷ�O(m+n),�ռ�O(1)
bool StringContainHash(string &a,string &b)
{
    int _hash = 0;
    for(int i=0; i<a.size(); ++i)
    {
        _hash |=(1<<(a[i]-'A'));
    }
    for(int i=0; i<b.size(); ++i)
    {
        if((_hash &(1<<(b[i]-'A'))) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string a = "ABCD";
    string b = "AA";
    string c = "BCD";
    string d = "BCDE";
    cout<<StringContain(a,b)<<endl;
    cout<<StringContain(a,c)<<endl;
    cout<<StringContain(a,d)<<endl;
    cout<<"---------------"<<endl;
    cout<<StringContainWithSort(a,b)<<endl;
    cout<<StringContainWithSort(a,c)<<endl;
    cout<<StringContainWithSort(a,d)<<endl;
    cout<<"---------------"<<endl;
    cout<<StringContainPrime(a,b)<<endl;
    cout<<StringContainPrime(a,c)<<endl;
    cout<<StringContainPrime(a,d)<<endl;
    cout<<"---------------"<<endl;
    cout<<StringContainHash(a,b)<<endl;
    cout<<StringContainHash(a,c)<<endl;
    cout<<StringContainHash(a,d)<<endl;
    return 0;
}
