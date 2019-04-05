/*Author: Rinn Joireman
File Name: symboltable.c
*/
#include <stdio.h>
#include "symboltable.h"
#include <string.h>
#include <stdlib.h>

typedef struct symbolEntry{
  char* symbol;
  int address;
} symbolEntry;

typedef struct node{
  symbolEntry data;
  struct node *next;
} node;

//Contains the address of a node
typedef node* nodePtr;

//this creates the table variable
static nodePtr symbolTable;

nodePtr getNode(symbolEntry data, nodePtr next){
  nodePtr ptr = malloc(sizeof(node));
  ptr->data = data;
  ptr->next = next;
  return ptr;
}

void initSymbolTable(){
  symbolTable = NULL;
}

// Looks up the symbol in the table.
// If the symbol is in the table, returns its address.
// Otherwise, returns -1.
int findSymbol(char* symbol){
  //nodePtr probe = symbolTable;
  nodePtr item = symbolTable;
  while(item != NULL){
    if(strcmp(item->data.symbol, symbol) == 0){
      return item->data.address;
    }
    item = item->next;
  }
  return (-1);
}


// Attempts to enter a symbol and its address.
// If the symbol is already in the table, simply returns NULL.
// Otherwise, enters the symbol and its address and returns the symbol.
char* enterSymbol(char* symbol, int address){
  symbolEntry se;
  se.symbol = symbol;
  se.address = address;
  int i = findSymbol(symbol);
  if(i == -1){
    //prepends the symbol table with the new node and returns the symbol
    symbolTable = getNode(se, symbolTable);
    return symbol;
  }
  else{
    return NULL;
  }
}

// Prints the contents of the table in two columns.
void printSymbolTable(){
  nodePtr n = symbolTable;
  while(n != NULL){
    printf("%s\t%d\n", n->data.symbol, n->data.address);
    n = n->next;
  }
}
