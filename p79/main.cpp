#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int g[300][300];
int ind[3000];
queue<int> q;
vector<int> topo;

int add(int a, int b)
{
    if (!g[a][b])
        g[a][b] = 1, ind[b]++;
}

void toposort()
{
    for (int i = 0; i<10; i++)
        if (ind[i] == 0) q.push(i);

    while (!q.empty())
    {
        int t = q.front();
        topo.push_back(t); printf("%d  ", t);
        q.pop();
        for (int i = 0; i<10; i++)
        {
            if (g[t][i])
            {
                g[t][i] = 0, ind[i]--;
                if (!ind[i])
                    q.push(i);
            }
        }
    }
}

int main()
{
    string c;
    while (cin >> c)
    {
        if (c.size() < 3) break;
        add(c[0]-'0', c[1]-'0');
        add(c[1]-'0', c[2]-'0');
    }
    printf("ok\n");
    toposort();

    for (int i = 0; i<topo.size(); i++)
        printf("%d ", topo[i]);
    printf("\n");
    return 0;
}
