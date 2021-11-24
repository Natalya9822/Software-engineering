'''
Алгоритм Дейкстры
Граф размером:6*6
Индекс начинается с 0
'''
import numpy as np

graph_list = [[0, 30, 20, 50, 20, 30],
              [20, 0, 30, 40, 50, 20],
              [40, 20, 0, 20, 40, 20],
              [30, 40, 20, 0, 40, 50],
              [20, 50, 20, 60, 0, 20],
              [40, 60, 50, 40, 20, 0]]


def dijkstra(graph, src):
    visited = []
    dist = {src: 0}
    node = list(range(len(graph[0])))
    if src in node:
        node.remove(src)
        visited.append(src)
    else:
        return None
    for i in node:
        dist[i] = graph[src][i]
    prefer = src
    while node:
        _dist = float('inf')
        for i in visited:
            for j in node:
                if graph[i][j] > 0:
                    if _dist > dist[i] + graph[i][j]:
                        _dist = dist[j] = dist[i] + graph[i][j]
                        prefer = j
        visited.append(prefer)
        node.remove(prefer)
    return dist


if __name__ == '__main__':
    dist = dijkstra(graph_list, 0)
    print(dist)