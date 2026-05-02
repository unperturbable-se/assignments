include irvine32.inc
.data
str1 byte "ASSEMBLY",0
str2 byte "found at:",0
str3 byte "not found",0
.code
;-------------------------------
searchstring proc 
mov al,'E'
mov ecx,lengthof str1
lea edi,str1
repne scasb 
jnz notfound
mov eax,(lengthof str1)-1
sub eax,ecx
ret
notfound:mov eax,-1
ret
searchstring endp
;--------------------------------
main proc
call searchstring
cmp eax,-1
jz notfound
lea edx,str2
call writestring
call writedec
exit
notfound:
lea edx,str3
call writestring
exit
main endp
end main