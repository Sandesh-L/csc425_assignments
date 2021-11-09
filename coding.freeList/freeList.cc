#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
}

long int*
freeList::reserve_space( int size ) {

  // the start location of the reserved space will be 2 after the current head
  // the 2 is for the headder information
  long int* loc = head + 2;

  // the new head will be after the headder information for the reserved space
  // plus the requested size of the reserved space
  // head  = head+ size+2;

  return loc;
}

void
freeList::free_space( long int* location ) {


}

void
freeList::coalesce_forward() {
}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;

  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}
