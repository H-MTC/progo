#include<iostream>
#include<cstring>
#include<cstdlib>
#pragma warning(disable : 4996)
using namespace std;

class String
{
    public:
        String(const char* str = NULL);
        String(const String &str);
        String& operator=(const String &str);
        ~String();

        String operator+(const String &str) const;
        String& operator+=(const String &str);
        bool operator==(const String &str);
        char& operator[](unsigned int index);

        friend ostream& operator<<(ostream& os, String& str);
        friend istream& operator>>(ostream& os, String& str);
        unsigned short size();
        const char* c_str() const;
    private:
        void Free();
    public:
        char* m_string;
};

String::String(const char* str)
{
    if(!str){m_string = NULL;}
    else{m_string = new char[strlen(str) + 1]; strcpy(m_string, str);}
}

String::String(const String &str)
{
    if(!str.m_string){m_string = NULL;}
    else{m_string = new char[strlen(str.m_string) + 1]; strcpy(m_string, str.m_string);}
}


String& String::operator=(const String &str)
{
    if(this != &str)
    {
        delete[] m_string;
        if(!str.m_string){m_string = NULL;}
        else
        {
            m_string = new char[strlen(str.m_string) + 1];
            strcpy(m_string, str.m_string);
        }
    }
    return *this;
}

String::~String()
{
    Free();
}

void String::Free()
{
    if(m_string){delete[] m_string; m_string = NULL;}
}

String String::operator+(const String &str) const
{
    String newString;
    if(!str.m_string){newString = *this;}
    else if(!m_string){newString = str;}
    else
    {
        newString.m_string = new char[strlen(m_string) + strlen(str.m_string) + 1];
        strcpy(newString.m_string, m_string);
        strcat(newString.m_string, str.m_string);
    }
    return newString;
}

String& String::operator+=(const String &str)
{
    String newString;
    if(!str.m_string){newString = *this;}
    else if(!m_string){newString = str;}
    else
    {
        newString.m_string = new char[strlen(m_string) + strlen(str.m_string) + 1];
        strcpy(newString.m_string, m_string);
        strcat(newString.m_string, str.m_string);
    }
    Free();
    m_string = new char[strlen(newString.m_string) + 1];
    strcpy(m_string, newString.m_string);

    return *this;
}

bool String::operator==(const String &str)
{
    if(strlen(m_string) != strlen(str.m_string)){return false;}
    return strcmp(m_string, str.m_string)?false:true;
}

char& String::operator[](unsigned int index)
{
    if(index >= 0 && index <= strlen(m_string)){return m_string[index];}
    else{cout<<"Invalid Index:"<<index<<endl; exit(0);}
}

ostream& operator<<(ostream& os, String& str)
{
    os << str.m_string;
    return os;
}

istream& operator>>(istream& is, String& str)
{
    char tmp[1024];
    is >> tmp;
    str.m_string = new char[strlen(tmp) + 1];
    strcpy(str.m_string, tmp);

    return is;
}

unsigned short String::size()
{
    return strlen(m_string);
}

const char* String::c_str() const
{
    return m_string;
}

void test()
{
    String s;
    cin >> s;
    cout << s << ":" << s.size() << endl;
    char a[] = "Hello", b[] = "world";
    String s1(a), s2(b);
    cout << s1 << "+" << s2 << "=" << (s1 + s2).m_string << endl;
    String s3 = s1 + s2;
    if(s1 == s3){cout<<"First: s1 == s3"<<endl;}
    s1+=s2;
    if(s1 == s3){cout<<"Second: s1 == s3"<<endl;}
    system("pause");

}
















