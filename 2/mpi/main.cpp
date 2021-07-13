#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"DF.h"

using namespace std;


void c_print(int n) {
    cout << n;
}
void c_init(int val, DF& df) {
    df.setValue(val);
}
//реализована задача, с инициализацией на root а вывод на последнем процессе
int main(int argc, char** argv) {
    int rank, commSize;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &commSize);
    MPI_Status status;
    if (!rank) {
        DF x;
        c_init(7, x);
        assert(x.get_type() == TYPE_INT);
        int* a = x.getBuffer<int>(); //сторонняя функция в DF.h
        MPI_Send(a, 1, MPI_INT, commSize - 1, 0, MPI_COMM_WORLD);
    }
    if (rank == commSize - 1) {
        int num;
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        c_print(num);
    }
    MPI_Finalize();
    return 0;
}