# line-testing
This program uses Linked Lists and compares queue systems. The list.c has functions to use single linked lists. The test_que.c uses those 
functions to compare two different types of queues. It compares a queue where you pick a line and stand there until your cashier is open 
(these lines are typically shorter) and it the queue where you stand in one line and go to the next available cashier. 

To run the program, the two files need to be complied together. The program also takes in command line arguments. You need a -n to say how 
many cashiers you want, -s which is the earliest a new customer can come in, -e which is the latest a new customer would come in, and a -c 
for how many customers will come in between those two times. For example, if you wanted 3 cashiers and 1 new customer coming in every 5-10 
minutes it would look like a.out -n 3 -s 5 -e 10 -c 1
