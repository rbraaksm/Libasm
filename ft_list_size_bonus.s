; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_list_size.s                                     :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/03 11:07:50 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/07 18:37:36 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_list_size

_ft_list_size:                  ; rdi = **begin_list
        mov     rax, 0
        cmp     rdi, 0
        je      return
        mov     rcx, rdi        ; begin element in register
        jmp     count

check_end:
        cmp     rcx, 0			; check end of list
        je      return

count:
        inc     rax				; increase return value
        mov     rcx, [rcx + 8]	; move adress next.element in rcx
        jmp     check_end

return:
        ret
