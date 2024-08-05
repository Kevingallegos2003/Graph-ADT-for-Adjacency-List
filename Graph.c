//Kevin Gallegos 1858764 PA2

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph.h"
#include "List.h"


//#define maxvertices 100
#define white 0
#define grey 1
#define black 2

typedef struct GraphObj{
        List *lists;
      	//[maxvertices];//fix  struct list* lists
        int *colors; //[maxvertices];
        int *par; //[maxvertices];
        int *dist;
       	int order;
	int size;
	int recent;

}GraphObj;




/*** Constructors-Destructors ***/
Graph newGraph(int n){
        //Graph G;
        Graph G = malloc(sizeof(GraphObj));
        assert(G!=NULL);
	//fix
	//n++;i
	G->lists = malloc(sizeof(List) * (n+1));
	G->colors = malloc(sizeof(int) * (n+1));
	G->par = malloc(sizeof(int) * (n+1));
	G->dist = malloc(sizeof(int) * (n+1));
	//G->lists[1] = newList();
	G->order =  n;
        G->size = 0;
        G->recent = NIL;
        for(int z = 1;z <= n; z++){
		//printf("i++\n")
                G->lists[z] = newList();
		//printf("newlist\n");
		//assert(G->lists[z]->length != -1);
                //G->lists[i] = NULL;
		//G->lists[i] = newList();
                //G->colors[z] = white;
		G->dist[z] = INF;
                G->par[z] = NIL;
        }

	//printf("after test %d\n",length(G->lists[0]));
	//printf("after test %d\n",length(G->lists[1]));
	//printf("after test %d\n",length(G->lists[2]));
	//G->lists[1] = newList();
	//G->order =  n;
        //G->size = 0;
        //G->recent = NIL;
        //printf("after test %d\n",G->size);
        //printf("after test %d\n",G->order);
        //printf("after test %d\n",G->recent);
        return G;
}
void freeGraph(Graph* pG){
	for(int i= 1; i<=(getOrder(*pG)); i++){
		List L = (*pG)->lists[i];
		freeList(&L);
	}
	free((*pG)->lists);
	free((*pG)->colors);
	free((*pG)->par);
	free((*pG)->dist);
        free(*pG);//free list crap
        *pG = NULL;
}
/*** Access functions ***/
int getOrder(Graph G){
        return G->order;
}
int getSize(Graph G){
        return G->size;
}
int getSource(Graph G){
        return G->recent;
}
int getParent(Graph G, int u){
        return G->par[u];
}
int getDist(Graph G, int u){
        return G->dist[u];
}
void getPath(List L, Graph G, int u){
	if(getSource(G) != NIL && getDist(G,u) != INF){
		int x = getSource(G);
		//append(L,x);
		append(L,u);
		moveFront(L);
		while(x!=u){
			u = G->par[u];
			insertBefore(L,u);
			movePrev(L);
		}
	}
}
/*** Manipulation procedures ***/
void makeNull(Graph G){
        G->size = 0;
        G->recent = NIL;
        for(int i= 1; i<=(G->order); i++){
                List L = G->lists[i];
                clear(L);
                G->lists[i] = L;
                G->colors[i] = white;
                G->par[i] = -1;
                G->dist[i] = -1;
        }
}
void addEdge(Graph G, int u, int v){
	//if (G->size> 100){G->size = 0;}
	//printf("adding edge %d\n", u);
        //List K = G->lists[u];
        //List V = G->lists[v]; 
	//assert(K != NULL);
	//length(K);
	//length(V);
	//printf("boutta append\n");
        //append(K, v);
	addArc(G,u,v);
	addArc(G,v,u);
	//make a sort so it goes in numericallly
       	//append(U, v);
        //append(V,u);    //append(V, u); This looks dumb i pray this is the right idea at least.
        //printf("size++\n");
	G->size--;//Also append (append(list[v], u) because undirected
	//printf("finished size\n");
}
void addArc(Graph G, int u, int v){
	//printf("in arc\n");
	//if (G->size > 100){G->size = 0;}
        if (length(G->lists[u]) == 0){
		//printf("in arc 0\n");
                //append(G->lists[u],NIL);
                append(G->lists[u],v);
		G->size++;
		return;
        }
	//printf("in arc 1\n");
	List F = G->lists[u];
	moveFront(F);
	//printf("index: %d\n", index(F));
	//while(index(F) != 1 && get(F) < v){moveNext(F);}
	//if(index(F) == -1){append(F,v);}
	//else{insertBefore(F,v);}
	while(v<get(F)){
		if(index(F) == 0){break;}
		movePrev(F);
	}
        insertAfter(F,v);
        G->size++;
}
void BFS(Graph G, int s){
	//shitout(G,1);
        for(int x = 1; x <= G->order; x++){
                G->colors[x] = white;
                G->dist[x] = INF;
                G->par[x] = NIL;
        }
	//printf("setted up all edges to white\n");
	G->recent = s;
	//printf("source created: %d\n",s);


        G->colors[s] = grey;
        G->dist[s] = 0;
        G->par[s] = NIL;
	//printf("source c,d,p established\n");
        List Q = newList();
	//int j = length(Q);//construct new queue
	//printf("length of list: %d\n",j);
	append(Q,s);
	//printf("appended source\n");
	//j = length(Q);
	//printf("index: %d\n", index(Q));
	//printf("length of q: %d\n",j);
	//shitout(G,1);
        while(length(Q) != 0){
		//printf("length not 0\n");
                int x = front(Q);
		deleteFront(Q);
		//rintf("List[%d] is now being looked at\n",x);
		List L = G->lists[x];
		//printf("grabbed list #%d into L\n",x);
		//shitout(G,1);
		//printf("index: %d\n", index(L));
		//printf("length of L: %d\n",length(G->lists[x]));
		moveFront(L);
		//printf("lookin at front shit\n");
		//moveNext(L);
		//moveNext(L);
		//printf("front of list is %d\n",get(L));
		//printList(out,Q);
		for(int inde = 1; inde <= length(L); inde++){//adj[
			int y = get(L);
			//printf("got %d from list L\n",y);
                        if (G->colors[y] == white){
				//printf("discovered %d adding to list\n", y);
                                G->colors[y] = grey;
                                G->dist[y] = G->dist[x]+1;
                                G->par[y] = x;
                                append(Q,y);
                        }
			moveNext(L);
			//printf("moved to next in in list");
                }
                G->colors[x] = black;
		//freeList(&L);
	}
	freeList(&Q);
}
/*** Other operations ***/
void printGraph(FILE* out, Graph G){

	//if(getSource(G) != NIL){
		for(int i=1; i<=(G->order); i++){//1=i
			fprintf(out, "%d", i);
			fprintf(out, ": ");
			List L = G->lists[i];
			if(L == NULL){break;}
			moveFront(L);
			//if(get(L) == NIL){delete(L);}
			printList(out,L);
			//fprintf(out, "%d", get(L));
                        fprintf(out, "\n");
			//fprintf(out,"loop %d done\n", i);
			
		}
		//fprintf(out, "its done\n");

	//}

}	
