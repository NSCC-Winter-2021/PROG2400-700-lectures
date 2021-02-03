#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(-1), next(nullptr) {}
};

class Queue {
private:
    Node* first;
    Node* last;

public:
    Queue() : first(nullptr), last(nullptr) {

    }

    void Push(int data) {
        Node* node = new Node();
        node->data = data;

        if (first == nullptr) {
            // first node in queue
            first = node;
        } else {
            // other node in queue
            last->next = node;
        }

        last = node;
    }

    int Peek() {
        if (first != nullptr)
            return first->data;
        return -1;
    }

    int Pop() {
        // set second node as new first node
        Node* node = first;

        if (node != nullptr) {
            first = first->next;
            // extract data from old first node
            int temp = node->data;
            delete node;
            // return data from old first node
            return temp;
        }

        return -1;
    }

    friend ostream& operator<<(ostream& output, Queue& queue);
};

ostream& operator<<(ostream& output, Queue& queue) {
    Node* node = queue.first;

    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }

    return output;
}

int main() {

    Queue queue;

    // add to end of queue
    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Push(4);
    queue.Push(5);

    // test 1
    cout << "Test 1" << endl;
    cout << "------" << endl;
    cout << queue << endl;

    // peek at the data at the beginning of the queue
    cout << "Test 2" << endl;
    cout << "------" << endl;
    cout << queue.Peek() << endl;

    // pop the data from the beginning of the queue
    cout << "Test 3" << endl;
    cout << "------" << endl;
    cout << queue.Pop() << endl;
    cout << queue << endl;

    // pop all the data from the queue
    cout << "Test 4" << endl;
    cout << "------" << endl;

    while (queue.Peek() != -1) {
        cout << queue.Pop() << endl;
        cout << queue << endl;
    }

    return 0;
}