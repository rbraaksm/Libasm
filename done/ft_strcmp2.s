# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    ft_strcmp2.s                                       :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <abobas@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/04/30 15:00:24 by abobas        #+#    #+#                  #
#    Updated: 2020/05/22 17:04:09 by rbraaksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

global  _ft_strcmp

_ft_strcmp:
                cmp     rdi, 0                      ;check first string
                je      error_s1
                cmp     rsi, 0                      ;check second string
                je      error_s2
                jmp     compare
increment:
                inc     rdi
                inc     rsi
compare:
                mov     cl, byte[rdi]
                mov     dl, byte[rsi]
                movzx   rcx, cl
                movzx   rdx, dl
                cmp     rcx, 0                       ;check delimiter
                je      return
                cmp     rdx, 0                       ;check delimiter
                je      return
                cmp     rcx, rdx                    ;cmp different chars from 2 strings
                je      increment

return:
                sub     rcx, rdx
                mov     rax, rcx
                ret
negative:
                sub     rdx, rcx
                mov     rax, rcx
                imul    rax, -1                     ;return negative value
                ret
error_s1:
                cmp     rsi, 0                      ;check if both strings are null
                je      error
                mov     dl, byte[rsi]
                mov     cl, 0
                jmp     return
error_s2:
                mov     cl, byte[rdi]
                mov     dl, 0
                jmp     return
error:
                mov     rax, 0                      ;return null
                ret



_ft_strcmp:
	mov 		al, byte [rdi]
	mov 		bl, byte [rsi]
	cmp 		al, 0
	je 			end
	cmp 		bl, 0
	je 			end
	cmp 		al, bl
	jg 			greater
	jl 			less
	inc			rdi
	inc 		rsi
	jmp 		_ft_strcmp

greater:
	mov 		rax, 1
	jmp 		exit

less:
	mov 		rax, -1
	jmp 		exit

end:
	sub 		al, bl
	js 			less
	jnz 		greater
	mov 		rax, 0

exit:
	ret