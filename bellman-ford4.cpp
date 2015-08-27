#include <cstdio>
#include <deque>
#include <vector>
#define FIN "bellmanford.in"
#define FOUT "bellmanford.out"
#define oo ((1LL<<31) - 1)
#define MAXN 50001
#define nodeY it->first
#define cost it->second

using namespace std;

vector< pair<int, int> > VEC[ MAXN ];

deque< int > Queue;

int A,
    B,
    C,
    dist[ MAXN ], 
    vis [ MAXN ],
    count[ MAXN ], 
    nodeX,     
    nodes,
    edges;         

void readData();
void BellmanFord();

int main() {

 readData();
 BellmanFord();

 return(0); 
};

void readData() {       

     FILE *fin = fopen(FIN, "r");

     fscanf(fin, "%d %d", &nodes, &edges);

     for( ;edges; edges--){

          fscanf(fin, "%d %d %d", &A, &B, &C);

          VEC[ A ].push_back( make_pair( B, C) ); 
     } 

     fclose( fin ); 
};

void BellmanFord() {

     FILE *fout = fopen(FOUT, "w"); 

     vector< pair <int, int> >::iterator it;

     for(int i = 2; i <= nodes; i++) dist[ i ] = oo;

     dist[ 1 ] = 0;

     Queue.push_back( 1 );

     for( ; Queue.size(); ) {

            nodeX = Queue.front();

            for(it = VEC[ nodeX ].begin(); it != VEC[ nodeX ].end(); ++it ) {

                if( dist[ nodeY ] >  dist[ nodeX ] + cost) { 

                    dist[ nodeY ] =  dist[ nodeX ] + cost;

                    if(!vis[ nodeY ]) {

                       if( ++count[ nodeY ] > nodes ) { 

                             fprintf(fout, "%s", "Ciclu negativ!"); 

                             return;
                       }

                       Queue.push_back( nodeY );  

                       vis[ nodeY ] = 1;
                    }                    
                }
                    
            }

            Queue.pop_front();

            vis[ nodeX ] = 0;
     }

     for(int j = 2; j <= nodes; j++) fprintf(fout, "%d ", dist[ j ]);  

     fclose( fout ); 
};