#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct QueueNode {
    int value;
    struct QueueNode *node;
} QueueNode;


QueueNode* front = NULL;
QueueNode* back = NULL;

int size(); 
int is_queue_empty(){
    if(front==NULL){
        return 1;
    }else{
        return 0;
    }
}
void enqueue(int value){
    QueueNode *pushNode = (QueueNode*)malloc(sizeof(QueueNode));
    // if queue is empty not has node
    if(is_queue_empty()){
        pushNode->value = value;
        pushNode->node = NULL;
        front = pushNode;
        back = pushNode;
    }else{
        pushNode->value = value;
        pushNode->node = NULL;
        back->node = pushNode;
        back = pushNode;
        
    }
}
void dequeue(){
    if(is_queue_empty()){
        cout << "queue is empty" << endl;
    }
    else{
        QueueNode* nextNode = front->node; 
        front = nextNode;
    }
}
int size(){
    int count = 0;
    if(is_queue_empty()){
        return count;
    }
    count++;
    for ( QueueNode* qn = front; qn->node!=NULL; qn=qn->node){
        count++;
    }
    return count;

}
void print(){
    cout << front->value << endl;
    cout << front->node->value << endl;
    cout << front->node->node->value << endl;
}

void test(){
}
int main(){
    cout << size() << endl;
    enqueue(32);
    enqueue(332);
    enqueue(12123);
    enqueue(223);
    cout << size() << endl;
    print();
    dequeue();
    print();
    return 0;
}
