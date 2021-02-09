
#include <iostream>

using namespace std;

class MazePosition {
public:
    int row;
    int col;

    MazePosition() : row(-1), col(-1) {}
    MazePosition(int row, int col) : row(row), col(col) {}
    MazePosition(const MazePosition& pos) : MazePosition(pos.row, pos.col) {}

    friend ostream& operator<<(ostream& output, MazePosition pos);
};

ostream& operator<<(ostream& output, MazePosition pos) {
    output << "(" << pos.row << "," << pos.col << ")";
    return output;
}

class Node {
public:
    MazePosition pos;
    Node* next;
    Node* prev;

    Node() : next(nullptr), prev(nullptr) {}
};

class MazeStack {
private:
    Node* first;
    Node* last;

public:
    MazeStack() : first(nullptr), last(nullptr) {}

    void Push(MazePosition pos) {
        Node* node = new Node();
        node->pos = pos;
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

    MazePosition Pop() {

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

            MazePosition temp = node->pos;

            delete node;

            return temp;
        }

        return MazePosition();
    }

    MazePosition Peek() {
        if (last != nullptr) {
            return last->pos;
        }
        return MazePosition();
    }

    friend ostream& operator<<(ostream& output, MazeStack& stack);
};

ostream& operator<<(ostream& output, MazeStack& stack) {
    Node* node = stack.first;

    while (node != nullptr) {
        output << node->pos << endl;
        node = node->next;
    }

    return output;
}

int main() {

    MazeStack stack;

    stack.Push({1, 1});
    stack.Push({2, 1});
    stack.Push({3, 1});
    stack.Push({4, 1});
    stack.Push({5, 1});

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

    while (stack.Peek().row != -1) {
        cout << stack.Pop() << endl;
        cout << stack << endl;
    }

    // ----

    //Maze maze;

    //maze.ReadTextFile(filenameIn);
    //maze.Solve();
    //maze.WriteTextFile(filenameOut);

    return 0;

}