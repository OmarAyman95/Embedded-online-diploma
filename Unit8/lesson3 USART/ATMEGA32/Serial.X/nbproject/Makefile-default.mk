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
FINAL_IMAGE=${DISTDIR}/Serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED="AVR files/EXTI.c" "AVR files/GPIO_MEGA32.c" "AVR files/Timer0.c" "AVR files/delayT0.c" "AVR files/main.c" "AVR files/usartATmega32.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED="${OBJECTDIR}/AVR files/EXTI.o" "${OBJECTDIR}/AVR files/GPIO_MEGA32.o" "${OBJECTDIR}/AVR files/Timer0.o" "${OBJECTDIR}/AVR files/delayT0.o" "${OBJECTDIR}/AVR files/main.o" "${OBJECTDIR}/AVR files/usartATmega32.o"
POSSIBLE_DEPFILES="${OBJECTDIR}/AVR files/EXTI.o.d" "${OBJECTDIR}/AVR files/GPIO_MEGA32.o.d" "${OBJECTDIR}/AVR files/Timer0.o.d" "${OBJECTDIR}/AVR files/delayT0.o.d" "${OBJECTDIR}/AVR files/main.o.d" "${OBJECTDIR}/AVR files/usartATmega32.o.d"

# Object Files
OBJECTFILES=${OBJECTDIR}/AVR\ files/EXTI.o ${OBJECTDIR}/AVR\ files/GPIO_MEGA32.o ${OBJECTDIR}/AVR\ files/Timer0.o ${OBJECTDIR}/AVR\ files/delayT0.o ${OBJECTDIR}/AVR\ files/main.o ${OBJECTDIR}/AVR\ files/usartATmega32.o

