# Advent of Code 2020 Makefile
# Gonna be lazy and manually update this with targets rather than autogenning it

BUILD	   := build
SOURCEDIR  := src
BIN_DIR    := bin

COMMON_SRC  := $(wildcard $(SOURCEDIR)/common/*.c)
COMMON_OBJ  := $(BUILD)/common/$(notdir $(COMMON_SRC:.c=.o))

all: 1p1.out 1p2.out

$(BUILD)/%.o: $(SOURCEDIR)/%.c Makefile | setup_builddir
	@printf "\033[1mCC\033[0m    $<\n"
	@$(CC) $(CFLAGS) -c $< -o $@

setup_builddir:
	@mkdir -p $(BUILD)
	@mkdir -p $(BUILD)/common
clean:
	@printf "\033[1mCLEAN\033[0m \n"
	@find $(BUILD) -type f -name '*.o' -exec rm {} +
	@find $(BIN_DIR) -type f -name '*.out' -exec rm {} +

1p1.out: $(BUILD)/1p1.o $(COMMON_OBJ)
	@$(CC) $^ -o $(BIN_DIR)/$@
	@printf "\033[1mLINK\033[0m    $@\n"
1p2.out: $(BUILD)/1p2.o $(COMMON_OBJ)
	@$(CC) $^ -o $(BIN_DIR)/$@
	@printf "\033[1mLINK\033[0m    $@\n"
