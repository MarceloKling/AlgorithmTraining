#include <iostream>

using namespace std;

int main()
{
    int n,m,i,j,k;
    int u[8],v[8],w[8];
    int first[6],next[8];//fisrt Ҫ��n�����ֵ��1��nextҪ��m�����ֵ��1
    int dis[6]={0},book[6]={0};
    int que[101]={0};
    int head =1,tail =1;

    int inf =99999999;
    cin>>n>>m;

    for(i=1;i<=n;i++)dis[i]=inf;
    dis[1]=0;
    for(i=1;i<=n;i++)book[i]=0;//�տ�ʼ�����ڶ�����
    for(i=1;i<=n;i++)first[i]=-1;//-1��ʾ1-n������ʱ��û�б�

    for(i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
        next[i]=first[u[i]];
        first[u[i]] =i;
    }

    que[tail]=1;
    tail++;
    book[1]=1;
    while(head <tail){
        k =first[que[head]];//��ǰ��Ҫ����Ķ��׶���
        while(k!= -1){//ɨ�赱ǰ�������еı�
            if(dis[v[k]] >dis[u[k]] +w[k]){//�ж��Ƿ��ɳڳɹ�
               dis[v[k]] =dis[u[k]] +w[k];//���¶���1������v[k]��·��
                //�����book���������ж϶���v[k]�Ƿ��ڶ�����
                //�����ʹ��һ����������ǵĻ����ж�һ�������Ƿ��ڶ�����ÿ�ζ���Ҫ��
                //���е�head ��tail ɨ��һ�飬���˷�ʱ��
                if(book[v[k]] ==0){//0��ʾ���ڶ����У�������v[k]�������
                    //��Ӳ���
                    que[tail]=v[k];
                    tail++;
                    book[v[k]] =1;//ͬʱ���v[k]�Ѿ����
                }
            }
            k=next[k];
        }
        //����
        book[que[head]] =0;
        head++;
    }
    cout<<endl;
    for(i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }

    return 0;
}


/*
��������
5 7
1 2 2
1 5 10
2 3 3
2 5 7
3 4 4
4 5 5
5 3 6
*/
