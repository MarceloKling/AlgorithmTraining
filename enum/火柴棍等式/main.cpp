#include <iostream>

using namespace std;

int fun(int x){
    int num =0;
    int f[10]={6,2,5,5,4,5,6,3,7,6};
    //��һ����������¼0-9ÿ������Ҫ�ö��ٸ����
    while(x/10!=0){//���x/10������0�Ļ���˵���������������λ
            num+=f[x%10];
            x=x/10;
    }
    num+=f[x];
    return num;
}

int main()
{
    int a,b,c,m,sum=0;
    cin>>m;
    for(a=0;a<=1111;a++){
        for(b=0;b<=1111;b++){
            c=a+b;//ͨ��a��b�����c
            if(fun(a)+fun(b)+fun(c)==m-4){
                cout<<a<<"+"<<b<<"="<<c<<endl;
                sum++;
            }
        }
    }
    cout<<"һ������ƴ��"<<sum<<"������ʽ"<<endl;
    return 0;
}
