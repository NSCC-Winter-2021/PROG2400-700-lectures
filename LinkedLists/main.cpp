#include <iostream>

using namespace std;

class LinkedListNode {
public:
    int data;               // the data to store
    LinkedListNode* next;   // a pointer to the next node in the chain

    LinkedListNode() : data(-1), next(nullptr) {}
};

class LinkedList {
private:
    LinkedListNode* start;

public:
    LinkedList() : start(nullptr) {

    }

    virtual ~LinkedList() {
        LinkedListNode *node = start;

        while (node != nullptr) {
            LinkedListNode* temp = node;
            node = node->next;
            delete temp;
        }
    }

    void Add(int data) {

        LinkedListNode* newNode = new LinkedListNode();
        newNode->data = data;

        if (start == nullptr) {
            start = newNode;
        } else {
            LinkedListNode* node = start;
            LinkedListNode* prev = nullptr;

            // go through each node until a null ptr is hit
            while (node != nullptr) {
                prev = node;
                node = node->next;
            }

            // attach new node to end of chain
            if (prev != nullptr) {
                prev->next = newNode;
            }
        }
    }

    // delete a node based on the value
    void Delete(int data) {
        LinkedListNode* node = start;
        LinkedListNode* prev = nullptr;

        // find node to delete
        while (node != nullptr) {
            if (node->data == data) {
                break;
            }
            prev = node;
            node = node->next;
        }

        // found node to delete
        if (node != nullptr) {
            if (prev == nullptr) {
                // we're deleting the first node
                start = node->next;
            } else {
                // any other node is deleted
                prev->next = node->next;
            }

            delete node;
        }
    }

    friend ostream& operator<<(ostream& output, LinkedList& list);
};

ostream& operator<<(ostream& output, LinkedList& list) {

    LinkedListNode* node = list.start;

    while (node != nullptr) {
        output << node->data << " ";
        node = node->next;
    }

    return output;
}

int main() {

    LinkedList list;

    // test 1
    list.Add(1);
    list.Add(4);
    list.Add(3);
    list.Add(2);
    list.Add(5);

    cout << "Test 1" << endl;
    cout << "------" << endl;
    cout << list << endl;

    // test 2
    list.Delete(3);

    cout << "Test 2" << endl;
    cout << "------" << endl;
    cout << list << endl;

    return 0;
}
