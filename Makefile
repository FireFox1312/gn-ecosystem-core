# ==============================================================================
# gn-ecosystem-core — Makefile
# ==============================================================================

# Compilador e flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Wpedantic -std=c17 -g
INCLUDES = -Iinclude

# Diretórios
SRC_DIR   = src
BUILD_DIR = build

# Detecta todos os .c em src/
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

# Nome do executável
TARGET = $(BUILD_DIR)/catalog.exe

# ==============================================================================
# Regras
# ==============================================================================

all: $(TARGET)
	@echo [OK] Build concluido: $(TARGET)

$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@echo [OK] Build limpo.

run: all
	@$(TARGET)

.PHONY: all clean run
