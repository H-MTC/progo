#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>

using namespace std;

struct Edge
{
    int vName;
    int weight;
    Edge* next;
};

struct Vertex
{
    int vName;
    int in;
    int out;
    Edge* next;
};

class GraphList
{
    public:
        ~GraphList();
        void createGraph();
        void printGraph();
        bool topSortInDegree();
    private:
        void inputVertexCount();
        void makeVertexArray();
        void inputEdgeCount();
        void inputEdgeInfo();

        void addEdgeToList(int vFrom, int weight, int vTo);
    private:
        int m_vCount;
        int m_eCount;
        Vertex* m_vVertex;
};

GraphList::~GraphList()
{
    for(int i = 0; i < m_vCount; ++i)
    {
        Edge* tmp = m_vVertex[i].next;
        Edge* edge = NULL;
        while(tmp)
        {
            edge = tmp;
            tmp = tmp->next;
            delete edge;
            edge = NULL;
        }
    }
    delete[] m_vVertex;
}

void GraphList::inputVertexCount()
{
    cout<<"Please input count of vertexes:\n";
    cin>>m_vCount;
}

void GraphList::makeVertexArray()
{
    m_vVertex = new Vertex[m_vCount];
    for(int i = 0; i < m_vCount; ++i)
    {
        m_vVertex[i].vName = i;
        m_vVertex[i].next = NULL;
        m_vVertex[i].in = 0;
        m_vVertex[i].out = 0;
    }
}

void GraphList::inputEdgeCount()
{
    cout<<"Please input count of edge:\n";
    cin>>m_eCount;
}

void GraphList::inputEdgeInfo()
{
    cout<<"Please input edge information:"<<endl;
    for(int i = 0; i < m_eCount; ++i)
    {
        cout<<"The edge"<<i<<":"<<endl;
        int from = 0; cout<<"From: "; cin>>from;
        int weight = 0; cout<<"Weight: "; cin>>weight;
        int to = 0; cout<<"To: "; cin>>to;
        cout<<endl;
        addEdgeToList(from, weight, to);
    }
}

void GraphList::addEdgeToList(int vFrom, int weight, int vTo)
{
    Edge* edge = new Edge();
    edge->vName = vTo;
    edge->weight = weight;
    edge->next = NULL;
    if(m_vVertex[vFrom].next)
    {
        Edge* tmp = m_vVertex[vFrom].next;
        while(tmp->next){tmp = tmp->next;}
        tmp->next = edge;
    }
    else{m_vVertex[vFrom].next = edge;}
    ++m_vVertex[vTo].in;
    ++m_vVertex[vFrom].out;
}

void GraphList::printGraph()
{
    for(int i = 0; i < m_vCount; ++i)
    {
        Edge* tmp = m_vVertex[i].next;
        cout<<"List:"<<m_vVertex[i].vName<<"(in: "<<m_vVertex[i].in<<")"<<"->";
        while(tmp)
        {
            cout<<"(weight: "<<tmp->weight<<")";
            cout<<tmp->vName;
            tmp = tmp->next;
        }
        cout<<"NULL"<<endl;
    }
}

bool GraphList::topSortInDegree()
{
    stack<Vertex*> vertexStack;
    queue<Vertex*> vertexQueue;
    int* degree = new int[m_vCount];
    for(int i = 0; i < m_vCount; ++i)
    {
        degree[i] = m_vVertex[i].in;
        if(!degree[i]){vertexStack.push(&m_vVertex[i]);}
    }
    int count = 0;
    while(!vertexStack.empty())
    {
        Vertex* tmp = vertexStack.top();
        vertexStack.pop();
        vertexQueue.push(tmp);
        ++count;
        Edge* edge = tmp->next;
        while(edge)
        {
            Vertex* vertex = &m_vVertex[edge->vName];
            --degree[edge->vName];
            if(!degree[edge->vName]){vertexStack.push(vertex);}
            edge = edge->next;
        }
    }
    if(count < m_vCount){return false;}
    while(!vertexQueue.empty())
    {
        Vertex* tmp = vertexQueue.front();
        vertexQueue.pop();
        cout<<tmp->vName<<" ";
    }
    cout<<endl;
    delete[] degree;
    return true;
}
void GraphList::createGraph()
{
    inputVertexCount();
    makeVertexArray();
    inputEdgeCount();
    inputEdgeInfo();
}

void test()
{
    GraphList graph;
    graph.createGraph();
    graph.printGraph();
    cout<<"Top sort output: "<<endl;
    graph.topSortInDegree();
    system("pause");
}












