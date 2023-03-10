# Bank-Simulation
An event-driven simulation of a bank using queues. 
A queue of arrival events represents the line of customers in the bank. 
Maintain the arrival events and departure events in a priority queue, sorted by the time of the event.
The input is a text file of arrival and transaction times. Each line of the file contains the arrival time and required transaction time for a customer. 
The program counts customers and keeps track of their cumulative waiting time to later computer the average waiting time.
Display a trace of the events executed and a summary of the computed statistics (the total number of arrivals and average time spent waiting in line). 
