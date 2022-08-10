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
        LinkedList();
        void init_list();
        void print_list();//;
        T insert_list(int,T);
        void insert_list(T);
        void change_list(int,T);
        T remove_list(int);
        T pop_list();
        T dequeue_list();
        int find_list(T);
        T get_list(int);
        int get_size();
    private:
        Node<T> *header;
        int valid_index(int);
};

template<typename T>
int LinkedList<T>::valid_index(int index){
    if(index<0 || index >= get_size()){
        return 0;
    }
    return 1;
}

template<typename T>
LinkedList<T>::LinkedList(){
    header = NULL;
}

template<typename T>
int LinkedList<T>::get_size(){
    int size = 0;
    Node<T> *temp_header = header;
    cout << temp_header;
    while(temp_header!=NULL){
        temp_header=temp_header->next;
        size++;
    }
    return size;
}

template<typename T>
int LinkedList<T>::find_list(T find_value){
    int pos = 0;
    for(Node<T>* i = header; i!=NULL; i=i->next){
        if(find_value==i->value){
            return pos;
        }
        pos++;
    }
    cout << "not found.."<< endl;
    return -1;
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
T LinkedList<T>::insert_list(int index,T value){
    if(valid_index(index)){
        cout << "out of index exception" << endl;
        return -123124;
    }
    if(get_size()==0){
        Node<T> *make_value =(Node<T>*) malloc(sizeof(Node<T>));
        make_value->value = value; 
        make_value->next = NULL;
        header = make_value;
        return make_value->value;
    }
    if(index==0){
        Node<T> *make_value =(Node<T>*) malloc(sizeof(Node<T>));
        make_value->value = value; 
        make_value->next = header;
        header = make_value;
        return make_value->value;
    }
    Node<T> *temp_header = header;
    for (int i=0; i< index-1;i++){
        temp_header = temp_header->next;
    }
    Node<T> *make_value =(Node<T>*) malloc(sizeof(Node<T>));
    make_value->value = value; 
    make_value->next = temp_header->next;
    temp_header->next = make_value;
    return make_value->value;
}

template<typename T>
T LinkedList<T>::pop_list(){
    Node<T>* temp_header;
    for (Node<T>* i = header; i->next!=NULL; i=i->next){
        temp_header = i;
    }
    Node<T>* remove_node = temp_header->next;
    T result_value = remove_node->value;
    free(remove_node);
    temp_header->next = NULL;
    return result_value;
}

template <typename T>
T LinkedList<T>::dequeue_list(){
    Node<T> *del_node = header;
    header = header->next;
    T result = del_node->value;
    free(del_node);
    return result;
}

template<typename T>
T LinkedList<T>::remove_list(int index){
    if(index<0 || index>get_size()){
        cout << "out of index exception" << endl;
        return -12334;
    }
    if(index==0){
        
        return dequeue_list();
    }
    if(index==get_size()-1){
        
        return pop_list();
    }
    
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
void LinkedList<T>::change_list(int index, T value){
    if(index > get_size()){
        cout << "out of index" << endl;
        return;
    }
    Node<T>* temp_header = header;
    for(int i=0; i <index; i++){
        temp_header = temp_header->next;
    }
    temp_header->value = value;
}

template<typename T>
void LinkedList< T>:: print_list(){
    for(Node<T>* i=header; i!=NULL; i=i->next){
        cout << " | " << i->value << " | " << endl;
    }
}
