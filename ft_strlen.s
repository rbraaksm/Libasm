; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/05/20 17:37:43 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/07 17:16:00 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strlen

_ft_strlen:
		mov		rax, 0				;set return value to zero
		cmp		rdi, 0				;compare input string
		je		return
		cmp		byte[rdi], 0		;check for delimiter
		je		return

loop:
		inc		rax					; increase return value
		cmp		byte[rdi + rax], 0
		jne		loop

return:
		ret