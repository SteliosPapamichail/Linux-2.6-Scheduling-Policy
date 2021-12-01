#include <linux/kernel.h>
#include <linux/errno.h>
#include <asm/uaccess.h>
#include <asm/current.h>
#include <linux/sched.h>

asmlinkage long sys_set_period_params(int period, int execution_time, int num_of_periods) {
        struct task_struct * current_process;
        printk("Stelios Papamichail csd4020 [set_period_params]\n");
        if(period < 0 || execution_time < 0 || num_of_periods < 0) {
                printk("Params cannot be negative!\n");
                return EINVAL;
        }
        if(period*1000 < execution_time) {
                printk("Execution time is larger than the period!\n");
                return EINVAL;
        }
        current_process = get_current();
        current_process->period = period;
        current_process->execution_time = execution_time;
        current_process->num_of_periods = num_of_periods;
        return 0;
}
