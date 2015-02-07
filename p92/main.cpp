#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int cal_sqr(int n)
{
    int sum = 0;
    while (n>0)
    {
        sum += (n%10)*(n%10);
        n/=10;
    }
    return sum;
}

int d[10000001];

int dfs(int k)
{
    if (k == 0) return 0;
    if (k == 1 || k == 89) return d[k];
    int sqr = cal_sqr(k);
    if (d[sqr])
        return d[k] = d[sqr];
    else
        return d[k] = dfs(sqr);
}

int main()
{
    memset(d, 0, sizeof(d));
    d[1] = 1;  d[89] = 89;
    const int MAXN = 10000000;
    for (int i = 0; i<MAXN; i++)
        dfs(i);

    int tot = 0;
    for (int i = 0; i<MAXN; i++)
        if (d[i] == 89) tot++;
    printf("%d\n", tot);
    return 0;
}
