#include<stdio.h>
#include<stdlib.h>

#define max 10
struct node{
  int data;
  struct node* next;
};

struct node* adj[max];
int vis1[max],vis2[max];
int que[max];
int f = -1, r = -1;

void push(int x){
  if(r == max-1) return;
  if(f == -1 && r == -1){
    f = r = 0;
    que[r] = x;
    return;
  }
  que[++r] = x;
}

int pop(){
  if(f == -1) return -1;
  if(f == r){
    int v = que[f];
    f = r = -1;
    return v;
  }
  return que[f++];
}

void addEdge(int u, int v){
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = v;
  newNode->next = NULL;
  struct node* temp = adj[u];
  if(adj[u] == NULL){
    adj[u] = newNode;
    return;
  }
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}

void BFS(int start, int n){
  push(start);
  vis1[start] = 1;

  while(f != -1){
    int v = pop();
    printf("%d ",v);
    struct node* temp = adj[v];
    while(temp != NULL){
      if(vis1[temp->data] != 1){
        push(temp->data);
        vis1[temp->data] = 1;
      }
      temp = temp->next;
    }
  }
  for(int i = 1; i <= n; i++){
    if(vis1[i] != 1){
      BFS(i,n);
    }
  }
}

void DFS(int start){
  printf("%d ",start);
  vis2[start] = 1;

  struct node* temp = adj[start];
  while(temp != NULL){
    if(vis2[temp->data] != 1){
      DFS(temp->data);
    }
    temp = temp->next;
  }
}

int main(){
  int n,e,u,v;
  printf("Enter number of nodes : ");
  scanf("%d",&n);
  printf("Enter number of edges : ");
  scanf("%d",&e);
  for(int i = 1; i <= n; i++){
    vis1[i] = 0;
    vis2[i] = 0;
    adj[i] = NULL;
  }

  printf("ENter edges : \n");
  for(int i = 0; i < e;i++){
    printf("Edges : ");
    scanf("%d %d",&u,&v);
    addEdge(u,v);
  }

  printf("BFS : ");
  BFS(1,n);
  printf("DFS : ");
  DFS(1);
  for(int i = 1; i <= n; i++){
    if(vis2[i] != 1) DFS(i);
  }
}
