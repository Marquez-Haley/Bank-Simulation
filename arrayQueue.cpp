#include "arrayQueue.h"

template<class T>
ArrayQueue<T>::ArrayQueue(){
    front = -1;
    back = -1;
    itemCount = 0;
}

template<class T>
bool ArrayQueue<T>::isEmpty() const{
    return front == -1 && back == -1;
}

template<class T>
bool ArrayQueue<T>::enqueue(const T& newEntry){
    bool canAdd = itemCount < DEFAULT_CAPACITY - 1;
    if(canAdd){
        if(isEmpty()){
            front++;
            back++;
            queue[front] = newEntry;
        }
        //creates a circular array where if the reaches the end of the array but there is room in the beginning, it will add to it
        else if(back == DEFAULT_CAPACITY - 1 && front != 0){
            back = 0;
            queue[back] = newEntry;
        }
        else{
            back++;
            queue[back] = newEntry;
        }
    }
    
    return canAdd;
}

template<class T>
bool ArrayQueue<T>::dequeue(){
    bool canDq = !isEmpty();

    if(canDq){
        //if it reaches the back of the array, it sets it back to the beginning
        if (front == DEFAULT_CAPACITY - 1 && back >= 0){
            front = 0;
            itemCount--;
        }
        //queue is empty if the front and back are equal
        else if(front == back){
            front = -1;
            back = -1;
            itemCount = 0;
        }
        else{
            front++;
            itemCount--;
        }
    }

    return canDq;
}

template<class T>
T ArrayQueue<T>::peekFront() const{
    bool canPeek = !isEmpty();

    if(canPeek){
        return queue[front];
    }
    else{
        throw "empty queue";
    }
}

template<class T>
ArrayQueue<T>::~ArrayQueue(){
    while(!isEmpty()){
        dequeue();
    }
}
