	;; Anna Alberti
	;; aca5z 11/14/2021
	;; name of file: threexplusone.s
	section .text
	global threexplusone
;;; optimizations used:
;;; (1) added for multipication instead of imul, this made it quicker
;;; (2) got rid of pushing and popping by using other register to limit memory access
;;; (3) used shifted instead of division by power of 2

threexplusone:
	push rdi		;save value of rdi entered by user
	xor r10, r10 		;zero out r10 for counter i = 0
	mov r8, rdi		;store the number in r8 to do calculations

	cmp r8, 1 		;base case
	je done			;jump to done if r8=1

	;; check if r8 is odd or even and jump to subroutine
	mov r11, r8
	and r11, 1 		; r11 will be 0 or 1
	cmp r11, 1 		; is the last digit 1?
	je odd			; jump to odd
	cmp r11, 0		;is the last digit 0?
	je even 		; jump to even
	
odd:	
	mov r9, r8		;multiply by 3 = store value in r9, add it twice
	add r8, r9
	add r8, r9
	add r8, 1 		;add 1
	mov rdi, r8

	;; should i be pushing and popping before and after this call?
	call threexplusone 	;call recursively
	inc r10 		;increment counter

	jmp done
	;; check if r8 is even
even:	
	shr r8, 1 		;divid r8 by 2
	mov rdi, r8 		;move r8 into rdi to call

	;; should i be pushing and popping before and after this call?
	call threexplusone 	;call recursively
	inc r10 		;increment counter
	
done:
	pop rdi 		;restore original value to rdi
	mov rax, r10 		;final answer is the counter
	ret
