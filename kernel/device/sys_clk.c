#include "kernel/device/sys_clk.h"
#include "kernel/utils/asm.h"
#include "kernel/utils/print.h"

#define MK_SYS_CLK_CMD(index, rw, mode) ((u8)(index << 6 | rw << 4 | mode << 1))
#define MK_SYS_CLK_LB(cnt) ((u8)(cnt & 0xff))
#define MK_SYS_CLK_HB(cnt) ((u8)((cnt >> 8) & 0xff))

static void
init_sys_intr_clk(void)
{
  outb(SYS_CLK_CMD,
       MK_SYS_CLK_CMD(SYS_CLK_INTR_TIMER, SYS_CLK_RWLH, SYS_CLK_MODE_RATEGEN));
  outb(SYS_CLK_TIMER_CMD(SYS_CLK_INTR_TIMER),
       MK_SYS_CLK_LB(SYS_CLK_INTR_COUNTER));
  outb(SYS_CLK_TIMER_CMD(SYS_CLK_INTR_TIMER),
       MK_SYS_CLK_HB(SYS_CLK_INTR_COUNTER));
}

void
init_sys_clk(void)
{
  kputs("Initializing system clock...\n");

  init_sys_intr_clk();
}