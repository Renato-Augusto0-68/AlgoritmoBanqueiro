banker: main.c
	gcc main.c -o banker

run: banker
	./banker

clean:
	rm -f *.o banker

.PHONY: run clean