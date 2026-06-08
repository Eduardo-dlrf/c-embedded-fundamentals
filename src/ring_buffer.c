
#include "ring_buffer.h"

void RingBuffer_init(RingBuffer_t *rb){
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

bool RingBuffer_push(RingBuffer_t *rb, uint8_t byte){
    if (rb->count == RING_BUFFER_SIZE){
        return false;
    }
    else{
        rb->buffer[rb->head] = byte;
        rb->head++;
        if (rb->head == RING_BUFFER_SIZE) {
            rb->head = 0;
        }
        rb->count++;
        return true;
    }
}

bool RingBuffer_pop(RingBuffer_t *rb, uint8_t *byte){
    if (rb->count == 0){
        return false;
    }
    else{
        *byte = rb->buffer[rb->tail];
        rb->tail++;
        if (rb->tail == RING_BUFFER_SIZE) {
            rb->tail = 0;
        }
        rb->count--;
        return true;
    }
}

bool RingBuffer_peek(RingBuffer_t *rb, uint8_t *byte){
    if (rb->count == 0){
        return false;
    }
    else{
        *byte = rb->buffer[rb->tail];
        return true;
    }
}

bool RingBuffer_isEmpty(RingBuffer_t *rb){
    if (rb->count == 0){
        return true;
    }   else{return false;}
}

bool RingBuffer_isFull(RingBuffer_t *rb){
    if (rb->count == RING_BUFFER_SIZE){
        return true;
    }   else{return false;}
}

uint16_t RingBuffer_count(RingBuffer_t *rb){
    return rb->count;
}
