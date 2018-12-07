*.pdf : *.dat plots.py
	python plots.py
*.dat : ejercicio1_c
	./ejercicio1_c

ejercicio1_c : ejercicio1.c
	gcc ejercicio1.c -lm -o ejercicio1_c

clean :
	rm *.dat  *_c
