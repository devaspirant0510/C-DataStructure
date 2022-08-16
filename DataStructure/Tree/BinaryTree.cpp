#include <iostream>
#include <cstdlib>
#include "BTree.hpp"

using namespace std;

int main(){
    BTree<int> btree;
    int a=1,b=2,c=3,d=4,e=5,f=6;
    TreeNode<int>* f_tree = btree.create_tree(&f,NULL,NULL);
    TreeNode<int>* e_tree = btree.create_tree(&e,NULL,NULL);
    TreeNode<int>* d_tree = btree.create_tree(&d,NULL,NULL);
    TreeNode<int>* b_tree= btree.create_tree(&b,d_tree,e_tree);
    TreeNode<int>* c_tree= btree.create_tree(&c,f_tree,NULL);
    TreeNode<int>* a_tree= btree.set_root(&a,b_tree,c_tree);

    btree.preorder(btree.root);
    cout << btree.count_node(btree.root) << endl;

    return 0;
}