#include <iostream>
#include <mpi.h>
#include "/home/anton/Документы/GitHub/summer_school/FragmentLibrary/DF.h"
using namespace std;
 
void c_print(){
	printf("Hello =)\n");
    fflush(stdout);
}

int main(int argc, char **argv) {
    int rank, commSize;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &commSize);
    
    c_print();
 
    MPI_Finalize();
    return 0;
}