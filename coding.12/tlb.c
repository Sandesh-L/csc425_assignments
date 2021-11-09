#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
using namespace std::chrono;

int main(int argc, char *argv[]){
 int jump = atoi(argv[1]);
 int size = atoi(argv[2]);
 int a[size];
 int len = sizeof(a)/sizeof(a[0]);

 //help for timing found at https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
 std::cout << "the length of the array: "<<  len << std::endl;
 auto start = high_resolution_clock::now();
 std::cout << "Hello"<< std::endl;
 auto stop = high_resolution_clock::now();
 auto duration = duration_cast<microseconds>(stop-start);
 std::cout << "It took this many microseconds: " << duration.count()<< std::endl;
 int sum;
 auto start1 = high_resolution_clock::now();
 for (int i = 0; i < len; i += jump){
  a[i] += 1;
 }
 auto stop1 = high_resolution_clock::now();
 auto duration1 = duration_cast<microseconds>(stop1-start1);
 int loopCount = len/jump;
 int totalTime = (duration1.count())/loopCount; 
 std::cout << "time for the average jump was: " << totalTime << std::endl;
 return 0;
}
