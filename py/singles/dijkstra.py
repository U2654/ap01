# AI generated code
import heapq

def dijkstra(graph, start):
    # Initialize distances and priority queue
    distances = {node: float('infinity') for node in graph}
    distances[start] = 0
    priority_queue = [(0, start)]
    
    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)
        
        if current_distance > distances[current_node]:
            continue
        
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))
    
    return distances

# Example graph represented as an adjacency list
graph = {
    'A': {'B': 23, 'C': 15},
    'B': {'A': 23, 'E': 10},
    'C': {'A': 15, 'E': 8, 'D': 9},
    'D': {'C': 9, 'F': 9},
    'E': {'B': 10, 'C': 8, 'F': 11},
    'F': {'D': 9, 'E': 11}    
}

# Running the algorithm
start_node = 'A'
distances = dijkstra(graph, start_node)
print(distances)
