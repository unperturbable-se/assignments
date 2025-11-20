include Irvine32.inc
.data
m sbyte 4
n sbyte 3
p sbyte 2
q sbyte 5
string byte "(m-n)+(p+q)-(m-q)="
.code
main proc
mov eax,0
add al,m
sub al,n
add al,p
add al,q
sub al,m
add al,q
call writeint
main endp
end main