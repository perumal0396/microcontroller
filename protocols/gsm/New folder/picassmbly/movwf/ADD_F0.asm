#include<p16f877a.inc>  ;header file for pic controller
ORG 00H                 ;orgain store the program in 00h prg mry address
MOVLW 0XF0              ;literal values moved into working register
ADDLW 0XF0
NOP                    ;no operation
END                    ;end of operation