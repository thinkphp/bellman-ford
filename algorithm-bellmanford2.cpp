/**
 *  Author           -> Adrian Statescu <mergesortv@gmail.com> <http://thinkphp.ro>
 *  Operating System -> Ubuntu
 *  Environments     -> Wim
 *  Compile          -> g++ -std=c++11 algorithm-bellmanford.cpp -o bell
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#define FIN "bellmanford.in"
#define FOUT "bellmanford.out"
#define oo ((1LL<<31)-1)
#define MAXN 50005

using namespace std;

int nodes,
    edges;

vector<pair<int,int > > Graph[ MAXN ];
int distMin[ MAXN ];

queue<int> Queue;
bitset<MAXN> inQueue;
int countInQueue[ MAXN ];
bool negative_cycle = false;

void readData() {

     int x,
         y,
         cost; 

     FILE *fin = fopen(FIN, "r");

     fscanf(fin, "%d %d", &nodes, &edges);

     while(edges--){

           fscanf(fin, "%d %d %d", &x, &y, &cost);

           Graph[ x ].push_back({y,cost}); 
     }
 
     fclose( fin );
};

void BellmanFord() {

     for(int i = 2; i <= nodes; i++) distMin[ i ] = oo;

     distMin[ 1 ] = 0;

     Queue.push( 1 );

     inQueue[ 1 ] = true;

     while( !Queue.empty() && !negative_cycle) {

            int node = Queue.front();

            Queue.pop();

            inQueue[ node ] = false;

            for(auto it : Graph[ node ]) {

                if(distMin[ it.first ] > distMin[ node ] + it.second) {

                   distMin[ it.first ] = distMin[ node ] + it.second;

                   if(!inQueue[ it.first ]) {

                       if(countInQueue[ it.first ] > nodes) {

                          negative_cycle = true;

                       } else {

                              Queue.push( it.first );  

                              inQueue[ it.first ] = true;

                              countInQueue[ it.first ]++;
                       }
                   }
                }
            } 
     }
};


void writeData() {

     FILE *fout = fopen(FOUT, "w");

     if(negative_cycle) 

          fprintf(fout, "%s", "Ciclu negativ!");  

     else {
  
         for(int i = 2; i <= nodes; i++) 

          fprintf(fout, "%d ", distMin[ i ]);  
     }

     fclose( fout );
};


int main() {

 readData();
 BellmanFord();
 writeData();

 return(0);   
};