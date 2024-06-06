#include <iostream>

using namespace std;

void evaluate_f1(int x) {
    int result;

    __asm {
        mov eax, x
        cmp eax, -4
        jl less_than_neg4
        je equal_neg4
        cmp eax, -4
        jg greater_than_neg4

        less_than_neg4:
            sub eax, 8
            cdq
            jmp end_asm

        equal_neg4:
            mov eax, 9
            jmp end_asm

        greater_than_neg4:
            imul eax, eax
            add eax, 3

        end_asm:
            mov result, eax
    }

    cout << "The value of the function f1 at x = " << x << " is: f1(" << x << ") = " << result << endl;
}

void evaluate_f2(int x) {
    int result = 0;

    __asm {
        mov ecx, x
        mov eax, 0
        mov ebx, 1

        loop_start:
            add eax, ebx
            inc ebx
            loop loop_start

        mov result, eax
    }

    cout << "The value of the function f2 at x = " << x << " is: f2(" << x << ") = " << result << endl;
}

int main() {
    int x = 8;

    evaluate_f1(x);
    evaluate_f2(x);

    return 0;
}
