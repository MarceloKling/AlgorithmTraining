#include <iostream>

using namespace std;

int main()
{
    int dis[10],i,k,n,m,u[10],v[10],w[10],check,flag;
    int inf =99999999;
    cin>>n>>m;

    for(i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }

    //��ʼ��dis����
    for(i=1;i<=n;i++)dis[i]=inf;
    dis[1]=0;

    //Bellman-Ford�������
    for(k=1;k<=n-1;k++){
            check =0;//��������ڱ����ɳ�������dis�Ƿ�ᷢ������
        for(i=1;i<=m;i++){//����һ���ɳ�
            if(dis[v[i]] >dis[u[i]]+w[i]){
                dis[v[i]] =dis[u[i]]+w[i];
                check =1;//����dis�������£��ı�check��ֵ
            }
        }
        //�ɳ���Ϻ�������dis�Ƿ��и���
        if(check ==0)break;//�������disû�и��£���ǰ�˳�ѭ�������㷨
    }
    //��⸺Ȩ��·
    flag=0;
    for(i=1;i<=m;i++){
        if(dis[v[i]] >dis[u[i]]+w[i])flag =1;
    }
    cout<<endl;
    if(flag ==1)cout<<"��ͼ���и�Ȩ��·"<<endl;
    else
    for(i=1;i<=n;i++)cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}


/*
��������
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
*/
