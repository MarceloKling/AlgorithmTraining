#include <iostream>

using namespace std;

int main()
{
    char a[20][21];
    int sum,maxn =0,p,q,x,y,n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == '.'){//���ж��Ƿ��ǿյ�
                sum=0;
                //����ǰ����i��j���Ƶ��±���x��y�С�
                //����ͳ�Ƶ�����Ŀ
                x=i;
                y=j;
                while(a[x][y]!= '#'){//�ж��Ƿ���ǽ
                    //����ǵ��������
                    if(a[x][y] =='G')sum++;
                    x--;//����ͳ��
                }

                //����ͳ�Ƶ�����Ŀ
                x=i;y=j;
                while(a[x][y] !='#'){
                    if(a[x][y] == 'G')sum++;
                    x++;
                }

                //����ͳ�Ƶ�����Ŀ
                x=i;
                y=j;
                while(a[x][y] !='#'){
                    if(a[x][y] == 'G')sum++;
                    y--;
                }

                //����ͳ�Ƶ�����Ŀ
                x=i;
                y=j;
                while(a[x][y] !='#'){
                    if(a[x][y] =='G')sum++;
                    y++;
                }
                //����maxֵ
                if(sum>maxn){
                    maxn =sum;
                    //��¼��ǰ����
                    p=i;q=j;
                }
            }
        }
    }
    cout<<"��ը��������("<<p<<","<<q<<")����������"<<maxn<<"������"<<endl;
    return 0;
}
/*
��������
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.###
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/