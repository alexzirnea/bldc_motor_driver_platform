#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/4808_bldc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/4808_bldc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/src/pin_manager.c mcc_generated_files/src/ac0.c mcc_generated_files/src/adc0.c mcc_generated_files/src/tca0.c mcc_generated_files/src/protected_io.S mcc_generated_files/src/ccl.c mcc_generated_files/src/cpuint.c mcc_generated_files/src/evsys.c mcc_generated_files/src/tcb0.c mcc_generated_files/mcc.c mcc_generated_files/device_config.c main.c hal.c mc_drive.c app.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/src/pin_manager.o ${OBJECTDIR}/mcc_generated_files/src/ac0.o ${OBJECTDIR}/mcc_generated_files/src/adc0.o ${OBJECTDIR}/mcc_generated_files/src/tca0.o ${OBJECTDIR}/mcc_generated_files/src/protected_io.o ${OBJECTDIR}/mcc_generated_files/src/ccl.o ${OBJECTDIR}/mcc_generated_files/src/cpuint.o ${OBJECTDIR}/mcc_generated_files/src/evsys.o ${OBJECTDIR}/mcc_generated_files/src/tcb0.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/device_config.o ${OBJECTDIR}/main.o ${OBJECTDIR}/hal.o ${OBJECTDIR}/mc_drive.o ${OBJECTDIR}/app.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/src/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/src/ac0.o.d ${OBJECTDIR}/mcc_generated_files/src/adc0.o.d ${OBJECTDIR}/mcc_generated_files/src/tca0.o.d ${OBJECTDIR}/mcc_generated_files/src/protected_io.o.d ${OBJECTDIR}/mcc_generated_files/src/ccl.o.d ${OBJECTDIR}/mcc_generated_files/src/cpuint.o.d ${OBJECTDIR}/mcc_generated_files/src/evsys.o.d ${OBJECTDIR}/mcc_generated_files/src/tcb0.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/device_config.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/hal.o.d ${OBJECTDIR}/mc_drive.o.d ${OBJECTDIR}/app.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/src/pin_manager.o ${OBJECTDIR}/mcc_generated_files/src/ac0.o ${OBJECTDIR}/mcc_generated_files/src/adc0.o ${OBJECTDIR}/mcc_generated_files/src/tca0.o ${OBJECTDIR}/mcc_generated_files/src/protected_io.o ${OBJECTDIR}/mcc_generated_files/src/ccl.o ${OBJECTDIR}/mcc_generated_files/src/cpuint.o ${OBJECTDIR}/mcc_generated_files/src/evsys.o ${OBJECTDIR}/mcc_generated_files/src/tcb0.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/device_config.o ${OBJECTDIR}/main.o ${OBJECTDIR}/hal.o ${OBJECTDIR}/mc_drive.o ${OBJECTDIR}/app.o

