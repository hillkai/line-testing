#include "./list.h"
#include<stdio.h>
#include<stdlib.h>

/***************************
 * Function: init 
 * Description: initialize pointers
 * Parameters: li
 * Pre-conditions: none
 * Post-conditions: head and tail are set to NULL
 * Return: none
 * ************************/
void init(struct list *li){
   li->head = NULL;
   li->tail = NULL;
}
/***************************
 * Function: size
 * Description: gives size of linked list
 * Parameters: li
 * Pre-conditions: none
 * Post-conditions: none
 * Return: counter
 * ************************/
int size(struct list li){
   struct node *temp;
   int counter = 0;
   if((li.head == NULL) && (li.tail == NULL)){
      return 0;
   }
   else{
      temp = li.head;
      while(temp != NULL){
         counter++;
	 temp = temp->next;
      }
      return counter;
   }
}
/***************************
 * Function: print
 * Description: prints values of linked list node
 * Parameters: li
 * Pre-conditions: none
 * Post-conditions: none
 * Return: none
 * ************************/
void print(struct list li){
   struct node *temp; 
   temp = li.head;
   while(temp != NULL){
      printf("here is my val: %d\n",temp->val);
      temp = temp->next;
   }
}
/***************************
 * Function: push_front
 * Description: push node on the front of the list
 * Parameters: *li, new_val
 * Pre-conditions: none
 * Post-conditions: list will have new node
 * Return: none
 * ************************/
void push_front(struct list *li, int new_val){
   struct node *temp;
   if((li->head == NULL) && (li->tail == NULL)){
      temp =(struct node *) malloc(sizeof(struct node));
      temp->val = new_val;
      li->head = temp;
      li->tail = temp;
      temp->next = NULL;
   }
   else{
      temp =(struct node *)malloc(sizeof(struct node));
      temp->next = li->head;
      li->head = temp;
      temp->val = new_val;
   }
}
/***************************
 * Function: push_back
 * Description: pushes a new node to the back
 * Parameters: *li, new_val
 * Pre-conditions: none
 * Post-conditions: linked list has a new node
 * Return: none
 * ************************/
void push_back(struct list *li, int new_val){
   struct node *temp;
   if((li->head == NULL) && (li->tail == NULL)){
      temp = (struct node *)malloc(sizeof(struct node));
      temp->val = new_val;
      li->head = temp;
      li->tail = temp;
      temp->next = NULL;       
   }
   else{
      temp = (struct node *)malloc(sizeof(struct node));
      li->tail->next = temp;
      li->tail = temp;
      temp->next = NULL;
      temp->val = new_val;
   }
}
/***************************
 * Function: front
 * Description: returns value of head
 * Parameters: li
 * Pre-conditions: head is not set to NULL
 * Post-conditions: none
 * Return: li.head->val
 * ************************/
int front(struct list li){
   return li.head->val;
}
/***************************
 * Function: back
 * Description: returns valued of tail
 * Parameters: li
 * Pre-conditions: tail is not set to NULL
 * Post-conditions: none
 * Return: li.tail->val
 * ************************/
int back(struct list li){
   return li.tail->val;
}
/***************************
 * Function: pop_back
 * Description: takes a node off the list and returns the value
 * Parameters: *li
 * Pre-conditions: none
 * Post-conditions: node will have one less node
 * Return: value
 * ************************/
int pop_back(struct list *li){
   struct node *temp;
   struct node *temp_2;
   int value;
   if((li->head == NULL) && (li->tail == NULL)){
   }
   else if(li->head == li->tail){
      temp = li->head;
      value = temp->val;
      free(temp);
      li->head = NULL;
      li->tail = NULL;
      return value;
   }
   else{
      temp = li->head;
      while(temp != NULL){
         if(temp->next->next == NULL){
            temp_2 = temp->next;
	    temp->next = NULL;
	    li->tail = temp;
	    value = temp_2->val;
	    free(temp_2);
	    return value;
         }
         temp = temp->next;
      }
   }
}
/***************************
 * Function: remove_front
 * Description: removes node from front of list
 * Parameters: *li
 * Pre-conditions: none
 * Post-conditions: node will be removed from list
 * Return: value
 * ************************/
int remove_front(struct list *li){
   struct node *temp;
   int value;
   if((li->head == NULL) && (li->tail == NULL)){
   }
   else if(li->head == li->tail){
      temp = li->head;
      value = temp->val;
      free(temp);
      li->head = NULL;
      li->tail = NULL;
      return value;
   }
   else{
      temp = li->head;
      li->head = temp->next;
      value = temp->val;
      free(temp);
      return value;
   }
}
/***************************
 * Function: empty
 * Description: Returns true or false based on whether the list is empty
 * Parameters: li
 * Pre-conditions: none
 * Post-conditions: none
 * Return: 1 or 0
 * ************************/
int empty(struct list li){
   int size_of;
   size_of = size(li);
   if(size_of == 0){
      return 1;
   }
   else if(size_of > 0){
      return 0;
   }
}
/***************************
 * Function: delete
 * Description: deletes all the nodes in a list
 * Parameters: *li
 * Pre-conditions: none
 * Post-conditions: all nodes will be deleted
 * Return: none
 * ************************/
void delete(struct list *li){
   int x;
   struct node *temp;
   struct node *temp_2;
   if((li->head == NULL) && (li->tail == NULL)){
   }
   else{
      do{
         temp = li->head;
	 if(temp->next != NULL){
	    temp_2 = temp->next;
	    li->head = temp_2;
	    free(temp);
            x = 1;
	 }
	 else{
	    temp = li->head;
	    free(temp);
	    li->head = NULL;
	    li->tail = NULL;
	    x = 0;
	 }
      }while(x == 1);
   }
}
