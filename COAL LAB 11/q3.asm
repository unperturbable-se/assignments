include irvine32.inc
.data
str1 byte "ASSEMBLY",0
.code
;-------------------------------
reverse proc
mov eax,0

lea esi,str1
l1:
   lodsb
   push eax
   cmp byte ptr [esi],0
   jnz l1

lea edi,str1
l2:
   pop eax
   stosb
   cmp byte ptr [edi],0
   jnz l2
ret
reverse endp
;--------------------------------

main proc
call reverse
lea edx,str1
call writestring
exit
main endp
end main