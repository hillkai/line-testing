/*Program: test_que.c
 * Author: Kaitlin Hill
 * Date: 06/08/17
 * Description: Simulates two different types of cues to see which is faster
 * Input: Cashiers, range of time and how many customers come every minute
 * Output: How many people are in the lines after 1, 5, and 10 hours
 * ********************/
#include "./list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/***************************
 * Function: esta_values 
 * Description: Takes the values from argv and puts them in separate variables
 * Parameters: argv, cashier, range_1, range_2, customer
 * Pre-conditions: argv has characters that can be turned into integer values
 * Post-conditions: cashier, range_1, range_2, and customer hold integer values
 * Return: none
 * ************************/
void esta_values(char **argv, int *cashier, int *range_1, int *range_2, int *customer){
   int i; 
   int j;
   char cash[256];
   char ran_1[256];
   char ran_2[256];
   char cust[256];
   for(i=0; i<9; i++){
      for(j=0; j<5; j++){
         if((argv[i][j] == '-') && (argv[i][j+1] == 'n')){
	    strcpy(cash, argv[i+1]);
	    *cashier = atoi(cash);
	 }
	 else if((argv[i][j] == '-') && (argv[i][j+1] == 's')){
	    strcpy(ran_1, argv[i+1]);
	    *range_1 = atoi(ran_1);
	 }
	 else if((argv[i][j] == '-') && (argv[i][j+1] == 'e')){
	    strcpy(ran_2, argv[i+1]);
	    *range_2 = atoi(ran_2);
	 }
	 else if((argv[i][j] == '-') && (argv[i][j+1] == 'c')){
	    strcpy(cust, argv[i+1]);
	    *customer = atoi(cust);
	 }
      }
   }
}

/***************************
 * Function: push_on
 * Description: add customers to our line
 * Parameters: customer, new_list
 * Pre-conditions: none
 * Post-conditions: the list will have a new node on the back of the list
 * Return: new_list
 * ************************/
struct list push_on(int customer, struct list new_list){
   int i;
   for(i=0; i<60; i+=customer){
      push_back(&new_list, 5);
   }
   return new_list;
}

/***************************
 * Function: push_on_2
 * Description: add customers to the list
 * Parameters: customer, cashier, new_list
 * Pre-conditions: customer and cashier must have values
 * Post-conditions: the list will have a new node
 * Return: new_list
 * ************************/
struct list push_on_2(int customer, int cashier, struct list new_list){
   int i;
   customer = (60/customer)/cashier;
   for(i=0; i<customer; i++){
      push_back(&new_list, 5);
   }
   return new_list;
}

/***************************
 * Function: push_off
 * Description: take a customer out of line
 * Parameters: range_2, range_1, cashiers, new_list
 * Pre-conditions: variables must have values
 * Post-conditions: list will have a new value
 * Return: new_list
 * ************************/
struct list push_off(int range_2, int range_1, int cashiers, struct list new_list){
   int i;
   int j;
   int time=0;
   for(i=0; i<cashiers; i++){
      for(j=0; j<60; j+=time){
         remove_front(&new_list);
	 time = (rand() % (range_2-range_1)) + range_1;
      }
   }
   return new_list;
}

/***************************
 * Function: push_off_2 
 * Description: takes a customer out of line
 * Parameters: new_list, range_2, range_1
 * Pre-conditions: variables must have values
 * Post-conditions: there will be a new list
 * Return: new_list
 * ************************/
struct list push_off_2(struct list new_list, int range_2, int range_1){
   int i;
   int time=0;
   for(i=0; i<60; i+=time){
      remove_front(&new_list);
      time = (rand() % (range_2-range_1)) + range_1;
   }
   return new_list;
}

/***************************
 * Function: main
 * Description: runs program
 * Parameters: argc, argv
 * Pre-conditions: none
 * Post-conditions: none
 * Return: 0
 * ************************/
int main(int argc, char *argv[]){
   int cashier;
   int range_1; 
   int range_2;
   int customer;
   time_t t;
   int i;
   int k;
   int size_1;
   struct list one;
   struct list *multi;
   srand((unsigned) time(&t));
   
   esta_values(argv, &cashier, &range_1, &range_2, &customer);
   multi = (struct list *) malloc(sizeof(struct list)*cashier);
   init(&one);
   for(i=0; i<cashier; i++){
      init(&multi[i]);
   }
  
   one = push_on(customer, one);
   for(i=0; i<cashier; i++){
      multi[i] = push_on_2(customer, cashier, multi[i]);
   }
   one = push_off(range_2, range_1, cashier, one);
   size_1 = size(one);
   printf("After 1 hour: \nOne queue, select first available has: %d \n", size_1);
   delete(&one);
   for(i=0; i<cashier; i++){
      multi[i] = push_off_2(multi[i], range_2, range_1);
      size_1 = size(multi[i]);
      printf("Self-select queues have: %d \n", size_1);
      delete(&multi[i]);
   }
  
   for(k=0; k<5; k++){
      one = push_on(customer, one);
      for(i=0; i<cashier; i++){
         multi[i] = push_on_2(customer, cashier, multi[i]);
      }
      one = push_off(range_2, range_1, cashier, one);
      if(k==4){
         size_1 = size(one);
         printf("After 5 hours: \nOne queue, select first available has: %d \n", size_1);
         delete(&one);
      }
      for(i=0; i<cashier; i++){
         multi[i] = push_off_2(multi[i], range_2, range_1);
         if(k==4){
	    size_1 = size(multi[i]);
            printf("Self-select queues have: %d \n", size_1);
            delete(&multi[i]);
	 }
      }  
   }   
   
   for(k=0; k<10; k++){
      one = push_on(customer, one);
      for(i=0; i<cashier; i++){
         multi[i] = push_on_2(customer, cashier, multi[i]);
      }
      one = push_off(range_2, range_1, cashier, one);
      if(k==9){
         size_1 = size(one);
         printf("After 10 hours: \nOne queue, select first available has: %d \n", size_1);
         delete(&one);
      }
      for(i=0; i<cashier; i++){
         multi[i] = push_off_2(multi[i], range_2, range_1);
         if(k==9){
	    size_1 = size(multi[i]);
	    printf("Self-select queues have: %d \n", size_1);
            delete(&multi[i]);
	 }
      }  
   }
   free(multi);
   multi = NULL;
   return 0;
}
