#include "BTree.hpp"

template<typename T>
class BTree2 : public BTree<T>{
    public:
        bool is_complete_binary_tree(); //TODO : 완전이진트리인지 여부
        int get_node_level(TreeNode<T>*); //TODO : 노드의 레벨
        bool is_balanced(); // TODO : 밸런스한지 (양쪽 서브트리의 높이 차가 1 이하일경우)
        int path_length(); // TODO : 루트부터 모든 자식까지의 경로의 길이 합 
        void reverse(); // TODO : 트리를 좌우 대칭시킴


};
