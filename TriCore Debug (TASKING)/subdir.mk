################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Asclin.c" \
"../CCU6_Config.c" \
"../CCU6_Interrupt.c" \
"../Cpu0_Main.c" \
"../TimeMeasure.c" \
"../nn_duty_comp.c" 

COMPILED_SRCS += \
"Asclin.src" \
"CCU6_Config.src" \
"CCU6_Interrupt.src" \
"Cpu0_Main.src" \
"TimeMeasure.src" \
"nn_duty_comp.src" 

C_DEPS += \
"./Asclin.d" \
"./CCU6_Config.d" \
"./CCU6_Interrupt.d" \
"./Cpu0_Main.d" \
"./TimeMeasure.d" \
"./nn_duty_comp.d" 

OBJS += \
"Asclin.o" \
"CCU6_Config.o" \
"CCU6_Interrupt.o" \
"Cpu0_Main.o" \
"TimeMeasure.o" \
"nn_duty_comp.o" 


# Each subdirectory must supply rules for building sources it contributes
"Asclin.src":"../Asclin.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc33x "-fC:/Users/HP/AURIX-v1.10.36-workspace/TC334_EvalBrd_Ex/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O2 --tradeoff=2 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
"Asclin.o":"Asclin.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"CCU6_Config.src":"../CCU6_Config.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc33x "-fC:/Users/HP/AURIX-v1.10.36-workspace/TC334_EvalBrd_Ex/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O2 --tradeoff=2 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
"CCU6_Config.o":"CCU6_Config.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"CCU6_Interrupt.src":"../CCU6_Interrupt.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc33x "-fC:/Users/HP/AURIX-v1.10.36-workspace/TC334_EvalBrd_Ex/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O2 --tradeoff=2 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
"CCU6_Interrupt.o":"CCU6_Interrupt.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Cpu0_Main.src":"../Cpu0_Main.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc33x "-fC:/Users/HP/AURIX-v1.10.36-workspace/TC334_EvalBrd_Ex/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O2 --tradeoff=2 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
"Cpu0_Main.o":"Cpu0_Main.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"TimeMeasure.src":"../TimeMeasure.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc33x "-fC:/Users/HP/AURIX-v1.10.36-workspace/TC334_EvalBrd_Ex/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O2 --tradeoff=2 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
"TimeMeasure.o":"TimeMeasure.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"nn_duty_comp.src":"../nn_duty_comp.c" "subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc33x "-fC:/Users/HP/AURIX-v1.10.36-workspace/TC334_EvalBrd_Ex/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O2 --tradeoff=2 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
"nn_duty_comp.o":"nn_duty_comp.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean--2e-

clean--2e-:
	-$(RM) ./Asclin.d ./Asclin.o ./Asclin.src ./CCU6_Config.d ./CCU6_Config.o ./CCU6_Config.src ./CCU6_Interrupt.d ./CCU6_Interrupt.o ./CCU6_Interrupt.src ./Cpu0_Main.d ./Cpu0_Main.o ./Cpu0_Main.src ./TimeMeasure.d ./TimeMeasure.o ./TimeMeasure.src ./nn_duty_comp.d ./nn_duty_comp.o ./nn_duty_comp.src

.PHONY: clean--2e-

