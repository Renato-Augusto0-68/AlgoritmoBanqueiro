banker: main.c functions/lerdados.c functions/lerdados.h functions/dados.h functions/comandos.h
	gcc functions/lerdados.c main.c  -o banker

run: banker
	./banker 10 5 7

clean:
	rm -f banker result.txt

.PHONY: run clean