;The following should print: ABCDEFG5
.orig x3000
LEA R0, STR1 ;R0 points to STR1
JSR TOUPPER ;Convert STR1 to all uppercase characters.
JSR TOUPPER ;Convert STR1 to all uppercase characters.
PUTS
HALT
;Data
.blkw 100 ;Change this value when testing between 50 and 150.
STR1 .stringz "abCDefG5" ;Use numbers, punctuation, spaces, etc... while testing.


FINDLAST
		ST R1, SAVR1
TOP		LDR R1, R0, #0
		BRZ END
		ADD R0, R0, #1
		BRNZP TOP
END		ADD R0, R0, #-1
		LD R1, SAVR1
		RET
		
SAVR1	.fill 0		

FINDCHAR
		ST R1, SAVR1
		ST R2, SAVR2
		ST R3, SAVR3
		ST R4, SAVR4
		NOT R0, R0
		ADD R0, R0, #1  ;makes what is in R0 negative
		AND R3, R3, #0  ;clears value of R3 to 0
HEAD
		LDR R2, R1, #0  ;points to first character in string
		BRZ TESTNEG1		
		ADD R3, R3, #1	;increments the index count
		ADD R4, R2, R0	;adds the character and the search character
		BRZ IFCHAR		;branch if the character is found
		ADD R1, R1, #1 	;increments pointer
		BRNZP HEAD		;loops back to head
IFCHAR  ADD R0, R3, #0
		ADD R0, R0, #-1 ;corrects index because it is off by one
		BRNZP ENDFC
NOTCHAR LD R0, NOCHAR
		BRNZP ENDFC
TESTNEG1
		ADD R3, R3, #-1
		BRN NOTCHAR		;if the string is empty return negative 1
		ADD R4, R2, R0	;if the chracter is not found
		BRNP NOTCHAR
		BRNZP ENDFC
ENDFC
		LD R1, SAVR1
		LD R2, SAVR2
		LD R3, SAVR3
		LD R4, SAVR4
		RET
		
SAVR2	.fill 0
SAVR3	.fill 0
SAVR4	.fill 0
NOCHAR  .fill -1

STRCAT
		ST R7, SAVR7
		ST R0, SAVR0
		ST R1, SAVR1
		ST R2, SAVR2
		ST R3, SAVR3
		JSR FINDLAST	;finds the last character of STR1
		ADD R0, R0, #1	;increments so that null terminated 0 is overwritten
		AND R3, R3, #0	
TOPSC	LDR R2, R1, #0
		BRZ ENDSC
		STR R2, R0, #0	;copies what is in STR2 to the end of STR1
		ADD R0, R0, #1	;increments variables
		ADD R1, R1, #1
		STR R3, R0, #0	;writes null terminated 0 at end of concatenated string
		BRNZP TOPSC
ENDSC	LD R7, SAVR7
		LD R0, SAVR0
		LD R1, SAVR1
		LD R2, SAVR2
		LD R3, SAVR3
		RET
		
SAVR7	.fill 0

TOUPPER
		ST R0, SAVR0
		ST R1, SAVR1
		ST R2, SAVR2
		ST R3, SAVR3
		ST R6, SAVR6
		LD R3, SUBTR ;32 to capitalize
TOPTU	LDR R1, R0, #0 ;points to character in R0
		BRZ ENDTU
		LD R2, LOWA
		ADD R6, R1, R2
		BRN INCR		;skips over if less than lowercase a because already capitalized
		LD R2, LOWZ
		ADD R6, R1, R2
		BRNZ CAP		;capitalizes if less than lowercase z but greater than lowercase a
		BRNZP TOPTU		;loops back to top
CAP		ADD R1, R1, R3
		STR R1, R0, #0
		BRNZP INCR
INCR	ADD R0, R0, #1
		BRNZP TOPTU
ENDTU	LD R0, SAVR0
		LD R1, SAVR1
		LD R2, SAVR2
		LD R3, SAVR3
		LD R6, SAVR6
		RET
		
SAVR0	.fill 0		
SAVR6 	.fill 0
LOWA	.fill -97
LOWZ	.fill -122
SUBTR	.fill -32
