// This is the learning class for c++ data structure and algorithm series
// created at 2017-10-04
#include<iostream>
using namespace std;
class IntCell
{
    private:
        int storedValue;

    public:
        IntCell()
        {
            storedValue = 0;
        }

        IntCell(int init)
        {
            storedValue = init;
        }

        int read()
        {
            return storedValue;
        }

        void write(int input)
        {
            storedValue = input;
        }

};

// public class definition

class PubClass
{
    public:
        int value;

        void set(int val)
        {
            value = val;
        }

        int get()
        {
            return value;
        }

};


// private class definition

class PriClass
{
    int value;
    public:
        void set(int val);
        void show(char*);
};

void PriClass::set(int val){value = val;}
void PriClass::show(char *name){cout<<name<<":"<<value<<endl;} // only this method has the access to private data field

// struct class whose access to member is public by default, which differs from ordinary class

struct StrClass
{
    void set(int val){value = val;}
    void show(char *name){cout<<name<<":"<<value<<endl;}
    private:
        int value;
};


// constructor for copying

class CoConClass
{
    private:
        int value;
        double score;
    public:
        CoConClass(int val, double scr): value(val), score(scr)
        {
            cout<<"Common Constructor called!\n"<<endl;
        }
        CoConClass(const CoConClass& item): value(item.value), score(item.score)
        {
            cout<<"Copying Constructor Called!\n"<<endl;
        }

};

// destructor function
class Ratio
{
    int value;
    public:
        Ratio(){cout<<"Constructor Called!\n"<<endl;}
        Ratio(Ratio &rat)
        {
            cout<<"Copying Constructor Called!\n"<<endl;
            value = rat.value;
            cout<<"Value Modified:"<<value<<endl;
        }
        ~Ratio(){cout<<"Destructor Called!\n"<<endl;} //despite the constructor type

};

//effect of local field: vars defined in inner block with the same name will override the outer var

// concepts about local var and global var and static var are same with C

// public static data member implements data share

// PubStaticFieldClass:: num, access static field through Class name

//In Private Static Field Class, static field can only be accessed by method

// notice the difference between statement of property(inside class) and definition of property(outside the class)

// the usage of static function member is same with data member.

// friend function

class FriClass
{
    int value;
    public:
        FriClass(int val){value = val;}
        friend int friFun(FriClass item); // this function does not belong to any class
};

int friFun(FriClass item)
{
    return item.value; // because this function does not belong to FriClass, the data field can not be accessed directly.
}

// and friend function can be shared for multiple classes, to connect them.

// & ref can not change the referenced data

// const member function can be called by const defined object

// #define PI 3.141592654, #define OP M*N*S, without parameters

// #define min(a, b) ((a)<(b)? (a):(b))

// conditional compile: #ifdef {} #endif {}

//








