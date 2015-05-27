#ifndef __elog_internal_h__
#define __elog_internal_h__

#include "alloc.h"

struct elog_appender;

struct elog {
    const struct elog_appender* appender;
    char* filename;
    void* od;
};

#endif
