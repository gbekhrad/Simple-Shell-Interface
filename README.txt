Name: Gabriella (Gabi) Bekhrad
Email: gbekhrad@chapman.edu
ID: 2417841

Title of Assignment: Programming Assignment 2 - Simple Shell Interface

Overview/Source Files:
- sshell.c: C program that simulates a shell interface, allowing users to input commands and run them on the terminal.  

To compile:
gcc -o sshell sshell.c

To run:
./sshell

Sample input and output:
(Note: text wrapped like *this* is not input or output. It describes what is happening.)

1. 
osh>pwd
/Users/gabibekhrad/CPSC_Courses/cpsc380/Assignment_2

2.
osh>ls
README.txt      sshell          sshell.c

3.
osh>mkdir tester
*a tester directory is created.*

4.
osh>ls -l
total 88
-rw-r--r--@ 1 gabibekhrad  staff    278 Sep 28 19:38 README.txt
-rwxr-xr-x@ 1 gabibekhrad  staff  34088 Sep 28 22:35 sshell
-rw-r--r--@ 1 gabibekhrad  staff   2503 Sep 28 22:34 sshell.c
drwxr-xr-x@ 2 gabibekhrad  staff     64 Sep 28 22:36 tester

5.
osh>sleep 5
*the shell waits 5 seconds before allowing the osh> prompt to appear again.*

6. 
osh>sleep 5 &
*the shell does not wait and the osh> prompt reappears immedietly.*

7.
osh>exit
*the program exits the shell and terminates.*

Sources:
https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm 
https://www.geeksforgeeks.org/strcmp-in-c/
https://www.geeksforgeeks.org/string-tokenization-in-c/
https://www.w3schools.com/c/c_booleans.php 