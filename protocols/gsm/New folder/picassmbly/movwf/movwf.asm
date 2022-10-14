#include<p16f877a.inc> ;header file for pic controller
ORG 00H                ;orgain store the program in 00h program memory address 
;BSF 83H,05H         ;clear the RP0 bit in status register
;BCF 83H,06H         ;set the RP1 bit in status register;
MOVLW h'ff           ;literal values moved into working register                    ;no operation
;MOVWF 0ffH              ;wo
;CLRF 0XA0 
END