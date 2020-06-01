# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strcpy2.s                                       :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/30 15:00:16 by abobas        #+#    #+#                  #
#    Updated: 2020/05/22 16:43:39 by rbraaksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

global  _ft_strcpy

_ft_strcpy:                                 ;rdi = destination string, rsi = source string
                mov     rbx, 0              ;index
                cmp     rdi, 0              ;check first input string
                je      error
                cmp     rsi, 0              ;check second input string
                je      error
                jmp     copy
increment:
                inc     rbx
copy:
                mov     al, byte[rsi + rbx] ;put source char in register
                mov     byte[rdi + rbx], al ;put register in dest string
                cmp     al, 0               ;check delimiter
                je      return
                jmp     increment
error:
                mov     rax, 0              ;return null
                ret
return:
                mov     rax, rdi            ;move destination string to return value
                ret

_ft_strcpy:
	mov rcx, -1

copy:
	inc rcx
	mov al, BYTE [rsi + rcx]
	mov BYTE [rdi + rcx], al
	cmp al, 0
	je return
	jmp copy

return:
	mov rax, rdi
	ret