################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/infineon_libraries/iLLD/TC26B/Tricore/Smu/Std/IfxSmu.c 

OBJS += \
./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Smu/Std/IfxSmu.o 

COMPILED_SRCS += \
./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Smu/Std/IfxSmu.src 

C_DEPS += \
./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Smu/Std/IfxSmu.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/infineon_libraries/iLLD/TC26B/Tricore/Smu/Std/%.src: ../Libraries/infineon_libraries/iLLD/TC26B/Tricore/Smu/Std/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Configurations" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Infra" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Infra\Platform" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Infra\Platform\Tricore" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Infra\Platform\Tricore\Compilers" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Infra\Sfr" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Infra\Sfr\TC26B" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Infra\Sfr\TC26B\_Reg" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric\If" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric\If\Ccu6If" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric\StdIf" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric\SysSe" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric\SysSe\Bsp" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric\SysSe\Comm" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric\SysSe\General" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric\SysSe\Math" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric\SysSe\Time" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\Service\CpuGeneric\_Utilities" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Asc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Lin" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Spi" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Asclin\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\Icu" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\PwmBc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\PwmHl" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\TPwm" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\Timer" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Ccu6\TimerWithTrigger" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cif" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cif\Cam" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cif\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\CStart" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\Irq" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Cpu\Trap" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dma" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dma\Dma" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dma\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc\Dsadc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc\Rdc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dsadc\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dts" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dts\Dts" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Dts\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Emem" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Emem\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eray" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eray\Eray" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eray\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eth" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eth\Phy_Pef7071" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Eth\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fce" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fce\Crc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fce\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fft" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fft\Fft" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Fft\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Flash" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Flash\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gpt12" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gpt12\IncrEnc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gpt12\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom\Pwm" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom\PwmHl" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Atom\Timer" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tim" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tim\In" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom\Pwm" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom\PwmHl" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Tom\Timer" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Gtm\Trig" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Hssl" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Hssl\Hssl" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Hssl\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\I2c" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\I2c\I2c" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\I2c\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Iom" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Iom\Driver" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Iom\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Msc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Msc\Msc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Msc\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Mtu" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Mtu\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Multican" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Multican\Can" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Multican\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Port" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Port\Io" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Port\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5\Psi5" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5s" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5s\Psi5s" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Psi5s\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi\SpiMaster" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi\SpiSlave" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Qspi\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Scu" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Scu\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Sent" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Sent\Sent" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Sent\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Smu" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Smu\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Src" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Src\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Stm" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Stm\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Stm\Timer" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Vadc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Vadc\Adc" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\Vadc\Std" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Impl" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Lib" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Lib\DataHandling" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_Lib\InternalMux" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\infineon_libraries\iLLD\TC26B\Tricore\_PinMap" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\seekfree_libraries" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\seekfree_libraries\common" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\Libraries\seekfree_peripheral" -I"F:\GIT\Seekfree_TC264_Opensource_Library\IPC_TC264\USER" --iso=99 --c++14 --language=+volatile --anachronisms --fp-model=3 --fp-model=c --fp-model=f --fp-model=l --fp-model=n --fp-model=r --fp-model=z -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file=$(@:.src=.d) --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/infineon_libraries/iLLD/TC26B/Tricore/Smu/Std/%.o: ./Libraries/infineon_libraries/iLLD/TC26B/Tricore/Smu/Std/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


