#include "elog.h"
#include "elog_internal.h"
#include "elog_appender.h"
#include <stdlib.h>
#include <string.h>

struct elog* 
elog_create(const char* filename) {
    if (filename == NULL)
        return NULL;
    
    struct elog* self = sh_malloc(sizeof(*self));
    self->filename = sh_malloc(strlen(filename)+1);
    strcpy(self->filename, filename);
    
    self->appender = NULL;
    return self;
}

void 
elog_free(struct elog* self) {
    if (self == NULL)
        return;
    if (self->appender) {
        self->appender->close(self);
    }
    sh_free(self->filename);
    sh_free(self);
}

void 
elog_append(struct elog* self, const char* msg, int sz) {
    if (self->appender)
        self->appender->append(self, msg, sz);
}

int
elog_set_appender(struct elog* self, const struct elog_appender* appender, const char *mode) {
    if (self->appender) {
        self->appender->close(self);
    }
    self->appender = appender;
    if (self->appender->open(self, mode)) {
        self->appender = NULL;
        return 1;
    }
    return 0;
}
