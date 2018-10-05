#include "stdio.h"
#include "stdlib.h"

int main()
{
    int a, b, f, k, i, remain, ans = 0, *dis;
    scanf("%d %d %d %d", &a, &b, &f, &k);
    dis = (int *) malloc (sizeof(int) * (1 + k));
    dis[0] = f;
    for(i = 1; i < k; i++)
    {
        if(i%2)
            dis[i] = 2 * (a - f);
        else
            dis[i] = 2 * f;
    }
    if(k%2)
        dis[k] = a - f;
    else
        dis[k] = f;
    remain = b;
    for(i = 0; i <= k; i++)
    {
        if(remain < dis[i])
        {
            ans = -1;
            break;
        }
        else if((i < k) && (remain < (dis[i] + dis[i + 1])))
        {
            ans++;
            remain = b;
        }
        else if(i < k)
            remain -= dis[i];
    }
    printf("%d\n", ans);
    return 0;
}
