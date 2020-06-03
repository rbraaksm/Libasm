; **************************************************************************** ;
;                                                                              ;
;                                                         ::::::::             ;
;    ft_list_sort.s                                     :+:    :+:             ;
;                                                      +:+                     ;
;    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      ;
;                                                    +#+                       ;
;    Created: 2020/06/03 11:21:36 by rbraaksm      #+#    #+#                  ;
;    Updated: 2020/06/03 15:40:17 by rbraaksm      ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

global _ft_list_sort

_ft_list_sort:                          ; rdi = **begin_list  rsi = cmp()
        cmp     rdi, 0
        je      return
        cmp     rsi, 0
        je      return
        mov     r12, [rdi]              ; first = *begin
        mov     rdi, [rdi]

while:
        cmp     rdi, 0
        je      return
        mov     r10, [rdi + 8]          ; address next element
        cmp     r10, 0                  ; check end of list
        je      return
        push    rdi
        push    rsi
        mov     rax, rsi
        mov     r13, [rdi + 8]          ; next element
        mov     rsi, [r13 + 0]          ; second argument data.next
        mov     rdi, [rdi + 0]          ; first argument data.current
        call    rax                     ; call cmp (rdi, rsi)
        pop     rsi
        pop     rdi
        jns     swap                    ; Jump No Sign (positive value)

new_data:
        mov     rdi, [rdi + 8]
        jmp     while

swap:
        cmp     rax, 0
        je      new_data
        mov     r14, [rdi + 0]          ; save current data
        mov     r15, [r13 + 0]          ; save next data
        mov     [r13 + 0], r10
        mov     [rdi + 0], r15
        mov     rdi, r12                ; set to first element
        jmp     while

return:
        mov     rax, 0
        ret