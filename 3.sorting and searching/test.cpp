#include <iostream>
#include<iomanip>
 using namespace std;
int main()
{
	cout<<setprecision(2000);
    float f = 1.0/3;
    cout<<f<<endl;
    double d1 =1.0/3.;
    cout<<d1<<endl;
    cout<<(float)d1<<endl;
    cout<<boolalpha;
    cout<<(f==d1)<<endl;
    cout<<noboolalpha;
    char ch{'a'};
    cout<<ch<<endl;
    cout<<&ch<<endl;
    #if 0
    cout<<(void )ch<<endl;
    #endif
    cout<<(int )ch<<endl;
    cout<<"\'"<<endl;
    cout<<"\xab";
}