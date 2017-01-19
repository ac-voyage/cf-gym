/* Codeforces Hello 2015 (Div.2). Problem F-TROY Query, by Abreto <m@abreto.net>. (GNU C++11) */
#include <cstdio>
#include <map>

using namespace std;

#define MAXN    100001

typedef long long int ll;

int n = 0, up = 0;
int x[MAXN] = {0}, y[MAXN] = {0};
int nuniquexs = 0, nuniqueys = 0;   /* positive for rows, negative for cols. */
map<ll,int> real2virtual;
bool same[MAXN] = {0};
map<int,int> par;

#define nt(rcxy) (((rcxy)>0)?(up-(rcxy)):(-(rcxy)-up))
/* initialize disjoint sets [-up..up] */
void init_disjointsets(void)
{
    int i = 0;
    for(i = -up;i <= up;++i)
        par[i] = i;
}
int findr(int i)
{
    return (i == par[i])?(i):(par[i] = findr(par[i]));
}
int uni(int i, int j)
{
    int ri = findr(i);
    int rj = findr(j);
    if( ri == rj )  return 1;
    par[rj] = ri;
    if( (ri == findr(nt(i))) || (rj == findr(nt(j))) )    return 0;
    return 1;
}

int main(void)
{
    int i = 0;
    ll xi = 0, yi = 0;
    int axy = 0, bxy = 0;
    bool failed = 0;
    scanf("%d", &n);
    up = 2*n+1;
    for(i = 0;i < n;++i)
    {
        scanf("%lld %lld %d %d", &xi, &yi, &axy, &bxy);
        if( real2virtual.count(xi) )
            x[i] = real2virtual[xi];
        else
            x[i] = (real2virtual[xi] = ++nuniquexs);
        if( real2virtual.count(-yi) )
            y[i] = real2virtual[-yi];
        else
            y[i] = (real2virtual[-yi] = --nuniqueys);
        same[i] = (axy == bxy);
    }
    init_disjointsets();
    for(i = 0;i < n;++i)
        if( failed )
            printf("No\n");
        else
        {
            int ok = 0;
            if( same[i] )
                ok = uni(x[i], y[i]) && uni(nt(x[i]), nt(y[i]));
            else
                ok = uni(x[i], nt(y[i])) && uni(nt(x[i]), y[i]);
            printf("%s\n", ok?"Yes":((failed=1), "No"));
        }
    return 0;
}

