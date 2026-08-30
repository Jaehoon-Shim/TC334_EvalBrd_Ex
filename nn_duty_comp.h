/*
 * nn.h
 * Author: Jaehoon Shim
 */

#ifndef NN_DUTY_COMP_H
#define NN_DUTY_COMP_H

#include "Ifx_Types.h"
#include "IfxStm_reg.h"

#define NN_INPUT_NUM 2
#define HIDDEN_NUM 8

extern volatile float duty_comp;
extern volatile float duty_comp_normalized;

extern volatile float hidden_output1[HIDDEN_NUM];
extern volatile float hidden_output2[HIDDEN_NUM];
extern volatile float nn_input[NN_INPUT_NUM];
extern volatile float input_normalized[NN_INPUT_NUM];

/* Te 입력으로 Id, Iq를 계산합니다. */
void NN_Run(volatile float *x);

#endif /* NN_DUTY_COMP_H */


