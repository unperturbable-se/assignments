include Irvine32.inc
.data
.code
;-------------------------------------------------------
addfour proc
push ebp
mov ebp,esp
mov eax,[ebp+8]; esp+4 stores the function address
mov ebx,[ebp+12]
add eax,ebx

mov ebx,[ebp+16]
add eax,ebx

mov ebx,[ebp+20]
add eax,ebx

pop ebp
ret 
addfour endp
;-------------------------------------------------------
addressebp proc
push ebp
mov ebp,esp
lea eax,[ebp+8] ;address of ebp+8
call writeint
call crlf
mov eax,[ebp+8] ;value of ebp+8
call writeint
call crlf
pop ebp
ret
addressebp endp
;-------------------------------------------------------
main proc
push 7
push 6
push 5
push 4

call addfour
add esp,12
call writeint
call crlf
call addressebp
add esp,4
exit
main endp
;-------------------------------------------------------
end main