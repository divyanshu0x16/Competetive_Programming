#An edge is a critical connection, if and only if it is not in  a cycle. 

#We use dfs to find cycles and discard those edges. The remaining edges is a set of critical edges

#Rank: Depth of node during a DFS. Only th nodes that we've started visiting, but haven't finished visting, have ranks. So 0 <= rank < n.

#If a node is not visited yet, it has special rank -2.

#Using rank to remove cycles. 

'''
Imagine you have a current path of length k during a DFS. 
The nodes on the path has increasing ranks from 0 to kand incrementing by 1. 
Surprisingly, your next visit finds a node that has a rank of p where 0 <= p < k.
Why does it happen? Aha! You found a node that is on the current search path! 
That means, congratulations, you found a cycle!
'''

'''
But only the current level of search knows it finds a cycle. 
How does the upper level of search knows, if you backtrack? 
Let's make use of the return value of DFS: dfs function returns the minimum rank it finds.
During a step of search from node u to its neighbor v, if dfs(v) returns something smaller than or equal to rank(u), 
then u knows its neighbor v helped it to find a cycle back to u or u's ancestor. 
So u knows it should discard the edge (u, v) which is in a cycle.
'''

import collections
class Solution(object):
    def criticalConnections(self, n, connections):
        def makeGraph(connections):
            graph = collections.defaultdict(list)
            for conn in connections:
                graph[conn[0]].append(conn[1])
                graph[conn[1]].append(conn[0])
            return graph

        graph = makeGraph(connections)
        connections = set(map(tuple, (map(sorted, connections))))
        rank = [-2] * n

        def dfs(node, depth):
            if rank[node] >= 0:
                # visiting (0<=rank<n), or visited (rank=n)
                return rank[node]
            rank[node] = depth
            min_back_depth = n
            for neighbor in graph[node]:
                if rank[neighbor] == depth - 1: #This is only true, if the neighbor is parent of the node.
                    continue  # don't immmediately go back to parent. that's why i didn't choose -1 as the special value, in case depth==0.
                back_depth = dfs(neighbor, depth + 1)
                if back_depth <= depth:
                    connections.discard(tuple(sorted((node, neighbor))))
                min_back_depth = min(min_back_depth, back_depth)
            return min_back_depth
            
        dfs(0, 0)  # since this is a connected graph, we don't have to loop over all nodes.
        return list(connections)

