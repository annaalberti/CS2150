	;;  Anna Alberti
	;;  aca5z
	;;  10/31/21

	section .text
	global product
	global power
product:
	;; prologue
	xor rax, rax 		; zero out the return register
	xor r10, r10 		; zero out the counter i
	jmp productStart

productStart:
	;; multiplication loop
	cmp r10, rsi 		;check if i == n?
	je productDone			; if so, jump to done
	add rax, rdi		; add the number in rdi
	inc r10 		; increment our counter i
	jmp productStart
productDone:
	;; epilogue
	ret 			;return the product
 				; return the power
power:
	
	;; prologue
			; move first value into second for product call
	cmp rsi, 0		;compare if rsi = 0, return 1
	mov rax, 1		; mov 1 to rax
	je powerDone 		; jump to done bc we are done
	dec rsi			;decrement rdx
	call power
	mov rsi, rax
	call product
	jmp powerDone		; jump to return
	;; power loop

powerDone:
	;; epilogue
	ret 			;return the product
