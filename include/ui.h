
#ifndef UI_H
#define UI_H

/* ========================================================================== */
/*                      CÓDIGOS DE CORES E ESTILOS ANSI                       */
/* ========================================================================== */

#define COLOR_RESET "\033[0m"
#define COLOR_BOLD "\033[1m" // Ênfase em nomes dos jogos, IDs em listas tabulares ou na opção selecionada

/* Cores de Texto (Padrão) */
#define COLOR_RED "\033[31m"     // Erros críticos, alertas negativos e ações destrutivas
#define COLOR_GREEN "\033[32m"   // Sucesso em operações e status concluídos
#define COLOR_YELLOW "\033[33m"  // Avisos/Warnings, edições e confirmações
#define COLOR_BLUE "\033[34m"    // Título de seções, cabeçalhos de menus, bordas e metadados informativos.
#define COLOR_MAGENTA "\033[35m" // Destaques especiais, como promoções, conquistas ou eventos importantes
#define COLOR_CYAN "\033[36m"    // Informações de status, dicas e instruções de uso

/* Cores de Alta Intensidade / Neutras */
#define COLOR_GRAY "\033[90m" // Informações neutras, mensagens de log e detalhes de depuração

/* ========================================================================== */
/*                      PROTÓTIPOS DO MÓDULO DE UI                            */
/* ========================================================================== */

void ui_title(const char *title);

void ui_error(const char *msg);

void ui_success(const char *msg);

int ui_show_menu(void);

int ui_show_sort_menu(void);

#endif /* UI_H */
