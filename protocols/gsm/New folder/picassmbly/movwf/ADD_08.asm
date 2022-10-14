#include<p16F877a.inc>  ;header file for pic controller
ORG 00H                 ;orgain store the program in 00h program memory address
MOVLW 0X08              ;literal values moved into working register 
ADDLW 0X08              ;add literal value to working register
;NOP
;ADDLW 0X08
NOP
END