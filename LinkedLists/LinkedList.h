//
// Created by nscc on 1/26/2021.
//

#ifndef PROG2400_700_LECTURES_LINKEDLIST_H
#define PROG2400_700_LECTURES_LINKEDLIST_H


class LinkedListNode {
public:
    int data;               // the data to store
    LinkedListNode* next;   // a pointer to the next node in the chain

    LinkedListNode();
};

class LinkedList {
private:
    LinkedListNode* start;

public:
    LinkedList();
    virtual ~LinkedList();

    void Add(int data);
    void Delete(int data);
    void Insert(int data, int before);

    friend ostream& operator<<(ostream& output, LinkedList& list);
};

ostream& operator<<(ostream& output, LinkedList& list);

#endif //PROG2400_700_LECTURES_LINKEDLIST_H
