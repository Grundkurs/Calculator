#include "Application.hpp"
#include <iostream>
#include <windows.h>
using namespace std;

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {
    Application application;
    application.run();
    return 0;
}
/*
    std::string left{""};
    std::string right{""};
    std::string dot{"."};
    std::getline(std::cin, left);

    left.append(dot);
    std::getline(std::cin, right);

    left.append(right);
    float result = std::stof(left);

    std::cout << "result is finally " << result;
*

    return 0;


}*/