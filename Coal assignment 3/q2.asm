include irvine32.inc
.data
a1 byte 0
e1 byte 0
i1 byte 0
o1 byte 0
u1 byte 0
str1 byte "a or A is:",0
str2 byte "e or E is:",0
str3 byte "i or I is:",0
str4 byte "o or O is:",0
str5 byte "u or U is:",0

str0 byte "Advanced Programming in UNIX Environment",0
.code
;----------------------------------------------------------------
countVowel proc ;takes al
cmp al,'a'
jz aa
cmp al,'A'
jz aa

cmp al,'e'
jz ee
cmp al,'E'
jz ee

cmp al,'i'
jz ii
cmp al,'I'
jz ii

cmp al,'o'
jz oo
cmp al,'O'
jz oo

cmp al,'u'
jz uu
cmp al,'U'
jz uu
jmp return

aa:
inc a1
jmp return

ee:
inc e1
jmp return

ii:
inc i1
jmp return

oo:
inc o1
jmp return

uu:
inc u1
return: ret
countVowel endp
;-------------------------------------------------
writeline proc
call writestring
call writedec
call crlf
ret
writeline endp
;-------------------------------------------------
main proc
lea esi,str0
mov ecx,lengthof str0
l1:
   lodsb
   call countVowel
   loop l1

lea edx,str1
movzx eax,a1
call writeline

lea edx,str2
movzx eax,e1
call writeline

lea edx,str3
movzx eax,i1
call writeline

lea edx,str4
movzx eax,o1
call writeline

lea edx,str5
movzx eax,u1
call writeline

exit
main endp
end main
