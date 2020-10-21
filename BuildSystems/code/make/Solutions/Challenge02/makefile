# Includes here
include sources.mk

# varaibles here
CPU = cortex-m0plus
ARCH = thumb
SPECS = nosys.specs
PLATFORM = WINDOWS
TARGET = result.out

# Conditions
ifeq ($(PLATFORM), ARM)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=mapfile.map
	CFLAGS  = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall 
endif

ifeq ($(PLATFORM), WINDOWS)
	CC = gcc
	LD = ld
	LDFLAGS = -w
	CFLAGS  = -Wall -O3
endif

ifeq ($(BUILD_MODE),debug)
	CFLAGS += -g
else ifeq ($(BUILD_MODE),run)
	CFLAGS += -O2
endif

# Targets
%.o: %.c
	$(CC) -c $^ $(CFLAGS) -o $@

.PHONY: all
all: main.o file01.o file02.o
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $(TARGET)

.PHONY: clean
clean:
	rm -rf *.o $(TARGET)


