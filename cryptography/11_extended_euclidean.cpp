#include<iostream>
using namespace std;
void xEuclidean(int a, int b,int &gcd,int &x_value, int &y_value)
{
    int old_x = 1, x = 0;
    int old_y = 0, y = 1;
    int q, r;
    while (b!=0){
        q = a / b;//quotient 
        r = a % b;//remainder
        int temp = x;
        x = old_x - q * x;
        old_x = temp;
        temp = y;
        y = old_y - q * y;
        old_y = temp;
        a = b;
        b = r;
    }
    x_value=old_x;
    y_value=old_y;
    gcd=a;
}
int main(){
	int a,b,x,y,gcd;
	cout<<"\nEnter the values of 'a' and 'b'for ax+by=gcd(a,b) : ";
	cin>>a>>b;
	xEuclidean(a,b,gcd,x,y);
	cout<<"\n GCD= "<<gcd<<"\t x= "<<x<<"\t and  y ="<<y<<endl;
    cout<<x<<" is multiplicative inverse of "<<a;
    cout<<"Name : Suraj Kumal"<<endl<<"Roll No : 32"<<endl;
	return 0;
}