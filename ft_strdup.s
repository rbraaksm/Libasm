; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_strdup.s                                        :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/05/25 14:14:45 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/05/27 17:01:00 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
	push	rdi					; save str into stack
	cmp		rdi, 0				; check input
	je		error
	mov		rcx, 0				; index counter
	call	_ft_strlen
	inc		rax					; length + 1
	mov		rdi, rax			; malloc size
	push	rbp					; safe base pointer
	mov		rbp, rsp
	and		rsp, - 16			; allign stack
	call	_malloc
	mov		rsp, rbp			; reset stack and base pointer
	pop		rbp
	cmp		rax, 0				; malloc succesful?
	je		error

copy:
	pop		rsi					; original str as src
	mov		rdi, rax			; allocated as dest
	call	_ft_strcpy
	ret

error:
	pop		rdi
	ret
