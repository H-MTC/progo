#include<iostream>
#include<cstdlib>
#include<iomanip> //std::setw
#define NO_EDGE (-1)

using namespace std;

class GraphMatrix
{
    public:
        ~GraphMatrix();
        void createGraph();
        void printGraph();
    private:
        void inputVertexCount();
        void makeVertexArray();
        void inputEdgeCount();
        void inputEdgeInfo();

        void addEdgeToList(int vFrom, int weight, int vTo);
    private:
        int m_vCount;
        int m_eCount;
        int** m_vVertex;
};

GraphMatrix::~GraphMatrix()
{
    for(int i = 0; i < m_vCount; ++i){delete m_vVertex[i];}
    delete[] m_vVertex;
}

void GraphMatrix::inputVertexCount()
{
    cout<<"Please input count of vertexes: ";
    cin>>m_vCount;
}

void GraphMatrix::makeVertexArray()
{
    m_vVertex = new int*[m_vCount];
    for(int i = 0; i < m_vCount; ++i){m_vVertex[i] = new int[m_vCount];}
    for(int i = 0; i < m_vCount; ++i)
    {
        for(int j = 0; j < m_vCount; ++j)
        {
            m_vVertex[i][j] = NO_EDGE;
        }
    }
}

void GraphMatrix::inputEdgeCount()
{
    cout<<"Please input count of edge:";
    cin>>m_eCount;
}

void GraphMatrix::inputEdgeInfo()
{
    cout<<"Please input edge information: ";
    for(int i = 0; i < m_eCount; ++i)
    {
        cout<<"The edge "<<i<<":"<<endl;
        int from = 0; cout<<"From:"; cin>>from;
        int weight = 0; cout<<"Weight:"; cin>>weight;
        int to; cout<<"To:"; cin>>to;
        addEdgeToList(from, weight, to);
    }
}

void GraphMatrix::addEdgeToList(int vFrom, int weight, int vTo)
{
    m_vVertex[vFrom][vTo] = weight;
}

void GraphMatrix::printGraph()
{
    for(int i = 0; i < m_vCount; ++i)
    {
        for(int j = 0; j < m_vCount; ++j)
        {
            cout<<setw(3)<<m_vVertex[i][j]<<" ";
        }
        cout<<endl;
    }
}

void GraphMatrix::createGraph()
{
    inputVertexCount();
    makeVertexArray();
    inputEdgeCount();
    inputEdgeInfo();
}

void test()
{
    GraphMatrix graph;
    graph.createGraph();
    graph.printGraph();
    system("pause");
}











