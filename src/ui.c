
#include <stdio.h>
#include "ui.h"

void ui_title (const char *title){

    if (title == NULL)
    {
        ui_error("Titulo nao fornecido.");
        return;
    }
    
    printf("%s %s %s\n", COLOR_BOLD, title, COLOR_RESET);

}

void ui_error (const char *msg){
    
    if (msg == NULL)
    {
        printf("%sERRO:%s Ocorreu um erro desconhecido (mensagem nula).\n", COLOR_RED, COLOR_RESET);
        
        return;
    }
    
    printf("%sERRO:%s %s\n", COLOR_RED, COLOR_RESET, msg);
}

void ui_success (const char *msg){

    if (msg == NULL)
    {
        printf("%sSucesso:%s Operacao concluida com sucesso.\n", COLOR_GREEN, COLOR_RESET);
        
        return;
    }

    printf("%sSucesso:%s %s\n", COLOR_GREEN, COLOR_RESET, msg);

}
