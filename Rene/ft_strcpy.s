# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strcpy.s                                        :+:    :+:             #
#                                                      +:+                     #
#    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/20 18:03:10 by rbraaksm      #+#    #+#                  #
#    Updated: 2020/05/22 16:48:24 by rbraaksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

global _ft_strcpy

_ft_strcpy:
		mov		rcx, 0					;index number
		cmp		rdi, 0					;check dest is null
		je		exit
		cmp		rsi, 0					;check src is null
		je		exit
		jmp		copy

exit:
		mov		rax, 0					;return null
		ret

copy:
		mov		al, byte[rsi + rcx]		;src char in al
		mov		byte[rdi + rcx], al		;src char in dst
		cmp		al, 0					;check char is delimiter
		je		return
		inc		rcx
		jmp		copy

return:
		mov		rax, rdi
		ret