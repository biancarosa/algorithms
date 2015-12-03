import java.io.IOException;
import java.lang.System;
import java.util.List;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class DepthFirstSearch {
    public static void main(String[] args) {
        InputHandler inputHandler = new InputHandler();
        try {
            inputHandler.readInput();
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

    public void addEdge(int u, int v) {
        this.graph[u][v] = true;
        this.graph[v][u] = true;
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


class InputHandler {
    public void readInput() throws IOException {
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

      //  graph.print();
    }
}