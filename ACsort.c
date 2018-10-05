#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct
{
    char name[10];
    char problem[12][8];
    int ac;
    int time;
}test, *group;

void Score(group data, int n, int m, int p)
{
    int i, j, g, k, t;
    char *s, temp[4];
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < n; j++)
        {
            k = 0;
            s = data[i].problem[j];
            if(s[0] != '-' && s[0] != '0')
            {
                data[i].ac++;
                while(s[k] != '(' && s[k] != '\0')
                {
                    temp[k] = s[k];
                    k++;
                }
                temp[k] = '\0';
                sscanf(temp, "%d", &t);
                data[i].time += t;
                if(s[k] == '(')
                {
                    k++;
                    g = 0;
                    while(s[k] != ')')
                        temp[g++] = s[k++];
                    temp[g] = '\0';
                    sscanf(temp, "%d", &t);
                    data[i].time += (t * m);
                }
            }
        }
    }
}

void Sort(group data, int p)
{
    int i, j;
    test temp;
    for(i = 0; i < p - 1; i++)
    {
        for(j = 0; j < p - i - 1; j++)
        {
            if(data[j].ac <= data[j + 1].ac)
            {
                if(data[j].ac < data[j + 1].ac)
                {
                    temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
                else
                {
                    if(data[j].time >= data[j + 1].time)
                    {
                        if(data[j].time > data[j + 1].time)
                        {
                            temp = data[j];
                            data[j] = data[j + 1];
                            data[j + 1] = temp;
                        }
                        else
                        {
                            if(strcmp(data[j].name, data[j + 1].name) > 0)
                            {
                                temp = data[j];
                                data[j] = data[j + 1];
                                data[j + 1] = temp;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Print(group data, int p)
{
    int i;
    for(i = 0; i < p; i++)
    {
        printf("%-10s %2d %4d\n", data[i].name, data[i].ac, data[i].time);
    }
}

int main()
{
    int n, m, i = 0;
    group data;
    scanf("%d %d", &n, &m);
    data = (group) malloc (sizeof(test));
    while(scanf("%s", &data[i].name) != EOF)
    {
        int j;
        getchar();
        for(j = 0; j < n; j++)
        {
            scanf("%s", data[i].problem[j]);
            getchar();
        }
        data[i].ac = data[i].time = 0;
        data = (group) realloc(data, sizeof(test) * (i + 2));
        i++;
    }
    Score(data, n, m, i);
    Sort(data, i);
    Print(data, i);
    return 0;
}
/*
8 20
Smith -1 -16 8 0 0 120 39 0
John 116 -2 11 0 0 82 55(1) 0
Josephus 72(3) 126 10 -3 0 47 21(2) -2
Bush 0 -1 -8 0 0 0 0 0
Alice -2 67(2) 13 -1 0 133 79(1) -1
Bob 0 0 57(5) 0 0 168 -7 0
*/
