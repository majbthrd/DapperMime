#include <stdint.h>
#include "pico/stdlib.h"
#include "pico/unique_id.h"
#include "tusb.h"

static uint8_t get_unique_id(uint16_t *desc_str)
{
  pico_unique_board_id_t uid;
  uint8_t chr_count = 0;

  pico_get_unique_board_id(&uid);

  for (int byte = 0; byte < TU_ARRAY_SIZE(uid.id); byte++)
  {
    uint8_t tmp = uid.id[byte];
    for (int digit = 0; digit < 2; digit++)
    {
      desc_str[chr_count++] = "0123456789ABCDEF"[tmp & 0xf];
      tmp >>= 4;
    }
  }

  return chr_count;
}

