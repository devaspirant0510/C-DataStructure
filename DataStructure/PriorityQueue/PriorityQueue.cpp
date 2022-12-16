#include <iostream>
#include "heap.hpp"

using namespace std;

void heap_sort(int *,int);

int main(){
    int N = 10;
    int arr[N];
    for (int i=0; i<N; i++){
        arr[i] = rand()%200;
    }
    heap_sort(arr,N);
}
void heap_sort(int * arr,int n){
    Heap heap = Heap();
    for(int i=0; i<n; i++){
        heap.insert(arr[i]);
    }
    int res_arr[n];
    for(int i=0; i<n; i++){
        int val =heap.remove_answer();
        res_arr[n-i] = val;
       cout <<n-i<<" : "<< val << " " ;
    }
    for(int i=1; i<=n; i++){
         cout << res_arr[i] << " " ;
    }
    cout << endl;

}