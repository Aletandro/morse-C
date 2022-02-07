#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LONGITUD_MENSAJE 500

char *codigosMorse[] = {
        ".-", "-...", "-.-.", "-..",
        ".", "..-.", "--.", "....", "..",
        ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...",
        "-", "..-", "...-", ".--", "-..-",
        "-.--", "--..", "-----", ".----", "..---",
        "...--", "....-", ".....", "-....", "--...",
        "---..", "----.", ".-.-.-", "--..--", "---...",
        "..--..", ".----.", "-....-", "-..-.", ".--.-.",
        "-...-", ".-..-.", "-.-.--",};

char *simbolosAscii[] = {"A", "B", "C", "D",
                         "E", "F", "G", "H", "I",
                         "J", "K", "L", "M", "N",
                         "O", "P", "Q", "R", "S",
                         "T", "U", "V", "W", "X",
                         "Y", "Z", "0", "1", "2",
                         "3", "4", "5", "6", "7",
                         "8", "9", ".", ",", ":",
                         "?", "'", "-", "/", "@",
                         "=", "\"", "!",};

const int NUMERO_CODIGOS = sizeof(codigosMorse) / sizeof(codigosMorse[0]);

int buscarIndiceDeMorse(char *codigo) {
    for (int x = 0; x < NUMERO_CODIGOS; x++) {
        if (strcmp(codigosMorse[x], codigo) == 0) {
            return x;
        }
    }
    return -1;
}

int buscarIndiceDeAscii(char signo) {
    // Convertir char a string
    char cadenaTemporal[2];
    cadenaTemporal[0] = signo;
    cadenaTemporal[1] = '\0';
    for (int x = 0; x < NUMERO_CODIGOS; x++) {
        if (strcmp(simbolosAscii[x], cadenaTemporal) == 0) {
            return x;
        }
    }
    return -1;
}

void demostrarCodificacionMorse() {
    char mensaje[LONGITUD_MENSAJE];
    printf("Palabra transformar a codigo MORSE: \n");
    fgets(mensaje, LONGITUD_MENSAJE, stdin);
    mensaje[strcspn(mensaje, "\r\n")] = 0;
    int i = 0;
    while (mensaje[i]) {
        char letraEnMayuscula = (char) toupper(mensaje[i]);
        int indice = buscarIndiceDeAscii(letraEnMayuscula);
        char *codigoMorse = codigosMorse[indice];
        printf("%s ", codigoMorse);
        i++;
    }
}

void demostrarDecodificacionMorse() {
    char mensaje[LONGITUD_MENSAJE];
    printf("Palabra Morse a decodificar:\n");
    fgets(mensaje, LONGITUD_MENSAJE, stdin);
    mensaje[strcspn(mensaje, "\r\n")] = 0;
    char delimitador[] = " ";
    char *token = strtok(mensaje, delimitador);
    if (token != NULL) {
        while (token != NULL) {
            int indice = buscarIndiceDeMorse(token);
            char *ascii = simbolosAscii[indice];
            printf("%s", ascii);
            token = strtok(NULL, delimitador);
        }
    }
}

int main() {
    demostrarCodificacionMorse();
    printf("\n");
    demostrarDecodificacionMorse();
    return 0;
}
