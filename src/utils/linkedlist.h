#pragma once

struct LinkedListNode
{
    void * data;
    struct LinkedListNode * next;
};

class LinkedList
{
private:
    // keep the head, iterate with the iterator, follow the iteration with the follower
    struct LinkedListNode * head;
    struct LinkedListNode * iterator;
    struct LinkedListNode * follower;
    struct LinkedListNode * tail;

public:
    LinkedList();
    void addNode(void *);
    void * getNextNode();
    void resetIteration();
    void removeCurrentNode();
    void removeThisNode(void * );
};

