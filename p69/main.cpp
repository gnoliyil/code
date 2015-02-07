#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int MAX = 1000000;
const int THRE = 50000;
bitset<MAX> isprime;
bitset<MAX> pt[6000];
int prime[100000], place[MAX], nprime;

void get_prime()
{
    isprime.reset();
    isprime.flip();

    for (int i = 2; i<1000; i++)
    {
        int ok = 1;
        for (int j = 2; j*j<=i; j++)
            if (i%j == 0)
            {
                ok = 0; break;
            }
        if (ok) isprime[i] = 1, prime[nprime++] = i, place[i] = nprime-1;
    }

    for (int i = 0; i<nprime; i++)
        for (int j = prime[i]; j<MAX; j+=prime[i])
            isprime[j] = 0;

    for (int i = prime[nprime-1]; i<MAX; i++)
        if (isprime[i]) prime[nprime++] = i, place[i] = nprime-1;

    for (int i = 0; i<6000; i++)
    {
        pt[i].flip();
        for (int j = prime[i]; j<MAX; j+=prime[i])
            pt[i][j] = 0;
    }

    //printf("%d\n",prime[2]);
}

int pflist[1000], npf;
bitset<MAX> defactorize(int n)
{
    npf = 0;
    for (int i = 0; prime[i]*prime[i]<=n; i++)
        if (n%prime[i] == 0)
        {
            pflist[npf++] = prime[i];
            while (n%prime[i] == 0) n/=prime[i];
        }

    if ( n != 1 ) pflist[npf++] = n;


    bitset<MAX> bs; bs.reset(); bs.flip();

    for (int i = 0; i < npf; i++)
    {
        if (pflist[i] < THRE)
        {
            //cout << pt[place[pflist[i]]] << endl;
            //getchar();
            bs &= pt[place[pflist[i]]];
        }
        else
        {
            for (int j = pflist[i]; j<MAX; j+=pflist[i])
                bs[j] = 0;
        }
    }

    //for(int i = 0; i<npf; i++) printf("%d ", pflist[i]);
    //printf("\n");

    return bs;

}

int main()
{
    get_prime();
    bitset<MAX> b; b.reset(); b[0] = b[1] = 1;
    int pi;
    double pm, maxp = 0;
    for(int i = 2; i<1000000; i++)
    {
        pm = double(i)/((defactorize(i) & b).count() - 1);
        if (pm > maxp)
            maxp = pm, pi = i;
        b[i] = 1;
        if (i%5000 == 0) cout << i << ' ' << maxp << ' ' << pi << endl;
    }

    cout << pi << endl;
    return 0;
}
