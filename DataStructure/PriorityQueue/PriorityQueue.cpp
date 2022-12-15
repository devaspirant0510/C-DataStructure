#include <iostream>
#include "heap.hpp"

using namespace std;

int main(){
    Heap heap = Heap(MIN_HEAP);
    heap.insert(2);
    heap.insert(3);
    heap.insert(6);
    heap.insert(8);
    heap.insert(1);
    heap.insert(9);
    heap.insert(-1);

    // cout << heap.heap[1] << heap.heap[2] << heap.heap[3] << endl;
    //cout << heap << endl;

    cout << heap.remove();
    cout << heap.remove();
    cout << heap.remove();
    cout << heap.remove();
    cout << heap.remove();
    cout << heap.remove();
    cout << heap.remove();

}