/************************************************************
* This is base code for recursion homework problems.
* It opens a file of numbers and reads it in to demonstrate
* the first set of functions, then it lets the user enter in
* numbers for prime number checking and factoring.
* This should NOT be turned in, and does not test all cases.
* The number file will have the number of subsequent lines
* on the first line, followed by that many numbers, each on
* a separate line.
* This code DOES NOT NEED TO BE CHANGED, but you can change it
* or comment out parts to help with testing.
* Author: Joshua Gross (jgross@csumb.edu)
* Date: Nov 7, 2020
************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include "recursion.h"
using namespace std;
int main() {
  string fname ="";
  do {
    cout << "Enter a file name: ";
    cin >> fname;
  } while (fname == "");
  ifstream infile;
  infile.open(fname);
  if(infile.fail()) {
    cerr << "Couldn't open " << fname << "\n";
    return 0;
  }

  int size;
  infile >> size;
  int * a = new int[size];
  for (int i = 0; i < size; i++) {
    infile >> a[i];
  }
  infile.close();

  cout << "Printing Contents of File: " << endl;
  for(int i = 0; i < size; i++){
    cout << a[i] << " ";
  }
  cout << endl << endl;

  cout << "Count of even numbers: " << countEvens(a, size) << "\n";
  cout << "Sum of even numbers: " << sumEvens(a, size) << "\n";
  cout << "Printing even numbers:\n\t";
  printEvens(a, size);
  cout << "\n";
  cout << "Printing even numbers in file order:\n\t";
  printEvensInOrder(a, size);
  cout << "\n";

  //MY TEST CODE:
  cout << endl << "==== MY TEST FOR isPrime ====" << endl;
  cout << "Is 5 prime: EXPECTED: true -> "<< boolalpha << isPrime(5) << endl;
  cout << "Is 15 prime: EXPECTED: false -> "<< boolalpha << isPrime(15) << endl;
  cout << "==== END OF MY TEST FOR isPrime ====" << endl;

  cout << "Populating vector...\n";
  vector<int> * v = populateVector(a, size);
  cout << "Sum of vector: " << sumVector(*v) << "\n";
  cout << "Printing vector in file order:\n\t";
  printVector(*v);
  cout << "\n\n";


  int base = 0;
  while(true) {
    cout << "Enter a number greater than 1 (or 0 to quit): ";
    cin >> base;
    if(base == 0) {
      break;
    } else if(base < 2) {
      continue;
    }
    if(isPrime(base)) {
      cout << base << " is prime\n";
    } else {
      cout << base << " is not prime\n";
    }
    vector<int> v;
    factorNumber(v, base);
    printFactors(v);
    cout << base << "\n\n";
  } 

}