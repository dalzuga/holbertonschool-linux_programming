BITS 64

section .text
	global _start
_start:
	mov eax, edi
	add eax, esi
	ret
