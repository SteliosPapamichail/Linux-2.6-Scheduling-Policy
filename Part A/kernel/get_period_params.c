#include <linux/kernel.h>
#include <asm/uaccess.h>
#include <linux/period_params.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <asm/current.h>

asmlinkage long sys_get_period_params(struct period_params * params) {
        struct task_struct * curr_proc;
        printk("Stelios Papamichail csd4020 from [get_period_params]\n");
        if(params == NULL) {
                printk("Params struct was NULL\n");
                return EINVAL;
        }
        curr_proc = get_current();
        params->period = curr_proc->period;
        params->execution_time = curr_proc->execution_time;
        params->num_of_periods = curr_proc->num_of_periods;
        if(access_ok(VERIFY_WRITE, (void *) params, sizeof(struct period_params *)) != 0) {
                return EINVAL;
        }
        if(copy_to_user((void *) params,(void *) params,sizeof(struct period_params *)) != 0) {
                return EINVAL;
        }
        return 0;
}
