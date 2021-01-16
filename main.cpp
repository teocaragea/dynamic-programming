#include <iostream>
#include <fstream>

using namespace std;
ifstream f ("date.in");
int v[20], n;
void citire()
{
    f>>n;
    for(int i=1;i<=n;i++)
        f>>v[i];
    f.close();
}

int factorial(int x)
{
    int r=1;
    for(int i=2;i<=x;i++)
        r*=i;
    return r;
}

void actualizare(int x,int k)
{
    for(int i=k+1;i<=n;i++)
        if(v[i]>x)
            v[i]--;
}

int raspuns()
{
    int s=0;
    for(int i=1;i<=n-1;i++)
    {
        s+=(v[i]-1)*factorial(n-i);
        actualizare(v[i],i);
    }
    return s;
}

int main()
{
    citire();
    cout<<raspuns();


    return 0;
}
