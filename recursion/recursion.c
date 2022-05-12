#include <stdio.h>

void printN(int n)
{
    if (n)
    {
        printN(n - 1);
        printf("%d\n", n);
    }
    return;
}

int main(int argc, char const *argv[])
{
    printN(5);
    return 0;
}
