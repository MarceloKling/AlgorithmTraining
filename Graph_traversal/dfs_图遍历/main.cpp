#include <iostream>

using namespace std;

int book[101],sum,n,e[101][101];

void dfs(int cur){//cur �ǵ�ǰ���ڵĶ�����
    cout<<cur<<endl;
    sum++;
    if(sum ==n)return;//�����ж��㶼���ʵ�ʱ���˳�
    for(int i=1;i<=n;i++){//��1�Ŷ��㵽n�����γ��ԣ�����Щ�����뵱ǰcur�б�����
            //�ж�cur��i�Ƿ��бߣ����ж϶���i�Ƿ���ʹ�
            if(e[cur][i] ==1 &&book[i]==0){
                book[i] =1;
                dfs(i);
            }
    }
    return;
}
int main()
{
    int i,j,m,a,b;
    cin>>n>>m;
    //��ʼ������
    for(i=1;i<=n;i++){
        for(j =1;j<=n;j++){
            if(i==j)e[i][j]=0;
            else e[i][j]=99999999999;
        }
    }
    //���������ӵı�
    for(i=1;i<=m;i++){
        cin>>a>>b;
        e[a][b]=1;
        e[b][a]=1;
    }
    book[1]=1;
    dfs(1);
    return 0;
}

/*
��������
5 5
1 2
1 3
1 5
2 4
3 5
*/
