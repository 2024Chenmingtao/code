#include <cstdio>
#include <vector>
#include <stack>
#include <bitset>
using namespace std;
vector<int> g[10005];
stack<int> s;
bitset<10005> instack;
int dfn[10005],low[10005];
int n,m;
void tarjan(int x,int deep)//访问节点x
{
    dfn[x]=low[x]=deep;
    s.push(x);
    instack[x]=true;
    for(auto a:g[x])
    {
        //visit tree edge
        if(dfn[a]==0)//没有被访问过
        {
            tarjan(a,deep+1);
            //更新low值
            low[x]=min(low[x],low[a]);
            /*
            判断他儿子low是否比他小,即是否是"返祖边"
            如果比自己小，就说明他的儿子或孙子访问到了他的祖先，证明有环，是一个连通分量
            如果自己小，证明不是一个联通分量，不做任何操作
            */
        }
        else if(instack[a]==true)
        {
            low[x]=min(low[x],dfn[a]);
            /**/
        }
    }
}
void build(int start,int end)
{
    g[start].push_back(end);
    return ;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int start,next;
        scanf("%d%d",&start,&next);
        build(start,next);
    }

}