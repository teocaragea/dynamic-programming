#include <iostream>

using namespace std;

int st[20], m, n;
int ns;

void afi()
{
    for(int i=1; i<=m; i++)
        cout<<st[i]<<" ";
    cout<<endl;
    ns++;
}

int valid(int k)
{
    for(int i=1; i<k; i++)
        if(st[i]!=st[k])
            return 0;
    return 1;
}
void bkt(int k)
{
    for(int i=1; i<=n; i++)
    {
        st[k]=i;
        if(valid(k)==1)
            if(k==m)
                afi();
            else
                bkt(k+1);
    }
}

int main()
{
    n=3;
    m=2;
    bkt(1);
    cout<<ns<<" solutii";
    return 0;
}
