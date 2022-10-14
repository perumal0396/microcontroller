#include<p16f877a.inc> ;header file for pic controller
ORG 00H                ;orgain store the program in 00h program memory address
MOVLW 0XFF             ;literal values moved into working register
ADDLW 0XFF             ; add literal value to working register
NOP                    ;no operation
END                    ;end of operation