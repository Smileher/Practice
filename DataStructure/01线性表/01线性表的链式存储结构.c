#include <stdio.h>
#include <stdlib.h>
typedef struct stu {
  int data;          //存放数据
  struct stu* next;  //下一个节点地址
} Node;
typedef struct {
  int count;   // 节点个数
  Node* head;  // 头结点
} List;

//创建新节点功能
Node* Create_node(int data) {
  Node* pnew = (Node*)malloc(sizeof(Node));  //为新节点开辟空间
  pnew->next = NULL;                         //新节点指向null;
  pnew->data = data;
  return pnew;
}

//头部插入数据
void push_head(List* p, int data) {
  //创建一个新的节点
  Node* pn = Create_node(data);
  //插入新节点到表头
  pn->next = p->head;
  p->head = pn;
  p->count++;
}

//尾插
void push_tail(List* p, int data) {
  //找到最后一个节点
  Node* pn = p->head;
  while (pn->next != NULL) {
    pn = pn->next;
  }
  //插入元素
  Node* pm = Create_node(data);
  pn->next = pm;
  p->count++;
}

//头删节点
void del_head(List* p) {
  Node* pn = p->head;       //把要删除的节点保存起来
  p->head = p->head->next;  //连接它的前节点与后节点
  free(pn);                 //释放并置为空
  pn = NULL;
  p->count--;
}

//尾删节点
void del_tail(List* p) {
  Node* pn = p->head;  //第一个节点
  while (pn->next->next != NULL) {
    pn = pn->next;
  }
  Node* pm = pn->next->next;
  pn->next = NULL;
  free(pm);
  pm = NULL;
  p->count--;
}

//任一位置节点插入
void push_arb(List* p, int data, int pos) {
  //判断插入位置是否合法
  if (pos < 0 || pos > p->count) {
    printf("插入位置不合法，插入到尾部\n");
    pos = p->count;
  }
  //头插
  if (pos == 0) {
    Node* pn = Create_node(data);
    pn->next = p->head;
    p->head = pn;
    p->count++;
    return;
  }
  //中间任意位置插入
  Node* pn = Create_node(data);
  Node* pm = p->head;
  for (int i = 1; i < pos; i++) {
    pm = pm->next;
  }
  pn->next = pm->next;
  pm->next = pn;
  p->count++;
}

//任一节点删除
void del_arb(List* p, int pos) {
  //判断删除位置是否合法
  if (pos < 0 || pos >= p->count)  //删除的是当前位置后面的一个节点
  {
    printf("删除位置不合法，删除失败\n");
    return;
  }
  Node* pn = p->head;
  if (pos == 0)  //头删
  {
    p->head = p->head->next;
    free(pn);
    p->count--;
    return;
  }
  //任意位置删除
  for (int i = 1; i < pos; i++) {
    pn = pn->next;
  }
  Node* pm = pn->next;
  pn->next = pn->next->next;
  free(pm);
  pm = NULL;
  p->count--;
}

//从尾到头打印链表递归调用
void tail_head(Node* head)  //递归方法
{
  if (head == NULL) {
    return;
  }
  tail_head(head->next);
  printf("%d  ", head->data);
}

//链表长度
void long_list(List* p) { printf("%d\n", p->count); }

//清空链表
void clear_list(List* p)  //从头开始清空
{
  printf("清空所有的节点\n");
  //第一个数据

  while (p->head != NULL) {
    Node* pn = p->head;
    p->head = p->head->next;
    free(pn);
    pn = NULL;
    p->count--;
  }
}

//遍历链表
void travel_list(List* p) {
  Node* ptemp = p->head;
  if (ptemp == NULL) {
    printf("链表已空\n");
    return;
  }
  printf("链表中元素有： ");
  while (ptemp != NULL) {
    printf("%d   ", ptemp->data);
    ptemp = ptemp->next;
  }
  printf("\n");
}
int main() {
  List list;
  list.head = NULL;
  list.count = 0;
  push_head(&list, 1);
  push_head(&list, 2);
  push_head(&list, 3);
  travel_list(&list);
  push_tail(&list, 4);
  travel_list(&list);
  del_head(&list);
  travel_list(&list);
  del_tail(&list);
  travel_list(&list);
  long_list(&list);
  clear_list(&list);
  long_list(&list);
  push_arb(&list, 6, 9);
  push_arb(&list, 6, 1);
  travel_list(&list);
  tail_head(list.head);
  travel_list(&list);
  return 0;
}