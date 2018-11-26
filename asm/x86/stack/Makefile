CXXFLAGS = -O0 -g3  -I ../.. -pthread #-g3可以让gdb展开宏, print命令
CFLAGS = -O0 -g3  -I ../.. -pthread #-g3可以让gdb展开宏, print命令
LDFLAGS = -lpthread -lm -fPIC
BASE_SRC = 
LIB_SRC =
BINARIES = stack stack2 stack3
HEADERS=$(wildcard *.h)

all: $(BINARIES)
$(BINARIES): $(HEADERS)
$(BINARIES):
	gcc $(CFLAGS) -o $@ $(LIB_SRC) $(BASE_SRC) $(filter %.c,$^) $(LDFLAGS)

clean:
	rm -f $(BINARIES) core

#hanming: CFLAGS += -Wall
stack: stack.c

stack2: stack2.c

stack3: stack3.c
