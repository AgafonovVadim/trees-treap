#ifndef TREE_HPP
#define TREE_HPP

#include <cstddef>
#include <cstdint>
#include <vector>

struct Node {
    int x;
    double y;
    Node *left_side = nullptr;
    Node *right_side = nullptr;

    explicit Node(int x);

    ~Node();
};


class Treap {
private:
    std::size_t elements_number = 0;
    Node *root = nullptr;

    std::pair<Node *, Node *> split(Node *current_t, int x);

    Node *merge(Node *left_tree, Node *right_tree);

    Node *removing(Node *current_t);

    void output_filling(Node *current_t, std::vector<int> &output) const;

public:
    [[nodiscard]] bool contains(int element) const noexcept;

    bool insert(int element);

    bool remove(int element);

    [[nodiscard]] std::size_t size() const noexcept;

    [[nodiscard]] bool empty() const noexcept;

    [[nodiscard]] std::vector<int> values() const noexcept;

    ~Treap();
};

#endif
