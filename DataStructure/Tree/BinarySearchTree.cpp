#include<iostream>

#include "BSTree.hpp"

using namespace std;

int main(){
    BSTree<int> bstree;
    int a_v = 4;
    int b_v = 2;
    int c_v = 8;
    TreeNode<int>* b = bstree.create_tree(&b_v,NULL,NULL);
    TreeNode<int>* c = bstree.create_tree(&c_v,NULL,NULL);
    bstree.set_root(&a_v,b,c);

    cout << "result : " <<bstree.search(bstree.root,5)<<endl;
    


    return 0;
}