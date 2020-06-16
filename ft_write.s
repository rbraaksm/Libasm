; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_write.s                                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/05/22 20:50:54 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/10 09:43:22 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_write
extern ___error

_ft_write:							; rdi = file descriptor, rsi = string, rdx = byte count
		mov		rax, 0x2000004
		syscall
    	jc		error		    	; error sets carry flag, rax = errno
		ret

error:
		mov		r15, rax 			; save errno
		call	___error			; retrieve address to errno
		mov		[rax], r15			; pointer to errno
		mov		rax, -1
		ret