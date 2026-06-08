#include <assert.h>
#include "ring_buffer.h"

int main(){
    RingBuffer_t MyRingBuffer;
    uint8_t MyByte = 42;

    /* Test init: all fields start at zero */
    RingBuffer_init(&MyRingBuffer);
    assert(MyRingBuffer.head  == 0);
    assert(MyRingBuffer.tail  == 0);
    assert(MyRingBuffer.count == 0);

    /* Test push: insert 42, buffer should have 1 element */
    assert(RingBuffer_push(&MyRingBuffer, MyByte) == true);

    /* Test peek: read without removing, value should be 42, count stays 1 */
    RingBuffer_peek(&MyRingBuffer, &MyByte);
    assert(MyByte == 42);
    assert(RingBuffer_count(&MyRingBuffer) == 1);

    /* Test pop: remove byte, value should be 42, buffer should be empty */
    assert(RingBuffer_pop(&MyRingBuffer, &MyByte) == true);
    assert(MyByte == 42);

    /* Test isEmpty and isFull after pop */
    assert(RingBuffer_isEmpty(&MyRingBuffer) == true);
    assert(RingBuffer_isFull(&MyRingBuffer)  == false);
    assert(RingBuffer_count(&MyRingBuffer)   == 0);

    return 0;
}