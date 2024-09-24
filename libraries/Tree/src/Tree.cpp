#include "tree/Tree.hpp"

#include <random>

Node::Node(int x) : x(x), y(std::mt19937(std::random_device{}())()) {}

Node::~Node() {
    delete left_side;
    delete right_side;
}

bool Treap::contains(int element) const noexcept {
    Node *tmp = root;
    while (tmp != nullptr && tmp->x != element) {
        tmp = (tmp->x > element) ? tmp->left_side : tmp->right_side;
    }
    return tmp != nullptr;
}

bool Treap::insert(int element)  // second realisation
{
    if (!contains(element)) {
        Node *new_branch = new Node(element);
        elements_number++;
        std::pair<Node *, Node *> t = split(root, element);
        t.first                     = merge(t.first, new_branch);
        root                        = merge(t.first, t.second);
        return true;
    }
    return false;
}

bool Treap::remove(int element)  // second realisation
{
    if (contains(element)) {
        elements_number--;
        if (elements_number == 0) {
            delete root;
            root = nullptr;
        } else if (root->x == element) {
            root = removing(root);
        } else {
            Node *current_t = root;
            while (current_t != nullptr) {
                if (current_t->right_side && current_t->right_side->x == element) {
                    current_t->right_side = removing(current_t->right_side);
                    return true;
                }
                if (current_t->left_side && current_t->left_side->x == element) {
                    current_t->left_side = removing(current_t->left_side);
                    return true;
                }
                current_t = (current_t->x < element) ? current_t->right_side : current_t->left_side;
            }
            return false;
        }
        return true;
    }
    return false;
}

Node *Treap::removing(Node *current_t) {
    Node *sub_t           = merge(current_t->left_side, current_t->right_side);
    current_t->left_side  = nullptr;
    current_t->right_side = nullptr;
    delete current_t;
    current_t = sub_t;
    return current_t;
}

std::size_t Treap::size() const noexcept {
    return elements_number;
}

bool Treap::empty() const noexcept {
    return elements_number == 0;
}

std::vector<int> Treap::values() const noexcept {
    std::vector<int> output;
    output_filling(root, output);
    return output;
}

void Treap::output_filling(Node *current_t, std::vector<int> &output) const {
    if (current_t != nullptr) {
        output_filling(current_t->left_side, output);
        output.push_back(current_t->x);
        output_filling(current_t->right_side, output);
    }
}

Treap::~Treap() {
    delete root;
}

std::pair<Node *, Node *> Treap::split(Node *current_t, int x) {
    if (current_t == nullptr) {
        return {nullptr, nullptr};
    }
    if (x > current_t->x) {
        std::pair<Node *, Node *> t = split(current_t->right_side, x);
        current_t->right_side       = t.first;
        return {current_t, t.second};
    } else {
        std::pair<Node *, Node *> t = split(current_t->left_side, x);
        current_t->left_side        = t.second;
        return {t.first, current_t};
    }
}

Node *Treap::merge(Node *left_tree, Node *right_tree) {
    if (right_tree == nullptr) {
        return left_tree;
    }
    if (left_tree == nullptr) {
        return right_tree;
    } else if (left_tree->y > right_tree->y) {
        left_tree->right_side = merge(left_tree->right_side, right_tree);
        return left_tree;
    } else {
        right_tree->left_side = merge(left_tree, right_tree->left_side);
        return right_tree;
    }
}
