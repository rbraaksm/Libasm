; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_atoi_base_bonus.s                               :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/05/30 20:39:28 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/07 17:43:36 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_atoi_base
extern _ft_strlen

_ft_atoi_base:							; ft_atoi_base(char *rdi, char *rsi)
		mov		rbx, 0					; base length
		mov		rcx, 0
        cmp		rdi, 0					; check input *string
        je		error
        cmp		rsi, 0					; check input *base
        je		error
        mov		rax, 0
		mov		r12, 0
		mov		r15, 0
		jmp		spaces_base

double_check:
		mov		r13, r12
		inc		r13
		cmp		byte[rsi + r13], 0
		jne		double
		jmp		inc_r12

double:
		mov		r14b, byte[rsi + r12]
		cmp		byte[rsi + r13], r14b
		je		error
		inc		r13
		cmp		byte[rsi + r13], 0
		je		inc_r12
		jmp		double

inc_r12:
		inc		r12

spaces_base:
		cmp		byte[rsi + r12], 0			; check for delimiter
		je		base
		cmp		byte[rsi + r12], 127
		jg		error
		cmp		byte[rsi + r12], 32
		jle		error
		cmp		byte[rsi + r12], 9
		je		error
		cmp		byte[rsi + r12], 10
		je		error
		cmp		byte[rsi + r12], 11
		je		error
		cmp		byte[rsi + r12], 12
		je		error
		cmp		byte[rsi + r12], 13
		je		error
		cmp		byte[rsi + r12], 43
		je		error
		cmp		byte[rsi + r12], 45
		je		error
		jmp		double_check

base:
		cmp		r12, 1
		jle		error
		jmp		spaces_str

inc_rdi:
		inc		rdi

spaces_str:
		cmp		byte[rdi], 32
		je		inc_rdi
		cmp		byte[rdi], 9
		je		inc_rdi
		cmp		byte[rdi], 10
		je		inc_rdi
		cmp		byte[rdi], 11
		je		inc_rdi
		cmp		byte[rdi], 12
		je		inc_rdi
		cmp		byte[rdi], 13
		je		inc_rdi
		mov		r13, 1
		jmp		plus_minus

inc_rdi_plus:
		inc		rdi
		jmp		plus_minus

negative:
		imul	r13, -1
		inc		rdi

plus_minus:
		cmp		byte[rdi], 43
		je		inc_rdi_plus
		cmp		byte[rdi], 45
		je		negative
		jmp		atoi

atoi:
		cmp		byte[rdi], 32
		jl		error
		cmp		byte[rdi], 127
		jg		error
		mov		r11, 0
		jmp		get_value

inc_r11:
		inc		r11

get_value:
		mov		r15b, byte[rdi]
		cmp		byte[rsi + r11], r15b
		je		next
		cmp		byte[rsi + r11], 0
		je		next
		jmp		inc_r11

next:
		cmp		r11, r12
		jge		return
		jmp		result

result:
		imul	rcx, r12
		add		rcx, r11
		mov		rax, rcx
		mov		r11, 0
		inc		rdi
		jmp		get_value

error:
		mov		rax, 0
		ret

negative_nb:
		neg		rax
		ret

return:
		cmp		r13, -1
		je		negative_nb
		ret