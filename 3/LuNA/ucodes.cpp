#include <cstdio>
#include <cstring>
#include "ucenv.h"
#include<fstream>
#include<iostream>
#include "/home/anton/Документы/GitHub/summer_school/FragmentLibrary/DF.h"

extern "C"
{
    void c_iprint(int x) 
    {
        printf("%d\n", x);
        fflush(stdout);
    }
    void c_init(int val, OutputDF &df) 
    {
        df.setValue<int>(val);
        //printf("c_init: %d --> %s, size: %d\n", val, df.getName().c_str(), (int)df.getSize());
    }
}