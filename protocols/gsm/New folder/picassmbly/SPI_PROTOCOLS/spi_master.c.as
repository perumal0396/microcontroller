opt subtitle "HI-TECH Software Omniscient Code Generator (Lite mode) build 7503"

opt pagewidth 120

	opt lm

	processor	16F877A
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
indf	equ	0
indf0	equ	0
pc	equ	2
pcl	equ	2
status	equ	3
fsr	equ	4
fsr0	equ	4
c	equ	1
z	equ	0
pclath	equ	10
# 3 "C:\Users\Perumal_Pichaaa!!!!!\Desktop\picassmbly\SPI_PROTOCOLS\UART_P.c"
	psect config,class=CONFIG,delta=2 ;#
# 3 "C:\Users\Perumal_Pichaaa!!!!!\Desktop\picassmbly\SPI_PROTOCOLS\UART_P.c"
	dw 0xFFFE & 0xFFFB & 0xFFFF & 0xFFFF & 0xFF7F ;#
	FNCALL	_main,_uart_init
	FNCALL	_main,_uart_tx
	FNCALL	_main,_dealy
	FNROOT	_main
	global	_RCREG
psect	text80,local,class=CODE,delta=2
global __ptext80
__ptext80:
_RCREG	set	26
	global	_RCSTA
_RCSTA	set	24
	global	_TMR1H
_TMR1H	set	15
	global	_TMR1L
_TMR1L	set	14
	global	_TXREG
_TXREG	set	25
	global	_RCIF
_RCIF	set	101
	global	_SPEN
_SPEN	set	199
	global	_T1CKPS0
_T1CKPS0	set	132
	global	_T1CKPS1
_T1CKPS1	set	133
	global	_TMR1CS
_TMR1CS	set	129
	global	_TMR1IF
_TMR1IF	set	96
	global	_TMR1ON
_TMR1ON	set	128
	global	_TXIF
_TXIF	set	100
	global	_SPBRG
_SPBRG	set	153
	global	_TXSTA
_TXSTA	set	152
	global	_TRISC6
_TRISC6	set	1086
	global	_TRISC7
_TRISC7	set	1087
	global	_TXEN
_TXEN	set	1221
	file	"spi_master.c.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

psect cinit,class=CODE,delta=2
global end_of_initialization

;End of C runtime variable initialization code

end_of_initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1
global __pcstackCOMMON
__pcstackCOMMON:
	global	?_uart_init
?_uart_init:	; 0 bytes @ 0x0
	global	??_uart_init
??_uart_init:	; 0 bytes @ 0x0
	global	?_uart_tx
?_uart_tx:	; 0 bytes @ 0x0
	global	??_uart_tx
??_uart_tx:	; 0 bytes @ 0x0
	global	?_dealy
?_dealy:	; 0 bytes @ 0x0
	global	??_dealy
??_dealy:	; 0 bytes @ 0x0
	global	?_main
?_main:	; 2 bytes @ 0x0
	global	uart_tx@val
uart_tx@val:	; 1 bytes @ 0x0
	ds	1
	global	??_main
??_main:	; 0 bytes @ 0x1
;;Data sizes: Strings 0, constant 0, data 0, bss 0, persistent 0 stack 0
;;Auto spaces:   Size  Autos    Used
;; COMMON          14      1       1
;; BANK0           80      0       0
;; BANK1           80      0       0
;; BANK3           96      0       0
;; BANK2           96      0       0

;;
;; Pointer list with targets:



