#include<mpi.h>
#include <stdio.h>
#include<stdlib.h>
#include"DF.h"
#include<iostream>
#include <map>
using namespace std;


void c_print(int n) {
    cout << n;
}
void c_init(int val, DF& df) {
    df.setValue(val);
}

int main(int argc, char** argv) {
    int rank, commSize;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &commSize);
    //можно переделать и в вектор, где будет обычная индексация
    //здесь map для наглядности и простоты
    map<string, DF> dfSet = { {"x_4", DF()}, {"x_7", DF()} };

    if (!rank) {
        c_init(7, dfSet["x_4"]);
        c_print(dfSet["x_4"].getValue<int>());
        int k = dfSet["x_4"].getValue<int>();
        string d = "x_" + k;
        
        c_init(7, dfSet[d]);
        c_print(dfSet[d].getValue<int>());
        }
    MPI_Finalize();
    return 0;
}