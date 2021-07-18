#include "mpi.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  int rank, commSize;
  
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &commSize);

  cout << rank << endl;

  MPI_Finalize();
}