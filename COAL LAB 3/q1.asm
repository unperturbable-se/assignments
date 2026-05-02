include Irvine32.inc
.data
output dword 25
string byte "The output is:",0
.code
main proc
mov edx, OFFSET string
call writestring
mov eax,output
call writeint
ret
main endp

end main

