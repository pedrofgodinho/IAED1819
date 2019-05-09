/*******************************************************************************
* Projeto 2 IAED1819: main.c                                                   *
* Neste projeto tenciona-se criar um sistema de gestao de contactos, com o     *
* qual se interage atraves de comandos.                                        *
*                                                                              *
*                                                 Pedro Godinho - 93608 - LETI *
********************************************************************************
* Este ficheiro contem as funcoes main() e main_loop(), responsaveis pelo      *
* inicio do programa, bem como pelo loop principal, no qual o utilizador       *
* inseres os comandos a usar.                                                  *
*                                                                              *
*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "contact_manager.h"
#include "contact_list.h"





#include "domain_table.h"

void print_table(DomainHashTable *ht) {
    int i;
    Item *current;
    for (i = 0; i < DT_SIZE; i++) {
        if (*(ht->items + i))
            printf("Hash: %d | ", i);
        for (current = *(ht->items + i); current; current = current->next_collision) {
            printf("%s: %d ", current->domain, current->num);
        }
        if (*(ht->items + i))
            printf("\n");
    }
}

/*******************************************************************************
* Funcao responsavel pelo loop principal do programa. A cada iteracao, a       *
* funcao respetiva ao comando dado e chamada.                                  *
*******************************************************************************/
void main_loop() {    
    char command;
    DomainHashTable *domain_hash_table = make_domain_hash_table();
    HashedContactList *hashed_contact_list = make_contact_list();

    /* Loop principal do programa, em que se recebe cada comando */
    while ((command = getchar()) != 'x' && command != EOF) {
        /* remover ' ' ou o fim de linha do buffer, dependendo do commando */
        getchar();
        switch (command) {
            case 'a':
                command_add_contact(hashed_contact_list, domain_hash_table);
                break;
            case 'l':
                command_print_contact_list(hashed_contact_list);
                break;
            case 'p':
                command_find_contact(hashed_contact_list);
                break;
            case 'r':
                command_remove_contact(hashed_contact_list, domain_hash_table);
                break;
            case 'e':
                command_change_email(hashed_contact_list, domain_hash_table);
                break;
            case 'c':
                command_count_email_domain(domain_hash_table);
                break;
            case 'b':
                print_hash_table(hashed_contact_list);
                break;
            case 'd':
                print_table(domain_hash_table);
        }
    }

    /* libertar a memoria no fim */
    destroy_contact_list(hashed_contact_list);
    destroy_domain_hash_table(domain_hash_table);
}

/*******************************************************************************
* Ponto de entrada no programa.                                                *
*******************************************************************************/
int main() {
    main_loop();
    return 0;
}
