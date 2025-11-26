
/*
 * License:
 *
 * This file has been released under "unlicense" license
 * (https://unlicense.org).
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or distribute
 * this software, either in source code form or as a compiled binary, for any
 * purpose, commercial or non-commercial, and by any means.
 *
 * For more information about this license, please visit - https://unlicense.org
 */

/*
 * Author: Amit Choudhary
 * Email: amitchoudhary0523 AT gmail DOT com
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

// Function prototype for gcc flag -Werror-implicit-function-declaration.
void signal_handler_function(int signum);

void signal_handler_function(int signum)
{

    static long count = 0;

    count = count + 1;

    printf("\n");
    printf("--------------------------------------------------------------\n");
    printf("%s(): \"\"SIGNAL HANDLER FUNCTION CALLED\"\".\n", __FUNCTION__);
    printf("This process has woken up because the signal \"SIGUSR1\" (signal"
           " number %d) was received.\n", signum);
    printf("Now, this process will again go back to sleep.\n");
    printf("This signal handler has been called \"%ld\" %s till now.\n",
           count, (count > 1) ? "times" : "time");
    printf("--------------------------------------------------------------\n");

    return;

} // end of function signal_handler_function()

int main(void)
{

    struct sigaction sa;
    pid_t mypid = -1;
    int retval = -1;
    
    memset(&sa, 0, sizeof(sa));

    sa.sa_handler = signal_handler_function;

    retval = sigaction(SIGUSR1, &sa, NULL);

    if (retval < 0) {
        printf("\n%s(): Error: sigaction() returned error. Signal handler was"
               " not installed. Exiting...\n", __FUNCTION__);
        exit(EXIT_FAILURE);
    }

    printf("\n%s(): Signal handler installed successfully.\n", __FUNCTION__);

    mypid = getpid();

    while(1) {
        printf("\n%s(): The pid of this process is %d.\n", __FUNCTION__, mypid);
        printf("\n%s(): This process is going to sleep. This process will wake"
               " up when the signal \"SIGUSR1\" (signal number 10) will be"
               " received. If any other signal is received then the results are"
               " undefined.\n", __FUNCTION__);
        pause();
    }

    return 0;

} // end of function main()

