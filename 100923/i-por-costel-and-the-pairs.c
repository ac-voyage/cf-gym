/* 2015 ACM National Contest Romania - Round 1. Problem I, by Abreto <m@abreto.net>. */
#include <stdio.h>

#define INPUT_FILE  "perechi3.in"
#define OUTPUT_FILE  "perechi3.out"

typedef long long int ll;

void process()
{
    ll i = 0;
    ll N = 0;
    ll ans = 0;

    scanf("%lld", &N);
    for(i = 1;i <= N;++i)
    {
        ll n = N/i;
        ll up = N/n;
        ans += (up-i+1)*n;
        i = up;
    }
    printf("%lld\n", ans);
}

int main(void)
{
    int T = 0;
    freopen(INPUT_FILE, "r", stdin);
    freopen(OUTPUT_FILE, "w+", stdout);
    scanf("%d", &T);
    while(T--)
        process();
    return 0;
}
