//Kevin Gallegos 1858764 PA2

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Graph.h"
int main(){
   int n=6;
   //List  C = newList(); // central vertices
   //printf("c built\n");
   //List  P = newList(); // peripheral vertices
   //List  J = newList();
   //printf("above was list e aloocate newlist()\n");// eccentricities
   //printf("pe built\n");
   //Graph G = NULL;
   //append(J,1);
   //moveFront(J);
   //int k = get(J);
   //printf("%d\n",k);
   // Build graph G
   Graph G = newGraph(n);
   printf("graph built\n");
   //int x = getDist(G,1);
   //printf("%d",x);
   //if(G->lists[1] == NULL){printf("NULL\n");}
   printf("starting add edges\n");
   addEdge(G, 1, 2);
   addEdge(G, 1, 3);
   //addEdge(G, 1, 3);
   //addEdge(G, 2, 1);
   addEdge(G, 2, 4);
   addEdge(G, 2, 5);
   addEdge(G, 2, 6);
   //addEdge(G, 3, 1);
   addEdge(G, 3, 4);
   //addEdge(G, 4, 2);
   //addEdge(G, 4, 3);
   addEdge(G, 4, 5);
   //addEdge(G, 5, 2);
   //addEdge(G, 5, 4);
   addEdge(G, 5, 6);
   //addEdge(G, 6, 2);
   //addEdge(G, 6, 5);
   printf("added edges done\n");
   printf("order: %d\n",getOrder(G));
   printf("side: %d\n",getSize(G));
   //printf("Dist: %d\n",getDist(G));
   //printf("par: %d\n",getParent(G));
   printf("source: %d\n",getSource(G));

   printGraph(stdout,G);
   //printGraph(stdout,G);
   
   printf("succ cess adding 3 edges\n");
   //shitout(G,1);

   //printf("ur mom: \n", length(G->lists[1]));
   BFS(G,6);
   printf("BFS done source is: %d\n",getSource(G));
   printf("parent of 5 is: %d\n",getParent(G,2));
   printf("get distance of 1: %d\n", getDist(G,1));
   //printGraph(stdout,G);
   List E = newList();
   printf("created e\n");
   getPath(E,G,2);
   printf("get path done\n");
   printList(stdout, E);
   printf("\n");


}
