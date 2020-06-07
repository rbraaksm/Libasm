; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strlen.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/05/20 17:37:43 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/07 18:40:51 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strlen

_ft_strlen:							; rdi = str
		mov		rax, 0				; set return value/counter to zero
		cmp		rdi, 0				; compare input string
		je		return
		cmp		byte[rdi], 0		; check for delimiter
		je		return

loop:
		inc		rax					; increase return value/counter
		cmp		byte[rdi + rax], 0	; compare character with delimiter
		jne		loop

return:
		ret