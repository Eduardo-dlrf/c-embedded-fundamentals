#ifndef BIT_UTILS_H
#define BIT_UTILS_H

#include <stdint.h>

void     BIT_set    (uint32_t *reg, uint8_t pos);
void     BIT_clear  (uint32_t *reg, uint8_t pos);
void     BIT_toggle (uint32_t *reg, uint8_t pos);
uint8_t  BIT_test   (uint32_t *reg, uint8_t pos);

#endif //BIT_UTILS_H