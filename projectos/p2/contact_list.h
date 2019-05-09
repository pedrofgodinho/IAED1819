/*******************************************************************************
* Projeto 2 IAED1819: contact_list.h                                           *
* Neste projeto tenciona-se criar um sistema de gestao de contactos, com o     *
* qual se interage atraves de comandos.                                        *
*                                                                              *
*                                                 Pedro Godinho - 93608 - LETI *
********************************************************************************
* Este ficheiro contem as estruturas necessarias a implementacao de uma lista  *
* duplamente ligada, bem como a declaracao das funcoes que gerem essas listas  *
* e respetivas documentacoes.                                                  *
*******************************************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define CL_SIZE 1009 /* size da contactlist hashtable - primo proximo de 1000 */


/*******************************************************************************
* Estrutura Contact:                                                           *
* Esta estrutura representa cada contacto na lista, tendo tres vetores de      *
* caracteres para representar o nome, email, e telefone de cada contacto.      *
*******************************************************************************/
typedef struct {
    char *name, *email, *tel;
} Contact;


/*******************************************************************************
* Estrutura Node:                                                              *
* Esta estrutura representa um elo na lista duplamente ligada, tendo um        *
* ponteiro para o elemento seguinte e para o elemento anterior, bem como um    *
* contacto (o valor de cada elo).                                              *
*******************************************************************************/
typedef struct struct_node {
    struct struct_node *next, *previous, *next_collision;
    Contact c;
} Node;


/*******************************************************************************
* Estrutura ContactList:                                                       *
* Esta estrutura representa a lista duplamente ligada, tendo ponteiros para o  *
* primeiro e ultimo elementos da lista.                                        *
*******************************************************************************/
typedef struct {
    struct struct_node *head, *tail, **hashtable;
} HashedContactList;


/*******************************************************************************
* Funcao que, dado um contacto, o escreve para o stdout (nome email telefone). *
*                                                                              *
********************************************************************************
* Args:                                                                        *
*     Contact c: o contacto a escrever                                         *
*******************************************************************************/
void print_contact(Contact c);


/*******************************************************************************
* Funcao que gera uma lista de contactos duplamente ligada vazia.              *
*                                                                              *
********************************************************************************
* Returns:                                                                     *
*     ContactList*: a lista vazia criada                                       *
*******************************************************************************/
HashedContactList *make_contact_list();


/*******************************************************************************
* Funcao que liberta toda a memoria relacionada com um Node.                   *
*                                                                              *
********************************************************************************
* Args:                                                                        *
*     Node *node: ponteiro para o node a destruir                              *
*******************************************************************************/
void destroy_node(Node *node);


/*******************************************************************************
* Funcao que liberta toda a memoria relacionada com uma lista de contactos.    *
*                                                                              *
********************************************************************************
* Args:                                                                        *
*     ContactList *cl: o ponteiro para a lista a destruir                      *
*******************************************************************************/
void destroy_contact_list(HashedContactList *cl);


/*******************************************************************************
* Funcao que adiciona um contacto ao fim de uma lista de contactos.            *
*                                                                              *
********************************************************************************
* Args:                                                                        *
*     ContactList *cl: a lista a qual adicionar o contacto                     *
*     Contact c: o contacto a adicionar                                        *
*******************************************************************************/
void append_to_contact_list(HashedContactList *cl, Contact c);

/* TODO */
void remove_node_from_list(HashedContactList *cl, char *name);


/*******************************************************************************
* Funcao que encontra um contacto atraves do seu nome.                         *
*                                                                              *
********************************************************************************
* Args:                                                                        *
*     ContactList *cl: a lista na qual procurar o contacto                     *
*     char *name: o nome pelo qual procurar                                    *
*                                                                              *
* Returns:                                                                     *
*     Contact*: um ponteiro para o contacto encontrado (ou NULL se nao         *
*               existir                                                        *
*******************************************************************************/
Node *get_node_by_name(HashedContactList *cl, char *name);

void print_hash_table(HashedContactList *cl);

#endif