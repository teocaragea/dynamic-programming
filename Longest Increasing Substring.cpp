#include <iostream>
#include <fstream>
using namespace std;
int n,l[100],v[100],ant[100];
void citire()
{
    ifstream f("date.in");
    f>>n;
    for(int i=1; i<=n; i++)
        f>>v[i];
}
void subsir()
{
    for(int i=2; i<=n; i++)
        for(int j=1; j<i; j++)
            if(v[i]>v[j] && l[j]+1>l[i])
            {
                l[i]=l[j]+1;
                ant[i]=j;
            }

}
void drum(int j)
{
    if(j!=0)
    {
        drum(ant[j]);
        cout<<v[j]<<" ";
    }
}
void afisare()
{
    for(int i=1; i<=n; i++)
        cout<<l[i]<<" ";
}
int main()
{

    citire();
    subsir();
    drum(10);

    return 0;
}
