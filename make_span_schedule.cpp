#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m,d[N],head[N],cnt,indeg[N],ans;
struct node
{
    int to,next;
}edge[N];
void add(int from,int to)
{
    edge[++cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt;
    indeg[to]++;
}
queue<int> q;
void topsort()
{
    for(int i=1;i<=n;i++)
        if(!indeg[i])
            q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ans=max(ans,d[u]);
        for(int i=head[u];i;i=edge[i].next)
        {
            int to=edge[i].to;
            d[to]=max(d[to],d[u]+1);
            indeg[to]--;
            if(!indeg[to])
                q.push(to);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    topsort();
    cout<<ans<<endl;
    return 0;
}
