#include "kernel/info.h"
#include "kernel/log.h"
#include "kernel/memory/memory.h"
#include "kernel/utils/print.h"
#include "lib/asm.h"

void
kmain(void);

static void
kinit(void)
{
  init_print();

  KINFO("%s STEP 3", KFULLNAME_STR);

  init_memory();
}

void
kmain(void)
{
  kinit();

  while (true) {
    hlt();
  }
}