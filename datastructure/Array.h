#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class Array
{
    public:
        Array(int size, int val = 0);
        Array(const Array &array);
        Array& operator= (const Array &array);
        ~Array();
        int operator[](int index) const;

        void InsertAt(int index, int val);
        void PushBack(int val);
        void DeleteAt(int index);
        void SetAt(int index, int val);
        int GetAt(int index);
        void SetSize(int size);
        int GetSize();

        void PrintArray();

    private:
        void Init();
        void Free();
        bool isValidIndex(int index);
        void getMoreMemory();

    private:
        int *m_array;
        int m_size;
        int m_max;
};

void Array::Init(){m_size = 0; m_max = 1; m_array = new int[m_max];}

void Array::Free(){delete[] m_array;}

bool Array::isValidIndex(int index)
{
    if(index >=0 && index <= m_size)
        return true;
    return false;
}

void Array::getMoreMemory()
{
    m_max *=2;
    int* tmp = new int[m_max];
    memcpy(tmp, m_array, m_size*sizeof(int));
    delete[] m_array;
    m_array = tmp;
}


Array::Array(int size, int val)
{
    if(size > 0)
        {
            m_size = size; m_max = size; m_array = new int[m_max];
            for(int i = 0; i < m_size; ++i)
                {m_array[i] = val;}
        }
    else if(size == 0){Init();}
    else{cout<<"Invalid Size:"<<size<<endl;}
}

Array::Array(const Array& array)
{
    m_size = array.m_size;
    m_max = array.m_max;
    m_array = array.m_array;

    memcpy(m_array, array.m_array, array.m_max*sizeof(int));
}

Array& Array::operator=(const Array& array)
{
    if(this != &array)
    {
        m_size = array.m_size;
        m_max = array.m_max;
        m_array = new int[array.m_max];
        memcpy(m_array, array.m_array, array.m_max*sizeof(int));
    }
    return *this;
}

Array::~Array(){Free();}

//Overloading
int Array::operator[](int index) const
{
    if(index >= 0 && index < m_size){return m_array[index];}
    else{cout<<"Invalid Index:"<<index<<endl; exit(0);}
}


//Operations
void Array::InsertAt(int index, int val)
{
    if(!isValidIndex(index)){cout<<"Invalid Index:"<<index<<endl; exit(0);}
    if(m_size >= m_max){getMoreMemory();}
    for(int i = index; i < m_size; ++i){m_array[i + 1] = m_array[i];}
    m_array[index] = val;
    ++m_size;
}

void Array::PushBack(int val)
{
    if(m_size >= m_max){getMoreMemory();}
    m_array[m_size] = val;
    ++m_size;
}

void Array::DeleteAt(int index)
{
    if(!isValidIndex(index)){cout<<"Invalid Index"<<index<<endl; exit(0);}
    for(int i = index; i < m_size; ++i)
        {m_array[i] = m_array[i + 1];}
    m_array[m_size - 1] = 0;
    --m_size;
}

void Array::SetAt(int index, int val)
{
    if(!isValidIndex(index)){cout<<"Invalid Index:"<<index<<endl; exit(0);}
    m_array[index] = val;
}

int Array::GetAt(int index)
{
    if(!isValidIndex(index)){cout<<"Invalid Index:"<<index<<endl; exit(0);}
    return m_array[index];
}

void Array::SetSize(int size)
{
    if(size < m_size)
        {
            for(int i = 0; i < m_size; ++i)
                {m_array[i] = 0;}
        }
    else if(size >= m_size)
    {
        if(size > m_size)
        {
            m_max = size;
            int* tmp = new int[m_max];
            memcpy(tmp, m_array, m_size*sizeof(int));
            m_array = tmp;
        }
        for(int i = m_size; i < size; ++i)
        {
            m_array[i] = 0;
        }
    }
}

int Array::GetSize()
{
    return m_size;
}

void Array::PrintArray()
{
    if(m_size == 0){cout<<"This array is empty."<<endl; exit(0);}
    else
    {
        for(int i = 0; i < m_size; ++i)
        {
            cout<<i<<":"<<m_array[i]<<endl;
        }
    }
    cout<<endl;
}

void test()
{
    Array arr1(1,1);
    cout<<"Array arr1(2):"<<endl;
    arr1.InsertAt(1,1);
    arr1.PrintArray();
    cout<<"arr1.InsertAt(1,1):"<<endl;
    arr1.PrintArray();
    arr1.DeleteAt(1);
    cout<<"arr1.DeleteAt(1):"<<endl;
    arr1.PrintArray();

    Array arr2(arr1);
    cout<<"Array arr2(arr1):"<<endl;
    arr1.PrintArray();
    arr1.SetAt(1,1);
    cout<<"arr1.SetAt(1,1):"<<endl;
    arr1.PrintArray();

    Array arr3 = arr1;
    cout<<"Array arr3 = arr1:"<<endl;
    arr3.PrintArray();
    arr3.PushBack(2);
    cout<<"arr3.PushBack(2):"<<endl;
    arr3.PrintArray();
    cout<<"arr3.GetSize():"<<arr3.GetSize()<<endl;
    cout<<"arr3.GetAt():"<<arr3.GetAt(1)<<endl;
    cout<<"arr3[2]:"<<arr3[2]<<endl;
    system("pause");
}




















