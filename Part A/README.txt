Stelios Papamichail csd4020

--- Kernel edits/additions ---

The first thing I did was to define the syscall numbers for the two new system calls in the
/arch/x86/include/asm/unistd_32.h file as well as update the total syscall count. Once that was done,
I added two new entries in the /arch/x86/kernel/syscall_table_32.S file in order to define the
function pointers for the two new syscalls.
Then I created the /include/linux/period_params.h file that includes the definition for the struct.
Next up, I defined the two system call functions in the /include/asm-generic/syscalls.h file
and also included the "period_params.h" file since it's needed for the argument of the sys_get_period_params
syscall. Furthermore, I modified the task_struct in the /include/linux/sched.h file in order to add
the three new fields for our future scheduling policy (period, execution_time and num_of_periods)
at the top of the struct's definition (around line 1200). From then on, I implemented the syscalls
in the /kernel/set_period_params.c and /kernel/get_period_params.c files and edited the /kernel/Makefile
in order to include these new syscalls in the kernel's compilation.

--- System call implementation details ---

The implementations are pretty straightforward. For the set_period_params, after printing the kernel
message, I check if any of the given args is < 0 and/or if the period < exec_time and if so, I return
EINVAL. Otherwise, I access the current task through get_current(), edit the appropriate fields with
the given values and return 0.
For the get_period_params, I check if the given struct is NULL, if it is I return EINVAL. Next up,
I again retrieve the current task_struct, copy the scheduling related fields to the period_params
struct and then I check if the given address of the struct is accessible and in the user-space. If
it is not, I return EINVAL, otherwise I attempt to write at that memory location the given updated
struct. If it succeeds, I return 0, otherwise EINVAL.

--- Test description ---

I wrote a single test that uses wrapper functions to call the appropriate system calls. I added a
prompt that allows us to select 3 possible tests that are described there so I'm going to avoid
repeating them. The test covers valid usage of the system calls, the case of passing invalid args
to the set_period_params as well as the get_period_params syscalls. It prints the arguments
that each syscall was called with as well as the returned value. 

Once you are done using the test, you can simply use "dmesg" to see the respective kernel messages
that were printed due to the usage of the tests (my name, A.M & error messages) :)

P.S. I know that in my test, the default case in the switch statement runs even though the input was
valid but I decided to avoid fixing it due to time constraints :(