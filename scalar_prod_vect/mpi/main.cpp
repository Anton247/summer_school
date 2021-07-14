#include <iostream>
#include <mpi.h>
#include<LuNA>
#include <map>
using namespace std;
 
void c_print(int n){
	cout<<n;
}
void c_init(int val, OutputDF &df) {
	df.setValue(val);
}

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

    void partialSum(InputDF &A, InputDF &B, OutputDF &S, int length){
        double* a = A.getData<double>();
        fflush(stdout);
        double* b = A.getData<double>();
        double* s = S.create<double>(length);
        
        for(int i=0; i<length; i++)
            s[i] = a[i] + b[i];
    }

int main(int argc, char **argv) {
    int rank, commSize;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &commSize);
    //что вместо DF можно применить обычный тип (int)
    
    DF length;
    init(4, length); //подставлены define
    DF size;
	init(4, size); //подставлены define
    //простой случай, когда данные по границам цикла нам известны
    DF A_0, A_1, A_2, A_3, B_0, B_1, B_2, B_3;
    //такие "неадеквантные" x просто для примера
    DF x_0_1_1, x_1_1_1, x_2_1_1, x_3_1_1; 

    if(!rank){
        //в принципе достаточно просто выяснить, что у нас повторение
        //size операций
        if(commSize > size)
            
    }
    initVA(A0, length, 0);
    initVB(B0, length, 0);
    partialSum(A[0], B[0], C[0], length);

    initVA(A0, length, 1);
    initVB(B0, length, 1);
    partialSum(A[1], B[1], C[1], length);

    initVA(A0, length, 2);
    initVB(B0, length, 2);
    partialSum(A[2], B[2], C[2], length);



    if(commSize>=2){ //для больше 2-х процессов
        if(rank == 0){
            //#pragma omp parallel for
            for(int i=0; i<size-1; i++){
               initVA(A0, length, i);
            }
        }
        else if(rank == 1){
            //#pragma omp parallel for
            for(int i=0; i<size-1; i++){
                initVB(B0, length, i);
            }
        }
    }
    else{
        //#pragma omp parallel for
        for(int i=0; i<size-1; i++){
            initVA(A0, length, i);
        }
        //#pragma omp parallel for
        for(int i=0; i<size-1; i++){
            initVB(B0, length, i);
        }
    }
    

    
    MPI_Finalize();
    return 0;
}