#include<p16f877a.inc>
ORG 10H
BSF STATUS,RP0
BSF STATUS,RP1
MOVLW h'ff
MOVWF 0X21
END