#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstdlib>
using namespace std;

class DList
{
    public:
        DList();
        DList(const DList &list);
        DList& operator=(const DList &list);
        ~DList();
        void PushFront(const int& data);
        int PopFront();
        void PushBack(const int& data);
        int PopBack();
        void reverse();
        unsigned short size();
        bool isEmpty();
        void PrintList();
    private:
        void Free();
    private:
        typedef struct Node
        {
            Node(int d):data(d), next(NULL),prev(NULL){}
            int data;
            Node* next;
            Node* prev;
        }Node;
        Node* m_head;
        Node* m_tail;
        unsigned short m_size;
};

void DList::Free()
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

DList::DList()
{
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}

DList::DList(const DList &list)
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
            else{node->prev = q; q->next = node; q = node;}
            tmp = tmp->next;
        }
        m_tail = q;
    }
    else{m_head = NULL; m_tail = NULL;}
}

DList& DList::operator=(const DList &list)
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
            else{node->prev = q; q->next = node; q = node;}
            tmp = tmp->next;
        }
        m_tail = q;
    }
    else{m_head = NULL; m_tail = NULL;}
    return *this;
}

DList::~DList()
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

void DList::PushFront(const int& data)
{
    Node* tmp = new Node(data);
    if(!m_head){m_head = tmp; m_tail = tmp;}
    else{tmp->next = m_head; m_head->prev = tmp; m_head = tmp;}
    ++m_size;
}

int DList::PopFront()
{
    assert(m_size > 0);
    Node* tmp = m_head;
    m_head = m_head->next;
    m_head->prev = NULL;
    int val = tmp->data;
    delete tmp;
    --m_size;

    return val;
}

void DList::PushBack(const int& data)
{
    Node* tmp = new Node(data);
    tmp->prev = m_tail;
    m_head?(m_tail->next = tmp):(m_head = tmp);
    m_tail = tmp;
    ++m_size;
}

int DList::PopBack()
{
    assert(m_size > 0);
    int val = 0;
    Node *pre = m_tail->prev;
    if(!pre)
    {
        val = m_tail->data;
        delete m_tail;
        m_head = NULL;
        m_tail = NULL;
        m_size = 0;
    }
    else
    {
        delete m_tail;
        m_tail = pre;
        m_tail->next = NULL;
        --m_size;
    }
    return val;
}

void DList::reverse()
{
    if(!m_head || !m_head->next){return;}
    Node* pre = m_head;
    Node* cur = m_head->next;
    Node* next = NULL;
    while(cur)
    {
        next = cur->next;
        cur->next = pre;
        pre->prev = cur;
        pre = cur;
        cur = next;
    }
    pre->prev = NULL;
    m_head->next = NULL;
    m_tail = m_head;
    m_head = pre;
}

unsigned short DList::size()
{
    return m_size;
}

bool DList::isEmpty()
{
    return m_size == 0;
}

void DList::PrintList()
{
    cout<<"Size: "<<m_size<<", content: "<<endl;
    cout<<"From Head: ";
    if(m_head)
    {
        Node* tmp = m_head;
        while(tmp){cout<<tmp->data<<"->"; tmp = tmp->next;}
    }
    cout<<"NULL"<<endl;
    cout<<"From Tail: ";
    if(m_tail)
    {
        Node* tmp = m_tail;
        while(tmp){cout<<tmp->data<<"->"; tmp = tmp->prev;}
    }
    cout<<"NULL"<<endl;
}

void test()
{
    DList lis;
    for(int i = 0; i < 9; ++i)
    {
        lis.PushFront(i);
    }
    lis.PrintList();
    lis.PushBack(0);
    lis.PrintList();
    DList liscopy(lis);
    liscopy.PrintList();
    DList listAssig;
    listAssig = lis;
    listAssig.PrintList();
    int popfront = lis.PopFront();
    cout<<"PopFront: "<<popfront<<endl;
    lis.PrintList();
    int popback = lis.PopBack();
    cout<<"PopBack: "<<popback<<endl;
    lis.PrintList();
    cout<<"Doing reverse..."<<endl;
    lis.reverse();
    lis.PrintList();
    system("pause");
}
























