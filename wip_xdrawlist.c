/**
 * This file belongs to the 'xlab' game engine.
 * Copyright 2009 xfacter
 * Copyright 2016 wickles
 * This work is licensed under the LGPLv3
 * subject to all terms as reproduced in the included LICENSE file.
 */

#include <string.h>
#include <pspgu.h>
#include "xmem.h"

#include "xlist.h"

static void* test_ptr = 0;

inline void xListStart(u32 test)
{
    if (test_ptr) return;
    test_ptr = x_malloc(test);
    sceGuStart(GU_CALL, test_ptr);
}

inline void* xListFinish()
{
    if (!test_ptr) return 0;
    int size = sceGuFinish();
    void* list_ptr = x_remalloc(test_ptr, size);
    test_ptr = 0;
    return list_ptr;
}

inline void xListDestroy(void* ptr)
{
    x_free(ptr);
}
