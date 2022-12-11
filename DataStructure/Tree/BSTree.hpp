#include <iostream>

#include "BTree.hpp"

using namespace std;

template<typename T>
class BSTree:public BTree<T>{
    public:
        int search(TreeNode<T>*,T);
        int insert(TreeNode<T>*,TreeNode<T>*);
        int test_insert(TreeNode<T>*,T);
        int remove(TreeNode<T>*, T);

    private:
        int insert_refer(TreeNode<T>*,T&);
        TreeNode<T>** search_return(TreeNode<T>*,TreeNode<T>*,T);
};

template<typename T>
int BSTree<T>::remove(TreeNode<T>* root,T value){
    TreeNode<T>** result = search_return(root,root,value);
    TreeNode<T>* ro = *result;
    TreeNode<T>* pa = *(result +1);
    TreeNode<T>* del_tree;
    cout << "root : " <<*(ro->value) << endl;
    cout << "parent : " <<*(pa->value) << endl;
    if(ro->left_tree==NULL && ro->right_tree==NULL){
        if(*(pa->value)>*(ro->value)){
            del_tree = pa->left_tree;
            //delete del_tree;
            pa->left_tree = NULL;
        }else{
            del_tree = pa->right_tree;
            //delete del_tree;
            pa->right_tree = NULL;
        }
    }
    else if(ro->left_tree!=NULL || ro->right_tree!=NULL){
        if(ro->left_tree!=NULL){
            del_tree = pa->left_tree;
            pa->left_tree = pa->left_tree->left_tree; 
            delete del_tree;
        }else if(ro->right_tree!=NULL){
            del_tree = pa->right_tree;
            pa->right_tree = pa->right_tree->right_tree; 
            delete del_tree;
        }
    }
    else if(ro->left_tree!=NULL && ro->right_tree!=NULL){
        TreeNode<T>*st_node = ro->left_tree;
        while(st_node!=NULL){
            st_node=st_node->left_tree;
        }
        cout << *(st_node->value) << endl;


    }
    return 1;
}
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
TreeNode<T>** BSTree<T>::search_return(TreeNode<T>* root,TreeNode<T>*parent,T value){
    
    if(root==NULL || parent==NULL){
        return NULL;
    }
    if(*(root->value)==value){
        TreeNode<T>** result = new TreeNode<T>*[2];
        result[0] = root; 
        result[1] = parent;
        cout << root->value << endl;
        cout << parent->value << endl;
        return result;
    }
    else if(*(root->value)>value){
        return search_return(root->left_tree,root,value);
    }else{
        return search_return(root->right_tree,root,value);
    }
}
template<typename T>
int BSTree<T>::insert_refer(TreeNode<T>* r,T&val){
    TreeNode<T>* temp = this->root;
    //validation
    if(search(r,val)){
        return -1;
    }

    while (temp!=NULL){
        if (*(temp->value)<val){
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
    TreeNode<T>* t = new TreeNode<T>;
    t->value = &val;
    t->left_tree = NULL;
    t->right_tree = NULL;
    if(*(temp->value)<val ){

        temp->right_tree = t;
    }else{
        temp->left_tree = t;
    }
    return val;

}
template<typename T>
int BSTree<T>::test_insert(TreeNode<T>* r,T val){
    int* a = new int;
    *a = val; 
    insert_refer(r,*a);
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
        
        temp->right_tree = v;
    }else{
        temp->left_tree = v;
    }
    return 1;
    


}
