#ifndef matrix_h
#define matrix_h
#include <fstream>
#include <string.h>
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

class Matrix{
    int **elem;
public:
    std::string name;
    int rows , cols;
    Matrix(int n, int m, std::string mmm);
    Matrix(std::string s, std::string mmm);
    Matrix(Matrix &A, int N, std::string mmm);
    Matrix(Matrix &A, int N, int K, std::string mmm);
    Matrix();
    friend Matrix operator *(Matrix &A, Matrix &B);
    friend Matrix operator %(Matrix &A, Matrix &B);
    friend std::ostream& operator << (std::ostream& stream, Matrix M);
    void Random_permutate();
    void RREF(Matrix &A);
    void IN(Matrix &A);
    void RM(Matrix &B, Matrix &C);
    void RMM(Matrix &B, Matrix &C);
    void TRM(Matrix &B, Matrix &C);
    void PRINT();
    void Last_cols_permutation();
    void First_cols_permutation();
    bool Full_rank();
    int Ham_weight();
    ~Matrix();
};

#endif
