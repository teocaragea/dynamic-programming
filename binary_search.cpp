#include <iostream>
#include <fstream>
using namespace std;
int m,n,a[10],b[10],k,c[10];
void citire()
{   int i;
    ifstream f("date.in");
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
}
int cautare_binara(int v[100],int n,int x)
{
    int st=1, dr=n;
    while(st<=dr)
    {
        int m=(st+dr)/2;
        if(v[m]==x)
            return 1;
        else if(x>v[m])
            st=m+1;
        else if(x<v[m])
            dr=m-1;

    }
    return 0;
}

int main()
{
    citire();
    for(int i=1;i<=n;i++)
        if(cautare_binara(b,m,a[i])==1)
    {
        k++;
        c[k]=a[i];
    }
    for(int i=1;i<=k;i++)
        cout<<c[i]<<" ";

    return 0;
}
