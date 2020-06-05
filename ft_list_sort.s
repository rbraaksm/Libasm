; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_list_sort.s                                     :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/03 11:21:36 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/05 11:08:16 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_list_sort

_ft_list_sort:						; rdi = **begin_list, rsi = *strcmp
		cmp		rdi, 0
		je		return
		cmp		rsi, 0
		je		return
		mov		r10, [rdi]			; save begint_list
		mov		rdi, [rdi]
		jmp		loop1

next:
		mov		rdi, [rdi + 8]		; set rdi to list->next

loop1:
		cmp		rdi, 0				; check	if list->next == 1
		je		return				; else end of list

loop2:
		mov		r11, [rdi + 8]		; set r11 to list->next
		cmp		r11, 0				; check	if r11 == 1
		je		return				; else end of list
		push	rdi
		push	rsi
		mov		rax, rsi			; set rsi to rax
		mov		rdi, [rdi + 0]		; set list->data to rdi
		mov		rsi, [r11 + 0]		; set next list->data to rsi
		call	rax					; call strcmp
		pop		rsi
		pop 	rdi
		jns		swap				; check for sign Not Set. If sign is set go on, else swap
		jmp		next

swap:
		cmp		rax, 0				; check if cmp is equal
		je		next
		mov		r12, [rdi + 0]
		mov		r13, [r11 + 0]
		mov		[r11 + 0], r12
		mov		[rdi + 0], r13
		mov		rdi, r10			; set rdi to begin
		jmp		loop2

return:
		mov		rax, 0
		ret