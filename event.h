#ifndef EVENT_H
#define EVENT_H
#include <iostream>

class Event{
    private:
    char eventType;
    int eventTime, transactionLength;
    public:
    Event();
    Event(char newEventType, int newEventTime, int newTransactionLength);
    Event(const Event& rhs);

    void setEventType(char newEventType);
    void setTime(int newEventTime);
    void setTransactionLength(int newTransactionLength);

    char getEventType();
    int getTime();
    int getTransactionLength();

    bool operator> (const Event& rhs);
    bool operator< (const Event& rhs);
    bool operator== (const Event& rhs);
    bool operator<= (const Event& rhs);
    bool operator>= (const Event& rhs);
    
    friend std::istream& operator>> (std::istream& in, Event& E);
    friend std::ostream& operator<< (std::ostream& out, const Event& E);

    ~Event();
};
#endif
