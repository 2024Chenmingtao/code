// 最小值优先
template <class T, long long MAXN>
class priority_queue
{
private:
    T tree[MAXN]; // heap
    long long queue_long = 0;
    void swap(T &a, T &b)
    {
        T c = a;
        a = b;
        b = c;
        return;
    }
    void down(int x) // 对节点编号为x的值进行下沉操作
    {
        int min_index = x;
        int left = (x << 1), right = (x << 1) + 1;
        if (left <= queue_long && tree[min_index] > tree[left])
        {
            min_index = left;
        }
        if (right <= queue_long && tree[min_index] > tree[right])
        {
            min_index = right;
        }
        if (min_index != x) // 需要下沉
        {
            swap(tree[x], tree[min_index]);
            down(min_index);
        }
        return;
    }
    // 上浮
    void up(int x)
    {
        int father = x >> 1;
        if (father) // father>=1 不是根节点
        {
            if (tree[x] < tree[father])
            {
                swap(tree[x], tree[father]);
            }
        }
        return;
    }

public:
    // 弹出堆顶
    void pop()
    {
        if (queue_long > 0) // 队列非空
        {
            tree[1] = tree[queue_long];
            queue_long--;
            down(1);
        }
    }
    // 入队
    void push(T x)
    {
        queue_long++;
        tree[queue_long] = x;
        up(queue_long);
        return;
    }
    // 是否空
    bool empty()
    {
        return queue_long == 0;
    }
    bool not_empty()
    {
        return queue_long > 0;
    }
    T front()
    {
        return tree[1];
    }
    T top()
    {
        return tree[1];
    }
    long long size()
    {
        return queue_long;
    }
};