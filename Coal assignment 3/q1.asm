include irvine32.inc
.data
.code
recursiveDivide proc;takes eax returns eax
cmp eax,5h ;base case
mov ebx,0Ah
jle return
mov edx,0
div ebx
call recursiveDivide
return:ret
recursiveDivide endp

main proc
mov eax,0D4A4h
call recursiveDivide
call writehex
exit
main endp
end main