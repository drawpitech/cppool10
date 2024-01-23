##
## EPITECH PROJECT, 2024
## MyCat
## File description:
## Makefile
##

CXX := g++ -std=c++20
CXXFLAGS := -W -Wall -Wextra -Wunused -Wpedantic
CXXFLAGS += -Wundef -Wshadow -Wcast-align
CXXFLAGS += -Wcast-qual
CXXFLAGS += -Wunreachable-code
CXXFLAGS += -U_FORTIFY_SOURCE
CXXFLAGS += -iquote ./.
CXXFLAGS += -lcriterion
CXXFLAGS += --coverage -g3
CXXFLAGS += -fprofile-arcs -ftest-coverage
LDFLAGS :=

NAME := unit_tests
NAME_ASAN := $(NAME)_asan

VPATH := .
SRC := $(wildcard *.cpp)
SRC += $(wildcard tests/*.cpp)

BUILD_DIR := .build
OBJ := $(SRC:%.cpp=$(BUILD_DIR)/normal/%.o)
OBJ_ASAN := $(SRC:%.cpp=$(BUILD_DIR)/asan/%.o)

all: $(NAME)

# ↓ Tests

$(BUILD_DIR)/normal/%.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

tests_run: $(NAME)
	@-./$<

.PHONY: tests_run $(NAME)

# ↓ Asan tests

$(BUILD_DIR)/asan/%.o: %.cpp
	@ mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME_ASAN): $(OBJ_ASAN)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

tests_run_asan: $(NAME_ASAN)
	@-./$<

.PHONY: tests_run_asan $(NAME_ASAN)

re: fclean
	$(MAKE) $(MKFLAGS)

.PHONY: re

clean:
	$(RM) $(OBJ) $(OBJ:.o=.gcno) $(OBJ:.o=.gcda)
	$(RM) $(OBJ_ASAN) $(OBJ_ASAN:.o=.gcno) $(OBJ_ASAN:.o=.gcda)

fclean: clean
	$(RM) -r $(BUILD_DIR)
	$(RM) $(NAME) $(NAME_ASAN)

.PHONY: clean fclean

cov: GCOVR_FLAGS := --exclude bonus/
cov: GCOVR_FLAGS += --exclude tests/
cov:
	@ gcovr $(GCOVR_FLAGS)
	@ gcovr $(GCOVR_FLAGS) --branches

.PHONY: cov
