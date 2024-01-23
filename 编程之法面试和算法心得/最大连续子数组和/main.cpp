#include <iostream>
#include <vector>

using namespace std;

//����ö��
int MaxSubArray(vector<int> a)
{
    int maxSum = a[0]; //ȫ�Ǹ���������£��������ĸ���
    int curSum = 0;
    int n = a.size();
    for(int i=0; i<n; i++)
    {
        for(int j =i; j<n; j++)
        {
            for(int k =i; k<=j; k++)
            {
                curSum += a[k];
                if(curSum > maxSum)
                {
                    maxSum = curSum;
                }
            }
            //����ǵ�Ҫ���㣬Ҫ��Ȼsum���մ��������������ĺ�
            curSum = 0;
        }
    }
    return maxSum;
}

//��̬�滮 DP ״̬ת�Ʒ���
int MaxSubArrayDP(vector<int> a)
{
    int curSum =0;
    int maxSum = a[0]; //����ȫΪ���������
    int n= a.size();
    for(int j =0;j<n;j++){
        if(curSum >= 0){
            curSum += a[j];
        }
        else{
            curSum = a[j];
        }
        if(curSum >maxSum){
            maxSum = curSum;
        }
    }
    return maxSum;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(-2);
    v.push_back(3);
    v.push_back(10);
    v.push_back(-4);
    v.push_back(7);
    v.push_back(2);
    v.push_back(-5);
    cout<<MaxSubArray(v)<<endl;
    cout<<MaxSubArrayDP(v)<<endl;
    return 0;
}
