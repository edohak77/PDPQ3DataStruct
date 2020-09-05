#include "../../include/b_tree/r_b_tree.hpp"

RBTNode::RBTNode(int data) {
    data_ = data;
    color_ = RED;
    l_child_ = nullptr;
    r_child_ = nullptr;
    parent_ = nullptr;
}

RBTNode::~RBTNode() {
    delete l_child_;
    delete r_child_;
    delete parent_;
}

RBTree::RBTree() : root_(nullptr), size_(0) {}

void RBTree::Add(int element) {
    if (size_ == 0) {
        root_ = new RBTNode(element);
        root_->color_ = BLACK;
    } else {
        RBTNode *new_nod = new RBTNode(element);
        RBTNode *current = SetToPosition(element);
        CheckForAddToRBTRulles(current);
    }

    size_++;
}

void RBTree::Remove(int element) {

}

bool RBTree::Contains(int element) {
    return false;
}

bool RBTree::isRoot(RBTNode *node) {
    return node->parent_ == nullptr;
}

int RBTree::Size() {
    return size_;
}

RBTNode *RBTree::SetToPosition(int element) {
    RBTNode *current = root_;
    RBTNode *current_prev = current;

    while (current != nullptr) {
        current_prev = current;
        if (element >= current->data_) {
            current = current->r_child_;
        } else {
            current = current->l_child_;
        }
    }

    current = new RBTNode(element);
    current->parent_ = current_prev;
    if (current->data_ < current_prev->data_) {
        current_prev->l_child_ = current;
    } else {
        current_prev->r_child_ = current;
    }

    return current;
}

void RBTree::CheckForAddToRBTRulles(RBTNode *current) {

    RBTNode *parent = current->parent_;
    RBTNode *g_parent = current->parent_->parent_;
    RBTNode *uncle = nullptr;
    CildSides my_side = IS_RIGHT;

    if (parent->l_child_ != nullptr && current == parent->l_child_) {
        my_side = IS_LEFT;
    }

    if (GetParentSide(current) == IS_LEFT) {
        if (g_parent->r_child_ != nullptr) {
            uncle = g_parent->r_child_;
        }
    } else if (GetParentSide(current) == IS_RIGHT) {
        if (g_parent->l_child_ != nullptr) {
            uncle = g_parent->l_child_;
        }
    } else {
        uncle = nullptr;
    }

    if (parent->color_ == BLACK) {
        return;
    }

//    case3 for Add functionality-> if parent's color is red and uncle's color is red
    if (g_parent != nullptr) {

        if (parent->color_ == RED && uncle != nullptr && uncle->color_ == RED) {
            parent->color_ = BLACK;
            uncle->color_ = BLACK;
            g_parent->color_ = RED;

            if (isRoot(g_parent)) {
                g_parent->color_ = BLACK;
            } else {
                CheckForAddToRBTRulles(g_parent);
            }

//    case 4 for Add functionality-> if parent's color is red and uncle's color is black
        } else if (parent->color_ == RED) {
            if (uncle == nullptr || uncle->color_ == BLACK) {
                // case 4.1 when current node is right child and his parent is left child
                if (my_side == IS_RIGHT && GetParentSide(current) == IS_LEFT) {
                    RotateToLeft(current);
                    CheckForAddToRBTRulles(current->l_child_);
                    // case 4.1 when current node is left child and his parent is left child
                } else if (my_side == IS_LEFT && GetParentSide(current) == IS_LEFT) {
                    RotateToRight(current);
                }
            }
        }
    }
}

std::vector<RBTNode *> RBTree::GetToAddCheckData(RBTNode *current) {
    std::vector<RBTNode *> data;
//    RBTNodeToAddCheckingData data;

    data.push_back(GetParent(current));
    data.push_back(GetUncle(current));
    data.push_back(GetGrandP(current));

    return data;
}

RBTNode *RBTree::GetParent(RBTNode *pNode) {
    if (isRoot(pNode)) {
        return nullptr;
    }
    return pNode->parent_;
}

RBTNode *RBTree::GetUncle(RBTNode *pNode) {
    if (isRoot(pNode)) {
        return nullptr;
    }

    if (pNode == pNode->parent_->l_child_) {
        if (pNode->parent_->r_child_ == nullptr) {
            return nullptr;
        }
        return pNode->parent_->r_child_;
    } else {
        if (pNode->parent_->l_child_ == nullptr) {
            return nullptr;
        }
        return pNode->parent_->l_child_;
    }

}

RBTNode *RBTree::GetGrandP(RBTNode *pNode) {
    if (isRoot(pNode)) {
        return nullptr;
    }

    if (pNode->parent_->parent_ == nullptr) {
        return nullptr;
    }

    return pNode->parent_->parent_;
}

CildSides RBTree::GetParentSide(RBTNode *pNode) {

    if (isRoot(pNode->parent_)) {
        return IS_NIL;
    }

    if (pNode == pNode->parent_->l_child_) {
        return IS_LEFT;
    }

    return IS_RIGHT;
}

void RBTree::RotateToLeft(RBTNode *current) {
    RBTNode *parent = current->parent_;
    RBTNode *g_parent = current->parent_->parent_;
    RBTNode *uncle;

    if (GetParentSide(current) == IS_LEFT) {
        if (g_parent->r_child_ != nullptr) {
            uncle = g_parent->r_child_;
        }
    } else if (GetParentSide(current) == IS_RIGHT) {
        if (g_parent->l_child_ != nullptr) {
            uncle = g_parent->l_child_;
        }
    } else {
        uncle = nullptr;
    }


    current->parent_ = g_parent;
    g_parent->l_child_ = current;

    RBTNode *new_node = parent;
    current->l_child_ = new_node;
    new_node->parent_ = current;

    delete parent;

    parent = new_node;
}

void RBTree::RotateToRight(RBTNode *current) {

    RBTNode *parent = current->parent_;
    RBTNode *g_parent = current->parent_->parent_;
    RBTNode *uncle;

    if (GetParentSide(current) == IS_LEFT) {
        if (g_parent->r_child_ != nullptr) {
            uncle = g_parent->r_child_;
        }
    } else if (GetParentSide(current) == IS_RIGHT) {
        if (g_parent->l_child_ != nullptr) {
            uncle = g_parent->l_child_;
        }
    } else {
        uncle = nullptr;
    }


    RBTNode *temp_g_parent = g_parent;

    g_parent->parent_ = parent;
    parent->r_child_ = g_parent;

    if (isRoot(parent)) {
        parent->color_ = BLACK;
    }
}
