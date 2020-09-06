#ifndef PDP_Q3_2020_RBTREE_HPP
#define PDP_Q3_2020_RBTREE_HPP
#include <vector>
enum RBTNodeColor {
    RED,
    BLACK
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
    void AddRule_1(RBTNode *current);
    void AddRule_2(RBTNode *current);
    void AddRule_3(RBTNode *current);
    void AddRule_4(RBTNode *current);
    void AddRule_5(RBTNode *current);
    RBTNode *Find(int element);
    void RemoveElementCheckedRules(RBTNode *removable);
    void RemoveRule_1(RBTNode *removable);
    void RemoveRule_2(RBTNode *removeable);
    void Replace(RBTNode *removable, RBTNode *child);
    void DeleteChild(struct node *n);
    void DeleteChild(RBTNode *removable);
    RBTNode *GetBrother(RBTNode *current);
    void RemoveRule_3(RBTNode *removable);
    void RemoveRule_4(RBTNode *removable);
    void RemoveRule_5(RBTNode *removable);
    void RemoveRule_6(RBTNode *removable);
};

#include "../../src/b_tree/r_b_tree.tpp"
#endif //PDP_Q3_2020_RBTREE_HPP
