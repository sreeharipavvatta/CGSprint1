# Defect Programmer Application
This project aims to develop a Defect Programmer Assignments application where clients of a Software Development company report defects in software they purchased. These defects are assigned to programmers depending on the functional area they are handling.

Read complete [SRS](Project/SRS/SRS_DefectProgrammer.pdf) Document here.

## Directory Structure
1. [Project](Project/): Main Project folder.
   1. [Cut](Project/CUT/)
      1. [Code](Project/CUT/Code/)
         1. [Bin](Project/CUT/Code/bin/): Contains executable file.
         2. [Data](Project/CUT/Code/data/): Contains input data file.   
            1. [out](Project/CUT/Code/data/out/): Contains output files generated after execution of program.
         3. [Header](Project/CUT/Code/Header/): Contains all header files.
         4. [Make](Project/CUT/Code/Make/): Contains Makefile.
         5. [Obj](Project/CUT/Code/obj/): Contains compiled object files.
         6. [SRC](Project/CUT/Code/SRC/): Contains source code.
      2. [CodeInspectionLog](Project/CUT/CodeInspectionLog/)
      3. [ToolsReport](Project/CUT/ToolsReport/)
         1. [CUnit](Project/CUT/ToolsReport/CUnit/): Contains Unit Testing Report
         2. [Splint](Project/CUT/ToolsReport/Splint/): Contains Splint Test Report
         3. [Valgrind](Project/CUT/ToolsReport/Valgrind/): Contains Valgrind Test Report
      4. [UT&ITReport](Project/CUT/UT_IT%20Plan%20Reports/)
   2. [Design](Project/DESIGN/): Contains Code & Design Review Checklist Documents and Pseudocodes.
   3. [Plan](Project/Plan/): Contains Minutes of Meetings & Sprint Schedule.
   4. [RTM](Project/RTM/): Contains Requirement Tracibility Matrix Document.
   5. [SRS](Project/SRS/): Contains our SRS {Software Requirement Specification} Document.
   6. [Storyboard](Project/Storyboard/)
2. [README](README.md): Introductory file.
3. [Checklist](checklist.md): Contains checklist of entire project.

## Input Files
### Defect File Format
```
Defect_ID:Description:Module_Name:Functional_Area:Filed_On_Date:Status:Type
```
### Employee File Format
```
EmpID:Emp_Name:Business_Unit:Expertise:Designation
```
## Acknowledgement
This project is part of Capgemini Post-Onboarding Freshers Training.

*Batch: E2E-Manipal-Systems C CPP Linux Programming PT Aug 4th Batch2*
## Contributors:
- [Aman Bhaskar](https://github.com/amanbh2)
- [Karan Nareshbhai Telar](https://github.com/telarKaran)
- [Krishna Chaitanya Chekka](https://github.com/Chaitu1018)
- [Sreehari  Ps](https://github.com/sreeharipavvatta)
- [Singuluri Sai Vamsee Krishna](https://github.com/ssvk053)
