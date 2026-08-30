/*
 * nn_basic.c
 * Author: Jaehoon Shim
 *
 * Auto-generated from fnn_checkpoint (5).pt.
 * Note: checkpoint metadata says [1, 24, 24, 24, 24, 1], but the stored tensor shapes
 *       unambiguously define [1, 8, 8, 8, 1]; tensor shapes were used.
 * PyTorch Linear weights [output][input] were transposed to
 * the embedded layout [input][output].
 */

#include "TimeMeasure.h"
#include "nn_basic.h"

/* =========================================================
 * Live Expression / Watch variables
 * ========================================================= */
volatile float FNN_Output = 0.0f;
volatile float x0_normalized = 0.0f;
volatile float y0_normalized = 0.0f;

volatile float nn_input[NN_INPUT_NUM] = {0.0f};
volatile float hidden_output1[HIDDEN1_NUM] = {0.0f};
volatile float hidden_output2[HIDDEN2_NUM] = {0.0f};
volatile float hidden_output3[HIDDEN3_NUM] = {0.0f};

TimeManager NN_Time1 = {0.0f};
TimeManager NN_Time2 = {0.0f};
TimeManager NN_Time3 = {0.0f};
TimeManager NN_Time4 = {0.0f};
TimeManager NN_Time5 = {0.0f};
TimeManager NN_Time6 = {0.0f};

/* =========================================================
 * StandardScaler parameters saved in the checkpoint
 * ========================================================= */
const float x0_mean  = 20.0f;
const float x0_scale = 11.5759087f;
const float y0_mean  = 5.44184351f;
const float y0_scale = 3.66043448f;

/* =========================================================
 * NN parameters: [input][output]
 * Architecture: 1 -> 8 -> 8 -> 8 -> 1
 * ========================================================= */
/* Auto-generated PyTorch ANN parameters */
/* Weight layout: [input][output] */

const float nn_theta1[NN_INPUT_NUM][HIDDEN1_NUM] = {
    {1.0340914f, 0.7880354f, -0.3428134f, 1.194189f, -0.4009673f, 0.5005526f, -1.2000026f, 0.8672409f}
};

const float nn_bias1[HIDDEN1_NUM] = {1.4252108f, -0.9823765f, 1.0492015f, 0.336196f, 0.7742864f, 0.2005697f, 0.9794672f, 0.2460824f};

const float nn_theta2[HIDDEN1_NUM][HIDDEN2_NUM] = {
    {0.4406632f, -1.2417836f, 0.4369758f, 0.1888513f, 0.3635372f, 0.8564163f, 0.2796937f, 0.0157573f},
    {0.5317684f, -0.1629918f, 0.3515267f, 0.1364934f, 0.035439f, -0.5671423f, -0.562805f, 0.3578155f},
    {-0.2993983f, -0.135866f, -0.0478026f, 0.0460251f, -0.438579f, 0.5041578f, 0.429899f, -1.0428394f},
    {0.2942268f, -0.2125819f, 0.4426164f, 0.5274716f, 0.0557964f, -0.8937483f, 0.3328708f, 0.049148f},
    {-0.2533584f, 0.2356007f, 0.1568571f, 0.1726494f, -0.3611303f, -0.05077f, -0.1118949f, -0.9600582f},
    {0.1618616f, -0.3491973f, 0.521657f, 0.0813036f, 0.4962453f, -0.5146078f, 0.8007076f, 0.4861448f},
    {-1.0912192f, 0.881734f, -0.1380626f, 0.1285904f, -0.352889f, -0.5810984f, 0.685363f, 0.1265989f},
    {0.4581452f, -0.3003324f, 0.1315372f, 0.2943316f, 0.3588905f, -0.7638852f, 0.1834098f, 0.7093518f}
};

const float nn_bias2[HIDDEN2_NUM] = {-0.1776885f, -0.9860772f, 0.3007888f, -0.1631203f, 0.3343256f, 0.4076678f, 0.3737385f, -0.8660479f};

