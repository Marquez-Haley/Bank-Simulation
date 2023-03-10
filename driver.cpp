/*
Authors: Haley Marquez and Jose Graciano
Purpose: to use queues to simulate a bank that calculates how many customers have been served and the average wait time
*/
#include <iostream>
#include <fstream>
#include <string>
#include "arrayQueue.h"
#include "priorityArrayQueue.h"
#include "event.h"

std::string getInFile();
void loadData(std::string&, PriorityArrayQueue<Event>&);
void processArrival(Event, PriorityArrayQueue<Event>&, ArrayQueue<Event>&);
void processDeparture(Event, PriorityArrayQueue<Event>&, ArrayQueue<Event>&);
void DisplayResults(PriorityArrayQueue<Event>&);
int main(){
    
    ArrayQueue<Event> bankQueue;
    PriorityArrayQueue<Event> eventListQueue;
    std::string filePtr = getInFile();

    loadData(filePtr, eventListQueue);
   
    while(!eventListQueue.isEmpty()){

        Event newEvent = eventListQueue.peekFront();
        std::cout << newEvent.getTime() << std::endl;
        int currentTime = newEvent.getTime();

        if(newEvent.getEventType() == 'A'){
           processArrival(newEvent, eventListQueue, bankQueue);
           std::cout << "Processing an arrival event at time: " << currentTime << std::endl;
        }
        else if(newEvent.getEventType() == 'D'){
            //processDeparture(newEvent, eventListQueue, bankQueue);
            std::cout << "Processing an arrival event at time: " << currentTime << std::endl;
        }
        
    }

    return 0;
}

std::string getInFile(){
    std::string fileName;
    std::cout << "Enter a file name: ";
    std::cin >> fileName;

    return fileName;
}

void loadData(std::string &fileName, PriorityArrayQueue<Event>& eventList){
    char type;
    int time, length;
    Event newArrivalEvent;
    std::ifstream file(fileName.c_str());
    if(file.is_open()){
        while(file){
            file >> time >> length;
            newArrivalEvent.setTime(time);
            newArrivalEvent.setTransactionLength(length);
            newArrivalEvent.setEventType('A');
            eventList.enqueue(newArrivalEvent);
        }
    }
}

void processArrival(Event arrivalEvent, PriorityArrayQueue<Event>& eventList, ArrayQueue<Event>& bankQueue){
    Event customer = arrivalEvent;
    if(bankQueue.isEmpty()){
        eventList.dequeue();
        customer.setEventType('D');
        eventList.enqueue(customer);
    }
    else{
        bankQueue.enqueue(customer);
    }
}

void processDeparture(Event departureEvent, PriorityArrayQueue<Event>& eventList, ArrayQueue<Event>& bankQueue){
    Event customer;
    while(!bankQueue.isEmpty()){
        eventList.dequeue();
        customer = bankQueue.peekFront();
        bankQueue.dequeue();
        customer.setEventType('D');
        eventList.enqueue(customer);
    }
}

void DisplayResults(PriorityArrayQueue<Event>& eventlist){
    int numberOfCustomers = 0;
    Event customer;
    int waitTime = eventlist.peekFront().getTime() + eventlist.peekFront().getTransactionLength();
    int tempValue;
    while(!(eventlist.isEmpty())){
        numberOfCustomers++;
        customer = eventlist.peekFront();
        eventlist.dequeue();
        tempValue = customer.getTime() + customer.getTransactionLength();
        std::cout << "Processing a departure event at time: " << tempValue;
        if(numberOfCustomers != 1){
            if(waitTime)
            waitTime = (waitTime - tempValue)*(-1);
        }
    }


    std::cout << "Final Statistics: " << std::endl;
    std::cout << "Total number of people processed: " << numberOfCustomers << std::endl;
    std::cout << "Average amount of time spent waiting: " << waitTime / numberOfCustomers << std::endl;
}
