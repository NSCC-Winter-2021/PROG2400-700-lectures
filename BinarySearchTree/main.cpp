#include <iostream>
#include <iomanip>

using namespace std;

// forward declaration
class Node;

typedef Node* NodePtr;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() : data(-1), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

public:
    BST() : root(nullptr) {}

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

    return 0;
}