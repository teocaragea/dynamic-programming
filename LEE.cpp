
#include <iostream>
#include <fstream>
using namespace std;

int a[100][100],X[10000],Y[10000],xi,yi,xf,yf,n,m,no,ant[10000],ultim,k=5,a2[100][100],s,f;
int dx[11]= {2,0,2,0,1,0,4,0,1,0};
int dy[11]= {0,2,0,2,0,1,0,4,0,1};
int d[6]={2,2,1,4,1};
void Read()
{
    ifstream f("date.in");
    f>>n;
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            f>>a[i][j];

}
void Drum(int k)
{int f=0;
    if(k>0)
    {
        Drum(ant[k]);
        cout<<X[k]<<" "<<Y[k]<<endl;
        f++;
    }
}
void Lee()
{
    int p=1,u=1,ok=0,x,y,i;
    X[p]=1;
    Y[p]=1;
    a2[1][1]=a[1][1];
    while(p<=u &&ok==0)
    {

        for(i=0; i<k;  i++)
        {x=X[p];
        y=Y[p];

            if(x+d[i]<=n)
            {
                u++;
                X[u]=x+dx[i];
                Y[u]=y;
                if(a2[x+d[i]][y]<a2[x][y]+a[x+d[i]][y])
                    a2[x+d[i]][y]=a2[x][y]+a[x+d[i]][y];

                if(X[u]==n && Y[u]==n && i==k)
                {
                    if(a2[n][n]>s)
                    {
                        s=a2[n][n];
                    }
                }
            }
            if(y+d[i]<=n)
            {
                u++;
                X[u]=x;
                Y[u]=y+d[i];
                if(a2[x][y+d[i]]<a2[x][y]+a[x][y+d[i]])
                    a2[x][y+d[i]]=a2[x][y]+a[x][y+d[i]];

                if(X[u]==n && Y[u]==n && i==k)
                {
                    if(a2[n][n]>s)
                    {
                        s=a2[n][n];
                    }
                }
            }


 p++;

        }
  }

}
int main()
{

    Read();
    Lee();
    int i,j;
    cout<<endl;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout<<a2[i][j]<<" ";

        cout<<endl;
    }

    return 0;
}
