; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_list_remove_if_bonus.s                          :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/08 10:43:07 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/10 13:06:14 by rbraaksm      ########   odam.nl          ;
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
		inc		rcx					; it's not the first_element anymore
		mov		r15, rdi			; save current.element
		mov		rdi, [rdi + 8]		; rdi = next.element

loop:
		cmp		rdi, 0				; check end of the list
		je		return
		push	rdi
		push	rsi
		push	rdx
		push	rcx
		mov		rdi, [rdi]		; set data.element in rdi
		call	rdx					; compare rdi.data with *data_ref
		pop		rcx
		pop		rdx
		pop		rsi
		pop		rdi
		cmp		rax, 0				; rdi.data and *data_ref are equal
		je		check_list
		jmp		next_element

check_list:
		mov		r14, [rdi]		; save pointer to current.element
		mov		r13, [rdi + 8]		; save address next.element
		cmp		rcx, 0				; check for first element
		je		first
		jmp		free_next

first:
		cmp		r13, 0				; check if next.element exists
		je		free_list			; if not? Remove list
		mov		r13, [r13]			; save next.element with data and address
		mov		[rdi], r13			; put next.element in current.element
		jmp		free

free_next:
		mov		[r15 + 8], r13		; put address next.element in address current.element
		mov		[rdi + 8], r15

free:
		push	rsi
		push	rdx
		push	rcx
		push	rdi
		mov		rdi, r12			; move current.element in rdi
		call	_free
		pop		rdi
		pop		rcx
		pop		rdx
		pop		rsi
		cmp		rcx, 0
		je		loop
		jmp		next_element

free_list:
		mov		rdi, r12			; move current.element in rdi
		push	rdi
		call	_free
		pop		rdi
		pop		rdi
		mov		[rdi], r13			; move address next.element in *begin_list
		ret

return:
		pop		rdi
		ret