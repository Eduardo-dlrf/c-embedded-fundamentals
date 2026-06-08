#include <assert.h>
#include "bit_utils.h"

#define BIT_0_MASK   0x00000001
#define BIT_1_MASK   0x00000002
#define BIT_31_MASK  0x80000000
#define ALL_CLEAR    0x00000000

int main(){
    uint32_t reg = 0;

    /* Test BIT_set: set bit 0 of 0x00000000 → 0x00000001 */
    reg = 0;
    BIT_set(&reg, 0);
    assert(reg == BIT_0_MASK);

    /* Test BIT_set: set bit 31 of 0x00000000 → 0x80000000 */
    reg = 0;
    BIT_set(&reg, 31);
    assert(reg == BIT_31_MASK);

    /* Test BIT_toggle: toggle bit 1 from 0 → 0x00000002 */
    reg = 0;
    BIT_toggle(&reg, 1);
    assert(reg == BIT_1_MASK);

    /* Test BIT_toggle: toggle bit 1 twice → returns to 0x00000000 */    
    BIT_toggle(&reg, 1);
    assert(reg == ALL_CLEAR);

    /* Test BIT_test: bit 1 of 0x00000002 is set → returns 1 */
    reg = BIT_1_MASK;
    uint8_t x = BIT_test(&reg, 1);
    assert(x == 1);

    return 0;
}