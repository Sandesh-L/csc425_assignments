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

  int length = atoi(argv[2]);

  int *a = malloc(byte*sizeof(int));


  //got code for time tracking from https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
  clock_t start,end;
  start = clock();
  end = clock();
  while ((((double) (end - start)) / CLOCKS_PER_SEC) < length){
    // printf("%f", ((double) (end - start)) / CLOCKS_PER_SEC);
    for(int i = 0; i < byte; i++){
      printf("%ls", a);
      // a[i] += 1;
      // printf("%i", a[i]); //I recommend commenting this part out.
    }
    end = clock();
  }
  printf("time run: %f \n", (((double) (end - start)) / CLOCKS_PER_SEC));
  return 0;

}
