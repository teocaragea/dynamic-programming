#include <iostream>
#include <fstream>

using namespace std;
/**
determina lantul de cost minim
pt oricare 2 noduri.
n<50, m<100, cost_maxim=70
=>pinf=70*100
*/
int a[50][50], n, pinf=1000;

void init()
{
    ifstream f ("date.in");
    f>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i!=j)
                a[i][j]=pinf;
    int x,y,c;
    while(f>>x>>y>>c)
        a[x][y]=a[y][x]=c;
}
void RF()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
    }
}

void costuri_minime()
{
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(a[i][j]==pinf)
                cerr<<"NU EXISTA LANT DE LA "<<i<< " LA "<<j<<endl;
            else
                cerr<<a[i][j]<<" " <<i<< " " <<j<<endl;
}
void afisare()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cerr<<a[i][j]<<" ";
        cerr<<endl;
    }
}

void drum(int x, int y)
{
    int ok=0;
    for(int k=1; k<=n&&ok==0; k++)
    {
        if(x!=k&&y!=k)
            if(a[x][y]==a[k][y]+a[x][k])
            {
                ok=1;
                drum(x,k);
                drum(k,y);
            }
    }
    if(ok==0)
        cerr<<y<< " ";
}

int main()
{
    init();
    ///afisare();
    RF();
    cerr<<endl;
    ///afisare();
    costuri_minime();
    ///------lant de la x la y -----
    int x, y;
    cout<<"x=";
    cin>>x;
    cout<<"y=";
    cin>>y;
    if(a[x][y]==pinf)
        cerr<<"nu avem lant de la x la y";
    else
    {
        cerr<<"lantul de la x la y are costul "<<a[x][y]<<endl;
        cerr<<"o solutie este "<< endl;
        cerr<<x<<" ";
        drum(x,y);
    }

    return 0;
}
