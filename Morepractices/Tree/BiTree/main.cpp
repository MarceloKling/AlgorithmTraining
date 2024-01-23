#include <iostream>
using namespace std;
#define maxn 50

template<class T>
struct Node{
    T data;
    Node<T> *lchild,*rchild;
};

//�ǵݹ������������ڱ�ǵĽṹ��
template <class T>
struct Element{
    Node<T> *ptr;
    int flag;
};

template<class T>
class BiTree{
private:
    Node<T> *root;  //ָ����ڵ��ͷָ��
    Node<T> *create(Node<T> *bt);   //���캯������
    void release(Node<T> *bt);      //������������
    void preOrder(Node<T> *bt);     //ǰ���������
    void inOrder(Node<T> *bt);      //�������
    void postOrder(Node<T> *bt);    //�������
    void NRPreOrder(Node<T> *bt);    //�ǵݹ�ǰ�����
    void NRInOrder(Node<T> *bt);    //�ǵݹ��������
    void NRPostOrder(Node<T> *bt); //�ǵݹ�������

public:
    BiTree(){root=create(root);}    //����һ�ö�����
    ~BiTree(){release(root);}       //��������
    void preOrder(){preOrder(root);}   //ǰ�����
    void inOrder(){inOrder(root);}      //�������
    void postOrder(){postOrder(root);}  //  �������
    void levelOrder();              //�������
    void NRPreOrder(){NRPreOrder(root);}    //�ǵݹ�ǰ�����
    void NRInOrder(){NRInOrder(root);}      //�ǵݹ��������
    void NRPostOrder(){NRPostOrder(root);}  //�ǵݹ�������
};

//�ݹ鷽��ʵ��ǰ�����
template <class T>
void BiTree<T>::preOrder(Node<T> *bt){
    if(bt==NULL)return;     //�ݹ���õĽ�������
    else{
        cout<<bt->data<<" ";
        preOrder(bt->lchild);
        preOrder(bt->rchild);
    }
}

//�ݹ鷽��ʵ���������
template <class T>
void BiTree<T>::inOrder(Node<T> *bt){
    if(bt==NULL)return; //�ݹ���õĽ�������
    else{
        inOrder(bt->lchild);
        cout<<bt->data<<" ";
        inOrder(bt->rchild);
    }
}

//�ݹ鷽��ʵ���������
template <class T>
void BiTree<T>::postOrder(Node<T> *bt){
    if(bt==NULL)return; //�ݹ���õĽ�������
    else{
        postOrder(bt->lchild);
        postOrder(bt->rchild);
        cout<<bt->data<<" ";
    }
}

//�������
template <class T>
void BiTree<T>::levelOrder(){
    int m_front=-1,m_rear=-1;
    if(root==NULL)return;   //���������Ϊ�գ����㷨����
    Node<T>* Q[maxn];
    Q[++m_rear]=root;   //��ָ�����
    Node<T> *q;
    while(m_front!=m_rear){
        q=Q[++m_front]; //���Ӳ���
        cout<<q->data<<" ";
        if(q->lchild!=NULL)Q[++m_rear]=q->lchild;
        if(q->rchild!=NULL)Q[++m_rear]=q->rchild;
    }
}

//�ǵݹ�ǰ�����
template <class T>
void BiTree<T>::NRPreOrder(Node<T>* bt){
    int top=-1; //��ʼ��ջ
    Node<T> *s[maxn];
    while(bt!=NULL || top !=-1){    //�������������������˳�ѭ��
        while(bt!=NULL){
            cout<<bt->data<<" ";
            s[++top]=bt;            //����ָ����ջ
            bt=bt->lchild;          //����������
        }
        if(top!=-1){                //ջ�ǿ�
            bt=s[top--];
            bt=bt->rchild;          //����������
        }
    }
}

//�ǵݹ��������
template <class T>
void BiTree<T>::NRInOrder(Node<T>* bt){
    int top=-1;
    Node<T>* s[maxn];
    while(bt!=NULL || top!=-1){
        while(bt!=NULL){
            s[++top]=bt;
            bt=bt->lchild;
        }
        if(top!=-1){
            bt=s[top--];
            cout<<bt->data<<" ";
            bt=bt->rchild;
        }
    }
}

//�ǵݹ�������������
template <class T>
void BiTree<T>::NRPostOrder(Node<T>* bt){
    int top=-1;
    Element<T> s[maxn];
    while(bt!=NULL || top!=-1){
        while(bt!=NULL){
            top++;
            s[top].ptr=bt;
            s[top].flag=1;
            bt=bt->lchild;
        }
        while(top!=-1 && s[top].flag==2){
            bt=s[top--].ptr;
            cout<<bt->data<<" ";
            if(top==-1)bt=NULL;
        }
        if(top!=-1){
            s[top].flag=2;
            bt=s[top].ptr->rchild;
        }
    }
}
//����������
template <class T>
Node<T>* BiTree<T>::create(Node<T> *bt){
    char ch;
    cin>>ch;
    if(ch=='#')bt=NULL;
    else{
        bt=new Node<T>();   //����һ���ڵ�
        bt->data=ch;
        bt->lchild=create(bt->lchild);  //�ݹ齨��������
        bt->rchild=create(bt->rchild);  //�ݹ齨��������
    }
    return bt;
}
//��������
template <class T>
void BiTree<T>::release(Node<T> *bt){
    if(bt!=NULL){
        release(bt->lchild);    //�ͷ�������
        release(bt->rchild);    //�ͷ�������
        delete bt;
    }
}
int main()
{
    BiTree<char> tree;
    cout<<"ǰ�����"<<endl;
    tree.preOrder();
    cout<<endl;
    cout<<"�������"<<endl;
    tree.inOrder();
    cout<<endl;
    cout<<"�������"<<endl;
    tree.postOrder();
    cout<<endl;
    cout<<"��α���"<<endl;
    tree.levelOrder();
    cout<<endl;
    cout<<"�ǵݹ�ǰ�����"<<endl;
    tree.NRPreOrder();
    cout<<endl;
    cout<<"�ǵݹ��������"<<endl;
    tree.NRInOrder();
    cout<<endl;
    cout<<"�ǵݹ�������"<<endl;
    tree.NRPostOrder();
    return 0;
}
