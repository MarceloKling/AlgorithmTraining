#include <iostream>

using namespace std;

int main()
{
    int n,m,i,j,k,minx,t1,t2,t3;
    int e[7][7],dis[7],book[7]={0};
    int inf =99999999;
    int countx=0,sum =0;

    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i ==j)e[i][j]=0;
            else e[i][j]=inf;
        }
    }

    for(i=1;i<=m;i++){
        cin>>t1>>t2>>t3;
        e[t1][t2] =t3;
        e[t2][t1] =t3;
    }

    for(i=1;i<=n;i++)dis[i]=e[1][i];

    //Prim���Ĳ��ֿ�ʼ
    //��1�Ŷ������������
    book[1]=1;
    countx++;
    while(countx <n){
        minx =inf;
        for(i=1;i<=n;i++){
            if(book[i] ==0&&dis[i] <minx){
                minx =dis[i];
                j=i;
            }
        }
        book[j]=1;
        countx++;
        sum+=dis[j];

        //ɨ�赱ǰ����j�����бߣ�����jΪ�м�㣬������������ÿһ����������ľ���
        for(k=1;k<=n;k++){
            if(book[k] ==0 &&dis[k] >e[j][k])dis[k]=e[j][k];
        }
    }


    cout<<sum<<endl;
    return 0;
}



/*
��������
6 9
2 4 11
3 5 13
4 6 3
5 6 4
2 3 6
4 5 7
1 2 1
3 4 9
1 3 2
*/
