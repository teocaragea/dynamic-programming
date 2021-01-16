#include <iostream>
#include <fstream>

using namespace std;
/**
determina lanturile de cost minim
de la nodul r (radacina)
la celelalte noduri
n<50, m<100, cost_maxim=70
=>pinf=70*100
*/
int a[50][50], n, pinf=1000;
int t[50], viz[50], d[50];
int r;

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

void optimizeaza_graf(int vf)
{
    for(int i=1; i<=n; i++)
        if(viz[i]==0)
            if(d[i]>d[vf]+a[vf][i])
            {
                d[i]=d[vf]+a[vf][i];
                t[i]=vf;
            }
}
int optim()
{
    int vf;
    int minim=pinf;
    for(int i=1; i<=n; i++)
        if(viz[i]==0&&d[i]<minim&&i!=r)
        {
            minim=d[i];
            vf=i;
        }
    return vf;
}
void DJ()
{
    int vf;
    viz[r]=1;
    for(int i=1; i<=n; i++)
    {
        d[i]=a[r][i];
        if(d[i]!=pinf&&i!=r)
            t[i]=r;

    }
    for(int i=1; i<=n-1; i++)
    {
        vf=optim();
        viz[vf]=1;
        optimizeaza_graf(vf);
    }
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

void drum(int x)
{
    if(t[x]!=0)
        drum(t[x]);
    cerr<<x<<" ";
}

void afi(int v[50], int n)
{
    for(int i=1; i<=n; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void costuri_minime()
{
    for(int i=1; i<=n; i++)
        if(d[i]!=pinf&&i!=r)
            cerr<<"lantul de la "<<r<<" la "<<i<< " are costul "<<d[i]<<endl;
        else
            cerr<<"nu exista"<<endl;
}
int main()
{
    init();
    afisare();
    cout<<"r=";
    cin>>r;
    DJ();
    afi(d,n);
    cerr<<endl;
    afi(t,n);
    costuri_minime();
    int nod;
    cin>>nod;
    drum(nod);

    return 0;
}
