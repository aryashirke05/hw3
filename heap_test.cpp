#include <iostream>
#include "heap.h"

int main()
{
  Heap<int> h;

  h.push(2);
  h.push(5);
  h.push(1);
  h.push(6);

  while (!h.empty()){
    std::cout << h.top() << " ";
    h.pop();
  }
  std::cout << std::endl;

  Heap<int, std::greater<int> > maxHeap;
  maxHeap.push(2);
  maxHeap.push(5);
  maxHeap.push(1);
  maxHeap.push(6);
}