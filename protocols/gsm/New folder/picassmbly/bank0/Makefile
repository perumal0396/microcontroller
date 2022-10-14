# MPLAB IDE generated this makefile for use with GNU make.
# Project: bank0.mcp
# Date: Mon Oct 04 11:06:05 2021

AS = MPASMWIN.exe
CC = 
LD = mplink.exe
AR = mplib.exe
RM = rm

bank0.cof : bank.o
	$(CC) /p16F877A "bank.o" /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"bank0.cof" /M"bank0.map" /W

bank.o : bank.asm ../../../../../Program\ Files\ (x86)/Microchip/MPASM\ Suite/p16f877a.inc
	$(AS) /q /p16F877A "bank.asm" /l"bank.lst" /e"bank.err" /o"bank.o" /d__DEBUG=1

clean : 
	$(CC) "bank.o" "bank.err" "bank.lst" "bank0.cof" "bank0.hex"

