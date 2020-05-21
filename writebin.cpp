#include <iostream>

int main()
{
    FILE *f = fopen("C.txt", "r");
    while (getline())
    std::cout << "Hello world" << std::endl;
    return 0;
}

