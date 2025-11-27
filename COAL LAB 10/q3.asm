include irvine32.inc
.data

.code
Factorial proc ;takes eax, returns ebx
enter 0,0
mov eax,[ebp+8]
cmp eax,1
jle return
recurse:
        dec eax
        push eax
        call factorial
        pop eax
        inc eax
        mov edx,0
        mul ebx
        mov ebx,eax
        leave
        ret
return: 
        mov ebx,1
        leave
        ret
Factorial endp


main proc
     call readdec
     push eax
     call Factorial
     pop eax
     call crlf
     mov eax,ebx
     call writedec
exit
main endp

end main