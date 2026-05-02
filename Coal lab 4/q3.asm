include Irvine32.inc
.data
arr byte 10,20,30,40
.code
main proc
mov ebx, offset arr
add ebx,3
mov al,[ebx]

mov ah,[ebx-1]
mov [ebx],ah

mov ah,[ebx-2]
mov [ebx-1],ah

mov ah,[ebx-3]
mov [ebx-2],ah

mov [ebx-3],al

mov ebx,offset arr
mov ecx,4
mov eax,0
printLoop:
mov al,[ebx]
call writeint
call crlf
inc ebx
loop printLoop

exit
main endp
end main