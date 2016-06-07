; Assembly Intel
  SECTION .text

  global scalarTimesMatrix_asm

scalarTimesMatrix_asm:
  push ebp
  mov ebp, esp

  mov ecx, [ebp+8]   ; L
  mov ebx, [ebp+12]  ; scalar
  mov esi, [ebp+16]  ; matrix 1st element (base)
  mov edi, [ebp+20]  ; outputMatrix 1st element

  xor eax, eax
  mov eax, ecx
  mul ecx
  mov ecx, eax ; ecx = L*L (size of the matrix)
  dec ecx      ; (L*L)-1   (Matrix's last element)

loop:
    ; counter ecx (L*L)-1 ~ 0
    mov eax, [esi+ecx*4]  ; iterating multiples of 4
    mul bx                ; scalar * ax
    mov [edi+ecx*4], eax  ; set the correspondent outputMatrix
    dec ecx
jns loop  ; loop L*L times - (do while)

  mov esp, ebp
  pop ebp
  ret
