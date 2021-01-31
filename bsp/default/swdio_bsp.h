#ifndef __SWDIO_BSP_H
#define __SWDIO_BSP_H

#warning "code will not function as-is; swdio_bsp.h must be created to suit the target hardware"

#define CLK_LOW      { }
#define CLK_HIGH     { }
#define CLK_ENABLE   { }
#define CLK_HIZ      { }

#define DATA_LOW     { }
#define DATA_HIGH    { }
#define DATA_ENABLE  { }
#define DATA_HIZ     { }

#define RESET_LOW    { }
#define RESET_HIGH   { }
#define RESET_ENABLE { }
#define RESET_HIZ    { }

#define SWDIO_INIT   { }

#define DATA_READ   (0)
#define CLK_READ    (0)
#define RESET_READ  (0)

#endif /* __SWDIO_BSP_H */
