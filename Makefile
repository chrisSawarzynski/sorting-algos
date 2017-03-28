output: main.o Utils.o
	gcc main.o Utils.o -o output/sorting-algs.exe

main.o: main.c 
	gcc -c main.c

Utils.o: Config.o
	gcc -c -o utils.o Config.o

Config.o:  Config/Config.h Config/Config.c
	gcc -c -o Config.o Config/Config.c



clean:
	rm *.o; rm output/*.exe
