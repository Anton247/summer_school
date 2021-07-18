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

    void c_vprint(InputDF &c, int n){
        double* C = c.getData<double>();
        for(int i=0; i<n; i++){
            printf("%lf\n", C[i]);
        }
		
	}

    void c_print(InputDF &c){
        printf("number\n");
        fflush(stdout);
        int C = c.getValue<int>();
        printf("number %d\n", C);
        fflush(stdout);
	}

    void partialSum(InputDF &A, InputDF &B, OutputDF &S, int length){
        double* a = A.getData<double>();
        fflush(stdout);
        double* b = A.getData<double>();
        double* s = S.create<double>(length);
        
        for(int i=0; i<length; i++)
            s[i] = a[i] + b[i];
    }
}