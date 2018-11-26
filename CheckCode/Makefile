CXXFLAGS = -O0 -g3  -I ../.. -pthread #-g3可以让gdb展开宏, print命令
CFLAGS = -O0 -g3  -I ../.. -pthread #-g3可以让gdb展开宏, print命令
LDFLAGS = -lpthread -lm
BASE_SRC = 
LIB_SRC =
BINARIES = hanming crc_allin1 crc0 crc1 crc2 crc3 crc4
HEADERS=$(wildcard *.h)

all: $(BINARIES)
$(BINARIES): $(HEADERS)
$(BINARIES):
	gcc $(CFLAGS) -o $@ $(LIB_SRC) $(BASE_SRC) $(filter %.c,$^) $(LDFLAGS)

clean:
	rm -f $(BINARIES) core

#hanming: CFLAGS += -Wall
hanming: hanming.c

crc_allin1: crc_allin1.c

crc0: crc0.c

crc1: crc1.c

crc2: crc2.c

crc3: crc3.c

crc4: crc4.c
