BUILD_DIR = build
SRC_DIR = src

LOGIC_DIR = $(SRC_DIR)/logic
GRAPHIC_DIR = $(SRC_DIR)/graphic

LOGIC_SRCS = $(wildcard $(LOGIC_DIR)/*.c)
GRAPHIC_SRCS = $(wildcard $(GRAPHIC_DIR)/*.c)
MAIN_SRC = $(SRC_DIR)/main.c

LOGIC_OBJS = $(patsubst $(LOGIC_DIR)/%.c, $(BUILD_DIR)/%.o, $(LOGIC_SRCS))
GRAPHIC_OBJS = $(patsubst $(GRAPHIC_DIR)/%.c, $(BUILD_DIR)/%.o, $(GRAPHIC_SRCS))
MAIN_OBJ = $(BUILD_DIR)/main.o

LIBS = -lraylib -ldl -lpthread -lm -lX11

all: $(LOGIC_OBJS) $(GRAPHIC_OBJS) $(MAIN_OBJ)
	gcc $^ -o $(BUILD_DIR)/main $(LIBS)

$(BUILD_DIR)/%.o: $(LOGIC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	gcc -c $< -o $@

$(BUILD_DIR)/%.o: $(GRAPHIC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	gcc -c $< -o $@

$(BUILD_DIR)/main.o: $(MAIN_SRC)
	mkdir -p $(BUILD_DIR)
	gcc -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean
