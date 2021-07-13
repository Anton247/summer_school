#include <iostream>
#include <mpi.h>
#include<LuNA>
using namespace std;
 
void c_print(int n){
	cout<<n;
}
void c_init(int val, OutputDF &df) {
	df.setValue(val);
}

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &commSize);
    int num;
    if (!rank){
        DF x;    
        c_init(7, x);   
        asert(x.get_type() == 1);
        num = x.getValue<int>();
        MPI_Send(&num, 1, MPI_INT, commSize - 1, 0, MPI_COMM_WORLD);
    }
	if(rank == commSize - 1){
		MPI_Resive(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		print(num);
	}
    MPI_Finalize();
    return 0;
}