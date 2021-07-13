#include <cstdio>
#include <cstring>
#include "ucenv.h"
#include<fstream>
#include<iostream>
#include "/home/anton/Документы/GitHub/summer_school/FragmentLibrary/DF.h"

extern "C"
{
    void c_print() 
    {
        printf("Hello =)\n");
        fflush(stdout);
    }
}