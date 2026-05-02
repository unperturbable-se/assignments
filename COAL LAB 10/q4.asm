include Irvine32.inc

.data
intArray DWORD 90, 10, 50, 20, 70, 40, 60, 30, 80
arraySize EQU ($ - intArray) / TYPE DWORD
msgBefore BYTE "Array before sorting:", 0
msgAfter BYTE "Array after sorting:", 0
spaceChar BYTE " ", 0

.code

DisplayArray PROC
    pushad
    
    mov ebx, ecx
    mov ecx, arraySize

L1:
    mov eax, [esi]
    call WriteDec
    lea edx, spaceChar
    call WriteString
    add esi, TYPE DWORD
    loop L1

    call Crlf
    popad
    ret
DisplayArray ENDP

BubbleSort PROC
    enter 0, 0
    
    mov esi, OFFSET intArray
    mov ecx, arraySize

L1:
    push ecx
    mov ecx, arraySize
    dec ecx
    mov ebx, 0

L2:
    mov eax, [esi]
    cmp eax, [esi+4]
    jle L3
    
    mov edx, [esi+4]
    mov [esi], edx
    mov [esi+4], eax
    mov ebx, 1

L3:
    add esi, 4
    loop L2
    
    mov esi, OFFSET intArray
    
    cmp ebx, 0
    je L4
    
    pop ecx
    loop L1

L4:
    leave
    ret
BubbleSort ENDP

main PROC
    lea edx, msgBefore
    call WriteString
    mov esi, OFFSET intArray
    mov ecx, arraySize
    call DisplayArray
    
    call BubbleSort
    
    lea edx, msgAfter
    call WriteString
    mov esi, OFFSET intArray
    mov ecx, arraySize
    call DisplayArray
    
    exit
main ENDP

end main