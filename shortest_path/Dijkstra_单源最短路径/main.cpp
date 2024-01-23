#include <iostream>

using namespace std;

int main()
{
    int e[10][10],dis[10],book[10],i,j,m,n,t1,t2,t3,u,v,minx;

    int inf =99999999;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i ==j)e[i][j]=0;
            else e[i][j]=inf;
        }
    }

    for(i=1;i<=m;i++){
        cin>>t1>>t2>>t3;
        e[t1][t2]=t3;
    }
    //��ʼ��dis���飬������1��������ߵĳ�ʼ·��
    for(i=1;i<=n;i++)dis[i]=e[1][i];

    for(i=1;i<=n;i++)book[i]=0;
    book[1]=1;

    //Dijkstra�㷨����
    for(i=1;i<=n-1;i++){
        //�ҵ���1�Ŷ�������Ķ���
        minx =inf;
        for(j=1;j<=n;j++){
            if(book[j]==0 && dis[j]<minx){
                minx=dis[j];
                u =j;
            }
        }
        book[u] =1;
        for(v=1;v<=n;v++){
            if(e[u][v] <inf){//���u���Ե���v��
                if(dis[v]>dis[u]+e[u][v])//�ߵ��ɳ�
                    dis[v]=dis[u]+e[u][v];
            }
        }
    }
    for(i=1;i<=n;i++)cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}


/*
��������
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/

/*
�㷨˼��
ÿ���ҵ���ԭ�������һ�����㣬Ȼ���Ըö���Ϊ���Ľ�����չ�����յõ�ԭ�㵽�������е�����·��
*/
