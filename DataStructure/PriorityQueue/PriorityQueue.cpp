#include <iostream>
#include "heap.hpp"

using namespace std;

int main(){
    Heap heap = Heap();
    heap.insert(2);

std::cout << heap.heap << endl;

}