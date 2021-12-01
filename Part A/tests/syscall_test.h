// csd4020 Stelios Papamichail

#define __NR_set_period_params 341
#define __NR_get_period_params 342

struct period_params {
  int period;
  int execution_time;
  int num_of_periods;
};

// define syscall wrapper functions
long setPeriodParams(int period, int executionTime, int numOfPeriods) {
    return syscall(__NR_set_period_params, period, executionTime, numOfPeriods);
}

long getPeriodParams(struct period_params *periodParams) {
    return syscall(__NR_get_period_params, periodParams);
}

// test functions
void testValidSetAndGetPeriodParams();
void testSetPeriodParamsWithInvalidArgs();
void testGetPeriodParamsWithInvalidArgs();