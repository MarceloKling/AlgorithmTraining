#include <iostream>
#include <string>
using namespace std;

//����һ��Ԫ�طŵ������
void LeftShiftOne(string &str,int n)
{
    char first = str[0]; //�����һ��Ԫ��
    for(int i=1; i<n; i++)
    {
        str[i-1] = str[i];
    }
    str[n-1] = first;
}

//��ת�����ַ��� ʱ�临�Ӷ�O(mn),�ռ临�Ӷ�O(1)
void LeftRotateString(string &s,int n, int m)
{
    while(m--)
    {
        LeftShiftOne(s,n);
    }
}

//��תһ���ַ���
void RevertString(string &str,int from,int to)
{
    while(from < to)
    {
        char t = str[from];
        str[from++] = str[to];
        str[to--] = t;
    }
}

//������ת����ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
void LeftRotateString3Step(string &s,int n,int m)
{
    //��Ҫ�ƶ���λ������n���ַ����ĳ��ȵĻ�����ô��%nЧ��һ��
    m %=n;
    RevertString(s,0,m-1);
    RevertString(s,m,n-1);
    RevertString(s,0,n-1);
}

int main()
{
    string s = "abcdef";
    LeftRotateString(s,s.size(),3);
    cout<<s<<endl;
    s = "abcdef";
    LeftRotateString3Step(s,s.size(),3);
    cout<<s<<endl;
    s = "abcdef";
    LeftRotateString3Step(s,s.size(),8);
    cout<<s<<endl;
    return 0;
}