const float nn_theta3[HIDDEN2_NUM][HIDDEN3_NUM] = {
    {-0.1784206f, 0.3237354f, -0.4111431f, 0.1089509f, 0.006983f, 0.5957867f, -0.5860148f, 0.1983539f},
    {0.1077901f, -0.1193004f, -1.1725078f, -0.3297537f, -0.1315584f, -0.1685268f, -1.1654978f, 0.8047087f},
    {0.0747438f, -0.1253405f, -0.0227108f, -0.2322046f, -0.0305052f, 0.461706f, 0.3061752f, 0.3552895f},
    {-0.0901415f, -0.3420964f, 0.2422897f, -0.1176823f, -0.2455837f, -0.0267548f, 0.3851932f, 0.4835858f},
    {0.2107424f, -0.2024695f, -0.2318683f, 0.0552855f, -0.2486812f, -0.0679884f, -0.0754666f, 0.5801524f},
    {0.2403488f, 0.0883189f, -0.8703976f, -0.3110992f, -0.212269f, 1.0888554f, -0.3617418f, -0.6025514f},
    {-0.2563875f, -0.0466666f, 0.5016544f, -0.1523366f, -0.1270258f, -0.2651926f, 0.4806578f, -0.2009836f},
    {-0.1887509f, -0.2566394f, -0.654818f, -0.2116613f, -0.279053f, 0.6119264f, -1.0123858f, 0.6023308f}
};

const float nn_bias3[HIDDEN3_NUM] = {-0.0387441f, -0.2646312f, 0.3197551f, -0.2594907f, 0.1829516f, 0.261484f, 0.289909f, -0.129526f};

const float nn_theta4[HIDDEN3_NUM][NN_OUTPUT_NUM] = {
    {0.3213629f},
    {0.0776935f},
    {-0.4662722f},
    {-0.3115706f},
    {0.1424129f},
    {0.4195022f},
    {-0.5798658f},
    {0.6233128f}
};

float nn_bias4[NN_OUTPUT_NUM] = {-0.0575344f};



/* =========================================================
 * NN calculation
 * ========================================================= */
void NN_Run(volatile float *x)
{
    uint32 i;
    uint32 j;

    /* 1. Input standardization */
    START_TICK_MANAGER(NN_Time1);
    nn_input[0U] = x[0U];
    x0_normalized = (nn_input[0U] - x0_mean) / x0_scale;
    END_TICK_MANAGER(NN_Time1);

    /* 2. Hidden layer 1 + ReLU */
    START_TICK_MANAGER(NN_Time2);
    for (j = 0U; j < HIDDEN1_NUM; j++)
    {
        hidden_output1[j] = nn_bias1[j] + x0_normalized * nn_theta1[0U][j];
        if (hidden_output1[j] < 0.0f)
        {
            hidden_output1[j] = 0.0f;
        }
    }
    END_TICK_MANAGER(NN_Time2);

    /* 3. Hidden layer 2 + ReLU */
    START_TICK_MANAGER(NN_Time3);
    for (j = 0U; j < HIDDEN2_NUM; j++) {

        hidden_output2[j] = nn_bias2[j];
        for (i = 0U; i < HIDDEN1_NUM; i++) {
            hidden_output2[j] += hidden_output1[i] * nn_theta2[i][j];
        }
        if (hidden_output2[j] < 0.0f)
        {
            hidden_output2[j] = 0.0f;
        }
    }
    END_TICK_MANAGER(NN_Time3);

    /* 4. Hidden layer 3 + ReLU */
    START_TICK_MANAGER(NN_Time4);
    for (j = 0U; j < HIDDEN3_NUM; j++) {

        hidden_output3[j] = nn_bias3[j];
        for (i = 0U; i < HIDDEN2_NUM; i++) {
            hidden_output3[j] += hidden_output2[i] * nn_theta3[i][j];
        }
        if (hidden_output3[j] < 0.0f)
        {
            hidden_output3[j] = 0.0f;
        }
    }
    END_TICK_MANAGER(NN_Time4);

    /* 5. Linear output layer (no activation) */
    START_TICK_MANAGER(NN_Time5);
    y0_normalized = nn_bias4[0U];
    for (i = 0U; i < HIDDEN3_NUM; i++)
    {
        y0_normalized += hidden_output3[i] * nn_theta4[i][0U];
    }
    END_TICK_MANAGER(NN_Time5);

    /* 6. Output inverse standardization */
    START_TICK_MANAGER(NN_Time6);
    FNN_Output = y0_normalized * y0_scale + y0_mean;
    END_TICK_MANAGER(NN_Time6);
}
