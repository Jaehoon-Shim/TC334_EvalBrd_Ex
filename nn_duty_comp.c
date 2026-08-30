/*
 * nn_duty_comp.c
 * Author: Jaehoon Shim
 */
#include "nn_duty_comp.h"
#include "TimeMeasure.h"

/* =========================================================
 * Live Expression variables
 * ========================================================= */
/* Check these outputs in Live Expressions. */
volatile float duty_comp = 0.0f;
volatile float duty_comp_normalized = 0.0f;
volatile float nn_input[NN_INPUT_NUM] = { 0.0f};
volatile float input_normalized[NN_INPUT_NUM] = { 0.0f};
/* Optional variables for debugging. */
volatile float hidden_output1[HIDDEN_NUM];
volatile float hidden_output2[HIDDEN_NUM];

/* =========================================================
 * MINMAX parameters
 * ========================================================= */
const float x_mean[NN_INPUT_NUM] = { 19.3500003f, 5.6999998f};
const float x_std[NN_INPUT_NUM] = { 7.6861882f, 2.8913664f};

const float y_mean = 0.0186292f;
const float y_std  = 0.0079966f;

/* =========================================================
 * NN parameters
 * ========================================================= */
/* Auto-generated PyTorch ANN parameters */
/* Weight layout: [input][output] */

/* Auto-generated PyTorch ANN parameters */
/* Weight layout: [input][output] */

const float nn_theta1[2][8] = {
    {0.3151028f, -0.1241558f, -0.6838506f, -0.2395691f, 0.4990348f, 0.6233454f, 0.617714f, 0.1208064f},
    {0.4777145f, 1.007845f, 0.6520342f, 0.5349746f, -0.8614089f, -0.1329424f, -0.205713f, -0.3152544f}
};

const float nn_bias1[8] = {0.8589545f, 0.1721523f, 0.1135765f, -0.097589f, 0.0943438f, -0.0793273f, -0.1075126f, 0.8695908f};

const float nn_theta2[8][8] = {
    {0.2677215f, 0.0607561f, -0.0337441f, 0.1432817f, -0.048235f, 0.4675046f, 0.1518542f, -0.0710826f},
    {0.3666378f, -0.1723296f, -0.2538886f, -0.283438f, -0.1832457f, 0.3625215f, -0.5303402f, -0.0803695f},
    {-0.1437531f, -0.4261358f, -0.023328f, 0.3844036f, 0.1309494f, 0.9249122f, -0.1070448f, -0.0021406f},
    {0.2643759f, 0.0232217f, 0.1379268f, -0.1500601f, -0.4483956f, 0.2693879f, -0.4082317f, -0.0628518f},
    {-0.1700949f, 0.2797201f, 0.4564658f, 0.000772f, 0.2865962f, -0.3337827f, -0.0564348f, 0.f},
    {0.0770898f, 0.391928f, -0.064348f, 0.3107053f, -0.1426474f, -0.1254344f, -0.0087963f, -0.0666457f},
    {0.0588325f, 0.1453932f, 0.2720139f, 0.1304846f, 0.1850772f, 0.4074328f, -0.0015009f, -0.0709548f},
    {-0.5801303f, 0.101062f, 0.495655f, 0.5485969f, 0.2811126f, -0.1481606f, 0.6511366f, -0.085583f}
};

const float nn_bias2[8] = {-0.4114769f, 0.0930404f, 0.364321f, 0.299761f, 0.6532192f, 0.6143016f, 0.1387826f, -0.0693412f};

const float nn_theta3[8][1] = {
    {0.5473634f},
    {0.0451242f},
    {-0.2897749f},
    {-0.3494499f},
    {-0.5359469f},
    {0.4663092f},
    {0.0926526f},
    {0.0436686f}
};

const float nn_bias3[1] = {0.2920245f};



TimeManager NN_Time1 = {0.0f};
TimeManager NN_Time2 = {0.0f};
TimeManager NN_Time3 = {0.0f};
TimeManager NN_Time4 = {0.0f};
TimeManager NN_Time5 = {0.0f};


/* =========================================================
 * NN calculation
 * ========================================================= */
void NN_Run(volatile float *x)
{
    unsigned int i;
    unsigned int j;


    /* =====================================================
     * 1. Input standardization
     *
     * x[0] = Vref
     * x[1] = Iout
     * ===================================================== */
    START_TICK_MANAGER(NN_Time1);
    for (i = 0U; i < NN_INPUT_NUM; i++)
    {
        input_normalized[i] = (x[i] - x_mean[i]) / x_std[i];
    }
    END_TICK_MANAGER(NN_Time1);


    /* =====================================================
     * 2. Hidden layer 1
     *
     * 2 -> 8 Linear + ReLU
     * ===================================================== */
    START_TICK_MANAGER(NN_Time2);
    for (j = 0U; j < HIDDEN_NUM; j++)
    {
        hidden_output1[j] = nn_bias1[j];
        for (i = 0U; i < NN_INPUT_NUM; i++)
        {
            hidden_output1[j] +=input_normalized[i]* nn_theta1[i][j];
        }
        if (hidden_output1[j] < 0.0f)
        {
            hidden_output1[j] = 0.0f;
        }
    }
    END_TICK_MANAGER(NN_Time2);


    /* =====================================================
     * 3. Hidden layer 2
     *
     * 8 -> 8 Linear + ReLU
     * ===================================================== */
    START_TICK_MANAGER(NN_Time3);

    for (j = 0U; j < HIDDEN_NUM; j++)
    {
        hidden_output2[j] = nn_bias2[j];
        for (i = 0U; i < HIDDEN_NUM; i++)
        {
            hidden_output2[j] += hidden_output1[i]* nn_theta2[i][j];
        }
        if (hidden_output2[j] < 0.0f)
        {
            hidden_output2[j] = 0.0f;
        }
    }
    END_TICK_MANAGER(NN_Time3);


    /* =====================================================
     * 4. Output layer
     *
     * 8 -> 1 Linear
     *
     * Regression output:
     * ReLU and Softmax are not applied.
     * ===================================================== */
    START_TICK_MANAGER(NN_Time4);
    duty_comp_normalized = nn_bias3[0];
    for (i = 0U; i < HIDDEN_NUM; i++)
    {
        duty_comp_normalized += hidden_output2[i]* nn_theta3[i][0];
    }
    END_TICK_MANAGER(NN_Time4);


    /* =====================================================
     * 5. Output denormalization
     *
     * duty_comp = Delta Duty
     * ===================================================== */
    START_TICK_MANAGER(NN_Time5);
    duty_comp = duty_comp_normalized * y_std + y_mean;
    END_TICK_MANAGER(NN_Time5);
}




