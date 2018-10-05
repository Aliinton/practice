#include "stdio.h"
#include "stdlib.h"

typedef struct
{
    int crd;
    int num;
}Lesson;

Lesson *Class;
int ans, n, K;

void Solve(int n, int i)
{
    int k, remain;
    for(k = 0; k <= Class[i].num; k++)
    {
        remain = n - k * Class[i].crd;
        if(remain == 0)
            ans++;
        if(remain < 0)
            break;
        if(remain > 0 && (i < (K - 1)))
        {
                Solve(remain, i + 1);
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        int i;
        ans = 0;
        scanf("%d %d", &n, &K);
        Class = (Lesson *) malloc (sizeof(Lesson) * K);
        for(i = 0; i < K; i++)
        {
            scanf("%d %d", &Class[i].crd, &Class[i].num);
        }
        Solve(n, 0);
        free(Class);
        printf("%d\n", ans);
    }
    return 0;
}
