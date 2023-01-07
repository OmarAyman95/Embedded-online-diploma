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
FINAL_IMAGE=${DISTDIR}/Timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED="AVR files/GPIO_MEGA32.c" "AVR files/delayT0.c" "AVR files/main.c" "AVR files/Timer0.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED="${OBJECTDIR}/AVR files/GPIO_MEGA32.o" "${OBJECTDIR}/AVR files/delayT0.o" "${OBJECTDIR}/AVR files/main.o" "${OBJECTDIR}/AVR files/Timer0.o"
POSSIBLE_DEPFILES="${OBJECTDIR}/AVR files/GPIO_MEGA32.o.d" "${OBJECTDIR}/AVR files/delayT0.o.d" "${OBJECTDIR}/AVR files/main.o.d" "${OBJECTDIR}/AVR files/Timer0.o.d"

# Object Files
OBJECTFILES=${OBJECTDIR}/AVR\ files/GPIO_MEGA32.o ${OBJECTDIR}/AVR\ files/delayT0.o ${OBJECTDIR}/AVR\ files/main.o ${OBJECTDIR}/AVR\ files/Timer0.o

# Source Files
SOURCEFILES=AVR files/GPIO_MEGA32.c AVR files/delayT0.c AVR files/main.c AVR files/Timer0.c

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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/AVR\ files/GPIO_MEGA32.o: AVR\ files/GPIO_MEGA32.c  .generated_files/flags/default/ca1d036a4a32cb6b6ba53c9345c6e4760d4a8931 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/GPIO_MEGA32.o".d 
	@${RM} "${OBJECTDIR}/AVR files/GPIO_MEGA32.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/GPIO_MEGA32.o.d" -MT "${OBJECTDIR}/AVR files/GPIO_MEGA32.o.d" -MT "${OBJECTDIR}/AVR files/GPIO_MEGA32.o"  -o "${OBJECTDIR}/AVR files/GPIO_MEGA32.o" "AVR files/GPIO_MEGA32.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/delayT0.o: AVR\ files/delayT0.c  .generated_files/flags/default/f62a09c12b10aa68f949776163cd0a139b7dfed8 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/delayT0.o".d 
	@${RM} "${OBJECTDIR}/AVR files/delayT0.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/delayT0.o.d" -MT "${OBJECTDIR}/AVR files/delayT0.o.d" -MT "${OBJECTDIR}/AVR files/delayT0.o"  -o "${OBJECTDIR}/AVR files/delayT0.o" "AVR files/delayT0.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/main.o: AVR\ files/main.c  .generated_files/flags/default/f13c4e5fc7caf1e97a76312bae53b7bf52471b7 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/main.o".d 
	@${RM} "${OBJECTDIR}/AVR files/main.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/main.o.d" -MT "${OBJECTDIR}/AVR files/main.o.d" -MT "${OBJECTDIR}/AVR files/main.o"  -o "${OBJECTDIR}/AVR files/main.o" "AVR files/main.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/Timer0.o: AVR\ files/Timer0.c  .generated_files/flags/default/8a5a6e0a80d28a6cdafca23517ce1c56362a429d .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/Timer0.o".d 
	@${RM} "${OBJECTDIR}/AVR files/Timer0.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/Timer0.o.d" -MT "${OBJECTDIR}/AVR files/Timer0.o.d" -MT "${OBJECTDIR}/AVR files/Timer0.o"  -o "${OBJECTDIR}/AVR files/Timer0.o" "AVR files/Timer0.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/AVR\ files/GPIO_MEGA32.o: AVR\ files/GPIO_MEGA32.c  .generated_files/flags/default/11b201be962041cb77f3876dcd6116e0ac19f77e .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/GPIO_MEGA32.o".d 
	@${RM} "${OBJECTDIR}/AVR files/GPIO_MEGA32.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/GPIO_MEGA32.o.d" -MT "${OBJECTDIR}/AVR files/GPIO_MEGA32.o.d" -MT "${OBJECTDIR}/AVR files/GPIO_MEGA32.o"  -o "${OBJECTDIR}/AVR files/GPIO_MEGA32.o" "AVR files/GPIO_MEGA32.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/delayT0.o: AVR\ files/delayT0.c  .generated_files/flags/default/197af697affef2168cdeb29c6f3f27752ab26fb7 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/delayT0.o".d 
	@${RM} "${OBJECTDIR}/AVR files/delayT0.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/delayT0.o.d" -MT "${OBJECTDIR}/AVR files/delayT0.o.d" -MT "${OBJECTDIR}/AVR files/delayT0.o"  -o "${OBJECTDIR}/AVR files/delayT0.o" "AVR files/delayT0.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/main.o: AVR\ files/main.c  .generated_files/flags/default/78d95e442a25f0a032d0d7d5041615c98d24e7f3 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/main.o".d 
	@${RM} "${OBJECTDIR}/AVR files/main.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/main.o.d" -MT "${OBJECTDIR}/AVR files/main.o.d" -MT "${OBJECTDIR}/AVR files/main.o"  -o "${OBJECTDIR}/AVR files/main.o" "AVR files/main.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/AVR\ files/Timer0.o: AVR\ files/Timer0.c  .generated_files/flags/default/7ae8d20e94c37f11cd0a25da29b4e16303d5e3d9 .generated_files/flags/default/92785dca4445cd50133b39d13cfd2b8e071e54a2
	@${MKDIR} "${OBJECTDIR}/AVR files" 
	@${RM} "${OBJECTDIR}/AVR files/Timer0.o".d 
	@${RM} "${OBJECTDIR}/AVR files/Timer0.o" 
	 ${MP_CC}  $(MP_EXTRA_CC_PRE) -mmcu=atmega32 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/AVR files/Timer0.o.d" -MT "${OBJECTDIR}/AVR files/Timer0.o.d" -MT "${OBJECTDIR}/AVR files/Timer0.o"  -o "${OBJECTDIR}/AVR files/Timer0.o" "AVR files/Timer0.c"  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega32 ${PACK_COMMON_OPTIONS}  -D__MPLAB_DEBUGGER_SIMULATOR=1 -gdwarf-2 -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\Timer0.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/Timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1 -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	
	
	
	
	
	
else
${DISTDIR}/Timer0.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mmcu=atmega32 ${PACK_COMMON_OPTIONS}  -D__$(MP_PROCESSOR_OPTION)__  -Wl,-Map="${DISTDIR}\Timer0.X.${IMAGE_TYPE}.map"    -o ${DISTDIR}/Timer0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}      -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION) -Wl,--gc-sections -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "${DISTDIR}/Timer0.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "${DISTDIR}/Timer0.X.${IMAGE_TYPE}.hex"
	
	
	
	
	
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
