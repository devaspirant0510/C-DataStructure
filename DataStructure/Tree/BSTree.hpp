#include <iostream>

#include "BTree.hpp"

using namespace std;

template<typename T>
class BSTree:public BTree<T>{
    public:
        int search(TreeNode<T>*,T);
        int insert(TreeNode<T>*,TreeNode<T>*);

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

template<typename T>
int BSTree<T>::insert(TreeNode<T>* r,TreeNode<T>* v){
    /*if(*(r->value)==*(v->value)){
        return 0;
    }
    if(*(r->value)>*(v->value)){
        if(r->left_tree!=NULL){
            insert(r->left_tree,v);
        }else{
            r->left_tree = v;
        }
    }else{
        if(r->right_tree!=NULL){
            insert(r->right_tree,v);
        }else{
            r->left_tree = v;
        }

    }*/

    TreeNode<T>* temp = this->root;
    //validation
    if(search(r,*(v->value))){
        return -1;
    }

    while (temp!=NULL){
        if (*(temp->value)<*(v->value)){
            if(temp->right_tree!=NULL){
                temp = temp->right_tree;    
            }else{
                break;
            }
        }else{
            if(temp->left_tree!=NULL){
                temp = temp->left_tree; 
            }else{
                break;
            }
        }

    }
    if(*(temp->value)<*(v->value) ){
        
        TreeNode<T>* t = new TreeNode<T>;
        t->value = v->value;
        t->left_tree = NULL;
        t->right_tree = NULL;
        temp->right_tree = t;
    }else{
        TreeNode<T>* t = new TreeNode<T>;
        t->value = v->value;
        t->left_tree = NULL;
        t->right_tree = NULL;
        temp->left_tree = t;
    }
    return 1;
    


}
