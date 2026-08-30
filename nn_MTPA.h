/*
 * nn.h
 * Author: Jaehoon Shim
 */

#ifndef NN_H
#define NN_H

#include "Ifx_Types.h"
#include "IfxStm_reg.h"

#define HIDDEN_NUM 20

extern volatile float Id_MTPA;
extern volatile float Iq_MTPA;
extern volatile float hidden_output[HIDDEN_NUM];
extern volatile float nn_input[1];

/* Te 입력으로 Id, Iq를 계산합니다. */
void NN_Run(volatile float *x);

#endif /* NN_H */


