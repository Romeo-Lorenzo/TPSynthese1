//
// Created by lorenzo on 27/11/24.
//

#include "Prompt.h"

#define BUFFER_SIZE 128

int Prompt(void) {
    char buffer[BUFFER_SIZE];
    int status;

    Write("Bienvenue dans le Shell ENSEA.\n");
    Write("Pour quitter, tapez 'exit'.\n");
    Write("Else write the name of the function that you wish to call.\n");

    while (1) {
        Write("enseash\n");
        ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

        if (bytesRead > 0) {
            buffer[bytesRead - 1] = '\0';   // Remove the newline \n character

            if (strcmp(buffer, "exit") == 0) {  // Compares the string stored in buffer with 'exit', if identical returns 0
                break;
            }

            // Parse the command and arguments
            char *args[BUFFER_SIZE];  // Array to hold command and up to 9 arguments
            char *token = strtok(buffer, " "); // divides buffer around the space " "
            int i = 0;
            char *inputFile = NULL;
            char *outputFile = NULL;

            while (token != NULL && i < BUFFER_SIZE) {
                if (strcmp(token, "<") == 0) {
                    token = strtok(NULL, " ");
                    if (token) inputFile = token;
                } else if (strcmp(token, ">") == 0) {
                    token = strtok(NULL, " "); // Move to the next token, which should be the output file name
                    if (token) outputFile = token; // Assign the next token to outputFile if it's not NULL
                } else {
                    args[i++] = token;
                }
                token = strtok(NULL, " ");
            }
            args[i] = NULL; // null terminates the arguments

            getTimeStart();
            pid_t pid = fork();     // create child process

            if (pid == 0) { // child process
                if (inputFile) {    // if input token then passes input file to redirect
                    redirect_input(inputFile);
                }
                if (outputFile) {
                    redirect_output(outputFile);    // analog to previous if
                }
                execvp(args[0], args);
                perror("execvp");   // not normally executed
                exit(EXIT_FAILURE);     // not normally executed
            } else if (pid > 0) {
                waitpid(pid, &status, 0);   // child process is over
                getTimeEnd();
                showElapsedTime();
            }
        }
    }

    Write("Bye Bye...\n");
    return 0;
}
