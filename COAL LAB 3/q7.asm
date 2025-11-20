include Irvine32.inc
.data
 array dword 5,10,15,20,25
 string byte "The sum of all elements is:"
.code
main proc
mov eax,array[0]
add eax,array[1]
add eax,array[2]
add eax,array[3]
add eax,array[4]

mov edx,offset string
call writestring
call writeint
main endp
end main