#include<string>

template <typename Object>
class MemoryCell
{
    public:
        explicit MemoryCell(const Object & initVal = Object{}) : storedValue{initVal}{}
        const Object & read() const {return storedValue;}
        void write(const Object &x){storedValue = x;}
    private:
        Object storedValue;
};

void test()
{
    MemoryCell<int> ml;
    MemoryCell<string> ms("Hello ");

    ml.write(37);
    ms.write(ms.read()+"World!");
    cout<<ml.read()<<endl<<ms.read()<<endl;
}
