#include <iostream>
#include <windows.h>

int main(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // you can loop k higher to see more color choices
    for(int k = 1; k < 255; k++)
    {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, k);
    std::cout << k << " I want to be nice today!" << std::endl;
    }
    return 0;
}