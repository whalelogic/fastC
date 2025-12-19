# 1. Compiler Settings
CC := gcc
CFLAGS := -Wall -Wextra -g -Isrc

# 2. Find all C files recursively
ALL_SRCS := $(shell find src -name '*.c')

# 3. Intelligent Separation
# FIX: simplified grep to avoid syntax errors with parentheses.
# It looks for the whole word "main". 
# NOTE: Ensure you DELETE the main function from library files, don't just comment it out!
MAIN_SRCS := $(shell grep -l -w "main" $(ALL_SRCS))
LIB_SRCS := $(filter-out $(MAIN_SRCS), $(ALL_SRCS))

# 4. Define Targets
LIB_OBJS := $(patsubst src/%.c, obj/%.o, $(LIB_SRCS))
BINS := $(patsubst %.c, bin/%, $(notdir $(MAIN_SRCS)))

# 5. Tell Make where to look for .c files
# This creates a list of all folders containing code so Make can find them
SRC_DIRS := $(sort $(dir $(ALL_SRCS)))
vpath %.c $(SRC_DIRS)

# --- Targets ---

all: $(BINS)

# Rule for Libraries (Helpers) - Compile to Object file
obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for Executables (Apps) - Link with ALL Library Objects
bin/%: %.c $(LIB_OBJS)
	@mkdir -p bin
	$(CC) $(CFLAGS) $< $(LIB_OBJS) -o $@

clean:
	rm -rf bin obj

.PHONY: all clean
