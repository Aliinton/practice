#include "stdio.h"
#include "stdlib.h"

int ans, N, *Chess;

void Queen(int hang)
{
    int i, j, flag;
    for(j = 0; j < N; j++)
    {
        flag = 1;
        for(i = 0; i < hang; i++)
        {
            if((Chess[i] == j) || (abs(i - hang) == abs(Chess[i] - j)))
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            if(hang < N - 1)
            {
                Chess[hang] = j;
                Queen(hang + 1);
            }
            else
                ans++;
        }
    }
}

int main()
{
    int i, a[10];
    for(N = 1; N <= 10; N++)
    {
        ans = 0;
        Chess = (int *) malloc(sizeof(int) * N);
        Queen(0);
        free(Chess);
        a[N - 1] = ans;
    }
    while(scanf("%d", &N), N)
    {
        printf("%d\n", a[N - 1]);
    }
    return 0;
}
