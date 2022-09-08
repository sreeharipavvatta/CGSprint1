app: main.o getdefect.o
	gcc -o ../bin/app.exe ../obj/main.o ../obj/getdefect.o
main.o: ../src/main.c
	gcc -o ../obj/main.o ../src/main.c -c
getdefect.o: ../src/getdefect.c
	gcc -o ../obj/getdefect.o ../src/getdefect.c -c
clean:
	rm ../obj/*.o ../bin/*.exe
