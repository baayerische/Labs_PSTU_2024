#include <iostream>

int main() 
{
    double a, b;
    int op;

    std::cin >> a >> b >> op;

    switch (op) 
    {
    case 1:
        std::cout << a+b << std::endl;
        break;
    case 2:
        std::cout << a-b << std::endl;
        break;
    case 3:
        std::cout << a*b << std::endl;
        break;
    case 4:
        if (b == 0) 
        {
            std::cout << "error" << std::endl;
        }
        else 
        {
            std::cout << (a / b) << std::endl;
        }
        break;
    default:
        std::cout << "Invalid operation code" << std::endl;
        break;
    }

    return 0;
}