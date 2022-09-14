run: app
	../bin/defectProgrammer.exe ../data/defect.txt ../data/defect2.txt ../data/defect3.txt > ../data/out/terminal.txt
app: main.o getdefect.o assign.o
	gcc -o ../bin/defectProgrammer.exe ../obj/main.o ../obj/getdefect.o ../obj/assign.o -lpthread
main.o: ../SRC/main.c
	gcc -o ../obj/main.o ../SRC/main.c -c
getdefect.o: ../SRC/getdefect.c
	gcc -o ../obj/getdefect.o ../SRC/getdefect.c -c
assign.o: ../SRC/assign.c
	gcc -o ../obj/assign.o ../SRC/assign.c -c
clean:
	rm ../obj/*.o ../bin/*.exe ../data/out/*.txt
test: ../../ToolsReport/CUnit/testprogram.c ../../ToolsReport/CUnit/func.c
	gcc -o ../../ToolsReport/CUnit/test.exe ../../ToolsReport/CUnit/testprogram.c ../../ToolsReport/CUnit/func.c -lcunit
	../../ToolsReport/CUnit/test.exe > ../../ToolsReport/CUnit/cunitReport.txt
