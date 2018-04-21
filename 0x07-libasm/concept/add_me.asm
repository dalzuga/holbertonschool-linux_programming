BITS 64
	global add_me
	section .text
add_me:
	mov eax, edi
	add eax, esi
	ret
