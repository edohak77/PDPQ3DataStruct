#ifndef PDP_Q3_2020_RBTREE_HPP
#define PDP_Q3_2020_RBTREE_HPP
#include <vector>
enum RBTNodeColor {
    RED,
    BLACK,
};

struct RBTNode {
    int data_;
    RBTNodeColor color_;
    RBTNode *l_child_;
    RBTNode *r_child_;
    RBTNode *parent_;

    RBTNode(int data);
    ~RBTNode();
};

class RBTree {
public:
    void Add(int element);
    void Remove(int element);
    bool Contains(int element);
    int Size();

    RBTree();

private:
    RBTNode *root_;
    int size_;
    bool isRoot(RBTNode *node);
    RBTNode *SetToPosition(int element);
    void CheckForAddToRBTRules(RBTNode *current);
    RBTNode *GetUncle(RBTNode *pNode);
    RBTNode *GetGrandP(RBTNode *pNode);
    void RotateToLeft(RBTNode *current);
    void RotateToRight(RBTNode *current);
    void Rule_1(RBTNode *current);
    void Rule_2(RBTNode *current);
    void Rule_3(RBTNode *current);
    void Rule_4(RBTNode *current);
    void Rule_5(RBTNode *current);
};



#include "../../src/b_tree/r_b_tree.tpp"
#endif //PDP_Q3_2020_RBTREE_HPP
