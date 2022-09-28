#include <iostream>
#include <cstdlib>
#include "BTree.hpp"

using namespace std;

#define FolderTreeType int

class FolderBTree : public BTree<int>
{
public:
    int get_folder_size(TreeNode<int> *);
};

int FolderBTree::get_folder_size(TreeNode<FolderTreeType> *root)
{
    if(root==NULL){
        return 0;
    }
    return *(root->value)+get_folder_size(root->left_tree)+get_folder_size(root->right_tree);
}

int main()
{
    FolderBTree btree;
    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 67;
    TreeNode<int> *f_tree = btree.create_tree(&f, NULL, NULL);
    TreeNode<int> *e_tree = btree.create_tree(&e, NULL, NULL);
    TreeNode<int> *g_tree = btree.create_tree(&g, NULL, NULL);
    TreeNode<int> *d_tree = btree.create_tree(&d, NULL, g_tree);
    TreeNode<int> *b_tree = btree.create_tree(&b, d_tree, e_tree);
    TreeNode<int> *c_tree = btree.create_tree(&c, f_tree, NULL);
    TreeNode<int> *a_tree = btree.set_root(&a, b_tree, c_tree);

    btree.preorder(btree.root);
    cout << "노드의 개수 : " << btree.count_node(btree.root) << endl;
    cout << "노드의 높이 : " << btree.get_height(btree.root) << endl;
    cout << "폴더 크기 : " << btree.get_folder_size(btree.root) << endl;

    return 0;
}