#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t_ {
    int val;
    struct node_t_ *next;
} node_t;

typedef struct queue_t_ {
    int count;
    node_t *head;
    node_t *tail;
} queue_t;

queue_t *queue_init(void);
void queue_destroy(queue_t *);
bool queue_is_empty(queue_t *);
int queue_get_count(queue_t *);
int queue_peek(queue_t *);
bool queue_enqueue(queue_t *, int);
int queue_dequeue(queue_t *);

#endif //QUEUE_H_
