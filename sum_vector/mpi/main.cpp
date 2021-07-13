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
    //map<string, DF> dfSet = { {"x_4", DF()}, {"x_7", DF()} };
    //DF A, B, C, length, size, x;
    //можем ли мы проанализировать код и понять
    //что вместо DF можно применить обычный тип (int)
    
    DF length;
    init(4, length); //подставлены define
    DF size;
	init(4, size); //подставлены define

    DF A0;
    initVA(A0, length, n);

    DF A1;
    initVA(A0, length, n);

    DF A2;
    initVA(A0, length, n);

    DF A3;
    initVA(A0, length, n);
    
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