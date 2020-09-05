#ifndef PDP_Q3_2020_RBTREE_HPP
#define PDP_Q3_2020_RBTREE_HPP
#include <vector>
enum RBTNodeColor {
    RED,
    BLACK,
    NIL
};

enum CildSides{
    IS_LEFT,
    IS_RIGHT,
    IS_NIL
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

struct RBTNodeToAddCheckingData{
    RBTNode *parent_;
    RBTNode *uncle_;
    RBTNode *grand_p;

    CildSides parentS_side_;
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
    void CheckForAddToRBTRulles(RBTNode *pNode);
    std::vector<RBTNode*> GetToAddCheckData(RBTNode *pNode);

    RBTNode *GetParent(RBTNode *pNode);

    RBTNode *GetUncle(RBTNode *pNode);

    RBTNode *GetGrandP(RBTNode *pNode);

    CildSides GetParentSide(RBTNode *pNode);

    void RotateToLeft(RBTNode *current);

    void RotateToRight(RBTNode *current);
};



#include "../../src/b_tree/r_b_tree.tpp"
#endif //PDP_Q3_2020_RBTREE_HPP
