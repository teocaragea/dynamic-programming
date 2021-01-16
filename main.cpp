#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int a[51][51];

int main()
{
    char s[50],s1[50];
    ifstream f ("levenstein.in");

    cin>>s;
    cin>>s1;
    for(int i=0; i<=strlen(s1); i++)
        a[0][i]=i;
    for(int i=0; i<=strlen(s); i++)
        a[i][0]=i;
    for(int i=1; i<=strlen(s); i++)
        for(int j=1; j<=strlen(s1); j++)
            if(s[i-1]==s1[j-1])
                a[i][j]=min(a[i-1][j],min(a[i][j-1],a[i-1][j-1]));
            else
                a[i][j]=min(a[i-1][j],min(a[i][j-1],a[i-1][j-1]))+1;

    for(int i=0; i<=strlen(s); i++)
    {
        for(int j=0; j<=strlen(s1); j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }




    return 0;
}
