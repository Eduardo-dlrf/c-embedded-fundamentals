#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#define RING_BUFFER_SIZE 8

typedef struct
{
    uint8_t buffer[RING_BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
    uint16_t count;
} RingBuffer_t;

void RingBuffer_init(RingBuffer_t *rb);
bool RingBuffer_push(RingBuffer_t *rb, uint8_t byte);
bool RingBuffer_pop(RingBuffer_t *rb, uint8_t *byte);
bool RingBuffer_peek(RingBuffer_t *rb, uint8_t *byte);
bool RingBuffer_isEmpty(RingBuffer_t *rb);
bool RingBuffer_isFull(RingBuffer_t *rb);
uint16_t RingBuffer_count(RingBuffer_t *rb);

#endif //RING_BUFFER_H
