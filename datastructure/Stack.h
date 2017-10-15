#include<cstdio>
#include<cassert>
#include<list>
#include<cstdlib>
#include<iostream>

using namespace std;

class Stack
{
    public:
        Stack();
        Stack(const Stack &Stack);
        Stack& operator=(const Stack &Stack);
        ~Stack();

        void Push(const int& data);
        int Pop();
        unsigned short Size();
        bool isEmpty();
        void PrintStack();
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

void Stack::Free()
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

Stack::Stack()
{
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}

Stack::Stack(const Stack &Stack)
{
    m_head = NULL;
    m_tail = NULL;
    m_size = Stack.m_size;
    if(Stack.m_head)
    {
        Node* tmp = Stack.m_head;
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

Stack& Stack::operator=(const Stack& Stack)
{
    Free();
    m_size = Stack.m_size;
    if(Stack.m_head)
    {
        Node* tmp = Stack.m_head;
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

Stack::~Stack()
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

void Stack::Push(const int& data)
{
    Node* tmp = new Node(data);
    if(!m_head){m_head = tmp; m_tail = tmp;}
    else{tmp->next = m_head; m_head = tmp;}
    ++m_size;
}

int Stack::Pop()
{
    assert(m_size > 0);
    Node* tmp = m_head;
    m_head = m_head->next;
    int val = tmp->data;
    delete tmp;
    --m_size;
    return val;
}

unsigned short Stack::Size(){return m_size;}

bool Stack::isEmpty(){return m_size == 0;}

void Stack::PrintStack()
{
    cout<<"Size: "<<m_size<<", content: ";
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
    Stack stk;
    for(int i = 0; i < 5; ++i)
    {
        stk.Push(i);
    }
    stk.PrintStack();
    Stack stkcpy(stk);
    stkcpy.PrintStack();
    Stack stackAssig;
    stackAssig = stk;
    stackAssig.PrintStack();
    int pop = stk.Pop();
    cout<<"Pop Item: "<<pop<<endl;
    stk.PrintStack();
    system("pause");
}


















