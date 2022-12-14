#include <iostream>
#include "heap.hpp"

using namespace std;

int main(){
    Heap heap = Heap();
    heap.insert(2);
    heap.insert(3);

    cout << heap.heap[0] << heap.heap[1] << endl;
//std::cout << heap.heap << endl;

}