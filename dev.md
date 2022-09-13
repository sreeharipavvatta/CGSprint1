# Developers Only
## Instructions
- Before you start making edits make sure:
  - You are in main branch. {Always update main branch only.}
  - Pull {sync changes} from GitHub so that you have updated code.
  - Create a new branch.
  - Cross check you are now working in new branch only.
- Now as we have our main file you can use it to test your function.
- Check [Commands](#commands) below.

## Commands
To pull from GitHub {everyday first step}
```
git pull origin
```
To compile and create executable file with sample defect test file:
```
cd Project/CUT/Code/Make
make app
```
To run executable file:
```
cd Project/CUT/Code/bin
./app.exe ../data/defect.txt
```
To compile and run executable sequentially { Above two steps combined into one }:
```
cd Project/CUT/Code/Make
make run
```

To clean executable, object files and output files generated:
```
cd Project/CUT/Code/Make
make clean
```
### Unit Testing
To test and to generate CUnit report:
```
cd Project/CUT/Code/Make
make test
```