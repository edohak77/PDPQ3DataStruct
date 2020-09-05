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
        RBTNode *current = SetToPosition(element);
        CheckForAddToRBTRules(current);
    }

    size_++;
}

void RBTree::Remove(int element) {
    RBTNode *removable = Find(element);
    if(removable == nullptr){
        throw "Can't find element: " + std::to_string(element) + " for remove";
    }

    RemoveElementCheckedRules(removable);

}

bool RBTree::Contains(int element) {
    return Find(element) != nullptr;
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

void RBTree::AddRule_1(RBTNode *current){
    if (current -> parent_ == nullptr){
        current->color_ = BLACK;
    } else {
        AddRule_2(current);
    }
}

void RBTree::AddRule_2(RBTNode *current){
    if (current->parent_->color_ == BLACK){
        return;
    } else {
        AddRule_3(current);
    }
}

void RBTree::AddRule_3(RBTNode *current) {
    RBTNode *uncle = GetUncle(current);

    if ((uncle != nullptr) && (uncle->color_ == RED)) {
        current->parent_->color_ = BLACK;
        uncle->color_ = BLACK;
        RBTNode *gParent = GetGrandP(current);
        gParent->color_ = RED;
        AddRule_1(gParent);
    } else {
        AddRule_4(current);
    }
}

void RBTree::AddRule_4(RBTNode *current) {
    RBTNode *gParent = GetGrandP(current);

    if ((current == current->parent_->r_child_) && (current->parent_ == gParent->l_child_)) {
        RotateToLeft(current->parent_);
        current = current->l_child_;
    } else if ((current == current->parent_->l_child_) && (current->parent_ == gParent->r_child_)) {
        RotateToRight(current->parent_);
        current = current->r_child_;
    }
    AddRule_5(current);
}

void RBTree::AddRule_5(RBTNode *current) {
    RBTNode *gParent = GetGrandP(current);

    current->parent_->color_ = BLACK;
    gParent->color_ = RED;
    if ((current == current->parent_->l_child_) && (current->parent_ == gParent->l_child_)) {
        RotateToRight(gParent);
    } else {
        RotateToLeft(gParent);
    }
}

void RBTree::CheckForAddToRBTRules(RBTNode *current) {
    AddRule_1(current);
}

RBTNode *RBTree::GetUncle(RBTNode *pNode) {
    RBTNode  *gParent = GetGrandP(pNode);
    if (gParent == nullptr){
        return nullptr;
    }

    if (pNode->parent_ == gParent->l_child_){
        return gParent->r_child_;
    }else {
        return gParent->l_child_;
    }
}

RBTNode *RBTree::GetGrandP(RBTNode *pNode) {
    if ((pNode != nullptr) && (pNode->parent_ != nullptr)){
        return pNode->parent_->parent_;
    } else{
        return nullptr;
    }
}

void RBTree::RotateToLeft(RBTNode *current) {
    RBTNode *temp_root = current->r_child_;

    temp_root->parent_ = current->parent_;
    if (current->parent_ != nullptr) {
        if (current->parent_->l_child_ == current){
            current->parent_->l_child_ = temp_root;
        }else {
            current->parent_->r_child_ = temp_root;
        }
    }

    current->r_child_ = temp_root->l_child_;
    if (temp_root->l_child_ != nullptr){
        temp_root->l_child_->parent_ = current;
    }

    current->parent_ = temp_root;
    temp_root->l_child_ = current;
}

void RBTree::RotateToRight(RBTNode *current) {
    RBTNode *temp_root = current->l_child_;

    temp_root->parent_ = current->parent_;

    if(current->parent_ != nullptr){
        if(current->parent_->l_child_ == current){
            current->parent_->l_child_ = temp_root;
        } else{
            current->parent_->r_child_ = temp_root;
        }
        current->l_child_ = temp_root->r_child_;
        if (temp_root->r_child_ != nullptr)
            temp_root->r_child_->parent_ = current;

        current->parent_ = temp_root;
        temp_root->r_child_ = current;
    }
}

RBTNode *RBTree::Find(int element) {
    RBTNode *current = root_;

    while (current != nullptr) {
        if(current->data_ == element){
            return current;
        }
        if (element >= current->data_) {
            current = current->r_child_;
        } else {
            current = current->l_child_;
        }
    }

    return nullptr;
}
void RBTree::RemoveElementCheckedRules(RBTNode *removable) {

}
