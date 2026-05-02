    include Irvine32.inc
    .data
    array db 5 dup(5)
    string1 byte "Every element has the value of 5",0
    string2 byte "for example, the [3]rd element has value of:",0

    .code
    main proc
    mov edx, offset string1
    call writestring
    call crlf
    mov edx, offset string2
    call writestring

    mov eax,0
    mov al,array[3]
    call writeint

    main endp
    end main
