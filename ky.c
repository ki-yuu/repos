#include "ky.h"

void list_memory_error(linked_list *list, const char *ch)
{
    printf("FAILED: Could not allocate memory.\n");
    printf("REMARKS: This failure was caused by the function %s.\n", ch);
}

linked_list *create_list()
{
    linked_list *new_item_ptr;
    new_item_ptr = malloc(sizeof(linked_list));
    ini_list(new_item_ptr, NULL, EMPTY);
    return new_item_ptr;
}

void add_list(linked_list *list, unsigned int a)
{
    size_t n = list_length(list) - 1;
    linked_list *tmp = (linked_list *)malloc(sizeof(linked_list) * a);
    if (tmp == NULL)
    {
        list_memory_error(list, "void add_list(linked_list *list, unsigned int a);");
        return;
    }
    linked_list *first_ptr = list;
    for (int i = 0; i < a; ++i)
    {
        if (i < (a - 1))
        {
            ini_list(&(tmp[i]), &(tmp[i + 1]), EMPTY);
        }
        else
        {
            ini_list(&(tmp[i]), NULL, EMPTY);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        first_ptr = first_ptr->next_ptr;
    }
    first_ptr->next_ptr = &(tmp[0]);
}

linked_list *insert_list(linked_list *list, size_t a, const char *ch)
{
    size_t len = list_length(list);
    if (a == 0)
    {
        linked_list *tmp = create_list();
        if (tmp == NULL)
        {
            list_memory_error(list, "linked_list *insert_list(linked_list *list, size_t a, const char *ch);");
            return list;
        }
        ini_list(tmp, list, ch);
        return tmp;
    }
    else if((a > 0) && (a < len))
    {
        size_t i;
        linked_list *tmp = create_list();
        if (tmp == NULL)
        {
            list_memory_error(list, "linked_list *insert_list(linked_list *list, size_t a, const char *ch);");
            return list;
        }
        linked_list *before_ptr = list;
        linked_list *after_ptr = NULL;
        for (i = 0; i < (a - 1); ++i)
        {
            before_ptr = before_ptr->next_ptr;
        }
        after_ptr = before_ptr->next_ptr;
        before_ptr->next_ptr = tmp;
        ini_list(tmp, after_ptr, ch);
        return list;
    }
    else if(a == len)
    {
        size_t i;
        linked_list *tmp = create_list();
        if (tmp == NULL)
        {
            list_memory_error(list, "linked_list *insert_list(linked_list *list, size_t a, const char *ch);");
            return list;
        }
        linked_list *first_ptr = list;
        for (i = 0; i < (len - 1); ++i)
        {
            first_ptr = first_ptr->next_ptr;
        }
        first_ptr->next_ptr = tmp;
        ini_list(tmp, NULL, ch);
        return list;
    }
    else
    {
        printf("FAILED: Could not insert into the list.\n");
        printf("REMARKS: Number of list is %d now, but value of the argument passed is %d.\n", len, a);
        printf("         linked_list *insert_list(linked_list *list, size_t a, const char *ch);\n");
        printf("                                                            ^                  \n");
        return list;
    }
}

linked_list *list_position(linked_list *list, size_t a)
{
    size_t len = list_length(list);
    if (a < len)
    {
        size_t i;
        linked_list *tmp = list;
        for (i = 0; i < a; ++i)
        {
            tmp = tmp->next_ptr;
        }
        return tmp;
    }
    else
    {
        printf("FAILED: Could not find in the list.\n");
        printf("REMARKS: Number of list is %d now, but value of the argument passed is %d.\n", len, a);
        printf("         linked_list *list_position(linked_list *list, size_t a);\n");
        printf("                                                              ^  \n");
        return NULL;
    }
}

linked_list *list_find_data(linked_list *list, const char *ch)
{
    size_t i;
    size_t len = list_length(list);
    linked_list *tmp = list;
    if (strcmp(tmp->data, ch) == 0)  return tmp;
    for (i = 0; i < (len - 1); ++i)
    {
        tmp = tmp->next_ptr;
        if (strcmp(tmp->data, ch) == 0)  return tmp;
    }
    return NULL;
}

void list_print(linked_list *list, size_t a, const char *ch)
{
    size_t i, n;
    linked_list *tmp = list;
    n = list_length(list) - 1;
    if (n < a)
    {
        add_list(list, (a - n));
    }
    for (i = 0; i < a; ++i)
    {
        tmp = tmp->next_ptr;
    }
    strcpy(tmp->data, ch);
}

void ini_list(linked_list *list, linked_list *next_list_ptr, const char *ch)
{
    strcpy(list->data, ch);
    list->next_ptr = next_list_ptr;
}

size_t list_length(linked_list *list)
{
    size_t i = 0;
    linked_list *tmp = list;
    while(tmp != NULL)
    {
        tmp = tmp->next_ptr;
        ++i;
    }
    return i;
}

linked_list *list_delete(linked_list *list, size_t a)
{
    size_t len = list_length(list);
    if ((a > 0) && (a < (len - 1)))
    {
        if (a == 1)
        {
            size_t i;
            linked_list *after_ptr = list;
            linked_list *before_ptr = list;
            linked_list *target_ptr = NULL;
            for (i = 0; i < (a + 1); ++i)
            {
                after_ptr = after_ptr->next_ptr;
                if (i == (a - 1))  target_ptr = after_ptr;
            }
            before_ptr->next_ptr = after_ptr;
            free(target_ptr);
            return list;
        }
        size_t i;
        linked_list *after_ptr = list;
        linked_list *before_ptr = NULL;
        linked_list *target_ptr = NULL;
        for (i = 0; i < (a + 1); ++i)
        {
            after_ptr = after_ptr->next_ptr;
            if (i == (a - 1))  target_ptr = after_ptr;
            if (i == (a - 2))  before_ptr = after_ptr;
        }
        before_ptr->next_ptr = after_ptr;
        free(target_ptr);
        return list;
    }
    else if (a == 0)
    {
        linked_list *tmp = list->next_ptr;
        free(list);
        return tmp;
    }
    else if (len == 2 && a == 1)
    {
        linked_list *target_ptr = list->next_ptr;
        list->next_ptr = NULL;
        free (target_ptr);
        return list;
    }
    else if (a == (len - 1))
    {
        size_t i;
        linked_list *target_ptr = list;
        linked_list *before_ptr = NULL;
        for (i = 0; i < a; ++i)
        {
            target_ptr = target_ptr->next_ptr;
            if (i == (a - 2))  before_ptr = target_ptr;
        }
        before_ptr->next_ptr = NULL;
        free(target_ptr);
        return list;
    }
    printf("FAILED: Could not delete in the list.\n");
    printf("REMARKS: Number of list is %d now, but value of the argument passed is %d.\n", len, a);
    printf("         linked_list *list_delete(linked_list *list, size_t a);\n");
    printf("                                                            ^  \n");
    return list;
}

void close_list(linked_list *list)
{
    size_t i = 0;
    size_t len = list_length(list);
    linked_list *list_ptr = list;
    linked_list *tmp = list_ptr->next_ptr;
    for (i = 0; i < (len - 1); ++i)
    {
        free(list_ptr);
        list_ptr = tmp;
        tmp = list_ptr->next_ptr;
    }
    free(list_ptr);
    free(tmp);
}

void ky_fin(FILE *fp, linked_list *pl)
{
    if(fp == NULL)
    {
		printf("File pointer is NULL!\n");
		return;
	}
    if(pl == NULL)
    {
		printf("List pointer is NULL!\n");
		return;
	}

    // ファイルの中身をリストの最後に追加へ
    while(fgets((list_position(pl, list_length(pl) - 1))->data, KY_LIST_ELEMENTS, fp) != NULL)
    {
		if ((list_position(pl, list_length(pl) - 1))->data[strlen((list_position(pl, list_length(pl) - 1))->data) - 1] == '\n')
		{
			(list_position(pl, list_length(pl) - 1))->data[strlen((list_position(pl, list_length(pl) - 1))->data) - 1] = '\0';
		}
		add_list(pl, 1);
	}
	list_delete(pl, list_length(pl) - 1);
}

void ky_fout(FILE *fp, linked_list *pl)
{
	if(fp == NULL)
    {
		printf("File pointer is NULL!\n");
		return;
	}
    if(pl == NULL)
    {
		printf("List pointer is NULL!\n");
		return;
	}

	size_t i;
	for (i = 0; i < list_length(pl); ++i)
	{
		if (i == (list_length(pl) - 1))
		{
		fprintf(fp, "%s", list_position(pl, i)->data);
		}
		else
		{
		fprintf(fp, "%s\n", list_position(pl, i)->data);
		}
	}
}

size_t list_numInatob(linked_list* pla, linked_list *plb)
{
	size_t counta = 0;
	linked_list *tmp = pla;
	++counta;
	while(tmp != plb)
	{
		tmp = tmp->next_ptr;
		++counta;
		if (tmp == NULL)
		{
			return 0;
		}
	}
	return counta;
}

void ky_exchange(linked_list *pla, linked_list *plb)
{
	linked_list *tmp = create_list();
	ini_list(tmp, NULL, pla->data);
	ini_list(pla, pla->next_ptr, plb->data);
	ini_list(plb, plb->next_ptr, tmp->data);
	free(tmp);
}

void ky_qsort(linked_list *pl, size_t numOfElements)
{
	if (numOfElements < 2) return;

	linked_list *ppiv = list_position(pl, numOfElements - 1);   /* pivot pointer */
    linked_list *pleft = pl;                         			/* left pointer */
    linked_list *pright = list_position(pl, numOfElements - 2); /* right pointer */
    linked_list *pnext_left_a;                       			/* next left of pointer that is array beginning */
    linked_list *pnext_right_a;                      			/* next right of pointer that is array beginning */
    size_t next_left_numOfElements;             				/* next left number of elements in the array */
    size_t next_right_numOfElements;            				/* next right number of elements in the array */
	size_t counta = 2;

	/* do sort */
    while(1)
    {
        while (pleft != ppiv) /* operate left pointer */
        {
            if (strtof((pleft->data), NULL) > strtof((ppiv->data), NULL)) break;
            pleft = pleft->next_ptr; /* left to right */
        }

		if (pleft == ppiv) break;

        while (pright != pleft) /* operate right pointer */
        {
            if (strtof((pright->data), NULL) < strtof((ppiv->data), NULL)) break;
			++counta;
            pright = list_position(pl, numOfElements - counta); /* right to left */
        }

        if (pleft == pright)
        {
            ky_exchange(ppiv, pleft);
            break;
        }

        ky_exchange(pleft, pright);
    }
    pnext_left_a = pl;                          /* enter next left of pointer that is array beginning */
    pnext_right_a = pleft->next_ptr;            /* enter next right of pointer that is array beginning */
    next_left_numOfElements = list_numInatob(pl, pleft) - 1;       /* enter next left number of elements in the array */
    next_right_numOfElements = list_numInatob(pleft, ppiv) - 1;    /* enter next right number of elements in the array */
	/* if left or right is not 0, recurs */
    if (next_left_numOfElements != 0)
	{
        ky_qsort(pnext_left_a, next_left_numOfElements);
    }
    if (next_right_numOfElements != 0)
    {
        ky_qsort(pnext_right_a, next_right_numOfElements);
    }
}

/**
 * memory_error -- Output error and end.
 */
void node_memory_error(void)
{
    fprintf(stderr, "Error:Out of memory\n");
    exit (8);
}

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
char *save_string(const char *string)
{
    char *new_string;       /* Where to save the string. */

    new_string = malloc((unsigned)(strlen(string) + 1));

    if (new_string == NULL)
        node_memory_error();
    
    strcpy(new_string, string);
    return(new_string);
}

/**
 * enter -- Insert the word in tree.
 * 
 * @param
 *      node -- Current node of interest.
 *      word -- The word to insert.
 */
void enter(node **ky_node, const char *word)
{
    int result;         /* strcmp result */

    char *save_string(const char *);      /* Save the string in the heap. */

    /**
     * If current node is NULL, reached the bottom end of the end and it must create a new node.
     */
    if ((*ky_node) == NULL)
    {
        /* Allocate memory for the new node. */
        (*ky_node) = malloc(sizeof(node));
        if ((*ky_node) == NULL)
            node_memory_error;
        
        /* Initialize the new node. */
        (*ky_node)->left = NULL;
        (*ky_node)->right = NULL;
        (*ky_node)->word = save_string(word);
        return;
    }
    /* Check where the word is comming. */
    result = strcmp((*ky_node)->word, word);

    /* If the current node is the same as the word, no need to insert. */
    if (result == 0)
        return;
    
    /* The word must be inserted into the left or right node. */
    if (result < 0)
        enter(&(*ky_node)->right, word);
    else
        enter(&(*ky_node)->left, word);
}

/**
 * scan -- Scan the word in the file.
 * 
 * @param
 *      name -- The file name to scan.
 */
void scan(const char *name, node **root)
{
    char word[KY_NODE_ELEMENTS];         /* Target word */
    int index;              /* Target word index */
    int ch;                 /* Current character */
    FILE *in_file;          /* Input file */

    in_file = fopen(name, "r");
    if (in_file == NULL) {
        fprintf(stderr, "Error:Unable to open %s\n", name);
        exit (8);
    }
    while (1) {
        /* Skip brank and scan. */
        while (1)
        {
            ch = fgetc(in_file);
            if (isalpha(ch) || (ch == EOF))
                break;
        }
        if (ch == EOF)
            break;

        word[0] = ch;
        for (index = 1; index < sizeof(word); ++index)
        {
            ch = fgetc(in_file);
            if (!isalpha(ch))
                break;
            word[index] = ch;
        }
        /* Add NULL at the end */
        word[index] = '\0';

        enter(root, word);
    }
    fclose(in_file);
}

/**
 * print_tree -- Input the word in the tree.
 * 
 * @param
 *      top -- The root of the tree to output.
 */
void print_tree(node *top)
{
    if (top == NULL)
        return;         /* Short tree. */

        print_tree(top->left);
        printf("%s\n", top->word);
        print_tree(top->right);
}

/**
 * fprint_tree -- Input the word in the tree to the file.
 * 
 * @param
 *      fp -- file to be written.
 *      top -- The root of the tree to output.
 */
void fprint_tree(FILE *fp, node *top)
{
    if (fp == NULL || top == NULL) return;         /* Short tree. */

    fprint_tree(fp, top->left);
    fprintf(fp, "%s\n", top->word);
    fprint_tree(fp, top->right);
}

void nclose(node *top)
{
    if (top == NULL) return;
    nclose(top->left);
    top->left = NULL;
    nclose(top->right);
    top->right = NULL;
    if ((top->left == NULL) && (top->right == NULL))
    {
        free(top->word);
        free(top);
    }
}

void copy_to_list(linked_list *lp, node *root)
{
    if (lp == NULL || root == NULL) return;
    copy_to_list(lp, root->left);
    if (list_position(lp, list_length(lp) - 1)->data[0] == '\0')
    {
        list_print(lp, list_length(lp) - 1, root->word);
    }
    else
    {
        insert_list(lp, list_length(lp), root->word);
    }
    copy_to_list(lp, root->right);
}