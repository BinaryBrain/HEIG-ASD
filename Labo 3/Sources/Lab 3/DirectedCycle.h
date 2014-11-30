//
//  DirectedCycle.h
//  ASD2
//
//  Created by Olivier Cuisenaire on 08.10.14.
//
//  A implementer
//  Classe permettant la detection de cycle sur un graphe oriente

#ifndef ASD2_DirectedCycle_h
#define ASD2_DirectedCycle_h

#include <map>

namespace ASD2 {
    template<typename GraphType>
    class DirectedCycle {
    private:
        const GraphType& g;
        bool hasCycle;
        std::map<std::string, bool> onStack;
        std::map<std::string, bool> marked;

        void dfs(std::string v) {
            onStack[v] = true;

            for (std::string w: g.adjacent(v)) {
                if (hasCycle) {
                    return;
                }

                if (!marked[w]) {
                    dfs(w);
                } else if (onStack[w]) {
                    hasCycle = true;
                }
            }

            onStack[v] = false;
        }

    public:
        // constructor
        DirectedCycle(const GraphType& G): g(G) {
            dfs(g.name(0));
        }

        //indique la presence d'un cycle
        bool HasCycle() {
            return hasCycle;
        }

        //liste les indexes des sommets formant une boucle
        std::list<int> Cycle() {
            /* A IMPLEMENTER */
            // STUB
            return new std::list<int>();
            //return ...
        }

    };

}

#endif
