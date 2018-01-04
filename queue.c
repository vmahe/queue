/*
 * queue.c
 */

#include "queue.h"
#include <assert.h>


queue_t *queue_init (void)
{
    queue_t *q = calloc(1, sizeof(queue_t));
    if (!q) return (NULL);
    q->count = 0;
    q->head = q->tail = NULL;
    return (q);
}


void queue_destroy (queue_t *obj)
{
    node_t *tmp;

    while (obj->head) {
        tmp = obj->head;
        obj->head = tmp->next;
        free(tmp);
    }
    free(obj);
}


bool queue_is_empty (queue_t *obj)
{
    assert(obj);
    return (obj->count == 0);
}


int queue_get_count (queue_t *obj)
{
    assert(obj);
    return(obj->count);
}


int queue_peek (queue_t *obj)
{
    int item;

    assert(obj);
    assert(obj->count);
    item = obj->head->val;

    return (item);
}


bool queue_enqueue (queue_t *obj, int val)
{
    node_t *new;

    assert(obj);
    new = calloc(1, sizeof(node_t));
    if (!new) return (false);
    new->val = val;

    if (obj->count == 0) {
        obj->head = obj->tail = new;
    } else {
        obj->tail->next = new;
        obj->tail = new;
    }
    obj->count++;

    return (true);
}


int queue_dequeue (queue_t *obj)
{
    int item;
    node_t *tmp;

    assert(obj);
    assert(obj->count);

    tmp = obj->head;
    obj->head = tmp->next;
    obj->count--;
    if (obj->count == 0) {
        obj->tail = NULL;
    }

    item = tmp->val;
    free(tmp);

    return (item);
}

