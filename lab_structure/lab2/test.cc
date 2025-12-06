#include <iostream>
#include "queue.h"

int main() {
  DynamicArray<int>arr(10);
  
  
  arr.push_back(202);
  arr.push_back(206);
  arr.push_back(207);
  arr.push_back(208);
  arr.push_back(209);
  arr.push_front(200);
  std::cout<<arr.front()<<std::endl;
  std::cout<<arr.back()<<std::endl;
  arr.dele_te(0);
  arr.erase_after(2);
  std::cout<<arr.front()<<std::endl;

  Queue<char> q(12);
  q.enqueue('j');
  q.enqueue('k');
  std::cout<<q.dequeue()<<std::endl;
  

  Stack<int>s(10);
  s.push(10);
  s.push(20);
  std::cout<<s.pop()<<std::endl;


  


  
  
  
}
