# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strcmp.s                                        :+:    :+:             #
#                                                      +:+                     #
#    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/22 17:03:22 by rbraaksm      #+#    #+#                  #
#    Updated: 2020/05/22 18:42:44 by rbraaksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

global _ft_strcmp

_ft_strcmp:
		cmp		rdi, 0				;check string1 for null
		je		error
		cmp		rsi, 0				;check string2 for null
		je		error1
		jmp		compare

compare:
		mov		cl, byte[rdi]		;char rdi in register cl
		mov		dl, byte[rsi]		;char rsi in register dl
		movzx   rcx, cl				;I need rcx to mov in rax
        movzx   rdx, dl				;I need rdx to substract from rcx
		cmp		rcx, 0
		je		return
		cmp		rdx, 0
		je		return
		inc		rdi
		inc		rsi
		cmp		cl, dl
		jne		return
		je		compare

return:
        sub     rcx, rdx
        mov     rax, rcx
		ret

zero:
		mov		rax, 0
		ret

error:
		cmp		rsi, 0
		je		zero
		mov		dl, byte[rsi]
		mov		cl, 0
		jmp		return

error1:
		mov		cl, byte[rdi]
		mov		dl, 0
		jmp		return
