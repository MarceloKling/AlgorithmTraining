#include <iostream>

using namespace std;

int h[101];//������Ŷѵ�����
int n;//������Ŷ���Ԫ�صĸ�����Ҳ���ǶѵĴ�С

void swap(int x,int y){
    int t;
    t=h[x];
    h[x]=h[y];
    h[y]=t;
    return;
}

//���µ�������
void siftdown(int i){//����һ����Ҫ���µ����Ľڵ���i
    int t,flag =0;//flag ��������Ƿ���Ҫ�������µ���
    //��i�ڵ��ж��ӣ�����������ӣ�����������Ҫ����������ʱ��ѭ���ͼ���ִ��
    while(i*2 <=n && flag ==0){
        //�����ж���������ӵĹ�ϵ����t��¼�Ƚ�С�ı��
        if(h[i] >h[i*2]){
            t =i*2;
        }
        else t=i;

        //�ٶ��Ҷ��ӽ�������
        if(i*2+1 <=n){
            if(h[t] >h[i*2+1]){
                t=i*2+1;
            }
        }

        if(t !=i){
            swap(t,i);
            i =t;
        }
        else{
            flag =1;
        }
    }
    return;
}

void create(){
    int i;
    for(i=n/2;i>=1;i--){//�����һ����Ҷ�ӽڵ㵽��һ���ڵ�һ�ν������µ���
        siftdown(i);
    }
    return;
}

int deleteMax(){
    int t;
    t =h[1];
    h[1]=h[n];
    n--;
    siftdown(1);
    return t;
}

int main()
{
    int i,num;
    cin>>num;
    for(i=1;i<=num;i++)cin>>h[i];
    n =num;
    create();
    for(i=1;i<=num;i++){
        cout<<deleteMax()<<" ";
    }
    cout<<endl;
    return 0;
}

/*
��������
14
99 5 36 7 22 17 46 12 2 19 25 28 1 92
*/
