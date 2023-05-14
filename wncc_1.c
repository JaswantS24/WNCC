#include <stdio.h>
int n;
int m;
void ifeligible(int a[][7], int b[][7], int c[][m]);
void comentor(int a[][7], int c[][m], int b[][7]);
void role(int a[][7], int c[][m], int b[][7], int d[m]);
int filling(int a[][7], int c[][m], int b[][7], int d[m]);
int main(void)
{
    int n, m, i, x;
    int a[n][7];
    int b[m][7];
    int c[n][m];
    int d[] = {0};
    int p;
    printf("enter no of participants: ");
    scanf("%d", &n);
    printf("enter the number of projects:");
    scanf("%d", &m);
    for (i = 0; i < n; i++)
    {
        printf("enter roll number: \n");
        scanf("%d", &a[i][0]);
        printf("enter html skill: \n");
        scanf("%d", &a[i][1]);
        printf("enter python skill:\n ");
        scanf("%d", &a[i][2]);
        printf("enter DSA skill: \n");
        scanf("%d", &a[i][3]);
        printf("enter JAVA skill: \n");
        scanf("%d", &a[i][4]);
        printf("enter SQL skill: \n");
        scanf("%d", &a[i][5]);
    }
    printf("\n\n");
    for (i = 0; i < m; i++)
    {
        printf("enter project number: \n");
        scanf("%d", &b[i][0]);
        printf("enter reqd role in html: \n");
        scanf("%d", &b[i][1]);
        printf("enter reqd role in PYTHON: \n");
        scanf("%d", &b[i][2]);
        printf("enter reqd role in DSA: \n");
        scanf("%d", &b[i][3]);
        printf("enter reqd role in JAVA: \n");
        scanf("%d", &b[i][4]);
        printf("enter reqd role in SQL: \n");
        scanf("%d", &b[i][5]);
    }
    ifeligible(a, b, c);
    comentor(a, c, b);
    role(a, c, b, d);
    p = filling(a, c, b, d);
    printf("the number of projects completed is: %d", p);
}
void ifeligible(int a[][7], int b[][7], int c[][m])
{
    /// given a project who are eligible
    int i, j, q, x;
    for (q = 0; q < m; q++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < 6; j++)
            {
                x = b[q][j];
                if (x != 0)
                {
                    if (a[i][j] >= x)
                    {
                        c[i][q] = j;
                    }
                }
            }
        }
    }
}
void comentor(int a[][7], int c[][m], int b[][7])
{
    int i, j, y, p;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (c[i][j] == 0)
            {
                for (y = 1; y <= 5; y++)
                {
                    if (a[i][y] + 1 == b[j][y])
                    {
                        for (p = 0; p < n; p++)
                        {
                            if (c[p][j] != 0)
                                if (a[p][y] > b[j][y])
                                {
                                    c[i][j] = y * 10;
                                }
                        }
                    }
                }
            }
        }
    }
}
void role(int a[][7], int c[][m], int b[][7], int d[m])
{
    int count, i, j;
    for (i = 0; i < m; i++)
    {
        count = 0;
        for (j = 1; j < 6; j++)
        {
            if (b[i][j] != 0)
            {
                count++;
                d[i] = count;
            }
        }
    }
}
int filling(int a[][7], int c[][m], int b[][7], int d[m])
{
    int i, j, k, filled, completed = 0, l, z;
    for (i = 0; i < m; i++)
    {
        filled = 0;
        for (j = 1; j < 6; j++)
        {
            if (b[i][j] != 0)
            {
                for (k = 0; k < n; k++)
                {
                    if (a[k][j] > b[i][j] && a[k][6] == 0)
                    {
                        filled = 10 * i + 1;
                        a[k][6] = 10 * i + j;
                        break;
                    }
                }
            }
        }
        b[i][6] = filled;
        if (b[i][6] % 10 == d[i])
        {
            completed++;
        }
    }
    for (i = 0; i < m; i++)
    {
        if (b[i][6] != d[i])
        {
            for (j = 1; j < 6; j++)
            {
                for (z = 0; z < n; z++)
                {
                    if ((a[z][6]) % 10 == j && a[z][6] / 10 == i)
                    {
                        continue;
                    }
                }
                if (b[i][j] != 0)
                {
                    for (k = 0; k < n; k++)
                    {
                        if (a[k][j] + 1 == b[i][j] && a[k][6] == 0)
                        {
                            for (l = 0; l < n; l++)
                            {
                                if (a[l][6] / 10 == i)
                                {
                                    if (a[l][j] >= b[i][j])
                                    {
                                        b[i][6] += 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (b[i][6] % 10 == d[i])
        {
            completed++;
        }
    }
    return completed;
}
