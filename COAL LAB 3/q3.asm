include Irvine32.inc
.data
x sdword 50
y sdword 15
string byte "y-x is:",0
.code
main proc
mov edx, OFFSET string
call writestring
mov eax,y
sub eax,x
call writeint
ret
main endp

end main

