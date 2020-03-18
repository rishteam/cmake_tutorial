#include "hello.h"

void sayHello(std::string name)
{
    puts(("Hello " + name).c_str());
}