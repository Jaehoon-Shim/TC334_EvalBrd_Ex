/*
 * nn_basic_diag.h
 * Author: Jaehoon Shim
 *
 * PyTorch FNN fault-classification inference for Infineon AURIX TC3xx.
 * Tensor-defined model: 18 -> 24 -> 24 -> 7, ReLU after hidden layers.
 * Input preprocessing: StandardScaler stored in fnn_fault_checkpoint.pt.
 * Output processing: stable softmax, argmax, Fault_ID, and confidence.
 */
#ifndef NN_BASIC_DIAG_H
#define NN_BASIC_DIAG_H

#include "Ifx_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NN_INPUT_NUM       (18U)
#define HIDDEN1_NUM        (24U)
#define HIDDEN2_NUM        (24U)
#define NN_OUTPUT_NUM      (7U)

/*
 * Required input order:
 * x[0..5]   = Ia_1, Ia_2, Ia_3, Ia_4, Ia_5, Ia_6
 * x[6..11]  = Ib_1, Ib_2, Ib_3, Ib_4, Ib_5, Ib_6
 * x[12..17] = Ic_1, Ic_2, Ic_3, Ic_4, Ic_5, Ic_6
 */

/* Final diagnosis result for Live Expressions / Watch. */
extern volatile uint32 Fault_ID;
extern volatile float Fault_Confidence;

/* Intermediate values for verification and debugging. */
extern volatile float nn_input[NN_INPUT_NUM];
extern volatile float nn_input_normalized[NN_INPUT_NUM];
extern volatile float hidden_output1[HIDDEN1_NUM];
extern volatile float hidden_output2[HIDDEN2_NUM];
extern volatile float nn_logits[NN_OUTPUT_NUM];
extern volatile float nn_probabilities[NN_OUTPUT_NUM];

/*
 * Runs one inference.
 * Result: Fault_ID is 0..6 and Fault_Confidence is the softmax probability.
 */
void NN_Run(volatile float *x);

#ifdef __cplusplus
}
#endif

#endif /* NN_BASIC_DIAG_H */
