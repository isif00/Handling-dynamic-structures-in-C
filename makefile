BUILD_DIR = build

SRCS = $(wildcard src/*.c)

OBJS = $(patsubst src/%.c, $(BUILD_DIR)/%.o, $(SRCS))

LIBS = -lraylib -ldl -lpthread -lm -lX11

all: $(OBJS)
	gcc $^ -o $(BUILD_DIR)/main $(LIBS)

$(BUILD_DIR)/%.o: src/%.c
	mkdir -p $(BUILD_DIR)
	gcc -c $< -o $@ 

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean
