
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() : data(-1), next(nullptr), prev(nullptr) {}
};

class Stack {
private:
    Node* first;
    Node* last;

public:
    Stack() : first(nullptr), last(nullptr) {}

    void Push(int data) {
        Node* node = new Node();
        node->data = data;
        node->prev = last;

        if (first == nullptr) {
            // add the first node
            first = node;
        } else {
            // add other node
            last->next = node;
        }

        last = node;
    }

    int Pop() {

        // have a node to pop
        if (first != nullptr) {

            Node* node = last;

            // the previous pointer is the new last node
            last = last->prev;

            // if there is still a node in the stack
            if (last != nullptr) {
                // set the new last node to point to null
                last->next = node->next;
            }

            // we are removing the only node in the stack
            if (node == first) {
                first = nullptr;
            }

            int temp = node->data;

            delete node;

            return temp;
        }

        return -1;
    }

    int Peek() {
        if (last != nullptr) {
            return last->data;
        }
        return -1;
    }

    friend ostream& operator<<(ostream& output, Stack& stack);
};

ostream& operator<<(ostream& output, Stack& stack) {
    Node* node = stack.first;

    while (node != nullptr) {
        output << node->data << " ";
        node = node->next;
    }

    return output;
}

int main() {

    Stack stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);

    // Test 1
    cout << "Test 1" << endl;
    cout << "------" << endl;
    cout << stack << endl;

    // Test 2
    cout << "Test 2" << endl;
    cout << "------" << endl;
    cout << stack.Pop() << endl;
    cout << stack << endl;

    // Test 3
    cout << "Test 3" << endl;
    cout << "------" << endl;

    while (stack.Peek() != -1) {
        cout << stack.Pop() << endl;
        cout << stack << endl;
    }

    return 0;

}