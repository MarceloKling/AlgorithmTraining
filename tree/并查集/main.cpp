#include <iostream>

using namespace std;

int f[1000]={0},n,m,k,sum=0;

void init(){
    int i;
    for(i=1;i<=n;i++){
        f[i]=i;
    }
    return;
}

//�������ҵ��ĵݹ麯������ͣ��ȥ�ҵ���֪���ҵ�����Ϊֹ����ʵ����ȥ�ҷ����Ż������쵼��
//������������ԭ��
int getf(int v){
    if (f[v]==v)return v;
    else{
        //·��ѹ����ÿ���ں������ص�ʱ��
//        ˳���·���������˵ġ�BOSS����Ϊ����ҵ������ڱ�ţ�����������߽���ҵ������Ż������쵼�˵��ٶ�
        f[v]=getf(f[v]);
        return f[v];
    }
}

void merge(int v,int u){
    int t1,t2;
    t1 =getf(v);
    t2 =getf(u);
    if(t1!=t2){
        f[t2]=t1;
    }
    return;
}
int main()
{
    int i,x,y;
    cin>>n>>m;
    init();
    for(i=1;i<=m;i++){
        cin>>x>>y;
        merge(x,y);
    }

    //���ɨ���ж��ٸ������ķ����Ż�
    for(i=1;i<=n;i++){
        if(f[i] ==i)sum++;
    }
    cout<<sum<<endl;
    return 0;
}


/*
��������
10 9
1 2
3 4
5 2
4 6
2 6
8 7
9 7
1 6
2 4
*/
