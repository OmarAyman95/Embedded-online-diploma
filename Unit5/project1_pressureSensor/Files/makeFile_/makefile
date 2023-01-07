#@copyright : OMAR
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
project_name = cortexM3

all: $(project_name).bin 	
	@echo "M   a   k   e    i s    d   o   n   e"
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

$(project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T LinkerScript.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=mapFile.map

$(project_name).bin : $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	$(CC)objcopy.exe -O ihex $< $(project_name).hex

clean_all:
	rm  *.o *.bin *.elf *.map *.hex
clean:
	rm *.bin *.elf
