//���Ȱ��ձߵ�Ȩֵ��С��������ÿ�δ�ʣ��ı���ѡ��Ȩֵ��С
//�ұߵ��������㲻��ͬһ�������ڵıߣ����ǲ��������·�ıߣ������뵽��������
//ֱ��������n-1����Ϊֹ
#include <iostream>

using namespace std;

struct edge{
    int u;
    int v;
    int w;
};
struct edge e[10];
int n,m;
int f[7]={0},sum=0,countx=0;

void quicksort(int left,int right){
    int i,j;
    struct edge t;
    if(left >right){
        return;
    }
    i=left;
    j=right;
    while(i!=j){
        while(e[j].w >=e[left].w &&i<j)j--;
        while(e[i].w <=e[left].w && i<j)i++;
        //swap
        if(i<j){
            t=e[i];
            e[i]=e[j];
            e[j]=t;
        }
    }
    t=e[left];
    e[left] =e[i];
    e[i]=t;

    quicksort(left,i-1);
    quicksort(i+1,right);
    return;
}

int getf(int v){
    if(f[v]==v)return v;
    else{
        //·��ѹ��
        f[v]=getf(f[v]);
        return f[v];
    }
}

int Merage(int v,int u){
    int t1,t2;
    t1 =getf(v);
    t2 =getf(u);
    if(t1 !=t2){
        f[t2]=t1;
        return 1;
    }
    return 0;
}

int main()
{
    int i;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    quicksort(1,m);
    for(i=1;i<=n;i++)f[i]=i;

    //Kruskal�㷨���Ĳ���
    for(i=1;i<=m;i++){//��С����ö��ÿһ����
        //�ж�һ���ߵ����������Ƿ��Ѿ���ͨ�����ж��Ƿ��Ѿ���ͬһ��������
        if(Merage(e[i].u,e[i].v)){//���Ŀǰ��δ��ͨ����ѡ��������
            countx++;
            sum=sum+e[i].w;
        }
        if(countx ==n-1)break;//ֱ��ѡ����n-1����֮���˳�ѭ��
    }
    cout<<endl;
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
