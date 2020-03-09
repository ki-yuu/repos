/**
 * This Header is wrriten about list.
 */
#ifndef KY_H
#define KY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define EMPTY ""
#define KY_LIST_ELEMENTS 32
#define KY_NODE_ELEMENTS 128
#define BIT_REVERSE(a) (((((((((a)>>4) | ((a)<<4))&0xCC)>>2) | (((((a)>>4) | ((a)<<4))&0x33)<<2))&0xAA)>>1) | ((((((((a)>>4) | ((a)<<4))&0xCC)>>2) | (((((a)>>4) | ((a)<<4))&0x33)<<2))&0x55)<<1))

/**
 * linked_list is basic list in this header.
 */
struct linked_list
{
    char data[KY_LIST_ELEMENTS];
    struct linked_list *next_ptr;
};
typedef struct linked_list linked_list;

/**
 * node is basic node in this header.
 */
struct node {
    struct node *left;      /* Left node. */
    struct node *right;     /* Right node. */
    char *word;             /* The word for this note. */
};
typedef struct node node;

/**
 * extern linked_list *create_list();
 * This function create list.
 * When list is created, First this is called.
 * @param
 *  void
 * @return
 *  After List is created, pointer of the list is returned.
 *  If failed about create list, return NULL.
 */
extern linked_list *create_list();

/**
 * extern void add_list(linked_list *list, unsigned int a);
 * Add list by extern linked_list *create_list();.
 * @param
 *  linked_list *list: pointer of list by extern linked_list *create_list();.
 *  unsigned int a: Number of add in the list.
 * @return
 *  void
 */
extern void add_list(linked_list *list, unsigned int a);

/**
 * extern linked_list *insert_list(linked_list *list, size_t a, const char *ch);
 * This function insert anywhere in the list.
 * @param
 *  linked_list *list: pointer of list by extern linked_list *create_list();.
 *  size_t a: place that is inserted by this function.
 *  const char *ch: Value of Member in linked_list.
 * @return
 *  After call this function, return lead pointer of the list.
 *  If failed, return NULL.
 */
extern linked_list *insert_list(linked_list *list, size_t a, const char *ch);

/**
 * extern linked_list *list_position(linked_list *list, size_t a);
 * This function find pointer of specific number in the list.
 * @param
 *  linked_list *list: pointer of list by extern linked_list *create_list();.
 *  size_t a: Number of find in the list.
 * @return
 *  After call this function, return specific pointer of the list.
 *  If nothing in the list, return NULL.
 */
extern linked_list *list_position(linked_list *list, size_t a);

/**
 * extern linked_list *list_find_data(linked_list *list, const char *ch);
 * This function find data in the list.
 * @param
 *  linked_list *list: pointer of list by extern linked_list *create_list();.
 *  const char *ch: Characters to find in the list.
 * @return
 *  After call this function, return specific pointer of the list.
 * If nothing in the list, return NULL.
 */
extern linked_list *list_find_data(linked_list *list, const char *ch);

/**
 * extern void list_print(linked_list *list, size_t a, const char *ch);
 * This function print characters in the member of linked_list.
 * @param
 *  linked_list *list: pointer of list by extern linked_list *create_list();.
 *  size_t a: Place of the list.
 *  const char *ch: The character is printed in the list.
 * @return
 *  void
 */
extern void list_print(linked_list *list, size_t a, const char *ch);

/**
 * extern void ini_list(linked_list *list, linked_list *next_list_ptr, const char *ch);
 * This function initialize the list passed.
 * @param
 *  linked_list *list: pointer of list by extern linked_list *create_list();.
 *  linked_list *next_list_ptr: pointer of member in the list passed.
 *  const char *ch: Characters of member in the list passed.
 * @return
 *  void
 */
extern void ini_list(linked_list *list, linked_list *next_list_ptr, const char *ch);

/**
 * extern size_t list_length(linked_list *list);
 * This function count elements in the list.
 * @param
 *  linked_list *list: pointer of list by extern linked_list *create_list();.
 * @return
 *  The quantity of elements in the list.
 */
