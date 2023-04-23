def dfs_limit(graph, start, end, depth_limit):
    stack = [(start, 0)]
    visited = set([start]) 
    
    while stack:
        node, depth = stack.pop() 
        print(f"->{node}", end ="")
        if node == end: 
            return True
        if depth < depth_limit: 
            for neighbor in graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    stack.append((neighbor, depth+1))
    
    return False 

    


def iddfs(graph, start, end):
    depth_limit = 0
    while True:
        if dfs_limit(graph, start, end, depth_limit):
            return depth_limit
        depth_limit += 1
        print("")

graph = {
    '1': ['2', '6', '7'],
    '2': ['4', '3'],
    '3': [],
    '4': ['5'],
    '5': [],
    '6': [],
    '7': ['8', '11'],
    '8': ['9', '10'],
    '9': [],
    '10': [],
    '11': []
}

start_node = '1'
end_node = '5'

min_depth = iddfs(graph, start_node, end_node)
print("")
