#include <iostream>
#include <string>
using namespace std;
long long cnt[26];
bool flag[26];
void read()
{
    string line;
    getline(cin, line, '\n');
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] >= 'A' && line[i] <= 'Z')
        {
            cnt[line[i] - 'A']++;
            flag[line[i] - 'A'] = true;
        }
    }
}
int main()
{
    read(), read(), read(), read();
    while (true)
    {
        bool is_print = false;
        int MAX = -1;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > 0)
            {
                is_print = true;
                if (cnt[i] > MAX)
                {
                    MAX = cnt[i];
                }
            }
        }
        if (is_print)
        {
            for (int i = 0; i < 26; i++)
            {
                if (cnt[i] == MAX)
                {
                    printf("* ");
                    cnt[i]--;
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c ", 'A' + i);
    }
}