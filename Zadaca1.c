#include <stdio.h>

struct element {
    int broj;
    char karakter;
    struct element* sleden;
};

void pecatiListaNanazad(struct element* lista) {
    if (lista == NULL) {
        return;
    }
    pecatiListaNanazad(lista->sleden);
    printf("%c%d ", lista->karakter, lista->broj);
}

int main() {
    // Пример листа со 3 елементи
    struct element element3 = { 3, 'C', NULL };
    struct element element2 = { 7, 'B', &element3 };
    struct element element1 = { 5, 'A', &element2 };
    struct element* lista = &element1;

    pecatiListaNanazad(lista); // ги печати елементите на листата наназад: C3 B7 A5

    return 0;
}
