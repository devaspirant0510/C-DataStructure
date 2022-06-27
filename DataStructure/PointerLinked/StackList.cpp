#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct StackEl {
    int el;
    struct StackEl* address;

} StackEl;
StackEl *header = NULL;

int size(){
    int count = 0;
    for (StackEl* node = header; node!=NULL; node=node->address){
        count++;
    }
    return count;
}
void push(int value){
    // define push value
    StackEl *push_value = (StackEl*)malloc(sizeof(StackEl));
    // Node Struct setting int value, pointer 
    // stack`s value is top of value then, previous node has current node
    push_value->el = value;
    push_value->address = header;
    header = push_value;
}
int pop(){
    StackEl *prevNode = header->address;
    int pop_value = header->el;
    header = prevNode;
    return pop_value;
}
int is_stack_empty(){
    if(header==NULL){
        return 1;
    }else{
        return 0;
    }
}

void print_stack(){
    if(!is_stack_empty()){
        for (StackEl* node = header; node!=NULL; node=node->address){
            cout << " | " << node->el << " | " << endl;
        }
        cout << "------" << endl;
    }
    else{
        cout << "stack is empty" << endl;
    }
}
void stack_test(){
    cout << " this is stack test program " << endl;
    int user_key;
    while(1){
        cout << "0:exit \t 1:push \t 2:pop \t 3:print \t 4:size "<< endl << endl;
        cout << "press key... ";
        cin >> user_key;
        if(user_key==0){
            cout << "exit program" << endl;
            break;
        }
        else if (user_key==1){
            int push_val;
            cout << "write push value... ";
            cin >> push_val;
            push(push_val);
        }else if (user_key==2){
            cout <<"pop value is "<<pop()<< endl << endl;
        }else if (user_key==3){
            print_stack();
            cout << endl;
        }else if (user_key==4){
            cout << size() << endl << endl;

        }
        else{
            cout << "error" << endl;
        }
        continue;

    }
}
int main(){
    stack_test();
    return 1;
}
