char buffer[128];
int status;

Write("Bienvenue dans le Shell ENSEA.\n");
Write("Pour quitter, tapez 'exit'.\n");

while (1) {
    Write("enseash\n");
    ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);

    if (bytesRead > 0) {
        buffer[bytesRead - 1] = '\0'; // Remove the newline \n character

        if (strcmp(buffer, "exit") == 0) { // Compares the string stored in buffer with 'exit' if identical returns 0
            break;
        }

        pid_t pid = fork();

        if (pid == 0) {
            execlp(buffer, buffer, (char *) NULL);
            _exit(127); // Command not found
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        }
    }
}

custom_write("Bye Bye...\n");
return 0;