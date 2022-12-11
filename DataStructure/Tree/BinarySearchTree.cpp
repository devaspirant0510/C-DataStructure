#include<iostream>

#include "BSTree.hpp"

using namespace std;

struct s{
    int a;
    s* refer;
};
int ** arr2r(){
    int **a = new int*[10];
    int a1 = 3;
    a[0] = &a1;
    return a;
}
int main(){
    BSTree<int> bstree;
    int a_v = 10;
    int b_v = 2;
    int c_v = 8;
    TreeNode<int>* aaa = bstree.ct(1,NULL,NULL);
    TreeNode<int>* b = bstree.create_tree(&b_v,NULL,NULL);
    TreeNode<int>* c = bstree.create_tree(&c_v,NULL,NULL);
    bstree.set_root(&a_v,b,c);
    bstree.print2_tree();
    int insert_ = 1;
    TreeNode<int>* insert_val = bstree.create_tree(&insert_,NULL,NULL);
    bstree.insert(bstree.root,insert_val);
    bstree.print2_tree();
    bstree.test_insert(bstree.root,4);
    bstree.print2_tree();
    bstree.test_insert(bstree.root,6);
    bstree.print2_tree();
    bstree.test_insert(bstree.root,11);
    bstree.print2_tree();
    //bstree.remove(bstree.root,8);
    return 0;
}