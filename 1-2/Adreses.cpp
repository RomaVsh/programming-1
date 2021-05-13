#include <iostream>

int glob;
int bss;

int main()
{
    printf("Text segment: %p\n", main);
    glob = 3;
    printf("Data segment: %p\n", &glob);
    printf("BSS segment: %p\n", &bss);
    int* heap = new int;
    printf("Heap: %p\n", heap);
    int stack;
    printf("Stack: %p\n", &stack);
}