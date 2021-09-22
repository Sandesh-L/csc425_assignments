#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]){

  if (argc != 3){
    printf("not enough arguments! \n");
    exit(1);
  }

  int byte = atoi(argv[1]);
  int mem_to_use = (1024*1024)*byte;

  int length = atoi(argv[2]);

  int *a = malloc(mem_to_use);


  //got code for time tracking from https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
  clock_t start,end;
  start = clock();
  end = clock();
  while ((((double) (end - start)) / CLOCKS_PER_SEC)>=length){

    for(int i = 0; 1 < mem_to_use; i++){
      a += 1;
    }
    end = clock();
  }
  printf((double) (end - start)) / CLOCKS_PER_SEC))
  return 0;

}
