#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <cstddef>
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> elems;
  int m_;
  PComparator comp;
  void trickleUp(int index);
  void trickleDown(int index);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp(c){
  if(m < 2){
    throw std::invalid_argument("Heap must be 2 or more.");
  }
}

// Heap constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
}

// Heap deconstructor
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return elems.empty();
}

// Size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return elems.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  elems.push_back(item);
  trickleUp(static_cast<int>(elems.size()) - 1);
}
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap.");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return elems[0];
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap.");
  }
  if(elems.size() == 1){
    elems.pop_back();
    return;
  }
  elems[0] = elems.back();
  elems.pop_back();
  trickleDown(0);
}

// Trickle Up function
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int index){
  while(index > 0){
    int parent = (index - 1) / m_;
    if(comp(elems[index], elems[parent])){
      T temp = elems[index];
      elems[index] = elems[parent];
      elems[parent] = temp;
      index = parent;
    }
    else{
      break;
    }
  }
}

// Trickle Down function
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int index){
  while(true){
    int best = index;
    int firstChild = m_ * index + 1;
    for(int i = 0; i < m_; i++){
      int child = firstChild + i;

      if(child < static_cast<int>(elems.size()) && comp(elems[child], elems[best])){
        best = child;
      }
    }
    if (best == index){
      break;
    }
    T temp = elems[index];
    elems[index] = elems[best];
    elems[best] = temp;
    index = best;
  }
}

#endif