;;
;; Critical Paths under _main in COMMON
;;
;;   _main->_uart_tx
;;
;; Critical Paths under _main in BANK0
;;
;;   None.
;;
;; Critical Paths under _main in BANK1
;;
;;   None.
;;
;; Critical Paths under _main in BANK3
;;
;;   None.
;;
;; Critical Paths under _main in BANK2
;;
;;   None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;;
;;Call Graph Tables:
;;
;; ---------------------------------------------------------------------------------
;; (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;; ---------------------------------------------------------------------------------
;; (0) _main                                                 0     0      0      15
;;                          _uart_init
;;                            _uart_tx
;;                              _dealy
;; ---------------------------------------------------------------------------------
;; (1) _uart_tx                                              1     1      0      15
;;                                              0 COMMON     1     1      0
;; ---------------------------------------------------------------------------------
;; (1) _uart_init                                            0     0      0       0
;; ---------------------------------------------------------------------------------
;; (1) _dealy                                                0     0      0       0
;; ---------------------------------------------------------------------------------
;; Estimated maximum stack depth 1
;; ---------------------------------------------------------------------------------

;; Call Graph Graphs:

;; _main (ROOT)
;;   _uart_init
;;   _uart_tx
;;   _dealy
;;

;; Address spaces:

;;Name               Size   Autos  Total    Cost      Usage
;;BITCOMMON            E      0       0       0        0.0%
;;EEDATA             100      0       0       0        0.0%
;;NULL                 0      0       0       0        0.0%
;;CODE                 0      0       0       0        0.0%
;;COMMON               E      1       1       1        7.1%
;;BITSFR0              0      0       0       1        0.0%
;;SFR0                 0      0       0       1        0.0%
;;BITSFR1              0      0       0       2        0.0%
;;SFR1                 0      0       0       2        0.0%
;;STACK                0      0       1       2        0.0%
;;ABS                  0      0       0       3        0.0%
;;BITBANK0            50      0       0       4        0.0%
;;BITSFR3              0      0       0       4        0.0%
;;SFR3                 0      0       0       4        0.0%
;;BANK0               50      0       0       5        0.0%
;;BITSFR2              0      0       0       5        0.0%
;;SFR2                 0      0       0       5        0.0%
;;BITBANK1            50      0       0       6        0.0%
;;BANK1               50      0       0       7        0.0%
;;BITBANK3            60      0       0       8        0.0%
;;BANK3               60      0       0       9        0.0%
;;BITBANK2            60      0       0      10        0.0%
;;BANK2               60      0       0      11        0.0%
;;DATA                 0      0       0      12        0.0%

	global	_main
psect	maintext,global,class=CODE,delta=2
global __pmaintext
__pmaintext:

;; *************** function _main *****************
;; Defined at:
;;		line 21 in file "C:\Users\Perumal_Pichaaa!!!!!\Desktop\picassmbly\SPI_PROTOCOLS\UART_P.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  2  694[COMMON] int 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 17F/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    1
;; This function calls:
;;		_uart_init
;;		_uart_tx
;;		_dealy
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext
	file	"C:\Users\Perumal_Pichaaa!!!!!\Desktop\picassmbly\SPI_PROTOCOLS\UART_P.c"
	line	21
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
	opt	stack 7
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	22
	
l1876:	
;UART_P.c: 22: uart_init();
	fcall	_uart_init
	line	23
;UART_P.c: 23: uart_tx('L');
	movlw	(04Ch)
	fcall	_uart_tx
	line	24
;UART_P.c: 24: dealy();
	fcall	_dealy
	line	25
;UART_P.c: 25: uart_tx('i');
	movlw	(069h)
	fcall	_uart_tx
	line	26
;UART_P.c: 26: dealy();
	fcall	_dealy
	line	27
;UART_P.c: 27: uart_tx('n');
	movlw	(06Eh)
	fcall	_uart_tx
	line	28
;UART_P.c: 28: dealy();
	fcall	_dealy
	line	29
;UART_P.c: 29: uart_tx('u');
	movlw	(075h)
	fcall	_uart_tx
	line	30
;UART_P.c: 30: dealy();
	fcall	_dealy
	line	31
;UART_P.c: 31: uart_tx('x');
	movlw	(078h)
	fcall	_uart_tx
	line	32
;UART_P.c: 32: dealy();
	fcall	_dealy
	goto	l696
	line	33
;UART_P.c: 33: while(1);
	
l695:	
	
l696:	
	goto	l696
	
l697:	
	line	34
	
l698:	
	global	start
	ljmp	start
	opt stack 0
GLOBAL	__end_of_main
	__end_of_main:
;; =============== function _main ends ============

	signat	_main,90
	global	_uart_tx
psect	text81,local,class=CODE,delta=2
global __ptext81
__ptext81:

;; *************** function _uart_tx *****************
;; Defined at:
;;		line 36 in file "C:\Users\Perumal_Pichaaa!!!!!\Desktop\picassmbly\SPI_PROTOCOLS\UART_P.c"
;; Parameters:    Size  Location     Type
;;  val             1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  val             1    0[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         1       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         1       0       0       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text81
	file	"C:\Users\Perumal_Pichaaa!!!!!\Desktop\picassmbly\SPI_PROTOCOLS\UART_P.c"
	line	36
	global	__size_of_uart_tx
	__size_of_uart_tx	equ	__end_of_uart_tx-_uart_tx
	
_uart_tx:	
	opt	stack 7
; Regs used in _uart_tx: [wreg]
;uart_tx@val stored from wreg
	movwf	(uart_tx@val)
	line	37
	
l1102:	
;UART_P.c: 37: TXREG=val;
	movf	(uart_tx@val),w
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	movwf	(25)	;volatile
	line	38
;UART_P.c: 38: while(TXIF==0);
	goto	l701
	
l702:	
	
l701:	
	btfss	(100/8),(100)&7
	goto	u21
	goto	u20
u21:
	goto	l701
u20:
	
l703:	
	line	39
;UART_P.c: 39: TXIF=0;
	bcf	(100/8),(100)&7
	line	40
	
l704:	
	return
	opt stack 0
GLOBAL	__end_of_uart_tx
	__end_of_uart_tx:
;; =============== function _uart_tx ends ============

	signat	_uart_tx,4216
	global	_uart_init
psect	text82,local,class=CODE,delta=2
global __ptext82
__ptext82:

;; *************** function _uart_init *****************
;; Defined at:
;;		line 48 in file "C:\Users\Perumal_Pichaaa!!!!!\Desktop\picassmbly\SPI_PROTOCOLS\UART_P.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text82
	file	"C:\Users\Perumal_Pichaaa!!!!!\Desktop\picassmbly\SPI_PROTOCOLS\UART_P.c"
	line	48
	global	__size_of_uart_init
	__size_of_uart_init	equ	__end_of_uart_init-_uart_init
	
_uart_init:	
	opt	stack 7
; Regs used in _uart_init: [wreg+status,2]
	line	49
	
l1088:	
;UART_P.c: 49: TRISC6=0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	bcf	(1086/8)^080h,(1086)&7
	line	50
;UART_P.c: 50: TRISC7=1;
	bsf	(1087/8)^080h,(1087)&7
	line	51
	
l1090:	
;UART_P.c: 51: TXSTA=0x00;
	clrf	(152)^080h	;volatile
	line	52
;UART_P.c: 52: RCSTA=0x00;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	clrf	(24)	;volatile
	line	53
	
l1092:	
;UART_P.c: 53: SPBRG=31;
	movlw	(01Fh)
	bsf	status, 5	;RP0=1, select bank1
	bcf	status, 6	;RP1=0, select bank1
	movwf	(153)^080h	;volatile
	line	54
	
l1094:	
;UART_P.c: 54: TXEN=1;
	bsf	(1221/8)^080h,(1221)&7
	line	55
	
l1096:	
;UART_P.c: 55: SPEN=1;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(199/8),(199)&7
	line	56
	
l1098:	
;UART_P.c: 56: TXIF=0;
	bcf	(100/8),(100)&7
	line	57
	
l1100:	
;UART_P.c: 57: RCIF=0;
	bcf	(101/8),(101)&7
	line	58
	
l713:	
	return
	opt stack 0
GLOBAL	__end_of_uart_init
	__end_of_uart_init:
;; =============== function _uart_init ends ============

	signat	_uart_init,88
	global	_dealy
psect	text83,local,class=CODE,delta=2
global __ptext83
__ptext83:

;; *************** function _dealy *****************
;; Defined at:
;;		line 9 in file "C:\Users\Perumal_Pichaaa!!!!!\Desktop\picassmbly\SPI_PROTOCOLS\UART_P.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;		None               void
;; Registers used:
;;		wreg
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1   BANK3   BANK2
;;      Params:         0       0       0       0       0
;;      Locals:         0       0       0       0       0
;;      Temps:          0       0       0       0       0
;;      Totals:         0       0       0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text83
	file	"C:\Users\Perumal_Pichaaa!!!!!\Desktop\picassmbly\SPI_PROTOCOLS\UART_P.c"
	line	9
	global	__size_of_dealy
	__size_of_dealy	equ	__end_of_dealy-_dealy
	
_dealy:	
	opt	stack 7
; Regs used in _dealy: [wreg]
	line	10
	
l1082:	
;UART_P.c: 10: TMR1CS=1;
	bcf	status, 5	;RP0=0, select bank0
	bcf	status, 6	;RP1=0, select bank0
	bsf	(129/8),(129)&7
	line	11
;UART_P.c: 11: T1CKPS0=1;
	bsf	(132/8),(132)&7
	line	12
;UART_P.c: 12: T1CKPS1=1;
	bsf	(133/8),(133)&7
	line	13
	
l1084:	
;UART_P.c: 13: TMR1H=0X3C;
	movlw	(03Ch)
	movwf	(15)	;volatile
	line	14
;UART_P.c: 14: TMR1L=0XB0;
	movlw	(0B0h)
	movwf	(14)	;volatile
	line	15
	
l1086:	
;UART_P.c: 15: TMR1ON=1;
	bsf	(128/8),(128)&7
	line	16
;UART_P.c: 16: while(!TMR1IF);
	goto	l689
	
l690:	
	
l689:	
	btfss	(96/8),(96)&7
	goto	u11
	goto	u10
u11:
	goto	l689
u10:
	
l691:	
	line	17
;UART_P.c: 17: TMR1IF=0;
	bcf	(96/8),(96)&7
	line	18
;UART_P.c: 18: TMR1ON=0;
	bcf	(128/8),(128)&7
	line	19
	
l692:	
	return
	opt stack 0
GLOBAL	__end_of_dealy
	__end_of_dealy:
;; =============== function _dealy ends ============

	signat	_dealy,88
psect	text84,local,class=CODE,delta=2
global __ptext84
__ptext84:
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp
	end