extern size_t list_length(linked_list *list);

/**
 * extern linked_list *list_delete(linked_list *list, size_t a);
 * This function delete an element in the list.
 * @param
 *  linked_list *list: pointer of list by extern linked_list *create_list();.
 *  size_t a: Place of the list.
 * @return
 *  Lead pointer of the list.
 */
extern linked_list *list_delete(linked_list *list, size_t a);

/**
 * extern void close_list(linked_list *list);
 * This funtion close the list.
 * After list created by extern linked_list *create_list();, this must be called.
 * This is not called, cause memory leak.
 * @param
 *  linked_list *list: pointer of list by extern linked_list *create_list();.
 * @return
 *  void
 */
extern void close_list(linked_list *list);

/**
 * extern void ky_fin(FILE *fp, linked_list *pl);
 * This function read specific file, store linked_list variable.
 * @param
 *  FILE *fp: read file
 *  linked_list *pl: stored list
 * @return
 *  void
 */
extern void ky_fin(FILE *fp, linked_list *pl);

/**
 * extern void ky_fout(FILE *fp, linked_list *pl);
 * This function write in the list to specific file.
 * @param
 *  FILE *fp: written file
 *  linked_list *pl: contents
 * @return
 *  void
 */
extern void ky_fout(FILE *fp, linked_list *pl);

/**
 * extern void ky_qsort(linked_list *pl, size_t numOfElements);
 * This function do quick sort in the list.
 * @param
 *  linked_list *pl: done list
 *  size_t numOfElements: number of elements in the list. usually list_length(pl);
 * @return
 *  void
 */
extern void ky_qsort(linked_list *pl, size_t numOfElements);

/**
 * extern void ky_exchange(linked_list *pla, linked_list *plb);
 * This function exchange list and list.
 * @param
 *  linked_list *pla: exchanged list
 *  linked_list *plb: exchanged list
 * @return
 * void
 */
extern void ky_exchange(linked_list *pla, linked_list *plb);

/**
 * extern size_t list_numInatob(linked_list* pla, linked_list *plb);
 * This function count number between pla to plb.
 * Including pla and plb.
 * @param
 *  linked_list *pla: start point
 *  linked_list *plb: finish point
 * @param
 *  number
 */
extern size_t list_numInatob(linked_list* pla, linked_list *plb);

/**
 * save_string -- Save the string to the heap.
 * 
 * @param
 *      string -- Save the string.
 * 
 * @return
 *      Memory pointer of the part to which malloc is applied.
 *      Memory of this part is cpied the string.
 */
extern char *__cdecl save_string(const char *string);

/**
 * enter -- Insert the word in tree.
 * 
 * @param
 *      node -- Current node of interest.
 *      word -- The word to insert.
 */
extern void __cdecl enter(node **ky_node, const char *word);

/**
 * scan -- Scan the word in the file.
 * 
 * @param
 *      name -- The file name to scan.
 */
extern void __cdecl scan(const char *name, node **root);

/**
 * print_tree -- Input the word in the tree.
 * 
 * @param
 *      top -- The root of the tree to output.
 */
extern void __cdecl print_tree(node *top);

/**
 * fprint_tree -- Input the word in the tree to the file.
 * 
 * @param
 *      fp -- file to be written.
 *      top -- The root of the tree to output.
 */
extern void __cdecl fprint_tree(FILE *fp, node *top);

/**
 * extern void __cdecl nclose(node *top);
 * This function close the node.
 * @param
 *  node *top: pointer of closed node
 * @return
 *  void
 */
extern void __cdecl nclose(node *top);

/**
 * extern void __cdecl copy_to_list(linked_list *lp, node *root);
 * This function copy the node to the list.
 * @param
 * linked_list *lp: reciver
 * node *root: The node to be copied
 * @return
 *  void
 */
extern void __cdecl copy_to_list(linked_list *lp, node *root);

#endif //KY_H