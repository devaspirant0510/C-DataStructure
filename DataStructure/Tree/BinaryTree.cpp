#include <iostream>
#include <cstdlib>
#include "BTree.hpp"
#include "BTree2.hpp"

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
    BTree2<int> btree;
    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 67, h=11;
    TreeNode<int> *f_tree = btree.create_tree(&f, NULL, NULL);
    TreeNode<int> *e_tree = btree.create_tree(&e, NULL, NULL);
    TreeNode<int> *g_tree = btree.create_tree(&g, NULL, NULL);
    TreeNode<int> *d_tree = btree.create_tree(&d, NULL, NULL);
    TreeNode<int> *b_tree = btree.create_tree(&b, d_tree, e_tree);
    TreeNode<int> *c_tree = btree.create_tree(&c, f_tree, g_tree);
    TreeNode<int> *a_tree = btree.set_root(&a, b_tree, c_tree);

    btree.preorder(btree.root);
    cout << "노드의 개수 : " << btree.count_node(btree.root) << endl;
    cout << "노드의 높이 : " << btree.get_height(btree.root) << endl;
    cout << "이진트리인가요? : " << btree.is_complete_binary_tree(btree.root) << endl;
    cout << "f_tree는 몇층에 있게요? : " << btree.get_node_level(f_tree) << endl;
    //cout << "폴더 크기 : " << btree.get_folder_size(btree.root) << endl;

    return 0;
}