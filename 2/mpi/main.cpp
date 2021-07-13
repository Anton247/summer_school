#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"/home/anton/Документы/GitHub/summer_school/FragmentLibrary/DF.h"

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
    int num;
    if (!rank) {
        DF x;
        //c_init(7, x);
       // assert(x.get_type() == TYPE_INT);
        //num = x.getValue<int>();
        //MPI_Send(&num, 1, MPI_INT, commSize - 1, 0, MPI_COMM_WORLD);
    }
    if (rank == commSize - 1) {
        //MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        //c_print(num);
    }
    MPI_Finalize();
    return 0;
}