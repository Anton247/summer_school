#include <cstdio>
#include <cstring>
#include "ucenv.h"
#include<fstream>
#include<iostream>

extern "C"
{
    void c_print() 
    {
        printf("Hello =)\n");
        fflush(stdout);
    }
}