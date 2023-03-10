#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
#include "queueInterface.h"

template<class T>
class ArrayQueue: public QueueInterface <T>{
    private:
    static const int DEFAULT_CAPACITY = 10;
    T queue[DEFAULT_CAPACITY];
    int front, back, itemCount;

    public:
    ArrayQueue();
    bool isEmpty() const;
    bool enqueue(const T& newEntry);
    bool dequeue();
    T peekFront() const;
    ~ArrayQueue();

};
#include "arrayQueue.cpp"
#endif
