#include <iostream>
#include <fstream>
using namespace std;

int a[51][51];
int b[51][51];

int main()
{
    /*int n;


    ifstream f ("date.in");
      f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            f>>a[i][j];


    for(int j=1; j<=n; j++)
        b[n][j]=a[n][j];

    for(int i=n-1;i>=1;i--)
    {
     for(int j=n-1;j>=1;j--)
        b[i][j]=a[i][j]+max(b[i+1][j],b[i+1][j-1]);
        n--;
    }
           // b[j][i]=max(a[j-1][i],a[j-1][i-1])+a[j][i];
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=i; j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    */
    int n;
    ifstream f ("date.in");
    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            f>>a[i][j];

    for(int j=1; j<=n; j++)
        b[n][j]=a[n][j];
    int x;
    for(int i=n-1; i>=1; i--)
        for(int j=n; j>=1; j--)
        {
            x=a[i][j]+max(max(b[i+1][j],b[i+1][j-1]),b[i+1][j+1]);
            if(x>b[i][j])
                b[i][j]=x;
        }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }



    return 0;
}
