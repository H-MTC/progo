#include<cstdio>
#include<cstdlib>
#include<list>
#include<cassert>
#include<iostream>
using namespace std;

class List
{
    public:
        List();
        List(const List &list);
        List& operator=(const List &list);
        ~List();

        void PushFront(const int& data);
        int PopFront();
        void PushBack(const int& data);
        int PopBack();
        void reverse();
        unsigned short size();
        bool isEmpty();
        void printList();
    private:
        void Free();
    private:
        typedef struct Node
        {
            Node(int d):data(d), next(NULL){}
            int data;
            struct Node* next;
        }Node;
        Node* m_head;
        Node* m_tail;
        unsigned short m_size;
};

void List::Free()
{
    if(m_head)
    {
        Node* tmp = NULL;
        while(m_head)
        {
            tmp = m_head;
            m_head = m_head->next;
            delete tmp;
        }
    }
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}

List::List()
{
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}

List::List(const List &list)
{
    m_head = NULL;
    m_tail = NULL;
    m_size = list.m_size;

    if(list.m_head)
    {
        Node* tmp = list.m_head;
        Node* q = NULL;
        while(tmp)
        {
            Node* node = new Node(tmp->data);
            if(!m_head){m_head = node; q = m_head;}
            else{q->next = node; q = node;}
            tmp = tmp->next;
        }
        m_tail = q;
    }
    else
    {
        m_head = NULL;
        m_tail = NULL;
    }
}

List& List::operator=(const List &list)
{
    Free();
    m_size = list.m_size;
    if(list.m_head)
    {
        Node* tmp = list.m_head;
        Node* q = NULL;
        while(tmp)
        {
            Node* node = new Node(tmp->data);
            if(!m_head){m_head = node; q = m_head;}
            else{q->next = node; q = node;}
            tmp = tmp->next;
        }
        m_tail = q;
    }
    else
    {
        m_head = NULL;
        m_tail = NULL;
    }
    return *this;
}

List::~List()
{
    if(m_head)
    {
        Node* tmp = m_head;
        while(tmp)
        {
            m_head = m_head->next;
            delete tmp;
            tmp = m_head;
        }
    }
    m_head = NULL;
    m_tail = NULL;
}

void List::PushFront(const int& data)
{
    Node* tmp = new Node(data);
    if(!m_head){m_head = tmp; m_tail = tmp;}
    else{tmp->next = m_head; m_head = tmp;}
    ++m_size;
}

int List::PopFront()
{
    assert(m_size > 0);
    Node* tmp = m_head;
    m_head = m_head->next;

    int val = tmp->data;
    delete tmp;
    --m_size;
    return val;
}

void List::PushBack(const int& data)
{
    Node* tmp = new Node(data);
    m_head?(m_tail->next = tmp):(m_head = tmp);
    m_tail = tmp;
    ++m_size;
}

int List::PopBack()
{
    assert(m_size > 0);
    int val = 0;
    Node *cur, *pri;
    if(!m_head->next)
    {
        val = m_head->data;
        delete m_head;
        m_head = NULL;
        m_tail = NULL;
        m_size = 0;
    }
    else
    {
        cur = m_head;
        while(cur->next->next){cur = cur->next;}
        pri = cur;
        m_tail = cur;
        cur = cur->next;
        pri->next = NULL;
        val = cur->data;
        delete cur;
        cur = NULL;// delete is enough??
        --m_size;
    }
    return val;
}

void List::reverse()
{
    if(!m_head || !m_head->next)
    {
        return;
    }
    Node *pri, *cur, *tmp;
    pri = m_head;
    cur = m_head->next;
    m_head->next = NULL;
    while(cur)
    {
        tmp = cur->next;
        cur->next = pri;
        pri = cur;
        cur = tmp;
    }
    m_head = pri;
}

unsigned short List::size()
{
    return m_size;
}

bool List::isEmpty()
{
    return (m_size == 0);
}

void List::printList()
{
    cout<<"size:"<<m_size<<"\ncontent:\n";
    if(m_head)
    {
        Node* tmp = m_head;
        while(tmp)
        {
            cout<<tmp->data<<"->";
            tmp = tmp->next;
        }
    }
    cout<<"NULL"<<endl;
}

void test()
{
    List list;
    for(int i = 0; i < 5; ++i)
    {
        list.PushFront(i);
    }
    list.printList();
    list.PushBack(0);
    list.printList();
    List listCopy(list);
    listCopy.printList();
    List listAssig;
    listAssig = list;
    listAssig.printList();
    int popfront = list.PopFront();
    cout<<"pop front: "<<popfront<<endl;
    list.printList();
    int popback = list.PopBack();
    cout<<"pop back: "<<popback<<endl;
    list.printList();
    list.reverse();
    cout<<"do reverse..."<<endl;
    list.printList();
    system("pause");
}














