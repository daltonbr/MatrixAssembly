/* Assembly AT&T */
   .text

  .global scalarTimesMatrix_s

scalarTimesMatrix_s:
  push %ebp
  mov %esp, %ebp

  mov 8(%ebp), %ecx  /* L */
  mov 12(%ebp), %ebx  /* scalar */
  mov 16(%ebp), %esi  /* matrix 1st element (base) */
  mov 20(%ebp), %edi  /* outputMatrix 1st element */

  xor %eax, %eax
  mov %ecx, %eax
  mul %ecx
  mov %eax, %ecx /* ecx = L*L (size of the matrix) */
  dec %ecx      /* (L*L)-1   (Matrix's last element) */

loop:
    /* counter ecx (L*L)-1 ~ 0 */
    mov (%esi,%ecx,0x4),%eax /* iterating multiples of 4 */
    mul %bx                     /* scalar * ax */
    mov (%edi,%ecx,0x4),%eax  /* set the correspondent outputMatrix */
    dec %ecx
jns loop  /* loop L*L times - (do while) */

  mov %ebp, %esp
  pop %ebp
  ret
