/**
 * CS 2110 - Spring 2016 - Homework #10
 *
 * Do not modify this file!
 *
 * deque.h
 */

#ifndef DEQUE_H
#define DEQUE_H

/**************************
 ** Datatype definitions **
 **************************/

/* Forward declaration
 * Don't know what a forward declaration is? 
 * Consult the fountain of knowledge:
 * http://en.wikipedia.org/wiki/Forward_declaration
 */
struct dnode;

/* Given to you for free, however you better know how to do this come time for
 * the final exam!
 * The deque struct. Has a head & tail pointer.
 */
typedef struct
{
  struct dnode* head; /* Head pointer either points to a node with data or NULL */
  struct dnode* tail; /* Tail pointer either points to a node with data or NULL */
  int size; /* Size of the deque */
} deque;

/* Given to you for free, However you better know how to do this come time for
 * the final exam!
 * A function pointer type that points to a function that takes in a void* and
 * returns nothing, call it deque_op
 */
typedef void (*deque_op)(void*);

/* A function pointer type that points to a function that takes in a const void*
 * and returns an int, call it deque_pred
 */
typedef int (*deque_pred)(const void*);

/* A function pointer type that points to a function that takes in a void* and
 * returns a void*, call it deque_copy
 */
typedef void* (*deque_copy)(const void*);

/* A function pointer type that points to a function that takes in two void* and
 * returns an int, call it deque_eq
 */
typedef int (*deque_eq)(const void*, const void*);

/*********************************************
** Prototypes for deque library functions.  **
**                                          **
** For more details on their functionality, **
** check deque.c.                           **
**********************************************/

/* Creating */
deque *create_deque(void);
deque *copy_deque(deque *d, deque_copy copy_func);

/* Adding */
void push_front(deque *d, void *data);
void push_back(deque *d, void *data);

/* Querying Deque */
void *front(deque *d);
void *back(deque *d);
void *get(deque *d, int index);
int is_empty(deque *d);
int size(deque *d);
void *contains(deque *d, void *data, deque_eq eq_func);

/* Removing */
void *pop_front(deque *d);
void *pop_back(deque *d);
int remove_if(deque *d, deque_pred pred_func, deque_op free_func);
void empty_deque(deque *d, deque_op free_func);

/* Traversal */
void traverse(deque *d, deque_op do_func);

#endif
