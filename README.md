
File "signal_handler_example.c" gives an example of how to install a user
defined signal handler that will override the signal handler provided by the
system for that signal.

In this file, we install a signal handler for the signal "SIGUSR1" (signal
number 10).

This program, on startup, goes to sleep waiting for the signal "SIGUSR1". When
the signal "SIGUSR1" is sent to this program, this program wakes up and the
user's signal handler function is called. After the signal handler function
returns, this program again goes back to sleep waiting for the signal "SIGUSR1".
This goes on in an endless loop until the user terminates the program.

If any other signal is sent to this program then the results are undefined.

You can send the signal "SIGUSR1" to this program by running the following
command in a terminal shell (bash, etc.):

            kill -10 pid_of_this_program

So, if the pid of this program is 14753, then you can send "SIGUSR1" signal to
this program as follows:

            kill -10 14753

This program prints its pid on the output screen, so you can use that pid
directly, instead of grepping the output of "ps -aef".

---- End of README ----
