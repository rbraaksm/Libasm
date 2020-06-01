; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_read.s                                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/05/27 08:51:50 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/05/27 18:12:27 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global  _ft_read
extern	___error

_ft_read:                                   ; rdi = fd, rsi = bufferstring, rdx = bytes to read
            mov         rax, 0x2000003
            syscall
            jc          error
            ret
error:
			mov			r15, rax
			call		___error
			mov			[rax], r15
            mov         rax, -1
            ret
