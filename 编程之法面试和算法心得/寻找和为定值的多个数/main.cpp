#include <iostream>
#include <vector>
#include <list>
using namespace std;

list<int> list1;

//�ⷨ1��ת��Ϊn-1���⣬01����
void SumOfKNumber(int sum,int n){
    //�ݹ����
    if(n<=0 || sum <=0){
        return;
    }
    //����ҵ��Ľ��
    if(sum == n){
        //��תList
        list1.reverse();
        for(list<int>::iterator it = list1.begin();it!=list1.end();it++){
            cout<<*it<<" + ";
        }
        cout<<n<<endl;
    }

    list1.push_front(n);
    SumOfKNumber(sum-n,n-1); //��n��ǰn-1��������sum-n
    list1.pop_front();
    SumOfKNumber(sum,n-1); //����n��ǰn-1��������sum
}

int main()
{
    SumOfKNumber(32,20);
    return 0;
}
