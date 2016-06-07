; Assembly Intel
  SECTION .bss
    L resb 4
    firstM resb 4
    secondM resb 4
    outputM resb 4
    accumulator resb 4
    temp resb 4

  SECTION .text

  global matrixTimesMatrix_asm

matrixTimesMatrix_asm:
  push ebp
  mov ebp, esp

  mov esi, [ebp+12]  ; firstMatrix 1st element (base)
  mov [firstM], esi
  mov esi, [ebp+16]  ; secondMatrix 1st element (base)
  mov [secondM], esi
  mov esi, [ebp+20]  ; outputMatrix 1st element
  mov [outputM], esi

  mov eax, [ebp+8]
  mov [L], eax
  mov ebx, [L]
  dec ebx           ; L-1 (i counter)
  mov ecx, ebx      ; L-1 (j counter)
  mov esi, ebx      ; L-1 (k counter)

loop_i:
    loop_j:
        mov [accumulator], 0
        loop_k:

            mov eax, [L]  ; firstM
            mul ebx
            add esi
            mul 4    ; 4 bytes per int
            add [firstM]
            mov ebx, eax

            mov eax, [L]
            mul esi
            add ecx
            mul 4
            add [secondM]  ; eax == second Element

            mul ebx ; eax has elem mult

            mov [accumulator], eax


            mov [outputM]
            ;mov ax, [firstM(ebx*L)+esi]
            ;mul [secondM(esi*L)+ecx]
            ;mov [outputM(ebx*L)+ecx], eax

            ;outputMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            ;(i*L)+j

            dec esi
        jns loop_k
        dec ecx   ; loop_j counter
    jns loop_j ; loop L times
    dec ebx   ; loop_i counter
jns loop_i    ; loop L times

end:
  mov esp, ebp
  pop ebp
  ret
