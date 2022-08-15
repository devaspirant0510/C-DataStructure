#include <iostream>
#include <cstdlib>
#include "BTree.hpp"


int main(){
    BTree<int> btree;
    int a=1,b=2,c=3;
    TreeNode<int>* b_tree= btree.create_tree(&b,NULL,NULL);
    TreeNode<int>* c_tree= btree.create_tree(&c,NULL,NULL);
    TreeNode<int>* a_tree= btree.set_root(&a,b_tree,c_tree);
    std::cout << *(btree.root->value) << std::endl;
    std::cout << *(btree.root->left_tree->value) << std::endl;
    std::cout << *(btree.root->right_tree->value) << std::endl;



    return 0;
}