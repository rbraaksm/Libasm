; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.s                                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/05/27 08:51:50 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/07 17:21:17 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global  _ft_read
extern	___error

_ft_read:
		mov		rax, 0x2000003
		syscall
    	jc		error		    	; error sets carry flag, rax = errno
		ret

error:
		mov		r15, rax 			; save errno
		call	___error			; retrieve address to errno
		mov		[rax], r15			; pointer to errno
		mov		rax, -1
		ret
