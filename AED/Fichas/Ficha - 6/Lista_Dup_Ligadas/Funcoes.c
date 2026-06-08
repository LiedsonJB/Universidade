#include "Biblioteca.h"

lista* create() {
    lista* new_list = (lista*)malloc(sizeof(lista));

    if (new_list) {
        new_list->first = NULL;
        new_list->last = NULL;
    }

    return new_list;
}


void insertBegin(lista* I, Item i) {
    link new_node = (link)malloc(sizeof(struct node));

    if (new_node) {
        new_node->item = i;
        new_node->next = I->first;
        new_node->prev = NULL;
        if (I->first)
            I->first->prev = new_node;
        else
            I->last = new_node;
        I->first = new_node;
    }
}

void insertEnd(lista* I, Item i) {
    link new_node = (link)malloc(sizeof(struct node));
    if (new_node) {
        new_node->item = i;
        new_node->next = NULL;
        new_node->prev = I->last;
        if (I->last)
            I->last->next = new_node;
        else
            I->first = new_node;
        I->last = new_node;
    }
}

void insertSorted(lista* I, Item i) {
    link new_node = (link)malloc(sizeof(struct node));
    if (new_node) {
        new_node->item = i;
        new_node->prev = NULL;
        new_node->next = NULL;

        if (!I->first) {
            I->first = new_node;
            I->last = new_node;
        } else {
            link curr = I->first;
            while (curr && itemCompare(curr->item, i) < 0)
                curr = curr->next;

            if (!curr) {
                new_node->prev = I->last;
                I->last->next = new_node;
                I->last = new_node;
            } else {
                new_node->next = curr;
                new_node->prev = curr->prev;
                if (curr->prev)
                    curr->prev->next = new_node;
                else
                    I->first = new_node;
                curr->prev = new_node;
            }
        }
    }
}

void show(lista* I) {
    link curr = I->first;
    while (curr) {
        showItem(curr->item);
        curr = curr->next;
    }
}

void removeFirst(lista* I, Item i) {
    link curr = I->first;
    while (curr) {
        if (itemCompare(curr->item, i) == 0) {
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                I->first = curr->next;
            if (curr->next)
                curr->next->prev = curr->prev;
            else
                I->last = curr->prev;
            free(curr);
            break;
        }
        curr = curr->next;
    }
}

void removeLast(lista* I, Item i) {
    link curr = I->last;
    while (curr) {
        if (itemCompare(curr->item, i) == 0) {
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                I->first = curr->next;
            if (curr->next)
                curr->next->prev = curr->prev;
            else
                I->last = curr->prev;
            free(curr);
            break;
        }
        curr = curr->prev;
    }
}

void removeAll(lista* I, Item i) {
    link curr = I->first;
    while (curr) {
        if (itemCompare(curr->item, i) == 0) {
            link temp = curr;
            curr = curr->next;
            if (temp->prev)
                temp->prev->next = temp->next;
            else
                I->first = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            else
                I->last = temp->prev;
            free(temp);
        } else {
            curr = curr->next;
        }
    }
}
