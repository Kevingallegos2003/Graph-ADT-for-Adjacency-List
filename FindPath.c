//Kevin Gallegos 1858764 PA2

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "List.h"
#include "Graph.h"


int main(int argc, char* argv[]){
	int line1;
	int scan;
	FILE* in = fopen(argv[1], "r");
	if(argv[1]==NULL){fprintf(stderr, "can't read file\n");}
	FILE* out =  fopen(argv[2], "w");
	if(argv[2]==NULL){fprintf(stderr, "can't OPEN file\n");}
	//int lengthlimit = 100;
	//char str[10];
	scan = fscanf(in,"%d",&line1);
	Graph G = newGraph(line1);
	//fprintf(out,"your mom");
	//fclose(out);
	//printf("vertexs: %d\n",line1);
	//scan = fscanf(in,"%d",&line1);
	while(scan != EOF){
		fscanf(in,"%d",&line1);
		if(line1 == 0){fscanf(in,"%d",&line1);break;}
        	int x = line1;
        	fscanf(in,"%d",&line1);
		int y = line1;
		//printf("adding edge, List[%d] {%d}\n", x,y);
		addEdge(G,x,y);
		//printGraph(stdout,G);
    	}

	printGraph(out,G);
	//fclose(out);
	fprintf(out,"\n");
        while(scan != EOF){
		fscanf(in,"%d",&line1);
		//printf("svanned: %d\n",line1);
                if(line1 == 0){fscanf(in,"%d",&line1);break;}
                int x = line1;
		//printf("should be same as above: %d\n",x);
		BFS(G,x);
		//printf("BFS done\n");
                fscanf(in,"%d",&line1);
                int y = line1;
		//printf("path going to %d\n",y);
                List L = newList();
		//printf("list created\n");
		getPath(L,G,y);
		if (getDist(G,y) == INF){
			fprintf(out, "The distance from %d to %d is infinity\n", x,y);
                	fprintf(out, "No %d-%d path exists", x,y);
			fprintf(out,"\n\n");
		}
		else{
			fprintf(out, "The distance from %d to %d is %d\n", x,y,getDist(G,y));
			fprintf(out, "A shortest %d-%d path is: ", x,y);
			printList(out,L);
			fprintf(out,"\n\n");
		}
		freeList(&L);
        }
	fclose(in);
	fclose(out);
	freeGraph(&G);
	//freeList(&L);
}



