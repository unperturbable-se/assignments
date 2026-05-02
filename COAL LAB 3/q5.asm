include Irvine32.inc
.data
array db 5 dup(0)

.code
main proc
mov byte ptr [array],1
mov byte ptr [array+1],2
mov byte ptr [array+2],3
mov byte ptr [array+3],4
mov byte ptr [array+4],5

mov eax,0
mov al,array[0]
call writeint 
call crlf
mov eax,0
mov al,array[1]
call writeint
call crlf
mov eax,0
mov al,array[2]
call writeint 
call crlf
mov eax,0
mov al,array[3]
call writeint 
call crlf
mov eax,0
mov al,array[4]
call writeint 
call crlf

main endp
end main
