#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

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
  std::vector<T> heap_;
  size_t m_;
  PComparator comp_;

  void heapifyUp(size_t index);
  void heapifyDown(size_t index);
	size_t getChildIdx(size_t parentIdx, size_t childIdx) const;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c){}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  heap_.push_back(item);
  heapifyUp(heap_.size() - 1);
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
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else{
    return heap_[0];
  }
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  std::swap(heap_[0], heap_.back());
  heap_.pop_back();
  heapifyDown(0);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return heap_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return heap_.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>:: heapifyUp(size_t index)
{
	while(index > 0){
		size_t parent = (index - 1) / m_;
		if(comp_(heap_[index], heap_[parent]))
		{
			std::swap(heap_[index], heap_[parent]);
			index = parent;
		}
		else{
			break;
		}
	}
}

template <typename T, typename PComparator>
void Heap<T, PComparator>:: heapifyDown(size_t index)
{
	size_t size = heap_.size();
	size_t iterations = 0;
	size_t max = size;
  while(iterations++ < max){
		size_t best = index;

		for(size_t i = 1; i <= m_; i++)
		{
			size_t child = getChildIdx(index, i);
			if(child < size && comp_(heap_[child], heap_[best]))
			{
				best = child;
			}
		}
		if(best != index)
		{
			std::swap(heap_[index], heap_[best]);
			index = best;
		}
		else{break;}
	}
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::getChildIdx(size_t parentIdx, size_t childIdx) const
{
	return m_ * parentIdx + childIdx;
}

#endif