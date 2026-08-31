// mergesort.cpp
// Read in positive integer n, generate non-monotonic sequence of n numbers, sort it using merge sort

#include <iostream>
#include <vector>
#include <cmath>

void merge_sort(double sequence[], double* buffer, unsigned n) {
    // precondition: length 'n' of sequence must be n>=1, 'buffer' must be at least of same length
    // postcondition: the sequence 'sequence' of length 'n' will be sorted
    if (n==1) return;
    // split
    double* seq1 = sequence;
    double* seq2 = sequence + n/2;
    merge_sort(seq1, buffer    , n/2  );
    merge_sort(seq2, buffer+n/2, n-n/2);
    // and merge it in buffer
    double* buf=buffer;
    while (seq1 < sequence + n/2 && seq2 < sequence + n) {
        if (*seq1<*seq2) {
            *buf++ = *seq1++;
        } else {
            *buf++ = *seq2++;
        }
    }
    while (seq1 < sequence + n/2) {
        *buf++ = *seq1++;
    }
    while (seq2 < sequence + n) {
        *buf++ = *seq2++;
    }
    // copy sorted sequence in buffer to sequence
    for (unsigned i = 0; i < n; ++i) {
        sequence[i] = buffer[i];
    }
}

int main() {
  unsigned n;
  std::cout<<"Set length of the sequence to be sorted: ";
  std::cin>>n;

  // generate a non-monotonic sequence of length n and print it
  double* sequence = new double[n];  // allocate memory for the sequence
  std::cout << "Original sequence: ";
  for (unsigned i=0; i<n; i++) {
    sequence[i] = sin(i);
    std::cout << sequence[i] << "  ";
  }
  std::cout << std::endl;

  // sort the sequence
  double* buffer = new double[n];  // allocate buffer for the merge_sort
  merge_sort(sequence, buffer, n);
  delete[] buffer;  //  deallocate the buffer

  // print the sorted sequence
  std::cout<<"Sorted sequence: ";
  for (unsigned i=0; i<n; ++i) {
    std::cout<<sequence[i]<<"  ";
  }
  std::cout<<std::endl;

  delete[] sequence;  // deallocate the memory for the sequence
  return 0;
}