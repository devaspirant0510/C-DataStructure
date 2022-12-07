#include<iostream>

#include "BSTree.hpp"

using namespace std;

int main(){
    BSTree<int> bstree;
    int a_v = 4;
    int b_v = 2;
    int c_v = 8;
    TreeNode<int>* aaa = bstree.ct(1,NULL,NULL);
    TreeNode<int>* b = bstree.create_tree(&b_v,NULL,NULL);
    TreeNode<int>* c = bstree.create_tree(&c_v,NULL,NULL);
    bstree.set_root(&a_v,b,c);
    //bstree.print_tree(bstree.root);
    int insert_ = 10;
    TreeNode<int>* insert_val = bstree.create_tree(&insert_,NULL,NULL);
    bstree.insert(bstree.root,insert_val);
    cout << "1:  " << *(bstree.root->value) << endl ;
    cout << "2:  " << *(bstree.root->left_tree->value) << endl ;
    cout << "3:  " << *(bstree.root->left_tree->left_tree->value) << endl ;
    //cout << "2:  " << *(bstree.root->left_tree->left_tree->value) << endl ;
    bstree.print_tree(bstree.root);

    cout << "result : " <<bstree.search(bstree.root,1)<<endl;
    


    return 0;
}