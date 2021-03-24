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

    void SaveAsArray(int* array) {
        SaveAsArray(array, root);
    }

    void SaveAsArray(int* array, NodePtr node) {
        static int i = 0;
        if (node != nullptr) {
            SaveAsArray(array, node->left);
            array[i++] = node->data;
            SaveAsArray(array, node->right);
        }
    }

};

void dumparray(int *array, int len) {
    for (int i = 0; i < len; ++i) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void bstsort(int *array, int len) {

    BST bst;

    for (int i = 0; i < len; ++i) {
        bst.Insert(array[i]);
    }

    bst.SaveAsArray(array);
}

int main() {

    int nums[] = {3,6,8,10,5,9,4,1,2,7};
    int len = sizeof(nums)/sizeof(int);

    cout << "Before Sorting..." << endl;
    dumparray(nums, len);

    bstsort(nums, len);

    cout << "After Sorting..." << endl;
    dumparray(nums, len);

    return 0;
}