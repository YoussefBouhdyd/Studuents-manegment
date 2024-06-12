CC = gcc
TARGET = main
SRCS = Affiche.c Ajoute.c main.c Modifier.c Recherche.c Supprime.c Trie.c Utile.c

# Determine the platform
ifeq ($(OS),Windows_NT)
    RM = del /Q
    EXE = $(TARGET).exe
else
    RM = rm -f
    EXE = $(TARGET)
endif

$(EXE): $(SRCS)
	$(CC) $^ -o $@

.PHONY: clean

clean:
	$(RM) $(EXE)