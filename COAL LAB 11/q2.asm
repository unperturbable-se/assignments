include irvine32.inc
.data
str1 byte "PROGRAMMING",0
str2 byte "CHARACTER ",0
str3 byte " OCCURED ",0
str4 byte " TIMES",0
.code
;----------------------------------
findoccurences proc ; takes al
mov ebx,0
lea edi,str1
mov ecx,lengthof str1
l1:
   repne scasb
   jnz return
   inc ebx
   jmp l1
return:
       lea edx,str2
       call writestring
       call writechar
       lea edx,str3
       call writestring
       mov eax,ebx
       call writedec
       lea edx,str4
       call writestring
       ret
findoccurences endp
;----------------------------------
main proc
mov al,'G'
call findoccurences
exit
main endp
;----------------------------------
end main