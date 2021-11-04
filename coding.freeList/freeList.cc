#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
}

long int*
freeList::reserve_space( int size ) {

  // the start location of the reserved space will be 2 after the current head
  // the 2 is for the headder information
  long int* loc = head + 2;
  cout << "reserved_space at: " << loc << endl;

  // the size will be at the first location
  cout << "the head is at " << head << endl;
  cout << "head 1st elem: " << head+1 << "\n";
  // int x = head[0];
  *head = size;
  // the new head will be after the headder information for the reserved space
  // plus the requested size of the reserved space
  //cout << "size:" << head[0];
  // head[0] = size;
  // cout << "reserved_space size:" << head[0];
  // head  = head + size+2;
  // long int s = (long int*) size;
  // long int freeChunkSize = head[0] - s - 2;
  //
  // head = head + s + 2;
  // head[0] = freeChunkSize
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
