Srcs := $(wildcard *.cc)
Outs := $(patsubst %.cc, %, $(Srcs))

CC := g++
CFLAGS = -Wall -g

ALL: $(Outs) 

%: %.c
	$(CC) $< -o $@ $(CFLAGS)

.PHONY: clean rebuild ALL

clean:
	$(RM) $(Outs)
rebuild: clean ALL
