#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct StackEl {
    int el;
    struct StackEl* address;

} StackEl;
StackEl *header = NULL;
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
        StackEl *temp = header;
        while(1){
            if(temp->address==NULL){
                cout << " | " <<  temp->el << " | " << endl;
                cout << " ----------" << endl;
                break;
            }
            cout << " | " <<  temp->el << " | " << endl;
            temp = temp->address;

        }
    }
    else{
        cout << "stack is empty" << endl;
    }
}
void stack_test(){
    cout << " this is stack test program " << endl;
    int user_key;
    while(1){
        cout << "0:exit \t 1:push \t 2:pop \t 3:print "<< endl << endl;
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
        }else{
            cout << "error" << endl;
        }
        continue;

    }
}
int main(){
    stack_test();
    return 1;
}
