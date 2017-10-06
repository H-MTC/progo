#include<iostream>
#include "IntCell.h"
#include<vector>
using namespace std;
// great case: count the bank account
// in example 5-19
int main()
{
    vector<int> num(100);
    for( int i = 0; i < num.size(); ++i)
    {
        num[i] = i*i;
        cout<<i<<":"<<num[i]<<endl;
    }

    return 0;
}