# Source Files
SOURCEFILES=AVR files/EXTI.c AVR files/GPIO_MEGA32.c AVR files/Timer0.c AVR files/delayT0.c AVR files/main.c AVR files/usartATmega32.c

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega32"



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/AVR\ files/EXTI.o: AVR\ files/EXTI.c  .generated_files/flags/default/f003fa05f7eb3896db18b5b15d3e15ccf35c864c .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/EXTI.o".d 
	@${RM} "${OBJECTDIR}/AVR files/EXTI.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/EXTI.o.d" -MT "${OBJECTDIR}/AVR files/EXTI.o.d" -MT "${OBJECTDIR}/AVR files/EXTI.o"  -o "${OBJECTDIR}/AVR files/EXTI.o" "AVR files/EXTI.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/GPIO_MEGA32.o: AVR\ files/GPIO_MEGA32.c  .generated_files/flags/default/b5518ba3f5b9da2879624fd8370ea351a2714005 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/GPIO_MEGA32.o".d 
	@${RM} "${OBJECTDIR}/AVR files/GPIO_MEGA32.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/GPIO_MEGA32.o.d" -MT "${OBJECTDIR}/AVR files/GPIO_MEGA32.o.d" -MT "${OBJECTDIR}/AVR files/GPIO_MEGA32.o"  -o "${OBJECTDIR}/AVR files/GPIO_MEGA32.o" "AVR files/GPIO_MEGA32.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/Timer0.o: AVR\ files/Timer0.c  .generated_files/flags/default/2bb43f3042d5a5ac8ba9f23033fb61fcf35ae1ef .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/Timer0.o".d 
	@${RM} "${OBJECTDIR}/AVR files/Timer0.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/Timer0.o.d" -MT "${OBJECTDIR}/AVR files/Timer0.o.d" -MT "${OBJECTDIR}/AVR files/Timer0.o"  -o "${OBJECTDIR}/AVR files/Timer0.o" "AVR files/Timer0.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/delayT0.o: AVR\ files/delayT0.c  .generated_files/flags/default/85c46c25573a461e20acc8f628408915a8270203 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/delayT0.o".d 
	@${RM} "${OBJECTDIR}/AVR files/delayT0.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/delayT0.o.d" -MT "${OBJECTDIR}/AVR files/delayT0.o.d" -MT "${OBJECTDIR}/AVR files/delayT0.o"  -o "${OBJECTDIR}/AVR files/delayT0.o" "AVR files/delayT0.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/main.o: AVR\ files/main.c  .generated_files/flags/default/c1ced156dcf86e2039c3a8404f36153874ab7bc4 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/main.o".d 
	@${RM} "${OBJECTDIR}/AVR files/main.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/main.o.d" -MT "${OBJECTDIR}/AVR files/main.o.d" -MT "${OBJECTDIR}/AVR files/main.o"  -o "${OBJECTDIR}/AVR files/main.o" "AVR files/main.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/usartATmega32.o: AVR\ files/usartATmega32.c  .generated_files/flags/default/604186e658f11a0c77b23264d2c32fb297da8d3c .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/usartATmega32.o".d 
	@${RM} "${OBJECTDIR}/AVR files/usartATmega32.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/usartATmega32.o.d" -MT "${OBJECTDIR}/AVR files/usartATmega32.o.d" -MT "${OBJECTDIR}/AVR files/usartATmega32.o"  -o "${OBJECTDIR}/AVR files/usartATmega32.o" "AVR files/usartATmega32.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/AVR\ files/EXTI.o: AVR\ files/EXTI.c  .generated_files/flags/default/92316f91a680a2b9f4131ffc963f93bd6224c944 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/EXTI.o".d 
	@${RM} "${OBJECTDIR}/AVR files/EXTI.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/EXTI.o.d" -MT "${OBJECTDIR}/AVR files/EXTI.o.d" -MT "${OBJECTDIR}/AVR files/EXTI.o"  -o "${OBJECTDIR}/AVR files/EXTI.o" "AVR files/EXTI.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/GPIO_MEGA32.o: AVR\ files/GPIO_MEGA32.c  .generated_files/flags/default/81c9373d5b5bbb3752193813935f1bfde1b006f7 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/GPIO_MEGA32.o".d 
	@${RM} "${OBJECTDIR}/AVR files/GPIO_MEGA32.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/GPIO_MEGA32.o.d" -MT "${OBJECTDIR}/AVR files/GPIO_MEGA32.o.d" -MT "${OBJECTDIR}/AVR files/GPIO_MEGA32.o"  -o "${OBJECTDIR}/AVR files/GPIO_MEGA32.o" "AVR files/GPIO_MEGA32.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/Timer0.o: AVR\ files/Timer0.c  .generated_files/flags/default/46bc213113710c955b0bae1839dcb06ca7234dd .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/Timer0.o".d 
	@${RM} "${OBJECTDIR}/AVR files/Timer0.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/Timer0.o.d" -MT "${OBJECTDIR}/AVR files/Timer0.o.d" -MT "${OBJECTDIR}/AVR files/Timer0.o"  -o "${OBJECTDIR}/AVR files/Timer0.o" "AVR files/Timer0.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/delayT0.o: AVR\ files/delayT0.c  .generated_files/flags/default/8754b9fe48a681cd4595b059d11076196ecb62cc .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/delayT0.o".d 
	@${RM} "${OBJECTDIR}/AVR files/delayT0.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/delayT0.o.d" -MT "${OBJECTDIR}/AVR files/delayT0.o.d" -MT "${OBJECTDIR}/AVR files/delayT0.o"  -o "${OBJECTDIR}/AVR files/delayT0.o" "AVR files/delayT0.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/main.o: AVR\ files/main.c  .generated_files/flags/default/4b9ee8d94d0386ed3428c0d2f4d9a719d7bb59be .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/main.o".d 
	@${RM} "${OBJECTDIR}/AVR files/main.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/main.o.d" -MT "${OBJECTDIR}/AVR files/main.o.d" -MT "${OBJECTDIR}/AVR files/main.o"  -o "${OBJECTDIR}/AVR files/main.o" "AVR files/main.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/usartATmega32.o: AVR\ files/usartATmega32.c  .generated_files/flags/default/c230645130eb3b917827d541ebd7306dc30aa1bb .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/usartATmega32.o".d 
	@${RM} "${OBJECTDIR}/AVR files/usartATmega32.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/usartATmega32.o.d" -MT "${OBJECTDIR}/AVR files/usartATmega32.o.d" -MT "${OBJECTDIR}/AVR files/usartATmega32.o"  -o "${OBJECTDIR}/AVR files/usartATmega32.o" "AVR files/usartATmega32.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega32 ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\Serial.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/Serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/Serial.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega32 ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\Serial.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/Serial.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/Serial.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/Serial.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
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
