#include <iostream>

using namespace std;
/**
���ݽṹ~����ϰ
*/
template<class T>
struct Node
{
    T data;
    Node<T> *next;
};

template<class T>
class LinkList
{
public:
    LinkList();     //�޲ι��캯��������������
    LinkList(T a[],int n);  //�вι��캯����������n��Ԫ�صĵ�����
    ~LinkList();
    int Length();   //��������
    T Get(int i);   //���ص�i������ֵ
    int Locate(T x);    //����ֵΪx�����
    void Insert(int i,T x);  //�ڵ�i��λ�ò���x
    T Delete(int i);        //ɾ����i���ڵ�
    void PrintList();       //��������
    void ReverseList();     //��������
private:
    Node<T> *first;     //ͷָ��
};

template<class T>
LinkList<T>::LinkList()
{
    first=new Node<T>();
    first->next=NULL;
}

//ͷ�巨
template<class T>
LinkList<T>::LinkList(T a[],int n)
{
    first=new Node<T>();
    first->next=NULL;
    Node<T> *s;
    for(int i=0;i<n;i++){
        s=new Node<T>();
        s->data=a[i];
        s->next=first->next;
        first->next=s;
    }
}

//β�巨
//template<class T>
//LinkList<T>::LinkList(T a[],int n)
//{
//    first=new Node<T>();
//    Node<T> *r=first;    //βָ���ʼ��
//    Node<T> *s;
//    for(int i=0;i<n;i++){
//        s=new Node<T>();
//        s->data=a[i];
//        r->next=s;
//        r=s;
//    }
//    r->next=NULL;
//}

template<class T>
LinkList<T>::~LinkList()
{
    while(first!=NULL){
        Node<T> *q;
        q=first;
        first=first->next;
        delete q;
    }
}

template<class T>
void LinkList<T>::PrintList()
{
    Node<T> *p;
    p=first->next;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}

template<class T>
int LinkList<T>::Length(){
    Node<T> *p;
    p=first->next;
    int countn=0;
    while(p!=NULL){
        p=p->next;
        countn++;
    }
    return countn;
}

template<class T>
T LinkList<T>::Get(int i){
    Node<T> *p;
    p=first->next;
    int countn=1;
    while(p!=NULL&&countn<i){
        p=p->next;
        countn++;
    }
    if(p==NULL)throw "λ�÷Ƿ�";
    else return p->data;
}

template<class T>
int LinkList<T>::Locate(T x){
    Node<T> *p=first;
    p=p->next;
    int countn=1;
    while(p!=NULL){
        if(p->data==x)return countn;
        p=p->next;
        countn++;
    }
    return 0;
}

template<class T>
void LinkList<T>::Insert(int i,T x){
    Node<T> *p=first;
    int countn=0;
    while(p!=NULL &&countn<i-1){
        p=p->next;
        countn++;
    }
    if(p==NULL)throw "λ�÷Ƿ�";
    else{
        Node<T> *s= new Node<T>();
        s->data=x;
        s->next=p->next;
        p->next=s;
    }
}

template<class T>
T LinkList<T>::Delete(int i){
    Node<T> *p=first;
    int countn=0;
    while(p!=NULL&&countn<i-1){
        p=p->next;
        countn++;
    }
    if(p==NULL||p->next==NULL){
        throw "λ�÷Ƿ�";
    }
    else{
        Node<T> *q;
        q=p->next;
        T x=q->data;
        p->next=q->next;
        delete q;
        return x;
    }
}

//template<class T>
//void LinkList<T>::ReverseList(){
//    if(first==NULL||first->next==NULL)return;
//        Node<T> *p, *q;
//    p = first->next;    //Pָ�������һ��Ԫ��
//    first->next = NULL; //�Ͽ�ͷ���������
//    while(p != NULL)
//    {
//        q = p;
//        p = p->next;
//        q->next = first->next;  //�൱��ǰ�巨�����µ�������ԭ�����෴
//        first->next = q;
//    }
//}

template<class T>
void LinkList<T>::ReverseList(){
    if(first==NULL||first->next==NULL)return;
    Node<T> *pre=first;
    Node<T> *cur=pre->next;
    Node<T> *next=NULL;
    Node<T> *cur1=cur;
    while(cur!=NULL){
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    first->next=pre;
    cur1->next=NULL;
}

int main()
{
    int a[]={1,2,3,4,5};
    LinkList<int> l(a,5);
    l.PrintList();
    cout<<endl;
    cout<<l.Length()<<endl;
    cout<<endl;
    l.ReverseList();
    l.PrintList();
    return 0;
}
