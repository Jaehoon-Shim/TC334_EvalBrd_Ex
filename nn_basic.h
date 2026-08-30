/*
 * nn_basic.h
 * Author: Jaehoon Shim
 *
 * PyTorch FNN inference for Infineon AURIX TC3xx (iLLD).
 * Model: [1, 8, 8, 8, 1], ReLU after the three hidden layers.
 * Input/output preprocessing: StandardScaler saved in the checkpoint.
 */
#ifndef NN_BASIC_H
#define NN_BASIC_H

#include "Ifx_Types.h"
#include "IfxStm_reg.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NN_INPUT_NUM       (1U)
#define HIDDEN1_NUM        (8U)
#define HIDDEN2_NUM        (8U)
#define HIDDEN3_NUM        (8U)
#define NN_OUTPUT_NUM      (1U)


/* Live-watch variables. */
extern volatile float nn_output;
extern volatile float nn_input[NN_INPUT_NUM];
extern volatile float hidden_output1[HIDDEN1_NUM];
extern volatile float hidden_output2[HIDDEN2_NUM];
extern volatile float hidden_output3[HIDDEN3_NUM];

/* x[0] = data1, FNN_Output = inferred data2. */
void NN_Run(volatile float *x);

#ifdef __cplusplus
}
#endif
#endif /* NN_BASIC_H */
