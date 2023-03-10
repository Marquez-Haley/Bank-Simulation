#ifndef QUEUE_INTERFACE
#define QUEUE_INTERFACE

template<class T>
class QueueInterface{
    public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueue(const T& newEntry) = 0;
    virtual bool dequeue() = 0;
    virtual T peekFront() const = 0;
    virtual ~QueueInterface() {}
};
#endif
