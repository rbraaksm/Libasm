; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_atoi_base.s                                     :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/05/30 20:39:28 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/05/31 12:50:15 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_atoi_base

_ft_atoi_base:					; rdi = string rsi = base
		 mov         rbx, 0                          ; base length
         cmp         rdi, 0
         je          error
         cmp         rsi, 0
         je          error
         mov         rax, 0
		jmp		base

base:
		cmp		rsi, 0
		jl		error
		cmp		rsi, 9
		jg		error
		mov		rax, rsi
		ret
		jmp		return

; base:
		; movzx	rdx, byte[rsi]
		; test	rdx, rdx
		; je		error
		; cmp		byte[rsi], 48
		; jl		error
		; cmp		byte[rsi], 57
		; jg		error
		; sub		rdx, 48
		; imul	rdx, 10
		; add		rax, rbx
		; inc 	rsi
		; jmp		return



; inc_rdi:
; 		inc		rdi
; 		jmp		spaces

; spaces:
; 		cmp		byte[rdi], 32
; 		je		inc_rdi
; 		cmp		byte[rdi], 9
; 		je		inc_rdi
; 		cmp		byte[rdi], 10
; 		je		inc_rdi
; 		cmp		byte[rdi], 11
; 		je		inc_rdi
; 		cmp		byte[rdi], 12
; 		je		inc_rdi
; 		cmp		byte[rdi], 13
; 		je		inc_rdi
; 		jmp		plus_minus

; inc_rdi_plus:
; 		inc		rdi
; 		jmp		atoi

; plus_minus:
; 		cmp		byte[rdi], 43
; 		je		inc_rdi_plus
; 		cmp		byte[rdi], 45
; 		je		negative
; 		jmp		atoi

; negative:
; 		mov		r12, 1
; 		inc		rdi
; 		jmp		atoi

; atoi:
; 		movzx	rbx, byte[rdi]
; 		test	rbx, rbx
; 		je		return
; 		cmp		rbx, 48
; 		jl		error
; 		cmp		rbx, 57
; 		jg		error

; 		sub		rbx, 48
; 		imul	rax, 10
; 		add		rax, rbx
; 		inc 	rdi
; 		jmp		atoi

error:
		mov		rax, 0
		ret

return:
		; cmp		r12, 1
		; je		negative_nb
		ret

negative_nb:
		neg		rax
		ret
