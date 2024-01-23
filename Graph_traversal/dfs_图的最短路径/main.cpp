#include <iostream>

using namespace std;

int minx =99999999999,book[101],n,e[101][101];

void dfs(int  cur,int dis){//dis���Ѿ��߹���·��
    int j;
    if(dis >minx)return;//����߹���·�̴���֮ǰ�����·�̣��ͷ��أ�û�б�Ҫ������
    if(cur ==n){//�ж�
        if(dis<minx)minx=dis;
        return;
    }
    for(j=1;j<=n;j++){//��1�ų��е�n���γ���
        if(e[cur][j]!=99999999999 &&book[j]==0){
            book[j]=1;
            dfs(j,dis+e[cur][j]);
            book[j]=0;
        }
    }
    return;
}
int main()
{
    int i,j,m,a,b,c;
    cin>>n>>m;
    //��ʼ������
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i ==j)e[i][j]=0;
            else e[i][j]=99999999999;
        }
    }

    //�������֮��ĵ�·
    for(i=1;i<=m;i++){
        cin>>a>>b>>c;
        e[a][b]=c;
    }
    book[1]=1;
    dfs(1,0);
    cout<<endl;
    cout<<minx<<endl;
    return 0;
}


/*
��������
5��ʾ��5�����У�8��ʾ��8����·��cΪ·�̹�����
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
*/
