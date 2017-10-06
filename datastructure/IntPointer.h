#ifndef IntPointer_H
#define IntPointer_H
/**
class with pointer member to implements Big-Five
*/

class IntPointer
{
    public:
        explicit IntPointer(int initVal = 0);
        IntPointer(const IntPointer&);
        IntPointer(const IntPointer&&);
        IntPointer & operator= (const IntPointer & rhs);
        IntPointer & operator= (IntPointer && rhs);
        ~IntPointer();
        int read() const;
        void write(int x);
};
#endif // InterPointer_H
