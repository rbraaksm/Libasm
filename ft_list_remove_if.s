; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_list_remove_if.s                                :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/07 17:54:46 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/07 18:17:00 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_list_remove_if
extern _free

_ft_list_remove_if:					; rdi = **begin_list, rsi = *data_ref, rdx = *cmp
		push	rdi
		cmp		rdi, 0
		je		return
		cmp		rdx, 0
		mov		rdi, [rdi]
		mov		rcx, 0				; check for first_element
		jmp		loop

next_element:
		inc		rcx
		mov		r10, rdi
		mov		rdi, [rdi + 8]

loop:
		cmp		rdi, 0
		je		return
		push	rdi
		push	rsi
		push	rdx
		push	rcx
		mov		rdi, [rdi + 0]
		call	rdx
		pop		rcx
		pop		rdx
		pop		rsi
		pop		rdi
		cmp		rax, 0
		je		check_list
		jmp		next_element

check_list:
		mov		r12, [rdi]
		mov		r14, [rdi + 8]
		cmp		rcx, 0
		je		first
		jmp		free_next

first:
		cmp		r14, 0
		je		free_list
		mov		r14, [r14]
		mov		r13, [rdi + 8]
		mov		[rdi], r14
		mov		r13, [r13 + 8]
		mov		[rdi + 8], r13
		jmp		free

free_next:
		mov		[r10 + 8], r14

free:
		push	rdi
		push	rsi
		push	rdx
		push	rcx
		mov		rdi, r12
		push	rdi
		call	_free
		pop		rdi
		pop		rcx
		pop		rdx
		pop		rsi
		pop		rdi
		cmp		rcx, 0
		je		loop
		jmp		next_element

free_list:
		mov		rdi, r12
		push	rdi
		call	_free
		pop		rdi
		pop		rdi
		mov		[rdi], r14
		ret

return:
		pop		rdi
		ret