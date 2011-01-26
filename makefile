# Formato:
# resultado: dependencia1 dependencia2 ...
#	comando para su compilación

tarea: almacenamiento.o main.o
	gcc almacenamiento.o main.o -o tarea

main.o: main.c main.h almacenamiento.h
	gcc -c main.c

almacenamiento.o: almacenamiento.c almacenamiento.h
	gcc -c almacenamiento.c

clean: 
	rm *.o tarea