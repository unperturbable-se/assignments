include Irvine32.inc
.data
x sbyte 4
y sbyte 3
z sbyte 2
w sbyte 5
string byte "(x+y)+(z+w)-(y+z)="
.code
main proc
mov eax,0
add al,x
add al,y
add al,z
add al,w
sub al,y
sub al,z
call writeint
main endp
end main


