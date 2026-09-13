 
#ifndef UI_H
#define UI_H

#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m" // Erros críticos e alertas negativos
#define COLOR_GREEN "\033[32m" // Sucesso em operações e status concluídos
#define COLOR_YELLOW "\033[33m" // Avisos/Warnings e nota de avalisação médias
#define COLOR_BLUE "\033[34m" // Título de seções, cabeçalhos de menus, bordas e metadados informativos.
#define COLOR_BOLD "\033[1m" // Ênfase em nomes dos jogos, IDs em listas tabulares ou na opção selecionada

void ui_title (const char *title);

void ui_error (const char *msg);

void ui_success (const char *msg);

#endif // UI_H
