#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//����1��ɢ��ӳ�䣬�����е������dic�У���������һ�����Ƿ�Ҳ��dic��
//����2������б�

void TwoSum(vector<int> v ,int sum){
    sort(v.begin(),v.end());

    int mBegin =0;
    int mEnd = v.size()-1;

    //��ͷɨ����߳�����ָ������ɨ�跨�Ǻܾ���ķ�����ʱ�临�Ӷ�ΪO(n)
    while(mBegin <mEnd){
        long curSum = v[mBegin]+v[mEnd];
        if(curSum == sum){
            //��ĿֻҪ���������һ�Լ���
            cout<<v[mBegin]<<" "<<v[mEnd]<<endl;
            //�����Ҫ�����������������ԣ������������ע�Ͳ�ȥ��break
            mBegin++;
            mEnd--;
            //break;
        }
        else{
            if(curSum <sum){
                mBegin++;
            }
            else{
                mEnd--;
            }
        }
    }
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(100);
    v.push_back(11);
    v.push_back(1);
    v.push_back(19);
    v.push_back(18);
    v.push_back(20);

    TwoSum(v,20);
    return 0;
}
