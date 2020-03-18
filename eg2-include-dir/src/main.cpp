#include <iostream>
#include <string>
#include "hello.h"

using std::cin;
int main()
{
    std::string myName;
    puts("Hello, world");
    printf("Type your name> ");
    cin >> myName;

    sayHello(myName);
}