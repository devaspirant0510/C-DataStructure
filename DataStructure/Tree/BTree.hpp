#pragma once

#include<iostream>
#include <queue>

using namespace std;

template<typename T>
struct TreeNode{
    T* value;
    TreeNode* left_tree;
    TreeNode* right_tree;
};

template<typename T>
class BTree{
    public:
        TreeNode<T>* create_tree(T*,TreeNode<T>*,TreeNode<T>*);
        TreeNode<T>* set_root(T*,TreeNode<T>*,TreeNode<T>*);
        TreeNode<T>* ct(T,TreeNode<T>*,TreeNode<T>*);
        bool is_empty();
        int count_node(TreeNode<T>* node); // 노드 개수
        int count_edge(); // 간선 개수
        int count_leaf(); // 단말노드 개수
        int get_height(TreeNode<T>*); // 트리 높이
        void preorder(TreeNode<T>*); // 전위 순회 VLR
        void inorder(TreeNode<T>*); // 중위 순회 LVR
        void postorder(TreeNode<T>*); // 후위 순회 LRV
        void print_tree(TreeNode<T>*);
        void print2_tree();
        TreeNode<T>* root = NULL;
    private:
        int temp_node[1000];

};
template<typename T>
TreeNode<T>* BTree<T> ::ct(T v,TreeNode<T>*l,TreeNode<T>* r){
    create_tree(&v,l,r);

}

template<typename T>
int BTree<T>::get_height(TreeNode<T>* node){
    if (node==NULL){
        return 0;
    }
    int left_node_height = get_height(node->left_tree);
    int right_node_height = get_height(node->right_tree);
    return (left_node_height>right_node_height)?left_node_height+1:right_node_height+1;
}

template<typename T>
TreeNode<T>* BTree<T>::create_tree(T* value,TreeNode<T>* left_node,TreeNode<T>* right_node){
    TreeNode<T>* make_tree = new TreeNode<T>;
    make_tree->value = value;
    make_tree->left_tree = left_node;
    make_tree->right_tree = right_node;
    return make_tree;
}

template<typename T>
TreeNode<T>* BTree<T>::set_root(T*value,TreeNode<T>* left_node,TreeNode<T>* right_node){
    TreeNode<T>* make_tree = new TreeNode<T>;
    make_tree->value = value;
    make_tree->left_tree = left_node;
    make_tree->right_tree = right_node;
    root = make_tree;
    return root;
}

template<typename T>
void BTree<T>::preorder(TreeNode<T>* node){
    if(node!=NULL){
        cout << *(node->value) << endl;
        preorder(node->left_tree);
        preorder(node->right_tree);
    }
}

template<typename T>
void BTree<T>::inorder(TreeNode<T>* node){
    if(node!=NULL){
        preorder(node->left_tree);
        cout << *(node->value) << endl;
        preorder(node->right_tree);
    }
}

template<typename T>
void BTree<T>::postorder(TreeNode<T>* node){
    if(node!=NULL){
        preorder(node->left_tree);
        preorder(node->right_tree);
        cout << *(node->value) << endl;
    }
}

template<typename T>
int BTree<T>::count_node(TreeNode<T> *node){
    if(node==NULL){
        return 0;
    }
    return 1+count_node(node->left_tree) + count_node(node->right_tree);
}
template<typename T>
void BTree<T>::print_tree(TreeNode<T> *node){
    if(node==NULL){
        return;
    }
    cout << *(node->value) << endl;
    print_tree(node->left_tree);
    print_tree(node->right_tree);

}

template<typename T>
void BTree<T>::print2_tree(){
    queue<TreeNode<T>*> qu;
    qu.push(this->root);
    TreeNode<T>* n;
    while(!qu.empty()){
        n = qu.front();
        qu.pop();
        
        if(n!=NULL){
            cout << *(n->value) << " " ;
            qu.push(n->left_tree);
            qu.push(n->right_tree);
        }else{
            cout << ". ";
        }

    }
    cout << endl;


}