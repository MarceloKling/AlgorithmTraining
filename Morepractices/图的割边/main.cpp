#include <iostream>

using namespace std;

int n,m,e[9][9],root;
int num[9],low[9],index;//index��������ʱ����ĵ���

int min(int a,int b){
    return a<b?a:b;
}

//����㷨����
void dfs(int cur ,int father){//��Ҫ����������������ǰ����ı�ź͸�����ı��
    int i;//i������¼���������е�ǰ����cur�Ķ��Ӹ���

    index++;//ʱ�����+1
    num[cur]=index;//��ǰcur�����ʱ���
    low[cur]=index;

    for(i=1;i<=n;i++){//ö���뵱ǰ����cur�б������Ķ���i
        if(e[cur][i] ==1){
            if(num[i] ==0){
                dfs(i,cur);
                low[cur] =min(low[cur],low[i]);
                //�����ǰ���㲻�Ǹ��ڵ㲢������low[i]>=num[cur],��ǰ����Ϊ���
                if(low[i]>num[cur])cout<<cur<<"--"<<i<<endl;
            }
            else if(i!= father){
                low[cur] =min(low[cur],num[i]);
            }
        }
    }
    return;
}
int main()
{
    int i,j,x,y;
    cin>>n>>m;

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            e[i][j]=0;
        }
    }

    for(i=1;i<=m;i++){
        cin>>x>>y;
        e[x][y]=1;
        e[y][x]=1;
    }

    root=1;
    dfs(1,root);
    return 0;
}


/*
��������
6 6
1 4
1 3
4 2
3 2
2 5
5 6
*/
