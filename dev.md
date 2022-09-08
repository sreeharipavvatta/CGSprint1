# Developers Only
## Instructions
- Before you start making edits make sure:
  - You are in main branch. {Always update main branch only.}
  - Pull {sync changes} from GitHub so that you have updated code.
  - Create a new branch.
  - Cross check you are now working in new branch only.
- Now as we have our main file you can use it to test your function.
- Check Commands below.

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
To clean executable and object files created:
```
cd Project/CUT/Code/Make
make clean
```
