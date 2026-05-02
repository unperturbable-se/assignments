include irvine32.inc
.data
str1 byte "Enter the number:",0
str2 byte "the number is prime",0
str3 byte "the number is not prime",0
.code
;-------------------------------------
checkprime proc
Enter 0,0

mov eax,[ebp+4]
mov ebx,eax
shr ebx,2
mov ecx,2


loop1:
      push eax
      xor edx,edx
      div ecx
      pop eax
      cmp edx,0
      jz isComposite
      inc ecx
      cmp ecx,ebx
      jnz loop1
      jmp isPrime

isComposite:
      leave
      stc
      ret

isPrime:
      leave
      clc ;is prime
      ret
checkprime endp
;-------------------------------------
main proc
lea edx,str1
call writestring
call readdec
call crlf
push eax    
call checkPrime
add esp,4
jnc prime
lea edx,str3
jmp endmain
prime: lea edx,str2
endmain:
call writestring
ret
main endp 
end main
;--------------------------------------
