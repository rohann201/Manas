#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 5
int arr[size][size];
void main()
{
    printf("Welcome to the game of 2048!\n");
    printf("Controls are : 'a' for left, 'd' for right, 'w' for up, and 's' for down, '0' to exit\n");
    int flag = 1;
    srand(time(0));
    int i = 0,j = 0;
    char c;
    for(i = 0;i<size;i++)
    {
        for(j = 0;j<size;j++)
        {
            arr[i][j] = 0;
        }
    }
    rando();
    printing();
    while(flag == 1)
    {
        scanf("%c",&c);
    switch(c)
    {
        case 'd' : right();
                   break;
        case 'a' : left();
                   break;
        case 'w' : up();
                   break;
        case 's' : down();
                   break;
        case '0' : flag = 0;
    }
    system("cls");
    printing();
    }
}
void printing()
{
    int i,j;
    for(i = 0;i<size;i++)
    {
        for(j = 0;j<size;j++)
        {
            printf("%d   ",arr[i][j]);
        }
        printf("\n");
    }
}
void right()
{
    int i,j,k,flag = 1,flag1 = 1,h=1;
    for(k = 0;k<=size-2;k++)
    {
        if(h == 0)
            flag1 = 0;
    for(i = size-1;i>=0;i--)
    {
        flag = 1;
        for(j = size-1;j>=0;j--)
        {
            if(j==0)
            {
                continue;
            }
            if(arr[i][j] == 0)
            {
                arr[i][j] = arr[i][j-1];
                arr[i][j-1] = 0;
            }
            else if(arr[i][j] != 0 && arr[i][j] == arr[i][j-1])
            {
                if(flag == 1 && flag1 == 1)
                {h = 0;
                arr[i][j] = arr[i][j] + arr[i][j-1];
                arr[i][j-1] = 0;
                flag = 0;
                }
            }
            else if(arr[i][j] != 0 && arr[i][j] != arr[i][j-1])
                continue;
        }
    }
    }
    check();
    rando();
}
void left()
{
    int i,j,k,flag = 1,flag1 = 1,h = 1;
    for(k = 0;k<=size-2;k++)
    {
        if(h == 0)
            flag1 = 0;
    for(i = 0;i<=size-1;i++)
    {
        flag = 1;
        for(j = 0;j<=size-1;j++)
        {
            if(j==size-1)
            {
                continue;
            }
            if(arr[i][j] == 0)
            {
                arr[i][j] = arr[i][j+1];
                arr[i][j+1] = 0;
            }
            else if(arr[i][j] != 0 && arr[i][j] == arr[i][j+1])
            {
                if(flag == 1 && flag1 == 1)
                {h = 0;
                arr[i][j] = arr[i][j] + arr[i][j+1];
                arr[i][j+1] = 0;
                flag = 0;
                }
            }
            else if(arr[i][j] != 0 && arr[i][j] != arr[i][j+1])
                continue;
        }
    }
    }
    check();
    rando();
}
void down()
{
    int i,j,k,flag = 1,flag1 = 1,h = 1;
    for(k = 0;k<=size-2;k++)
    {
        if(h == 0)
            flag1 = 0;
    for(j = size-1;j>=0;j--)
    {
        flag = 1;
        for(i = size-1;i>=0;i--)
        {
            if(i==0)
            {
                continue;
            }
            if(arr[i][j] == 0)
            {
                arr[i][j] = arr[i-1][j];
                arr[i-1][j] = 0;
            }
            else if(arr[i][j] != 0 && arr[i][j] == arr[i-1][j])
            {
                if(flag == 1 && flag1 == 1)
                {h = 0;
                   arr[i][j] = arr[i][j] + arr[i-1][j];
                   arr[i-1][j] = 0;
                   flag = 0;
                }
            }
            else if(arr[i][j] != 0 && arr[i][j] != arr[i-1][j])
                continue;
        }
    }
    }
    check();
    rando();
}
void up()
{
    int i,j,k,flag = 1,flag1 = 1, h = 1;
    for(k = 0;k<=size-2;k++)
    {
        if(h == 0)
            flag1 = 0;
    for(j = 0;j<=size-1;j++)
    {
        flag = 1;
        for(i = 0;i<=size-1;i++)
        {
            if(i==size-1)
            {
                continue;
            }
            if(arr[i][j] == 0)
            {
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = 0;
            }
            else if(arr[i][j] != 0 && arr[i][j] == arr[i+1][j])
            {
                if(flag == 1 && flag1 == 1)
                {h = 0;
                arr[i][j] = arr[i][j] + arr[i+1][j];
                arr[i+1][j] = 0;
                flag = 0;
                }
            }
            else if(arr[i][j] != 0 && arr[i][j] != arr[i+1][j])
                continue;
        }
    }
    }
    check();
    rando();
}
void rando()
{
    int a,b,i,j,flag = 1;
    while(flag == 1)
    {
    srand(time(0));
    a = rand()%size;
    b = rand()%size;
    for(i = 0;i<size;i++)
    {
        for(j = 0;j<size;j++)
        {
            if(arr[a][b] == 0)
                flag = 0;
        }
    }
    }
    if(flag == 1)
    {
        printf("Game over");
        exit(0);
    }
    arr[a][b] = 2;
}
void check()
{
    int i,j;
    for(i = 0;i<size;i++)
    {
        for(j = 0;j<size;j++)
        {
            if(arr[i][j] == 2048)
                printf("You won! But you can keep going on if you want");
        }
    }
}
