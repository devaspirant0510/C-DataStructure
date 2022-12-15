#include <iostream>

#define HEAP_SIZE 300
#define MAX_HEAP 1
#define MIN_HEAP 0

using namespace std;

class Heap{
    public :
        Heap(int );
        int insert(int );
        int remove();
        int remove_answer();
        int get_size();
        int get_root();
        friend ostream& operator<<(ostream& outputStream, Heap&);
        int heap[HEAP_SIZE];
    private :
        int heap_size = 0;
        int heap_type = MAX_HEAP;
};
Heap::Heap(int heap_type=MAX_HEAP){
    this->heap_type = heap_type;
}

ostream& operator<<(ostream& out,Heap& heap){
    int s = 1;
    for(int i=1; i<=heap.heap_size; i++){
        if (i==s*2){
            cout << endl;
            s*=2;

        }
        out<<heap.heap[i] << " ";
    }
    return out;
}

int Heap::insert(int value){
    int low_pos = ++(heap_size);
    while(low_pos!=1 && (heap_type==MAX_HEAP?heap[low_pos/2]<value:heap[low_pos/2]>value)){
        heap[low_pos] = heap[low_pos/2];
        low_pos/=2;
    }
    heap[low_pos] = value;
    return 1;
}
int Heap::remove_answer(){
    int parent = 1; int child =2;
    int root,last;
    root = heap[1];
    last = heap[heap_size--];
    while (child<=heap_size){
        if(child<heap_size && heap[child*2]>heap[child*2+1]){
            child++;
        }
        if(last>=heap[child]){
            break;
        }
        heap[parent] = heap[child];
        parent = child;
        child *=2;
    }
    heap[parent] = last;
    return root;
}
int Heap::remove(){
    if(heap_size==0){
        cout << "heap is empty !" << endl;
        exit(1);
    }
    int pos = 1;
    int temp;
    int result = heap[pos];
    heap[pos] = heap[heap_size--];
    while(pos<heap_size){
        if((heap_type==MAX_HEAP?heap[pos*2] > heap[pos*2+1]:heap[pos*2] < heap[pos*2+1])){
            temp = heap[pos*2];
            heap[pos*2] = heap[pos];
            heap[pos] = temp;
            pos*=2;
        }else{
            temp = heap[pos*2+1];
            heap[pos*2+1] = heap[pos];
            heap[pos] = temp;
            pos = pos*2+1;
        }
    }
    return result;
}