#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//s<=1000

int s, v[1001];
int a[101],n;

int prim(int x)
{
    if(x==2)
        return 1;
    for(int i=3; i<=sqrt(x); i=i+2)
        if(x%i==0)
            return 0;
    return 1;
}

void citire()
{   int i;
    ifstream f("date.in");
    f>>s;
    a[1]=2;
    n=1;
    for(i=3; i<=s; i=i+2)
        if(prim(i)==1)
        {
            n++;
            a[n]=i;
        }
   for(i=1;i<=n;i++)
         cout<<a[i]<<" ";
         cout<<endl;
}

int main()
{
    citire();
    int x,i,j;
    for(int i=1; i<=n; i++)
    {
        x=a[i];
        for(j=1; j<=s; j++)
            if(v[j]!=0 && v[j]!=i && v[j+x]==0)
                v[j+x]=i;
        if(v[x]==0)
            v[x]=i;

    }

    for(i=1; i<=s; i++)
        cout<<v[i]<<" ";
    cout<<endl;
    int  p=v[s];
    while(s!=0)
    {
        cout<<a[p]<<" ";
        s=s-a[p];
        p=v[s];

    }

    return 0;
}
