.PHONY: elog.so clean

CFLAGS=-g -Wall -Werror
SHARED=-fPIC -shared

SRC=\
	elog.c \
	elog_appender_file.c \
	elog_appender_rollfile.c

elog.so:
	gcc $(CFLAGS) $(SHARED) -o $@ $(SRC)

clean:
	rm -rf elog.so*
