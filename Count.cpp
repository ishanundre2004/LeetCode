#include <iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the number : ";
    cin>>num;
    int dup=num;
    int count = 0;
    while (num > 0)
    {
        int lastdigit = num % 10;
        count += 1;
        num = num / 10;
    }
    cout << "The number of digits in "<< dup <<" are "<< count;
    return 0;
}