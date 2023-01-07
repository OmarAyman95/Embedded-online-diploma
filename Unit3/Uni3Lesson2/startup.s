@@ Omar_Ayman Dev this startup at 09/24/2022 (05:11)AM 
.globl reset 
reset:
	  ldr sp,=0x00011000
	  bl main
stop: 
	  b stop	  