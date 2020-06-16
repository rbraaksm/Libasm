; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_list_push_front_bonus.s                         :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/08 10:42:45 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/10 12:28:10 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_list_push_front
extern _malloc

_ft_list_push_front:                    ; rdi = **begin_list rsi = data
        push    rdi                     ; store begin_list
        push    rsi                     ; store data

create_element:
        mov     rdi, 16                 ; list = 16
        push    rbp
        mov	rbp, rsp
	and	rsp, - 16	        ; allign stack
	call	_malloc                 ; malloc 16
	mov	rsp, rbp	        ; reset stack and base pointer
	pop	rbp
        pop     rsi                     ; pop data
        pop     rdi                     ; pop begin_list
        cmp     rax, 0                  ; Malloc check
        je      return

new_element:
        mov     [rax + 0], rsi          ; data in new_element
        mov     rbx, [rdi]              ; store rdi in rbx
        mov     [rax + 8], rbx          ; last->next = list_start
        mov     [rdi], rax              ; list_start = last
        ret

return:
        ret
