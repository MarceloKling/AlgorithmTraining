#include <iostream>

using namespace std;

//�ⷨ1��ȫ������Ȼ�����
//�ⷨ2����������
//�ⷨ3������������

//�ⷨ4������ѡ���㷨������ѡ���㷨 O(n)��,quickSelect����kС��Ԫ�ط���S[k-1]
void quickSelect(int s[],int k, int left,int right){
    int i,j;
    int pivot;

    if(left<right){
        pivot = mediad3(s,left,right);
        //ȡ3��������ֵ��Ϊ��Ԫ�����Ժܴ�̶��ϱ�������
        i = left;j = right -1;
        for(;;){
            while(s[++i]<pivot){}
            while(s[--j] > pivot){}
            if(i<j){
                swap(s[i],s[j]);
            }
            else{
                break;
            }

        }
        swap(s[i],s[right-1]);
        if(k<=i){
            quickSelect(s,k,left,i-1);
        }
        else if(k>i+1){
            quickSelect(s,k,i+1,right);
        }
    }
    else{
        //���left>right�����ò����������һ��
        InsertSort(s+left,right-left+1);
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
