PROGRAM_NAME = printer

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): main.o file.o
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@
