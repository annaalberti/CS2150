	;; Anna Alberti aca5z 11/1/2021

	global linearSearch

	section .text

	;; parameter 1 (rdi): pointer to the array
	;;  parameter 2 (rsi): n size of the array
	;; parameter 3 (rdx): k target element to find in the array


linearSearch:
	;; mov r8, rsi		; move size of array
	;; shl r8, 2 		;times 4, since ints are 4 bytes
	xor r9, r9 		;0 in r9 for incrementing i
	xor rax, rax
	xor rcx, rcx
start:	
	cmp rsi, r9 		;is size =r9?
	je not_found		; not found and at the end of the array
	;; mov r10, rdi 		; move start index into
	;; add r10, r9 		;add index* 4
	;; shl r10, 2
	mov ecx, [rdi+4*r9]
	cmp rcx, rdx 		;arr[start+4*ci] = k?
	je found		; jumpt to found if yes
	;; else, increment i
	inc r9			;i++
	jmp start

not_found:
	mov rax, -1
	ret
found:
	mov rax, r9
	ret

	
