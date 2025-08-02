#include <stdio.h>

void HelloWorld()
{
    int i = 0;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    for(i = 0; i <= 10; i++)
    {
        a[i] = 0;
        printf("Hello World!\n");
    }
}

int main(int argc, char* argv[])
{
    HelloWorld();
    getchar();
    return 0;
}
