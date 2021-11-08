#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {

  head = inRAM;
  head[0] = size-2;
  head[1] = 0;
}

long int*
freeList::reserve_space( int size ) {
  long int* loc = NULL;
  long int currentHeadSize = head[0];
  loc = head; //set the header of the reserved space to be where the head is
  loc[0] = size;
  head = loc + 2 + size;
  head[0] = currentHeadSize-2-size;
  return loc+2;
}

void
freeList::free_space( long int* location ) {

  long int* locationStart = location -2; //where the header starts
  long int prevHead = (long int) head; //where the head currently is
  // cout << "type of prevHead: " << typeid(prevHead).name() << endl;
  // cout << "type of head[1]: " << typeid(head[1]).name() << endl;
  head = locationStart; // head is now the location of the newest freed space

  head[1] = prevHead; // the next of the head is where the previous head used to be


}

void
freeList::coalesce_forward() {

  long int* currentNode = head;
  while (currentNode[1] != 0) {  //while there is a next node in the freeList
    long int* nextNode = (long int*) currentNode[1]; //headder location for next node
    long int sizeOfNextNode = nextNode[0]; //size of the next node

    if ((currentNode+2+currentNode[0]) == nextNode){ //if the end of current node is the start of the next one
      cout << "going forwards" << endl;
      currentNode[0] = currentNode[0]+2+sizeOfNextNode; //expand the current node to include the next node
      currentNode[1] = nextNode[1]; //set the next value of current node the next value of the next node
    } else if ((nextNode+2+sizeOfNextNode) == (currentNode) ){ //if the end of the next node is the start of the current one
      cout << "going backwards" << endl;

      nextNode[0] = sizeOfNextNode+2+currentNode[0]; // expand the next node to include the current one (header included)
      currentNode = nextNode;  //set the next node to be the currentNode

    }else{
      currentNode = (long int*)currentNode[1];

    }
  }

}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;

  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}
