#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode{
    int n;  //  정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphNode;


// 그래프 초기화
void init(GraphNode* g){
    int r;
    int c;
    g->n =0;
    for(r=0;r<MAX_VERTICES;r++){
        for(c=0;c<MAX_VERTICES;c++){
            g->adj_mat[r][c] = 0;
        }
    }
}

// 정점 삽입 연산
void insert_vertex(GraphNode* g, int v){
    if(((g->n)+1)>MAX_VERTICES){
        fprintf(stderr,"그래프 : 정점의 개수 초과");
        return;
    }
    g->n++;
}

// 간선 삽입 연산
void insert_edge(GraphNode* g, int start, int end){
    if(start>=g->n || end >= g->n){
        fprintf(stderr,"그래프 : 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// 인접 행렬 출력 함수
void print_adj_mat(GraphNode* g){
    for(int i=0;i<g->n;i++){
        for(int j=0;j<g->n;j++){
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void main(){
    GraphNode* g;
    g = (GraphNode*)malloc(sizeof(GraphNode));
    init(g);

    for(int i=0;i<4;i++){
        insert_vertex(g,i);
    }

    insert_edge(g,0,1);
    insert_edge(g,0,2);
    insert_edge(g,0,3);
    insert_edge(g,1,2);
    insert_edge(g,2,3);
    print_adj_mat(g);

    free(g);


}