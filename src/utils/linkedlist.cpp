#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
    iterator = nullptr;
    follower = nullptr;
    tail = nullptr;
}

void LinkedList::addNode(void * data)
{
    LinkedListNode * node = nullptr;
    node = new LinkedListNode;

    tail->next = node;
    node->data = data;
    node->next = nullptr;
    tail = node;
}

void * LinkedList::getNextNode()
{
    follower = iterator;
    iterator = iterator->next;
    return iterator->data;
}


void LinkedList::resetIteration()
{
    follower = head;
    iterator = head;
}

void LinkedList::removeCurrentNode()
{
    // it's the callers responsability to release the memory of the node data (void * data)
    follower->next = iterator->next;
    delete iterator;
    iterator = follower->next;
}

void LinkedList::removeThisNode(void * remove)
{
    // home made iteration!!
    struct LinkedListNode * _iterator = head;
    struct LinkedListNode * _follower = head;
    while (_iterator != nullptr)
    {
        // remove the node from the linked list
        if (_iterator->data == remove)
        {
            // it's the callers responsability to release the memory of the node (void * data)
            _follower->next = _iterator->next;
            
            // deal with extreme cases: removing head
            if (_iterator == head)
            {
                head = _iterator->next;
            }
            // deal with extreme cases: removing tail
            if (_iterator == tail)
            {
                tail = _follower;
            }
            delete _iterator;
            return;
        }
        // iter
        _follower = _iterator;
        _iterator = _iterator->next;
    }

}