; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_list_remove_if.s                                :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/03 15:42:57 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/03 17:21:43 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_list_remove_if
extern _free

_ft_list_remove_if:                      ; rdi = **begin_list, rsi = *data_ref, rdx = *strcmp
        push    rdi
        cmp     rdi, 0
        je      return
        cmp     rdx, 0
        je      return
        mov     rdi, [rdi]
        mov     rcx, 0                  ; counter
        jmp     compare


compare:
        cmp     rdi, 0
        je      return
        