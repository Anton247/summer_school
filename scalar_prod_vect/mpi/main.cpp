#include <iostream>
#include <mpi.h>
#include<LuNA>
#include <vector>
using namespace std;
 
void c_init(int, OutputDF &);
void c_dinit(double, OutputDF &);

void c_initVA(OutputDF &, int, int);
void c_initVB(OutputDF &, int, int);
void c_dprint(InputDF &);
void partialSum(InputDF &, InputDF &, OutputDF &, int);
void c_sum(InputDF &, InputDF &, OutputDF &);
int main(int argc, char **argv) {
    int rank, commSize;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &commSize);
    
    DF length;
    c_init(4, length);
    DF size;
	init(4, size); 
    
    for(i=0; i<size; i++)    
    DF A_0;
    initVA(A_0, length, 0);
    DF B_0;
	initVB(B_0, length, 0);
    DF C_0;
	partialSum(A_0, B_0, C_0, length);

    DF A_1;
    initVA(A_1, length, 1);
    DF B_0;
	initVB(B_1, length, 1);
    DF C_0;
	partialSum(A_1, B_1, C_1, length);

    ...

    vprint(C_0, length);




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