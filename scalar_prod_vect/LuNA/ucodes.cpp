#include<cstdio>
#include<cstring>
#include"ucenv.h"
#include<fstream>
#include<iostream>
extern "C"
{
    void c_init(int val, OutputDF &df) 
    {
        df.setValue<int>(val);
        //printf("c_init: %d --> %s, size: %d\n", val, df.getName().c_str(), (int)df.getSize());
    }

    void c_dinit(double val, OutputDF &df) 
    {
        df.setValue<double>(val);
        //printf("c_init: %d --> %s, size: %d\n", val, df.getName().c_str(), (int)df.getSize());
    }


    void c_initVA(OutputDF &dfo, int l, int k) 
    {
        //int* length = l.getData<int>();
        int length = l;
        std::ifstream in("VA.txt"); // окрываем файл для чтения 
        assert(in.is_open());  
        double *A = dfo.create<double>(length);
        double a;
        for(int i=0; i<length*k; i++)
           in>>a;
        for(int i=0; i<length; i++)
           in>>A[i];
    }
    void c_initVB(OutputDF &dfo, int l, int k) 
    {
        int length = l;
        std::ifstream in("VB.txt"); // окрываем файл для чтения 
        assert(in.is_open());  
        double *A = dfo.create<double>(length);
        double a;
        for(int i=0; i<length*k; i++)
           in>>a;
        for(int i=0; i<length; i++)
           in>>A[i];
    }

    void c_dprint(InputDF &c){
        double C = c.getValue<double>();
        printf("%lf\n", C);
	}

    void partialSum(InputDF &A, InputDF &B, OutputDF &S, int length){
        double* a = A.getData<double>();
        double* b = A.getData<double>();
        double s = 0;
        
        for(int i=0; i<length; i++)
            s += a[i] * b[i];
        S.setValue<double>(s);
    }

    void c_sum(InputDF &A, InputDF &B, OutputDF &SUM){
        double s=0;
        s += A.getValue<double>();
        s += B.getValue<double>();
        SUM.setValue<double>(s);
    }
}