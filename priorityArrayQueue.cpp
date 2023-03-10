#include "priorityArrayQueue.h"

template <class T>
PriorityArrayQueue<T>::PriorityArrayQueue(){
    front = -1;
    back = -1;
    itemCount = 0;
}

template <class T>
PriorityArrayQueue<T>::~PriorityArrayQueue(){
    while(!isEmpty()){
        dequeue();
    }
}

template <class T>
bool PriorityArrayQueue<T>::isEmpty() const{
    return itemCount == 0 && front == -1 && back == -1;
}

template <class T>
bool PriorityArrayQueue<T>::enqueue(const T& newEntry){
    bool canEnqueue = itemCount < DEFAULT_SIZE;
    if(canEnqueue){
        if(isEmpty()){
            front++;
            back++;
            priorityQueue[front] = newEntry;
        }
        else{
            //checks to see if the item at the index is less than the new item
            if(priorityQueue[back % DEFAULT_SIZE] < newEntry){
                priorityQueue[(back + 1) % DEFAULT_SIZE] = newEntry;
            }
            else{
                //iterates through the array to find where the new item will go
                for(int i = back; priorityQueue[i % DEFAULT_SIZE] >= newEntry && (i % DEFAULT_SIZE) >= 0; i--){
                    if(priorityQueue[i % DEFAULT_SIZE] > newEntry){
                        priorityQueue[(i + 1)% DEFAULT_SIZE] = priorityQueue[i % DEFAULT_SIZE];
                    }

                    if(priorityQueue[(i - 1) % DEFAULT_SIZE] <= newEntry){
                        priorityQueue[i % DEFAULT_SIZE] = newEntry;
                    }
                    if((i % DEFAULT_SIZE) == front % DEFAULT_SIZE){
                        priorityQueue[i % DEFAULT_SIZE] = newEntry;
                        i = 0;
                    }
                }
            }
            back++;
        }
        itemCount++;
    }
    
    return canEnqueue;
}

template <class T>
bool PriorityArrayQueue<T>::dequeue(){
    bool canDequeue = !isEmpty();

    if(canDequeue){
        if((front % DEFAULT_SIZE) == (back % DEFAULT_SIZE)){
            front = -1;
            back = -1;
        }
        else{
            front++;
        }
        itemCount--;
    }

    return canDequeue;
}

template <class T>
T PriorityArrayQueue<T>::peekFront() const{
    bool canPeek = !isEmpty();
    if(canPeek){
        return priorityQueue[front];
    }
    else{
        throw "The queue is empty!";
    }
}
