#include "bit_utils.h"

/* Set bit at position pos: OR with a mask of 1 shifted to pos */
void BIT_set(uint32_t *reg, uint8_t pos){
    *reg |= (1 << pos);
}

/* Clear bit at position pos: AND with the inverse of 1 shifted to pos */
void BIT_clear(uint32_t *reg, uint8_t pos){
    *reg &= ~(1 << pos);
}

/* Toggle bit at position pos: XOR with 1 shifted to pos */
void BIT_toggle(uint32_t *reg, uint8_t pos){
    *reg ^= (1 << pos);
}

/* Return 1 if bit at pos is set, 0 otherwise.
 * Isolate the bit with AND, then shift it down to position 0. */
uint8_t BIT_test(uint32_t *reg, uint8_t pos){
    return (*reg & (1 << pos)) >> pos;
}