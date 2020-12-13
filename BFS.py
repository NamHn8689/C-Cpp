# sample graph implemented as a dictionary
# graph = {'A': ['B', 'C', 'D'],
#          'B': ['M', 'N'],
#          'M': ['X', 'Y'],
#          'X': [],
#          'Y': ['R', 'S'],
#          'R': [],
#          'S': [],
#          'N': ['U', 'V'],
#          'U': [],
#          'V': ['G', 'H'],
#          'C': ['L'],
#          'L': [],
#          'D': ['O', 'P'],
#          'O': ['I', 'J'],
#          'I': [],
#          'J': [],
#          'P': []
#          }

def inputGraph():
    d = {}
    i = 0
    while True:
        keys = input(f'input node[{i}]: ')  # here i have taken keys as strings
        if keys == '-1':
            break
        values = list(input(f'->value node[{i}]: ').split(' '))  # here i have taken values as integers
        d[keys] = values
        i += 1
    return d
# visits all the nodes of a graph (connected component) using BFS
def bfs_connected_component(graph, start):
    # keep track of all visited nodes
    explored = []
    # keep track of nodes to be checked
    queue = [start]

    # keep looping until there are nodes still to be checked
    while queue:
        # pop shallowest node (first node) from queue
        node = queue.pop(0)
        if node not in explored:
            # add node to list of checked nodes
            explored.append(node)
            neighbours = graph[node]

            # add neighbours of node to queue
            for neighbour in neighbours:
                queue.append(neighbour)
    return explored


# finds shortest path between 2 nodes of a graph using BFS
def bfs_shortest_path(graph, start, goal):
    # keep track of explored nodes
    explored = []
    print(f'explored = {explored}')
    # keep track of all the paths to be checked
    queue = [[start]]
    print(f'queue= {queue}')
    # return path if start is goal
    print('-'*30)
    if start == goal:
        return f"Start = goal = {goal}"
    # keeps looping until all possible paths have been checked
    while queue:
        # pop the first path from the queue
        path = queue.pop(0)
        print(f'path = {path}')
        print(f'queue - > pop(0) = {queue}')
        # get the last node from the path
        node = path[-1]
        print(f'Node = {node}')
        print('-'*20)
        if node not in explored:
            print(f'node = {node}')
            neighbours = graph[node]
            print(f'neighbours = {neighbours}')
            # go through all neighbour nodes, construct a new path and
            # push it into the queue
            print('-'*10)
            for neighbour in neighbours:
                print(f'neighbour = {neighbour}')
                new_path = list(path)
                print(f'new path = {new_path}')
                new_path.append(neighbour)
                print(f'new_path = {new_path}')
                # return path if neighbour is goal
                if neighbour == goal:
                    return new_path
                queue.append(new_path)
                print(f'queue = {queue}')
                print('-'*5)

            # mark node as explored
            explored.append(node)
            print('->explored = ', explored)

    # in case there's no path between the 2 nodes
    return "ERR"
if __name__ == '__main__':
    gr = inputGraph()
    start = input('input start: ')
    goal = input('input goal: ')
    # print('-'*20)
    print(bfs_shortest_path(gr, start, goal))
    # print(bfs_connected_component(graph, 'A'))
    # inputGraph()
    # print(graph)