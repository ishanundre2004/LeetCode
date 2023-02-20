#include <iostream>
using namespace std;

int main()
{
    int num;
    cout<<"Enter the number : ";
    cin >> num;
    int dup = num;
    int arm = 0;
    while (num > 0)
    {
        int x = num % 10;
        arm += (x * x * x);
        num /= 10;
    }
    if (arm == dup)
    {
        cout << "The number " << dup << " is an Armstrong Number"<< endl;
    }
    else
    {
        cout << "The number " << dup << " is not an Armstrong Number"<< endl;
    }
}
