//��Ŀ������
// ��˵��ʫ����ף�һ���������Һ����Ӳ�������
//һ�죬�����žƺ����Ӽ���������ƺ����о�2���������߱߳���
// ���½����ߣ����ȥ��ơ�
//����һ����������һ����
//
//��һ·�ϣ���һ��������5�Σ�������10�Σ���֪���һ���������ǻ��������ðѾƺȹ��ˡ�
//����������������ͻ��Ĵ��򣬿��԰������Ϊa��������Ϊb��
//��babaabbabbabbbb ���Ǻ���Ĵ����������Ĵ�һ���ж����أ�
//�����������п��ܷ����ĸ�����������Ŀ�����ģ�

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isFit(char* str){
    int value =2;
    str[14]='b';
    for(int i=0;i<15;i++){
        if(str[i]=='a')value*=2;
        else if(str[i]=='b')value-=1;
    }
    if(value ==0)return true;
    else return false;
}
int main()
{
    int sum=0;
    char ss[16] = "aaaaabbbbbbbbb";
    sort(ss,ss+14);
    while(next_permutation(ss,ss+14)){
            if(isFit(ss)){
                sum++;
            }
    }
    cout<<sum<<endl;
}
