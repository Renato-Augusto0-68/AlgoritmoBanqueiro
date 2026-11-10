banker: main.c functions/lerdados.c functions/lerdados.h functions/dados.h functions/comandos.h
	gcc functions/lerdados.c main.c  -o banker

run: banker
	./banker

clean:
	rm -f banker

.PHONY: run clean