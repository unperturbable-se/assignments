include irvine32.inc
.data
str0 byte "###FAST",0
.code
strtrim proc ;takes al,ed\si,ecx
cld
mov edi,esi
repe scasb
dec edi
xchg esi,edi
rep movsb
movsb
ret
strtrim endp

main proc
lea esi,str0
mov al,'#'
mov ecx,lengthof str0
call strtrim
lea edx,str0
call writestring
exit
main endp
end main