#ifndef IntCell_H
#define IntCell_H

/**
*a class for simulating an integer memory cell
*/

class IntCell
{
    public:
        explicit IntCell(int initVal = 0);
        int read() const;
        void write(int x);

    private:
        int storedValue;

};
#endif // IntCell_H
