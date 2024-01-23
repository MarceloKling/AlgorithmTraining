#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//�ݹ�ʵ��
void CalcAllPermutation(string &s,int from , int to){
    if(to<=1){
        return;
    }
    if(from == to){
        for(int i=0;i<=to;i++){
            cout<<s[i];
        }
        cout<<endl;
    }
    else{
        for(int j=from;j<=to;j++){
            swap(s[j],s[from]);
            CalcAllPermutation(s,from+1,to);
            swap(s[j],s[from]);
        }
    }
}

//�ֵ���
bool CalcAllPermutationDic(string &s, int num){
    int i;
    //step1:�ҳ����������(����)һ���������λλ��i, x=ai
    for(int i=num-2;(i>=0) && (s[i]>=s[i+1]); --i){
        ;
    }
    //�Ѿ��ҵ���������
    if(i<0){
        return false;
    }
    int k;
    //step2:�ҵ������е�iλ�ұ����һ����ai���λ��j,y=ai
    for(k = num-1;(k>i) && (s[k]<=s[i]);--k){
        ;
    }
    //step3:����x,y
    swap(s[i],s[k]);
    //step4:�ѵ�i+1λ�����Ĳ��ַ�ת;
    reverse(s.begin()+i+1,s.begin()+num);
    return true;
}

int main()
{
    string ss= "abcd";
    CalcAllPermutation(ss,0,ss.size()-1);
    return 0;
}
