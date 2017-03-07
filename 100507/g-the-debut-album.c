/* 2014-2015 ACM-ICPC, NEERC, Eastern Subregional Contest. Problem G - The Debut Album, by Abreto <m@abreto.net>. */
#include <stdio.h>

#define TOMOD   1000000007
#define MIN(a,b)    (((a)<(b))?(a):(b))

typedef long long int ll;


int main(void)
{
    int i = 0, j = 0;
    int n = 0;
    int k[2] = {0}; /* 0 for a, 1 for b. */
    ll dp[2][314] = {0};
    ll ans = 0;
    
    scanf("%d %d %d", &n, k, k+1);

    dp[0][1] = dp[1][1] = 1;
    for(i = 2;i <= n;++i)
    {
        int song = 0, x = 0;
        ll dp1[2] = {0,0};
        for(song = 0;song < 2;++song)
            for(x = 1;x <= MIN(k[1-song], i-1);++x)
                dp1[song] = ( dp1[song] + dp[1-song][x] )%TOMOD;
        for(song = 0;song < 2;++song)
            for(x = MIN(k[song], i);x > 1;--x)
                dp[song][x] = dp[song][x-1];
        dp[0][1] = dp1[0];
        dp[1][1] = dp1[1];
    }

    for(i = 0;i < 2;++i)
        for(j = 1;j <= MIN(k[i], n);++j)
            ans = (ans + dp[i][j]) % TOMOD;
    printf("%lld\n", ans);
    return 0;
}
