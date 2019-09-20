#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "benchmark.h"

clock_t start;
clock_t end;
double *times;
int nr_runs;


void init_benchmark(int i, char fname[]){
  printf("\nBenchmarking code: %s...\n", fname);
  double timeArray[i];
  nr_runs = i;
  times = (double*) malloc(sizeof(double) * i);
}

void start_benchmark(){
  start = clock();
}

void end_benchmark(int ix){
  end = clock();
  times[ix] = (double) (end - start)/CLOCKS_PER_SEC;
}

void print_benchmark(){
  double sum = 0;
  double min = 99999999999999;
  double max = 0;

  for(size_t ix = 0; ix < nr_runs; ++ix){
    sum += times[ix];
    if(times[ix] < min){
      min = times[ix];
    }
    else if(times[ix] > max){
      max = times[ix];
    }
  }
  printf("---------------------------\n");
  printf("Mean runtime: %.4fms\n", 1000*sum/nr_runs);
  printf("Min runtime:  %.4fms\n", 1000*min);
  printf("Max runtime:  %.4fms\n \n", 1000*max);

}
