/*
 * nn_MTPA.c
 * Author: Jaehoon Shim
 */
#include "nn_MTPA.h"
#include "TimeMeasure.h"

/* =========================================================
 * Live Expression variables
 * ========================================================= */
/* Check these outputs in Live Expressions. */
volatile float Id_MTPA = 0.0f;
volatile float Iq_MTPA = 0.0f;

/* Optional variables for debugging. */
volatile float hidden_output[HIDDEN_NUM];

/* =========================================================
 * MINMAX parameters
 * ========================================================= */
/* Input Te MINMAX */
const float x0_min = 0.f;
const float x0_max = 262.35f;

/* Output Id, Iq MINMAX */
const float y0_min = -70.2296f;
const float y0_max = 0.0f;

const float y1_min = 0.0f;
const float y1_max = 258.0f;


/* Auto-generated PyTorch ANN parameters */
/* Weight layout: [input][output] */

float nn_theta1[1][20] = {
    {1.0424787f, 0.9124239f, 0.f, 0.747029f, 0.0000003f, 0.f, -0.5388183f, 0.517313f, 0.619355f, -0.0000494f, 1.1598727f, -0.0000017f, 1.0252818f, -0.1640235f, 0.3775712f, -0.528918f, 0.4528986f, 0.1297674f, -0.5474016f, 0.f}
};

float nn_bias1[20] = {-0.3641484f, -0.1540286f, 0.f, 0.8459258f, -0.0000519f, 0.f, 0.2717957f, -0.3775167f, 0.292128f, -0.0026496f, 0.6853488f, -0.0000102f, 0.5481475f, 0.4004521f, -0.3993232f, 0.8759899f, 0.3372437f, 0.9374285f, 0.5479734f, 0.f};

float nn_theta2[20][2] = {
    {-0.3520055f, 0.0455371f},
    {-0.2926128f, -0.0539854f},
    {0.f, 0.f},
    {0.2759715f, 0.0173054f},
    {0.0000015f, 0.f},
    {0.f, 0.f},
    {-0.5745952f, -0.1534824f},
    {-0.6250534f, 0.1481901f},
    {0.1062647f, -0.0099748f},
    {0.0013294f, 0.f},
    {-0.1539009f, 0.2963759f},
    {0.f, 0.f},
    {-0.1084347f, 0.3116781f},
    {0.3625878f, -0.1328928f},
    {0.0597939f, -0.1305951f},
    {0.3248009f, -0.1746124f},
    {0.0951512f, -0.0375871f},
    {0.1433421f, 0.1466528f},
    {0.7663202f, -0.2883234f},
    {0.f, 0.f}
};

float nn_bias2[2] = {0.0471837f, -0.1004477f};




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
    int i;
    float x0_normalized;
    float y0, y1, y0_normalized, y1_normalized;

    /* 1. Input normalization */
    START_TICK_MANAGER(NN_Time1);
    x0_normalized = (x[0] - x0_min) / (x0_max - x0_min);
    END_TICK_MANAGER(NN_Time1);


    /* 2. Hidden layer + ReLU */
    START_TICK_MANAGER(NN_Time2);
    for (i = 0; i < HIDDEN_NUM; i++)
    {
        hidden_output[i] = x0_normalized * nn_theta1[0][i] + nn_bias1[i];

        if (hidden_output[i] < 0.0f)
        {
            hidden_output[i] = 0.0f;
        }
    }
    END_TICK_MANAGER(NN_Time2);

    /* 3. Output layer */
    START_TICK_MANAGER(NN_Time3);
    y0_normalized = nn_bias2[0];
    y1_normalized = nn_bias2[1];
    for (i = 0; i < HIDDEN_NUM; i++)
    {
        y0_normalized += hidden_output[i] * nn_theta2[i][0];
        y1_normalized += hidden_output[i] * nn_theta2[i][1];
    }
    END_TICK_MANAGER(NN_Time3);

    /* 4. Output denormalization */
    START_TICK_MANAGER(NN_Time4);
    y0 = y0_normalized * (y0_max - y0_min) + y0_min;
    y1 = y1_normalized * (y1_max - y1_min) + y1_min;

    Id_MTPA = y0;
    Iq_MTPA = y1;
    END_TICK_MANAGER(NN_Time4);
}





