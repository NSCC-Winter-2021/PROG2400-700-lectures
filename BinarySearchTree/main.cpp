#include <iostream>
#include <iomanip>

using namespace std;

// forward declaration
class Node;

typedef Node* NodePtr;

class Node {
public:
    int data;
    NodePtr left;
    NodePtr right;

    Node() : data(-1), left(nullptr), right(nullptr) {}
};

class BST {
private:
    NodePtr root;

public:
    BST() : root(nullptr) {}

    virtual ~BST() {
        DeleteTree(root);
    }

    void DeleteTree(NodePtr node) {
        if (node != nullptr) {
            DeleteTree(node->left);
            DeleteTree(node->right);

            delete node;

            node = nullptr;

        }
    }

    void Insert(int num) {
        Insert(num, root);
    }

    void Insert(int num, NodePtr& node) {
        if (node == nullptr) {
            node = new Node();
            node->data = num;
        } else if (num < node->data) {
            Insert(num, node->left);
        } else if (num > node->data) {
            Insert(num, node->right);
        } else {
            cout << "Node value " << node->data << " already exists." << endl;
        }
    }

    void Remove(int num) {

        NodePtr node = root;
        NodePtr parent = nullptr;

        while (node != nullptr) {
            if (num < node->data) {
                parent = node;
                node = node->left;
            } else if (num > node->data) {
                parent = node;
                node = node->right;
            } else {
                break;
            }
        }

        if (node == nullptr) return;

        // if a child has two children,
        // use right-most node of left tree as successor
        if (node->left != nullptr && node->right != nullptr) {

            // start at left tree
            NodePtr successor = node->left;

            // keep going right as far as possible
            parent = node;
            while (successor->right != nullptr) {
                parent = successor;
                successor = successor->right;
            }

            // swap data with successor and successor is now the one to delete
            node->data = successor->data;
            node = successor;
        }

        // now the node to delete must have only one or no children

        // assume there is left child
        NodePtr subtree = node->left;

        // if no left child, maybe a right child
        if (subtree == nullptr) {
            subtree = node->right;
        }

        // connect any children to new parents
        if (parent == nullptr) {
            // must be the root node
            root = subtree;
        } else if (parent->left == node) {
            // deleting a left node of a parent
            parent->left = subtree;
        } else if (parent->right == node) {
            // deleting a right node of parent
            parent->right = subtree;
        }

        // finally!
        delete node;
    }

    void PrintTree(ostream& output, NodePtr& node, int indent) {
        if (node != nullptr) {
            PrintTree(output, node->right, indent + 8);
            output << setw(indent) << node->data << endl;
            PrintTree(output, node->left, indent + 8);
        }
    }

    friend ostream& operator<<(ostream& output, BST& bst);
};

ostream& operator<<(ostream& output, BST& bst) {
    bst.PrintTree(output, bst.root, 0);
    return output;
}

int main() {

    BST bst;

    bst.Insert(5);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(2);
    bst.Insert(4);
    bst.Insert(6);
    bst.Insert(8);

    // test 1
    cout << bst << endl;

    // test 2
    cout << "\n\nTest 2" << endl;
    cout << "------" << endl;

    bst.Remove(7);

    cout << bst << endl;

    return 0;
}