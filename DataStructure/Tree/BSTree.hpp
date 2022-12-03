#include <iostream>

#include "BTree.hpp"

using namespace std;

template<typename T>
class BSTree:public BTree<T>{
    public:
        int search(TreeNode<T>*,T);

    private:
};

template<typename T>
int BSTree<T>::search(TreeNode<T>* root,T value){
    if(root==NULL){
        return NULL;
    }
    if(*(root->value)==value){
        return 1;
    }
    else if(*(root->value)>value){
        return search(root->left_tree,value);
    }else{
        return search(root->right_tree,value);
    }
}
