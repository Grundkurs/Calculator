#include "Application.hpp"
#include <iostream>
#include <windows.h>
using namespace std;

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow) {

    Application application;
    application.run();
    return 0;
}