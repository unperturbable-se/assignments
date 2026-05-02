include irvine32.inc
.data
arr dword 1,2,3
    dword 4,5,6
    dword 7,8,9
lenArr equ ($-arr)/4
str1 byte "The Sum is:",0
.code
;--------------------------
main proc
cld
mov ebx,0
mov ecx,lenArr
lea esi,arr
l1:
   lodsd
   add ebx,eax
   loop l1
mov eax,ebx
lea edx,str1
call writestring
call writedec
main endp
;--------------------------
end main