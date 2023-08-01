	;; Anna Alberti
;;; 11/16/2021
	;; 	aca5z

	global binarySearch
	section .text

	;; parameter 1 (rdi): pointer to int array
	;; parameter 2 (rsi): int representing beginning of array
	;; parameter 3 (rdx): int representing the end of the array
	;; parameter 3 (rcx): int target element

binarySearch:

	;; zero out the middle 
	;; xor r10, r10
	;;  if rdx > rsi, then we haven't found it in the array
	cmp rdx, rsi
	jl not_found

	;; find the middle of the array to start
	mov r10, rsi		;rsi+rdx
	add r10, rdx
	shr r10, 1		;divide by two
	
	;r10 now holds the middle of the array
	cmp ecx, [rdi+4*r10] 	;compare target element with element at the middle index
	je finished			;if they are equal, jump to done
	jl left 		;jump to left side
	jg right		; jump to right side
left:
	mov rdx, r10 		;make rdx where the middle was
	dec rdx
	;;			dec to move one over
	call binarySearch
	ret
right:
	mov rsi, r10		;make rsi where the middle was
	inc rsi			;inc to move over one
	call binarySearch	;call binary search again
	ret
not_found:
	mov rax, -1
	ret
finished:
	mov rax, r10
	ret
