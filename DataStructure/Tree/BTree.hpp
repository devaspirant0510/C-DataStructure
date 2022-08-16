#include<iostream>

using namespace std;

template<typename T>
struct TreeNode{
    T* value;
    TreeNode* left_tree;
    TreeNode* right_tree;
};

template<typename T>
class BTree{
    public:
        TreeNode<T>* create_tree(T*,TreeNode<T>*,TreeNode<T>*);
        TreeNode<T>* set_root(T*,TreeNode<T>*,TreeNode<T>*);
        bool is_empty();
        int count_node(TreeNode<T>* node); // 노드 개수
        int count_edge(); // 간선 개수
        int count_leaf(); // 단말노드 개수
        void preorder(TreeNode<T>*); // 전위 순회 VLR
        void inorder(TreeNode<T>*); // 중위 순회 LVR
        void postorder(TreeNode<T>*); // 후위 순회 LRV
        void print_tree();
        TreeNode<T>* root = NULL;
    private:

};

template<typename T>
TreeNode<T>* BTree<T>::create_tree(T* value,TreeNode<T>* left_node,TreeNode<T>* right_node){
    TreeNode<T>* make_tree = new TreeNode<T>;
    make_tree->value = value;
    make_tree->left_tree = left_node;
    make_tree->right_tree = right_node;
    return make_tree;
}

template<typename T>
TreeNode<T>* BTree<T>::set_root(T*value,TreeNode<T>* left_node,TreeNode<T>* right_node){
    TreeNode<T>* make_tree = new TreeNode<T>;
    make_tree->value = value;
    make_tree->left_tree = left_node;
    make_tree->right_tree = right_node;
    root = make_tree;
    return root;
}

template<typename T>
void BTree<T>::preorder(TreeNode<T>* node){
    if(node!=NULL){
        cout << *(node->value) << endl;
        preorder(node->left_tree);
        preorder(node->right_tree);
    }
}

template<typename T>
void BTree<T>::inorder(TreeNode<T>* node){
    if(node!=NULL){
        preorder(node->left_tree);
        cout << *(node->value) << endl;
        preorder(node->right_tree);
    }
}

template<typename T>
void BTree<T>::postorder(TreeNode<T>* node){
    if(node!=NULL){
        preorder(node->left_tree);
        preorder(node->right_tree);
        cout << *(node->value) << endl;
    }
}

template<typename T>
int BTree<T>::count_node(TreeNode<T> *node){
    if(node==NULL){
        return 0;
    }
    return 1+count_node(node->left_tree) + count_node(node->right_tree);
}
template<typename T>
void BTree<T>::print_tree(){
}