run: app
	../bin/app.exe ../data/defect.txt ../data/defect2.txt ../data/defect3.txt > ../data/out/terminal.txt
app: main.o getdefect.o assign.o
	gcc -o ../bin/app.exe ../obj/main.o ../obj/getdefect.o ../obj/assign.o
main.o: ../src/main.c
	gcc -o ../obj/main.o ../src/main.c -c
getdefect.o: ../src/getdefect.c
	gcc -o ../obj/getdefect.o ../src/getdefect.c -c
assign.o: ../src/assign.c
	gcc -o ../obj/assign.o ../src/assign.c -c
clean:
	rm ../obj/*.o ../bin/*.exe ../data/out/*.txt
test: ../../ToolsReport/CUnit/testprogram.c ../../ToolsReport/CUnit/func.c
	gcc -o ../../ToolsReport/CUnit/test.exe ../../ToolsReport/CUnit/testprogram.c ../../ToolsReport/CUnit/func.c -lcunit
	../../ToolsReport/CUnit/test.exe > ../../ToolsReport/CUnit/cunitReport.txt
