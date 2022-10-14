#include<p16f877a.inc>  ;header file for pic controller
ORG 00H                 ;orgain store the program in 00h prg mry address
MOVLW 0XF8              ;literal value moved into working register
ADDLW 0XF8              ;add literal value to working register
NOP                     ;no opeartion
END                     ;End of operation