#include <iostream>

#define MAX_HEAP 300

using namespace std;

class Heap{
    public :
        int insert(int );
        int get_size();
        int get_root();
        friend ostream& operator<<(ostream& outputStream, int value[MAX_HEAP]);
        int heap[MAX_HEAP];
    private :
        int heap_size = 0;
};

ostream& operator<<(ostream& out,int value[MAX_HEAP]){
    for(int i=0; value[i]!='\0'; i++){
        out<<value[i] << " ";
    }
}

int Heap::insert(int value){
    if(heap_size==0){
        heap[0] = value;
        heap_size++;
    }
    int low_pos = ++heap_size;
    while(low_pos!=1 && heap[low_pos/2]>value){
        low_pos/=2;
        heap[low_pos*2] = heap[low_pos];
        heap[low_pos] = value;
    }


}