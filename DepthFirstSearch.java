import java.io.IOException;
import java.lang.System;
import java.util.List;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class DepthFirstSearch {
    private static boolean visited[];
    private static Graph graph;

    public static void depthFirstSearch(int w) {
        visited[w] = true;

        for (int i = 1; i <= graph.getVertices(); i++) {
            if (graph.hasPathBetween(w,i)) {
                if (!visited[i]) {
                    depthFirstSearch(i);
                }
            }
        }
    }

    public static void main(String[] args) {
        GraphInputHandler inputHandler = new GraphInputHandler();
        try {
            graph = inputHandler.readInput();
            visited = new boolean[graph.getVertices()+1];
            for (int i = 0; i < graph.getVertices(); ++i) {
                visited[i] = false;
            }
            depthFirstSearch(1);
            for (int i = 0; i < graph.getVertices(); ++i) {
                System.out.println(visited[i]);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}

class Graph {
    private boolean graph[][];
    private int vertices;
    private int edges;

    Graph(int vertices) {
        this.vertices = vertices;
        graph = new boolean[vertices+1][vertices+1];
    }

    public boolean hasPathBetween(int u, int v) {
        return this.graph[u][v];
    }

    public void addEdge(int u, int v) {
        this.graph[u][v] = true;
        this.graph[v][u] = true;
    }

    public int getVertices() {
        return this.vertices;
    }

    public int getEdges() {
        return this.edges;
    }

    void print() {
        for (int i = 1; i < vertices; ++i) {
            for (int j = 1; j < vertices; ++j) {
                System.out.print(graph[i][j]+"  ");
            }
            System.out.print("\n");
        }
    }

}


class GraphInputHandler {
    public Graph readInput() throws IOException {
        System.out.print("Number of vertices: ");
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Integer vertices = Integer.parseInt(reader.readLine());

        Graph graph = new Graph(vertices);

        System.out.print("Number of edges: ");
        Integer edges = Integer.parseInt(reader.readLine());

        System.out.println("Write edges separated by a comma, one per line.");
        for (int i = 1; i <= edges; ++i) {
            System.out.print("Edge #" + i + " ");
            String line = reader.readLine();
            String[] splitted = line.split(",");
            graph.addEdge(Integer.parseInt(splitted[0]), Integer.parseInt(splitted[1]));
        }

        return graph;
    }
}
