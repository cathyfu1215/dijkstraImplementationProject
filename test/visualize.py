"""
Graph visualization of cities and distances
(for Homework 9 - Dijkstra's Algorithm and Graphs, CS 5008)
Use this script to help visualize the graph of cities and distances
and the shortest path between two cities. It will help you test your implementation.
"""

import matplotlib.pyplot as plt
import networkx as nx
import argparse


def parse_arguments():
    """
    Parse command-line arguments
    """
    parser = argparse.ArgumentParser(description='Visualize a graph of cities and distances.')
    parser.add_argument('-c', dest='cities', required=True, help='Path to the cities file')
    parser.add_argument('-d', dest='distances', required=True, help='Path to the distances file')
    parser.add_argument('-f', dest='from_city', required=True, help='City to start from')
    parser.add_argument('-t', dest='to_city', required=True, help='City to end at')
    return parser.parse_args()


def visualize_graph(cities_file, distances_file, from_city, to_city):
    """
    Visualize the graph of cities and distances
    """
    # Create a new figure with a specified size (width, height)
    plt.figure(figsize=(15, 15))  # Adjust the values as needed

    # Create a directed graph
    G = nx.DiGraph()

    # Read cities from file and add them as nodes in the graph
    with open(cities_file, 'r') as file:
        for city in file:
            G.add_node(city.strip())

    # Read distances from file and add them as edges with weights
    with open(distances_file, 'r') as file:
        for line in file:
            parts = line.strip().split()
            if len(parts) == 3:
                src, dst, weight = parts
                G.add_edge(src, dst, weight=int(weight))

    # Drawing the graph
    pos = nx.spring_layout(G, seed=42)  # For consistent layout
    nx.draw_networkx_nodes(G, pos, node_size=700, node_color='lightblue')
    nx.draw_networkx_edges(G, pos, edgelist=G.edges(), edge_color='black', arrows=True, arrowstyle='->', arrowsize=20)
    nx.draw_networkx_labels(G, pos, font_size=12, font_family='sans-serif')

    edge_labels = dict([((u, v,), d['weight']) for u, v, d in G.edges(data=True)])
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, label_pos=0.3)

    # Add dijkstra path
    try:
        path = nx.dijkstra_path(G, from_city, to_city)
        path_edges = list(zip(path, path[1:]))
        nx.draw_networkx_edges(G, pos, edgelist=path_edges, edge_color='red', arrows=True, arrowstyle='->', arrowsize=20)
    except nx.NetworkXNoPath:
        print(f'No path found from {from_city} to {to_city}')

    plt.axis('off')
    plt.tight_layout()

    # Save the graph to a file
    plt.savefig('graph.png')


def main():
    args = parse_arguments()
    visualize_graph(args.cities, args.distances, args.from_city, args.to_city)


if __name__ == '__main__':
    main()
