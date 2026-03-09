# The compiler to use
CC = gcc

# Compiler flags: -Wall shows all warnings, -g adds debugging info
CFLAGS = -Wall -g

# The list of files to compile (based on your screenshot)
TARGETS = chainedlist CircularDoubledChainedList Inverser_tableau Produit_VecteurMatrice Produit_vectoriel

# Default rule: compile everything
all: $(TARGETS)

# Rule to compile each specific file
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Rule to clean up the folder (remove binaries)
clean:
	rm -f $(TARGETS)
