CC = gcc
LD = gcc

%.o: %.c
	$(CC) -c $< -o $@

all: main

main: main.o pow.o
	$(LD) $^ -o $@

inject: inject.c
	$(CC) $< -o $@

fake.raw: fake.o
	objcopy -O binary -j .text $< $@

hack: main fake.raw inject
	cp $< $@
	./inject $@ fake.raw \
	$(shell objdump -d $< | awk '/<int_pow>:/ {printf $$1}')

.PHONY: clean
clean:
	rm -f *.o *.raw main hack inject

