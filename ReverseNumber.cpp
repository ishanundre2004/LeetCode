#include<iostream>
using namespace std;

int main() {
	int num;
    cout<<"Enter the number : ";
    cin>>num;
    int dup=num;
	int revnum=0;
	while (num>0){
		int lastdigit=num%10;
		revnum = (revnum*10)+lastdigit;
        num=num/10;
	}
	cout<<"The reverse of the number "<< dup <<" is " << revnum;
return 0;		
}
