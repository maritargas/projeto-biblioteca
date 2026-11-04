#include <stdio.stdio.h> // Biblioteca padrão de entrada e saída (para usar printf e scanf)

int main() {
    float nota1, nota2, media;

    printf("=== Programa de Calculo de Media ===\n");
    
    // Solicitando as notas ao usuario
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    // Calculando a media
    media = (nota1 + nota2) / 2.0;

    // Exibindo o resultado
    printf("\nA media final do aluno e: %.2f\n", media);

    if (media >= 6.0) {
        printf("Status: Aprovado!\n");
    } else {
        printf("Status: Reprovado.\n");
    }

    return 0;
}