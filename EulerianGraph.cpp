#include <iostream>
#include <fstream>
using namespace std;
int a[201][201],n,m,g[201];
int viz[201];

struct nod
{
    int info;
    nod *next;
};


void citire()
{
    ifstream f("date.in");
    f>>n;
    int i;
    int x,y;
    while(f>>x>>y)
    {
        a[x][y]=a[y][x]=1;
        g[x]++;
        g[y]++;
        m++;
    }
}
void lista(nod *&p, nod *&u, int x)
{
    nod *q;
    int i;
    q=new nod;
    q->info=x;
    p=u=q;
    do
    {
        x=u->info;
        for(i=1; i<=n; i++)
            if(a[x][i]==1)
            {
                q=new nod;
                q->info=i;
                u->next=q;
                u=q;
                g[i]--;
                g[x]--;
                m--;
                a[i][x]=0;///!!!!
                a[x][i]=0;///!!!!
                break;
            }
    }
    while(p->info!=u->info);
    u->next=NULL;
}
void Afi(nod *q)
{
    while(q!=NULL)
    {
        cout<<q->info<<" ";
        q=q->next;
    }
}
void Eulerian(int x)
{
    nod *p,*u, *p1, *u1, *q;
    lista(p,u,x);
    q=p;
    while(m>0)
    {
        if(g[q->info]>0)
        {
            lista(p1,u1,q->info);
            u1->next=q->next;
            q->next=p1->next;
        }
        else q=q->next;
    }




    Afi(p);
}

void DF(int x)
{
    viz[x]=1;
    int i;
    for(i=1;i<=n;i++)
        if(a[x][i]==1&&viz[i]==0)
            DF(i);
}

int main()
{
    citire();
    int i,ok=0;
    for(i=1;i<=n&&ok==0;i++)
        if(g[i]!=0)
    {
        DF(i);
        ok=1;
    }
    ok=1;
    for(i=1;i<=n&&ok==1;i++)
        if(viz[i]==0&&g[i]!=0||g[i]%2==1)
            ok=0;
    //cout<<ok<<endl;
    if(ok==1)
        Eulerian(1);
    else
        cout<<"Nu este eulerian";
    return 0;
}
