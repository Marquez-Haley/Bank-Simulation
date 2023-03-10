bank: driver.o
	g++ -o bank driver.o event.o

driver.o: driver.cpp arrayQueue.h priorityArrayQueue.h event.o
	g++ -c driver.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

clean:
	rm *.o bank
