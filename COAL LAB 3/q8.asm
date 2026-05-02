include Irvine32.inc
.data
a sdword 3
b sdword 4
c1 sdword 2
string byte "a+b-c=",0
.code
main proc
mov eax,a
add eax,b
sub eax,c1
mov edx, offset string
call writestring
call writeint

main endp
end main
