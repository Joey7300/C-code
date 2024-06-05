//3.请实现非递归版本的链表空间释放函数erase_list(list_item *head)。
#include<stdio.h>
#include<stdlib.h>

typedef struct _list_item {
    float value;
    struct _list_item *next;
} list_item ;


list_item* create_a_list_item(float value){
    list_item *p;
    p = (list_item*)calloc(1,sizeof(list_item));
    p->value = value;
    p->next  = NULL;
    return p;
}

list_item* create_a_list(){
  list_item *head,*p;
  int i;
  head = create_a_list_item(0);
  p = head;
  for(i=1;i<=3;i++){
      p->next = create_a_list_item(-1 * i);
      p       = p->next;
  }
  return head;
}


void insert_a_list_item_at_head(list_item *head, float value){
    list_item *item = create_a_list_item(value);
    item->next = head->next;
    head->next = item;
}

//insert into a sorted linked list
void insert_a_list_item(list_item *head, float value){
    list_item *item = create_a_list_item(value);
    list_item *current  = head->next;
    list_item *previous = head;

    while(current) {
        if(current->value<value){
            previous = current;
            current  = current->next;
         } else {
            break;
         }
    }


    while(current && (current->value < value)   ) { //unsafe code, show  circuit evaluatin trick
        previous = current;
        current  = current->next;
    }


    // key steps of insert
    item->next     = current;
    previous->next = item;
}



void delete_a_list_item(list_item *head, float value){
    list_item *current  = head->next;
    list_item *previous = head;
    list_item *p;

    while(current) {
        if(current->value != value){
            previous = current;
            current  = current->next;
         } else {
            break;
         }
    }

    // key steps of delete
    if(current){
        previous->next = current->next;
        free(current);
    }

}

void display_list(list_item *head) {
  list_item *p  = head -> next;
  while(p) {
      printf("%f -> ",p->value);
      p=p->next;
  }
  printf("NULL\n");
}


void rec_erase_list(list_item *head) {
    if(!head) return;
    rec_erase_list(head->next);
    free(head);
}
//
//erase_list函数
void erase_list(list_item *head) {
    list_item *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    
}

void insert_sort(list_item *head) {
    list_item *p, *q,*item, *current, *previous;
    q       = head->next;
    p       = q->next;
    q->next = NULL;
    display_list(head);

    while(p){
        item = p;
        p    = p->next;
        item->next = NULL;
        insert_a_list_item(head,item->value);
        free(item);
        display_list(head);

    }
}


int main(){
    list_item *head,*p;
    int i;
    head = create_a_list();
    insert_a_list_item_at_head(head,2.5);
    insert_a_list_item_at_head(head,5.5); // cause an error,maybe
    insert_a_list_item_at_head(head,1.5);

    //delete_a_list_item(head,6.5); cause an error,maybe
    //delete_a_list_item(head,5.5);

    display_list(head);

    insert_sort(head);

    rec_erase_list(head);
    return 0;
}