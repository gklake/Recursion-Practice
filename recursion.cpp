/*
* Title: hw09
* Abstract: This program will implement various functions using recursion
* Author: Gabrielle Lake
* Email: glake@csumb.edu
* Estimate: 3 hours
* Date: 11/16/2020
*/
#include "recursion.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int countEvens(int * a, int size) {
  if(size == 0){
    return 0;
  } else if(size == 1){
    if(a[size - 1] % 2 == 0){
      return 1;
    } else {
      return 0;
    }
  } else {
    if(a[size - 1] % 2 == 0){
      return 1 + countEvens(a, size - 1);
    } else {
      return countEvens(a, size - 1);
    }
  }
}

int sumEvens(int * a, int size) {
  if(size == 0){
    return 0;
  } else if(a[size - 1] % 2 == 0){
    return a[size - 1] + sumEvens(a, size - 1);
  } else {
    return sumEvens(a, size - 1);
  }
}


void printEvens(int * a, int size) {
  if(size == 0){
    //return;
  } else if(a[size - 1] % 2 == 0) {
    cout << a[size - 1] << " ";
    printEvens(a, size - 1);
  } else {
    printEvens(a, size - 1);
  }
}

/**
* This helper function is implemented and does not need to be changed
*/
void printEvensInOrder(int * a, int size) {
  printEvensInOrder(a, size, 0);
}

void printEvensInOrder(int * a, int size, int current) {
  if(current == size){
    return;
  } else if(a[current] % 2 == 0) {
    cout << a[current] << " ";
    printEvensInOrder(a, size, current + 1);
  } else {
    printEvensInOrder(a, size, current + 1);
  }
}

/**
* This helper function is implemented and does not need to be changed
*/
bool isPrime(int base) {
  if(base == 2) {
    return true;
  } else {
    return isPrime(base, 2);
  }
}

bool isPrime(int base, int comparison) {
  
  if(base > comparison){
    if(base % comparison == 0){
      return false;
    } else {
      return isPrime(base, comparison + 1);
    }
  } else {
    return true;
  }
}

/**
* This helper function is only partially implemented and MUST BE COMPLETED
*/
vector<int> * populateVector(int * a, int size) {
  vector<int> * v = new vector<int>();

  // first, call the actual recursive function
  populateVector(*v, a, size);
  // the reverse the vector
  reverse(v->begin(), v->end());

  return v;
}

void populateVector(vector<int> &v, int * a, int size) {
  if(size == 0){
    return;
  } else if(size > 0) {
    v.push_back(a[size-1]);
    return populateVector(v, a, size - 1);
  }
}

/**
* This helper function must be implemented
*/
void printVector(vector<int> & v) {
  printVector(v, 0);
}

void printVector(vector<int> & v, int position) {
  if(v.size() - 1 == position){
    cout << v[position];
    return;
  } else {
    cout << v[position] << " ";
    return printVector(v, position + 1);
  }
}

/**
* This helper function must be implemented
*/
int sumVector(vector<int> & v) {
  return sumVector(v, v.size());
}

int sumVector(vector<int> & v, int position) {
  if(position < 0){
    return 0;
  } else {
    return v[position - 1] + sumVector(v, position - 1);
  }
}

/**
* This helper function must be implemented
*/
void factorNumber(vector<int> & v, int base) {
  factorNumber(v, base, 1);
}

void factorNumber(vector<int> & v, int base, int comparison){
  if (comparison == 1){
    // if comparison == 1, we're at the start, so push the one
    // and try to factor with the next number for comparison
    v.push_back(1);
    factorNumber(v, base, comparison + 1);
  } else if(comparison == base){
    v.push_back(base);
    return;
  } else if (base % comparison == 0){
    v.push_back(comparison);
    factorNumber(v, base/comparison, comparison);
  } else {
    return factorNumber(v, base, comparison + 1);
  }
}

void printFactors(vector<int> & v) {
  return printFactors(v, 0);
}

void printFactors(vector<int> & v, int position) {
  if(position < v.size() - 1){
    cout << v[position] << " * ";
    return printFactors(v, position + 1);
  } else {
    cout << v[position] << " = ";
  }
}