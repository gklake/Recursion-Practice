/************************************************************
* This is base code for recursion homework problems.
* This .h file contains function declarations for recursive
* functions and helper functions to add parameters (in some cases)
* Author: Joshua Gross (jgross@csumb.edu)
* Date: Nov 7, 2020
************************************************************/
#ifndef RECURSION_H
#define RECURSION_H
#include <vector>
using namespace std;
int countEvens(int * a, int size);
int sumEvens(int * a, int size);
void printEvens(int * a, int size);
void printEvensInOrder(int * a, int size);
void printEvensInOrder(int * a, int size, int current);
bool isPrime(int base);
bool isPrime(int base, int comparison);
vector<int> * populateVector(int * a, int size);
void populateVector(vector<int> &v, int * a, int size); 

void printVector(vector<int> & v);
void printVector(vector<int> & v, int position);
int sumVector(vector<int> & v);
int sumVector(vector<int> & v, int position);

void factorNumber(vector<int> & v, int base);
void factorNumber(vector<int> & v, int base, int comparison);
void printFactors(vector<int> & v);
void printFactors(vector<int> & v, int position);
#endif