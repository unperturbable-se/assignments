include irvine32.inc
.data
array byte 1,4,2,5,3,5,3,5,3,5,4,5,5,5,5,5,0
str0 byte "5 fives found",0
.code
;-----------------------------
findfive proc ;uses ecx,esi
l1:
   push ecx
   mov ecx,5
   mov edi,esi
   mov al,5
   repe scasb
   jz found
   pop ecx
   inc esi
   loop l1
   ret
found:
      pop ecx
      lea edx,str0
      call writestring
      ret
findfive endp
;----------------------------

main proc
lea esi,array
mov ecx,lengthof array
call findfive
exit
main endp
end main