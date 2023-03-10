#ifndef PRIORITY_ARRAY_QUEUE
#define PRIORITY_ARRAY_QUEUE
#include "queueInterface.h"

#define DEFAULT_SIZE 10

template <class T>
class PriorityArrayQueue: public QueueInterface<T>{
private:
    T priorityQueue[DEFAULT_SIZE];
    int front, back, itemCount;
public:
    PriorityArrayQueue();
    ~PriorityArrayQueue();

    bool isEmpty() const;
    bool enqueue(const T& newEntry);
    bool dequeue();
    T peekFront() const;
};

#include "priorityArrayQueue.cpp"
#endif
