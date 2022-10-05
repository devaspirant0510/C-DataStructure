#pragma once

#include "BTree.hpp"

template<typename T>
class BTree2 : public BTree<T>{
    public:
        bool is_complete_binary_tree(TreeNode<T>*); //TODO : 완전이진트리인지 여부
        int get_node_level(TreeNode<T>*); //TODO : 노드의 레벨
        bool is_balanced(); // TODO : 밸런스한지 (양쪽 서브트리의 높이 차가 1 이하일경우)
        int path_length(); // TODO : 루트부터 모든 자식까지의 경로의 길이 합 
        void reverse(); // TODO : 트리를 좌우 대칭시킴
    private:
        int find_level(TreeNode<T>*,TreeNode<T>*);

};

template<typename T>
bool BTree2<T>::is_complete_binary_tree(TreeNode<T>* node){
    if(node->left_tree !=NULL && node->right_tree != NULL){
        return is_complete_binary_tree(node->left_tree) && is_complete_binary_tree(node->right_tree);
    }
    else if (node->left_tree==NULL && node ->right_tree==NULL){
        return true;
    }
    else{
        return false;
    }
}

template<typename T>
int BTree2<T>::get_node_level(TreeNode<T>*find_node){
    return find_level(this->root,find_node);
}

template<typename T>
int BTree2<T>::find_level(TreeNode<T> *root,TreeNode<T> *find_node){
    if(root==NULL){
        return 0;
    }
    if (root==find_node){
        return 1;
    }

    else{
        int left = find_level(find_node->left_tree,find_node);
        int right = find_level(find_node->right_tree,find_node);
       // if(left==0 && right==0){
         //   return 0;
        //}
        return left>right ?left:right;

    }
}