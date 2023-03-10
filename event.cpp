#include "event.h"

Event::Event(){
    eventType = ' ';
    eventTime = 0;
    transactionLength = 0;
}
Event::Event(char newEventType, int newEventTime, int newTransactionLength) : eventType(newEventType), eventTime(newEventTime), transactionLength(newTransactionLength){}

Event::Event(const Event& rhs){
    eventType = rhs.eventType;
    eventTime = rhs.eventTime;
    transactionLength = rhs.transactionLength;
}

void Event::setEventType(char newEventType){
    eventType = newEventType;
}

void Event::setTime(int newEventTime){
    eventTime = newEventTime;
}

void Event::setTransactionLength(int newTransactionLength){
    transactionLength = newTransactionLength;
}

char Event::getEventType(){
    return eventType;
}

int Event::getTime(){
    return eventTime;
}
    
int Event::getTransactionLength(){
    return transactionLength;
}

bool Event::operator> (const Event& rhs){
    return this->eventTime > rhs.eventTime;
}

bool Event::operator< (const Event& rhs){
    return this->eventTime < rhs.eventTime;
}

bool Event::operator== (const Event& rhs){
    return this->eventTime == rhs.eventTime;
}

bool Event::operator<= (const Event& rhs){
    return this->eventTime == rhs.eventTime || this->eventTime < rhs.eventTime;
}

bool Event::operator>= (const Event& rhs){
    return this->eventTime == rhs.eventTime || this->eventTime > rhs.eventTime;
}

std::istream& operator>> (std::istream& in, Event& E){
    in >> E.eventTime >> E.transactionLength;
    return in;
}

std::ostream& operator<< (std::ostream& out, const Event& E){
    out << E.eventType << " " << E.eventTime << " " << E.transactionLength << std::endl;
    return out;
}

Event::~Event(){}
