BUILD_DIR = build

SRCS = src/main.c

OBJS = $(BUILD_DIR)/main

all: $(OBJS)

$(BUILD_DIR)/%.o: src/%.c
	mkdir -p $(BUILD_DIR)
	gcc -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean
