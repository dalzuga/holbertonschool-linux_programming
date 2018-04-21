BITS 64
	global swap
	section .text

	; void swap(int *a, int *b);
	; Swaps the values of two pointers
	;
	; rdi <- a
	; rsi <- b
swap:
	push rbp
	mov rbp, rsp

	push r8
	push r9

	mov r8d, dword [rdi]	; r8 is 64-bit, r8d is 32-bit
	mov r9d, dword [rsi]

	mov dword [rdi], r9d
	mov dword [rsi], r8d

	pop r9
	pop r8

	mov rsp, rbp
	pop rbp

	ret
