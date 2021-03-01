#include <iostream>
#include <vector>
#include <algorithm>

struct node
{
    int data;
    node *left;
    node *right;
};

class Tree
{
private:
    std::vector<node *> children;
    node *root = nullptr;

public:
    void insert(int value);
    bool empty() const;
    void balanceTree();
    int size() const;
    int getHeight(bool side) const;
    void display() const;
};

int Tree::size() const
{
    int leftHeight = getHeight(0);  // left subtree
    int rightHeight = getHeight(1); // right subtree

    int sum = leftHeight + rightHeight;

    if (root)
        sum += 1;

    return sum;
}

bool Tree::empty() const
{
    return root ? false : true;
}

int Tree::getHeight(bool side) const
{
    int count = 0;
    node *pre = root;
    node *cur = root;

    while (cur != nullptr)
    {
        pre = cur;
        if (side == 0)
            cur = cur->left;
        else
            cur = cur->right;

        if (pre != root)
            count++;
        if (cur == nullptr)
        {
            cur = pre;
            if (cur == root)
                cur = nullptr;
            else
            {
                if (side == 0)
                    cur = cur->right;
                else
                    cur = cur->left;
            }
        }
    }

    return count;
}

void Tree::display() const
{
    node *cur = root;

    std::cout << "Right subtree" << std::endl;
    while (cur != nullptr)
    {
        std::cout << cur->data << "->";
        cur = cur->right;
    }
    std::cout << std::endl
              << std::endl;

    cur = root;

    std::cout << "Left subtree" << std::endl;
    while (cur != nullptr)
    {
        std::cout << cur->data << "->";
        cur = cur->left;
    }
    std::cout << std::endl;
}

void Tree::balanceTree()
{

    while (children.size() > 0)
    {
        int mid = children.size() / 2;
        children[mid]->right = children[mid + 1];
        children[mid]->left = children[mid - 1];
        root = children[mid];

        children.erase(children.begin() + mid);
    }
}
bool pComp(node *a, node *b) { return a->data < b->data; }
void Tree::insert(const int value)
{

    node *temp = new node;
    temp->data = value;

    if (root == nullptr)
        root = temp;
    else
    {
        node *cur = root;
        node *pre = root;

        if (value > root->data)
        {
            while (cur != nullptr)
            {
                pre = cur;
                cur = cur->right;
            }
        }
        else
        {
            while (cur != nullptr)
            {
                pre = cur;
                cur = cur->left;
            }
        }

        if (value > pre->data)
            pre->right = temp;
        else
            pre->left = temp;
    }
    children.push_back(temp);

    int leftHeight = getHeight(0);  // left subtree
    int rightHeight = getHeight(1); // right subtree

    node *pre = root;
    node *cur = root;

    std::sort(children.begin(), children.end(), pComp); // sort vector of pointers
};