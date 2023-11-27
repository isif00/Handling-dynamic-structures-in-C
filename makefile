BUILD_DIR = build

SRCS = src/main.c

OBJS = $(BUILD_DIR)/main.o

LIBS = -lraylib -ldl -lpthread -lm -lX11

all: $(OBJS)
	gcc $^ -o $(BUILD_DIR)/main $(LIBS)

$(BUILD_DIR)/%.o: src/%.c
	mkdir -p $(BUILD_DIR)
	gcc -c $< -o $@ 

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean
