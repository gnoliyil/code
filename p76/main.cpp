#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long f[1000];
int c[] = {1,2,5,10,20,50,100,200};
int main()
{
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i<8; i++)
        for (int j = c[i]; j<=200; j++)
            f[j] += f[j-c[i]];

    cout << f[2] << " " << f[200] << endl;
    return 0;
}
