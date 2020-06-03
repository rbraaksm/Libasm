; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_list_size.s                                     :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/03 11:07:50 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/03 11:40:23 by rbraaksm      ########   odam.nl          ;
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
        cmp     rcx, 0
        je      return

count:
        inc     rax
        mov     rcx, [rcx + 8]
        jmp     check_end

return:
        ret
