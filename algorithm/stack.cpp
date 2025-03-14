template <class T, long long MAXSIZE>
class stack
{
private:
    T a[MAXSIZE];
    long long count;
public:
    stack()
    {
        count = 0;
    }
    void pop()
    {
        if (count > 0)
        {
            count--;
        }
        return;
    }
    T top()
    {
        return a[count];
    }
    void push(T input)
    {
        count++;
        a[count] = input;
    }
    bool empty()
    {
        return count == 0;
    }
    bool not_empty()
    {
        return count > 0;
    }
};