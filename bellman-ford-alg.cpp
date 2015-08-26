#include <cstdio>
#include <queue>
#include <bitset>
#define oo ((1LL<<31) - 1)
#define FIN "bellmanford.in"
#define FOUT "bellmanford.out"
#define MAXN 50001

using namespace std;

int nodes,
    edges,
    distMin[ MAXN ],
    count[ MAXN ];

queue<int> Queue;
bitset<MAXN> in_Queue(0);

struct Node {

       int y,
           c;
       Node *next;
};

Node *Graph[ MAXN ];

void addEdge(const int x, const int y, const int c) {

     Node *newNode;

     newNode = new Node;
     newNode->y = y;
     newNode->c = c;
     newNode->next = Graph[ x ];
     Graph[ x ] = newNode;       
};

void readData() {

     int X,
         Y,
         cost;

     FILE *fin = fopen(FIN, "r");

     fscanf(fin, "%d %d", &nodes, &edges);

     for(;edges; edges--) {

           fscanf(fin, "%d %d %d", &X, &Y, &cost);          

           addEdge(X, Y, cost); 
     } 

     fclose( fin );  

};

void BellmanFord() {

     FILE *fout = fopen(FOUT, "w");

     for(int i = 2; i <= nodes; i++) distMin[ i ] = oo; 

     distMin[ 1 ] = 0;

     Queue.push( 1 );

     in_Queue[ 1 ] = 1; 

     int x;

     while( !Queue.empty() ) {

            x = Queue.front();
     
            Queue.pop();

            in_Queue[ x ] = false;

            for(Node *p = Graph[ x ]; p; p = p->next) {

                     if( distMin[ p->y ] > distMin[ x ] + p->c ) {

                         distMin[ p->y ] = distMin[ x ] + p->c;

                         if(!in_Queue[ p->y ]) {

                             Queue.push( p->y );

                             in_Queue[ p->y ] = true;

                             if(++count[ p->y ] > nodes - 1) {
                                         
                                         fprintf(fout, "%s", "Ciclu negativ!");

                                         return; 
                             }
                         }
                     }  
            } 
     }

     for(int j = 2; j <= nodes; j++) fprintf(fout, "%d ", distMin[ j ]);
};

int main() {

   readData();
   BellmanFord();

 return(0);
};