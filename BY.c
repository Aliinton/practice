#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef enum{F, T} mark;

int main()
{
    char stack[5], N;
    int top = 0, i, j, len, ans = 0;
    mark used[10];
    for(i = 0; i < 10; i++)
        used[i] = F;
    while(stack[top] = getchar(), stack[top++] != '\n');
    len = --top;
    stack[len - 1]++;
    i = 0;
    used[stack[i++] - '0'] = T;
    while(i < len)
    {
        N = stack[i];
        if(used[N - '0'])
        {
             do
                N = N + 1;
             while(N <= '9' && used[N - '0']);
             if(N > '9')
             {
                 for(j = i; j < len; j++)
                    stack[j] = '0';
                 i--;
                 while(stack[i] == '9')
                 {
                     used[stack[i] - '0'] = F;
                     stack[i--] = '0';
                 }
                 used[stack[i]++ - '0'] = F;
                 continue;
             }
             else
                 stack[i] = N;
        }
        used[stack[i] - '0'] = T;
        i++;
    }
    for(i = 0; i < len; i++)
    {
        ans += (stack[i] - '0') * pow(10, len - i - 1);
    }
    printf("%d\n", ans);
    return 0;
}
