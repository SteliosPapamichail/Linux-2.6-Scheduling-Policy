// csd4020 Stelios Papamichail

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "syscall_test.h"

void testValidSetAndGetPeriodParams()
{
    long result = setPeriodParams(1, 500, 10);
    printf("set_period_params returned %ld\n", result);
    struct period_params *params = malloc(sizeof(struct period_params *));
    if (!params)
    {
        printf("failed to allocate memory for period_params struct\n");
        exit(-1);
    }
    result = getPeriodParams(params);
    printf("get_period_params returned %ld and the params retrieved are:\nperiod = %d | exec_time = %d | numOfPeriods = %d\n",
           result, params->period, params->execution_time, params->num_of_periods);
}

void testSetPeriodParamsWithInvalidArgs()
{
    long result = setPeriodParams(-5, 400, 10);
    printf("called set_period_params(-5,400,10) and returned %ld\n", result);
    result = setPeriodParams(1, -5, 10);
    printf("called set_period_params(1, -5, 10) and returned %ld\n", result);
    result = setPeriodParams(2, 500, -1);
    printf("called set_period_params(1, 5, -1) and returned %ld\n", result);
    result = setPeriodParams(1, 5000, 10);
    printf("called set_period_params(1, 5000, -1) and returned %ld\n", result);
}

void testGetPeriodParamsWithInvalidArgs() {
    long result = getPeriodParams(NULL);
    printf("called get_period_params(NULL) and returned %ld\n",result);
}

int main(void)
{
    printf("--- Choose a test ---\n\t1. Call set_period_params with valid args\n\t(period == 1 (s), execution_time == 500 (ms), numOfPeriods = 10) and then\n\tcall get_period params (period_params != NULL)\n\t2. Call set_period params four times (3 times with a negative argument and one with period < exec_time).\n\t3. Call get_period_params with period_params == NULL.\n\t4. Exit\n---------------------\n");
    char choice;

    while ((choice = fgetc(stdin)) != -1)
    { // while not eof
        switch (choice)
        {
        case '1':
            testValidSetAndGetPeriodParams();
            break;
        case '2':
            testSetPeriodParamsWithInvalidArgs();
            break;
        case '3':
            testGetPeriodParamsWithInvalidArgs();
            break;
        case '4':
            exit(0);
            break;
        default:
            printf("Invalid input, try again\n");
            break;
        }
    }
    return 0;
}