# Source Files
SOURCEFILES=mcc_generated_files/src/pin_manager.c mcc_generated_files/src/ac0.c mcc_generated_files/src/adc0.c mcc_generated_files/src/tca0.c mcc_generated_files/src/protected_io.S mcc_generated_files/src/ccl.c mcc_generated_files/src/cpuint.c mcc_generated_files/src/evsys.c mcc_generated_files/src/tcb0.c mcc_generated_files/mcc.c mcc_generated_files/device_config.c main.c hal.c mc_drive.c app.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega4808"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/4808_bldc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega4808
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/src/protected_io.o: mcc_generated_files/src/protected_io.S  .generated_files/flags/default/50888e47520fe1c5d3c4d0511835f3e08cded4c3 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/protected_io.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/protected_io.o 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/protected_io.o.ok ${OBJECTDIR}/mcc_generated_files/src/protected_io.o.err 
	 ${MP_CC} $(MP_EXTRA_AS_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -DDEBUG  -x assembler-with-cpp -c -D__$(MP_PROCESSOR_OPTION)__  -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/protected_io.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/protected_io.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/protected_io.o -o ${OBJECTDIR}/mcc_generated_files/src/protected_io.o mcc_generated_files/src/protected_io.S  -DXPRJ_default=$(CND_CONF)  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/mcc_generated_files/src/protected_io.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1
	
else
${OBJECTDIR}/mcc_generated_files/src/protected_io.o: mcc_generated_files/src/protected_io.S  .generated_files/flags/default/f059ac1726cc5b903bc45b10e7adf6e61fad96b6 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/protected_io.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/protected_io.o 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/protected_io.o.ok ${OBJECTDIR}/mcc_generated_files/src/protected_io.o.err 
	 ${MP_CC} $(MP_EXTRA_AS_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x assembler-with-cpp -c -D__$(MP_PROCESSOR_OPTION)__  -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/protected_io.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/protected_io.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/protected_io.o -o ${OBJECTDIR}/mcc_generated_files/src/protected_io.o mcc_generated_files/src/protected_io.S  -DXPRJ_default=$(CND_CONF)  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/mcc_generated_files/src/protected_io.o.asm.d"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/src/pin_manager.o: mcc_generated_files/src/pin_manager.c  .generated_files/flags/default/52e1511050f7bc541fad8657b2d82bdd294d4ccb .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/pin_manager.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/pin_manager.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/pin_manager.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/pin_manager.o  -o ${OBJECTDIR}/mcc_generated_files/src/pin_manager.o mcc_generated_files/src/pin_manager.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/ac0.o: mcc_generated_files/src/ac0.c  .generated_files/flags/default/8f10757bf291b8fb2fc22ae07a8026745bd9ddd5 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/ac0.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/ac0.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/ac0.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/ac0.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/ac0.o  -o ${OBJECTDIR}/mcc_generated_files/src/ac0.o mcc_generated_files/src/ac0.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/adc0.o: mcc_generated_files/src/adc0.c  .generated_files/flags/default/8548e52b9e9a5e1a013735abb100031aaa336a88 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/adc0.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/adc0.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/adc0.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/adc0.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/adc0.o  -o ${OBJECTDIR}/mcc_generated_files/src/adc0.o mcc_generated_files/src/adc0.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/tca0.o: mcc_generated_files/src/tca0.c  .generated_files/flags/default/77a1af18e2273db4a1f5a9f0069189f3d7969cef .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/tca0.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/tca0.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/tca0.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/tca0.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/tca0.o  -o ${OBJECTDIR}/mcc_generated_files/src/tca0.o mcc_generated_files/src/tca0.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/ccl.o: mcc_generated_files/src/ccl.c  .generated_files/flags/default/f975b4b71965f0a3966acad49cdc87064232b259 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/ccl.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/ccl.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/ccl.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/ccl.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/ccl.o  -o ${OBJECTDIR}/mcc_generated_files/src/ccl.o mcc_generated_files/src/ccl.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/cpuint.o: mcc_generated_files/src/cpuint.c  .generated_files/flags/default/5ca9e31b82570c9add97918449b17056e093e22 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/cpuint.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/cpuint.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/cpuint.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/cpuint.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/cpuint.o  -o ${OBJECTDIR}/mcc_generated_files/src/cpuint.o mcc_generated_files/src/cpuint.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/evsys.o: mcc_generated_files/src/evsys.c  .generated_files/flags/default/284d7f11c7e0731a89326bf6b16cf5a351a77d78 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/evsys.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/evsys.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/evsys.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/evsys.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/evsys.o  -o ${OBJECTDIR}/mcc_generated_files/src/evsys.o mcc_generated_files/src/evsys.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/tcb0.o: mcc_generated_files/src/tcb0.c  .generated_files/flags/default/6244a8f2201ebfdfbe8193f1a6a286e0c50aa084 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/tcb0.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/tcb0.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/tcb0.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/tcb0.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/tcb0.o  -o ${OBJECTDIR}/mcc_generated_files/src/tcb0.o mcc_generated_files/src/tcb0.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/b22c1624454d03b2ebd8daecec6661f520a904ed .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -MT "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -MT ${OBJECTDIR}/mcc_generated_files/mcc.o  -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/device_config.o: mcc_generated_files/device_config.c  .generated_files/flags/default/d6a54d86216da0d29c4e89b0efec6a18c175394e .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/device_config.o.d" -MT "${OBJECTDIR}/mcc_generated_files/device_config.o.d" -MT ${OBJECTDIR}/mcc_generated_files/device_config.o  -o ${OBJECTDIR}/mcc_generated_files/device_config.o mcc_generated_files/device_config.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/d9ad384c476be914c133862669b004c5e4472694 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal.o: hal.c  .generated_files/flags/default/e0484bf4c4b1c3d144acd2fcc299ffc68ce7da91 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/hal.o.d 
	@${RM} ${OBJECTDIR}/hal.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/hal.o.d" -MT "${OBJECTDIR}/hal.o.d" -MT ${OBJECTDIR}/hal.o  -o ${OBJECTDIR}/hal.o hal.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mc_drive.o: mc_drive.c  .generated_files/flags/default/f33e7b2a6475e02959b7dc295c24bca7488e785 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mc_drive.o.d 
	@${RM} ${OBJECTDIR}/mc_drive.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mc_drive.o.d" -MT "${OBJECTDIR}/mc_drive.o.d" -MT ${OBJECTDIR}/mc_drive.o  -o ${OBJECTDIR}/mc_drive.o mc_drive.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/app.o: app.c  .generated_files/flags/default/d732d2c5c1f34e8373c551a421a3ac3f3ab6d7e1 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.o.d 
	@${RM} ${OBJECTDIR}/app.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/app.o.d" -MT "${OBJECTDIR}/app.o.d" -MT ${OBJECTDIR}/app.o  -o ${OBJECTDIR}/app.o app.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/mcc_generated_files/src/pin_manager.o: mcc_generated_files/src/pin_manager.c  .generated_files/flags/default/12c37fbddb4649098656895f69ed82812443c74a .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/pin_manager.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/pin_manager.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/pin_manager.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/pin_manager.o  -o ${OBJECTDIR}/mcc_generated_files/src/pin_manager.o mcc_generated_files/src/pin_manager.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/ac0.o: mcc_generated_files/src/ac0.c  .generated_files/flags/default/cbdd4ef0354fe9f207b2a9d03b8d6f010cd891fd .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/ac0.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/ac0.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/ac0.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/ac0.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/ac0.o  -o ${OBJECTDIR}/mcc_generated_files/src/ac0.o mcc_generated_files/src/ac0.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/adc0.o: mcc_generated_files/src/adc0.c  .generated_files/flags/default/b133679fdf1b572492ce87191a110e5e94212feb .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/adc0.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/adc0.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/adc0.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/adc0.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/adc0.o  -o ${OBJECTDIR}/mcc_generated_files/src/adc0.o mcc_generated_files/src/adc0.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/tca0.o: mcc_generated_files/src/tca0.c  .generated_files/flags/default/b6c4e53280fac0f34c45c9daefdfaae44573fb83 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/tca0.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/tca0.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/tca0.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/tca0.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/tca0.o  -o ${OBJECTDIR}/mcc_generated_files/src/tca0.o mcc_generated_files/src/tca0.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/ccl.o: mcc_generated_files/src/ccl.c  .generated_files/flags/default/cd2ad177a2878fc7c8de52c8aa45fdfa2f234fbe .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/ccl.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/ccl.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/ccl.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/ccl.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/ccl.o  -o ${OBJECTDIR}/mcc_generated_files/src/ccl.o mcc_generated_files/src/ccl.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/cpuint.o: mcc_generated_files/src/cpuint.c  .generated_files/flags/default/36be8bb10123951619c1eabc8891f5287ee0ae07 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/cpuint.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/cpuint.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/cpuint.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/cpuint.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/cpuint.o  -o ${OBJECTDIR}/mcc_generated_files/src/cpuint.o mcc_generated_files/src/cpuint.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/evsys.o: mcc_generated_files/src/evsys.c  .generated_files/flags/default/dc6b26b93d5f7b8dc8e4aa7d0aafabac2b6c96d0 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/evsys.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/evsys.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/evsys.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/evsys.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/evsys.o  -o ${OBJECTDIR}/mcc_generated_files/src/evsys.o mcc_generated_files/src/evsys.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/src/tcb0.o: mcc_generated_files/src/tcb0.c  .generated_files/flags/default/7f25050f1eb5fb59a155e2eb02d9976c1bef5a1a .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/tcb0.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/src/tcb0.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/src/tcb0.o.d" -MT "${OBJECTDIR}/mcc_generated_files/src/tcb0.o.d" -MT ${OBJECTDIR}/mcc_generated_files/src/tcb0.o  -o ${OBJECTDIR}/mcc_generated_files/src/tcb0.o mcc_generated_files/src/tcb0.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/default/24a42b1c649692f38411048a79324cc7f4a76d79 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -MT "${OBJECTDIR}/mcc_generated_files/mcc.o.d" -MT ${OBJECTDIR}/mcc_generated_files/mcc.o  -o ${OBJECTDIR}/mcc_generated_files/mcc.o mcc_generated_files/mcc.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mcc_generated_files/device_config.o: mcc_generated_files/device_config.c  .generated_files/flags/default/9115560837025d9320e16b267fbd5cbe39e6bf1c .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/device_config.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mcc_generated_files/device_config.o.d" -MT "${OBJECTDIR}/mcc_generated_files/device_config.o.d" -MT ${OBJECTDIR}/mcc_generated_files/device_config.o  -o ${OBJECTDIR}/mcc_generated_files/device_config.o mcc_generated_files/device_config.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/29321056357779b3fae9d422db9c4532bd09f1af .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o  -o ${OBJECTDIR}/main.o main.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/hal.o: hal.c  .generated_files/flags/default/bd9812d6f9316a2f6ab30040f98ac6870b1d99ce .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/hal.o.d 
	@${RM} ${OBJECTDIR}/hal.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/hal.o.d" -MT "${OBJECTDIR}/hal.o.d" -MT ${OBJECTDIR}/hal.o  -o ${OBJECTDIR}/hal.o hal.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/mc_drive.o: mc_drive.c  .generated_files/flags/default/468614d7606219bdee25664be2c69811ec3e53bf .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mc_drive.o.d 
	@${RM} ${OBJECTDIR}/mc_drive.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/mc_drive.o.d" -MT "${OBJECTDIR}/mc_drive.o.d" -MT ${OBJECTDIR}/mc_drive.o  -o ${OBJECTDIR}/mc_drive.o mc_drive.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/app.o: app.c  .generated_files/flags/default/50bccad401b413c5254cfc3662ce363ba0c3a7e4 .generated_files/flags/default/6271d6bb391491ff4651685f954d7efa6a65a3bd
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.o.d 
	@${RM} ${OBJECTDIR}/app.o 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega4808 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/app.o.d" -MT "${OBJECTDIR}/app.o.d" -MT ${OBJECTDIR}/app.o  -o ${OBJECTDIR}/app.o app.c  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/4808_bldc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega4808 ${PACK_COMMON_OPTIONS}   -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\4808_bldc.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/4808_bldc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/4808_bldc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega4808 ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\4808_bldc.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/4808_bldc.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/4808_bldc.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/4808_bldc.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
