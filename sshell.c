#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void){
    char *args[MAX_LINE/2+ 1]; // command line arguments
    int should_run = 1; // flag to determine when to exit program

    char input[MAX_LINE]; // define user input

    while (should_run){
        printf("osh>");
        fflush(stdout);

        // if invalid input
        if (fgets(input, MAX_LINE, stdin) == NULL){
            perror("Invalid input.");
            should_run = 0;
        }

        // if user would like to exit
        input[strcspn(input, "\n")] = 0; // Remove newline char
        if (strcmp(input, "exit") == 0){
            should_run = 0; // exit the while loop
            break;
        }

        // follow the guideline of strtok(str, delimiter) 
        char *command = strtok(input, " \n"); // string of unknown size, tokenize input to separate commands
        
        bool hasAmpersand = false; // to keep track if there is an ampersand
        int i = 0; // int to store tokens in args array

        while (command != NULL){ // while there is a command
            if (strcmp(command, "&") == 0){ // if there is an ampersand
                hasAmpersand = true; // set to true so it can be handled accordingly
            } else {
                args[i] = command; // update the index, store in the args array
                i++;
            } // get the next token
            command = strtok(NULL, " \n"); // pass null to continue from where the last loop left off
        }
        
        args[i] = NULL;  // null terminate args array
        pid_t pid; // Create a variable to store the pid number
        pid = fork(); // Fork a child process

        if (pid < 0){ // Handle the error 
            perror("Fork failed.");
            return -1;
        } else if (pid == 0){ // Fork a child process using fork
            if (execvp(args[0], args) == -1){ // if when you execute the command it failts
                perror("Failed to execute the command.");
            }
            return -1; // In case it fails. 
        } else { // Parent process
            if (hasAmpersand == false){
                // check whether the user included (&) to determine whether or not the parent process is to wait for the child to exit.
                waitpid(pid, NULL, 0);
            }
        }       
    }
    wait(NULL); // null because the child isn't returning anything 
}