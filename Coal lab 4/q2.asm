include irvine32.inc
.data
arr byte 1,0,3,3,4
.code
main proc
mov ecx,0
mov ebx,offset arr
mov eax,0
loop1:
add al,[ebx]
inc ebx
inc ecx
cmp ecx,4
jle loop1
call writeint
exit
main endp
end main