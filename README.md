1.How did you represent the social network?  Why did you choose this representation?<br>
<br>The social network was represented as an unweighted undirected graph.
<br>An user is represented as a vertex in the graph.
<br>The friendship between two users is represented as an edge in the graph.
<br>I have chosen this representation because it is the simplest way to understand and to explain the concept of a social network.
<br><br><br>2.What algorithm did you use to compute the shortest chain of friends?  What alternatives did you consider?  Why did you choose this algorithm over the alternatives?
<br><br>I have chosen a variant of the breadth-first-search algorithm in order to compute the shortest chain of friends because of its complexity,
big O(|V| + |E|), |V| being the number of vertices in a graph and |E| the edges in it.
There is no need to use other algorithms, such as Dijkstra, or Bellman-Ford because there are no negative weights and the graph is also unweighted and undirected.
<br><br><br>3. Please enumerate the test cases you considered and explain their relevance.
<br>Test cases I've considered:
<br>1. An empty social network (no users and no chain to be found);
<br>2. A social network with only one user (no chain to be found);
<br>3. Trying to find a chain from an user to itself (we cannot create an edge from a vertex to itself in an undirected graph);
<br>4. Trying to find a chain between two users that are directly connected (distance 1 chain);
<br>5. Trying to find a chain between to users that are not connected indirectly at all (no chain can be found);
<br>6. Simple success case with chain distance >= 2;
<br>7. Trying to create users with no genericUsername;
<br>8. Trying to create a friendship relationship from a user to itself.

*The solution could have been much simpler, this is just me having a bit of fun, trying to make use of smart pointers and creating UT as it should look in a C++ project
