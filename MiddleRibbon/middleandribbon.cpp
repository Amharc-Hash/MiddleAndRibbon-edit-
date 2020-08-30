#include<stdio.h>
#include<math.h>
typedef struct
{
    int point, space;
}Coordinate;

Coordinate ribbon(int k) {
    int num, loop, loop2, x1 = 1, x2 = 1, space, sumSpace = 0, sumP = 0;
    Coordinate p;
    space = (k - 1) + (k - 2);
    printf("This is your butterfly \n\n");
    for (loop2 = 0; loop2 < (k * 2) - 1; loop2++)
    {
        for (loop = 0; loop < x1; loop++)
        {
            sumP += 1;
            printf("* ");
        }
        for (loop = 0; loop < space; loop++)
        {
            sumSpace += 1;
            printf("  ");
        }
        for (loop = 0; loop < x2; loop++)
        {
            sumP += 1;
            printf("* ");
        }
        if (loop2 <= k - 1)
        {
            x1++;
            x2++;
            space -= 2;
        }
        else
        {
            x1--;
            x2--;
            space += 2;
        }
        if (loop2 == k - 2)
        {
            x1--;
        }
        if (loop2 == k - 1)
        {
            x1 = k - 1;
            x2 = k - 1;
            space = 1;
        }
        printf("\n");
    }
    p.space = sumSpace;
    p.point = sumP;
    return p;
}

int main()
{
    int x[100];

    printf("Input 3 number follow this pattern (1 2 3) : ");
    for (int i = 0; i < 3; i++)
    {
        scanf_s("%d", &x[i]);
    }
    if ((x[0] < x[1] && x[1] < x[2]) || (x[2] < x[1] && x[1] < x[0]))
    {
        printf("Middle point is %d\n", x[1]);
        Coordinate p = ribbon(x[1]);
        printf("Space in butterfly : %d\n", p.space);
        printf("* in butterfly : %d\n", p.point);
        printf("The difference between space and * = %d\n ", abs(p.space - p.point));
    }
    else if ((x[1] < x[0] && x[0] < x[2]) || (x[2] < x[0] && x[0] < x[1]))
    {
        printf("Middle point is %d\n", x[0]);
        Coordinate p = ribbon(x[0]);
        printf("Space in butterfly : %d\n", p.space);
        printf("* in butterfly : %d\n", p.point);
        printf("The difference between space and * = %d\n ", abs(p.space - p.point));
    }
    else if ((x[1] < x[2] && x[2] < x[0]) || (x[0] < x[2] && x[2] < x[1]))
    {
        printf("Middle point is %d\n", x[2]);
        Coordinate p = ribbon(x[2]);
        printf("Space in butterfly : %d\n", p.space);
        printf("* in butterfly : %d\n", p.point);
        printf("The difference between space and * = %d\n ", abs(p.space - p.point));
    }
    return 0;
}


