CC := gcc
OPT ?= 2
EXT ?= 
CFLAGS := -O$(OPT)

OBJ := hrpkg.o handlePkg.o utils.o build.o

all: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o hrpkg$(EXT)

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

clean:
	rm -f $(OBJ)
	rm -f hrpkg$(EXT)
