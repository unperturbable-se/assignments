include Irvine32.inc
.data
a dword 10
b dword 20
string byte "a+b is:",0
.code
main proc
mov edx, OFFSET string
call writestring
mov eax,a
add eax,b
call writeint
ret
main endp

end main

