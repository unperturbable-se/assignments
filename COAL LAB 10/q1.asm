include irvine32.inc
.data
str1 byte "enter the first number:",0
str2 byte "enter the second number:",0
.code
;----------------------------------------------
computesum proc
lea edx,str1
call writestring
call readdec
call crlf
mov ebx,eax

lea edx,str2
call writestring
call readdec
call crlf
add eax,ebx
ret
computesum endp
;----------------------------------------------
main proc
invoke computesum
call writedec
ret
main endp
;----------------------------------------------

end main