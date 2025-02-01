#include <cstdio>

struct edge
{
    edge* next=nullptr;
    int to_id;
};

edge* head[100005];
edge* e[100005];
int elong=0,maxvisit[100005];
bool visit[100005];

inline int max(int x,int y)
{
    return (x>y)?x:y;
}

int dfs(int next)//求从当前节点出发能到达最大的点
{
    maxvisit[next]=next;
    visit[next]=true;
    for(edge* it=head[next];it!=nullptr;it=it->next)
    {
        if(visit[it->to_id]==false)
        {
            maxvisit[next]=max(maxvisit[next],dfs(it->to_id));
        }
    }
    return maxvisit[next];
}

void build(int from,int to)
{
    elong++;
    e[elong]->next=head[from];
    e[elong]->to_id=to;
    head[from]->next=e[elong];
    return;
}

int main()
{

}