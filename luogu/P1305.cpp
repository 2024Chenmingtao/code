/*
思路:
一个tree数组存树
一个int数组标记节点标号 代替map
*/
#include <cstdio>
struct TREE
{
    char me;
    int left,right;
};
TREE tree[30];

int map[26];
int n;

void dfs(TREE x)
{
    printf("%c",x.me);
    if(x.left!='*')
    {
        dfs(tree[x.left-'a']);
    }
    if(x.right!='*')
    {
        dfs(tree[x.right-'a']);
    }
    return;
}
int main()
{
    TREE* root;
    //read
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char a,b,c;
        scanf(" %c %c %c",&a,&b,&c);
        tree[a-'a'].me=a;
        tree[a-'a'].left=b;
        tree[a-'a'].right=c;
        if(i==1)
        {
            root=&tree[a-'a'];
        }
    }
    dfs(*root);
    return 0;
}