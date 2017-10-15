#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstdlib>

using namespace std;

class Queue
{
    public:
        Queue();
        Queue(const Queue &Queue);
        Queue& operator=(const Queue &Queue);
        ~Queue();

        int Pop();
        void Push(const int& data);
        unsigned short Size();
        bool isEmpty();
        void PrintQueue();
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

void Queue::Free()
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

Queue::Queue()
{
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}

Queue::Queue(const Queue &Queue)
{
    m_head = NULL;
    m_tail = NULL;
    m_size = Queue.m_size;
    if(Queue.m_head)
    {
        Node* tmp = Queue.m_head;
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
    else{m_head = NULL; m_tail = NULL;}
}

Queue& Queue::operator=(const Queue &Queue)
{
    Free();
    m_size = Queue.m_size;
    if(Queue.m_head)
    {
        Node* tmp = Queue.m_head;
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
    else{m_head = NULL; m_tail = NULL;}
    return *this;
}

Queue::~Queue()
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

void Queue::Push(const int& data)
{
    Node* tmp = new Node(data);
    if(!m_head){m_head = tmp; m_tail = tmp;}
    else{tmp->next = m_head; m_head = tmp;}
    ++m_size;
}

int Queue::Pop()
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
        cur = NULL;
        --m_size;
    }
    return val;
}

unsigned short Queue::Size(){return m_size;}

bool Queue::isEmpty(){return m_size == 0;}

void Queue::PrintQueue()
{
    cout<<"Size: "<<m_size<<", content: ";
    if(m_head)
    {
        Node* tmp = m_head;
        while(tmp){cout<<tmp->data<<"->"; tmp = tmp->next;}
    }
    cout<<"NULL"<<endl;
}

void test()
{
    Queue que;
    for(int i =0; i < 9; ++i)
    {
        que.Push(i);
    }
    que.PrintQueue();
    Queue quee(que);
    quee.PrintQueue();
    Queue queueAssig;
    queueAssig = que;
    queueAssig.PrintQueue();
    int pop = que.Pop();
    cout<<"Pop: "<<pop<<endl;
    que.PrintQueue();
    system("pause");
}

























