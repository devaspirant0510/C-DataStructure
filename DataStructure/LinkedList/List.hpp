#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
struct Node{
    T value;
    struct Node *next;
};

template<typename T>
class LinkedList{
    public:
        void print_list();//;
        void insert_list(int,T);
        void insert_list(T);
        T remove_list(int);
        T pop_list();
        int find_list(T);
        T get_list(int);
        int get_size();
    private:
        Node<T> *header;
};


template<typename T>
int LinkedList<T>::get_size(){
    int size = 0;
    Node<T> *temp_header = header;
    while(temp_header!=NULL){
        temp_header=temp_header->next;
        size++;
    }
    return size;
}

template<typename T>
T LinkedList<T>::get_list(int index){
    Node<T>* temp_header = header;
    for(int i=0; i < index; i++){
        temp_header = temp_header->next;
    }
    return temp_header->value;
}

template<typename T>
void LinkedList<T>::insert_list(int index,T value){
    if(index<0 || index>get_size()){
        cout << "out of index exception" << endl;
        return;
    }
    if(get_size()==0){
        Node<T> *make_value =(Node<T>*) malloc(sizeof(Node<T>));
        make_value->value = value; 
        make_value->next = NULL;
        header = make_value;
        cout << header->value ;
        return;
    }
    if(index==0){
        Node<T> *make_value =(Node<T>*) malloc(sizeof(Node<T>));
        make_value->value = value; 
        make_value->next = header;
        header = make_value;
        return;
    }
    Node<T> *temp_header = header;
    for (int i=0; i< index-1;i++){
        temp_header = temp_header->next;
    }
    Node<T> *make_value =(Node<T>*) malloc(sizeof(Node<T>));
    make_value->value = value; 
    make_value->next = temp_header->next;
    temp_header->next = make_value;
}
template<typename T>
T LinkedList<T>::remove_list(int index){
    Node<T> *temp_header = header;
    for (int i=0; i < index-1; i++){
        temp_header = temp_header->next;
    }
    Node<T> *next_value = temp_header->next;
    int result = next_value->value;
    temp_header->next = next_value->next; 
    return result;
}

template<typename T>
void LinkedList< T>:: print_list(){
    for(Node<T>* i=header; i!=NULL; i=i->next){
        cout << " | " << i->value << " | " << endl;
    }
}
