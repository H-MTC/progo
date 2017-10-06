#ifdef SIMPLE_H
#define SIMPLE_H
int f(int x)
{
    if(x == 0)
        return 0;
    else
        return 2*f(x-1)+x*x;
}

void printDigit(int n)
{
    cout<<n;
}

void printOut(int n)
{
    if(n>=10)
        printOut(n/10);
    printDigit(n%10);
}

class IntCell
{
    public:
        explict IntCell(int initval = 0)
        : storedValue{initval} {}
        int read() const
        {return storedValue;}
        void write(int x){storedValue = x;}
    private:
        int storedValue;

};

#endif // SIMPLE_H










