#include <stdint.h>
#include "tusb.h"

/* in the absence of the board-specific directory providing a unique ID, we provide a canned one */

static uint8_t get_unique_id(uint16_t *desc_str)
{
  const char canned[] = "123456";
  uint8_t i;

  for(i=0; i<TU_ARRAY_SIZE(canned); i++)
  {
    desc_str[i] = canned[i];
  }

  return i;
}

#define PRODUCT_PREFIX ""
