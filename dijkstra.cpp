//Sasha Morgan
//Major: Computer Engineering and Electrical Engineering
//Minor: Cyber Security and Math
//Class of 2019
//This program will implent dijkstra's shortest path algorithm using
//Dynamic Arraylists and Min Priority Queues
//I tried my best this assignment was very difficult, I really do not want to take this class again
//I was able to get the minpriority queue to work though
//Have a great winter break!

#include "heap_priority_queue.h" //includes the min priority queue
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
	/*
	Information to read from the adjacency list
	*/
	std::ifstream file("graph.csv"); //reads in the graph.csv file
	    string line; //creates a string called line
		int a = 0;
		int count = 0;
		DynamicArrayList<pair<int, int>> input; //creates a vector of inputs
	    while(!file.eof()){ //runs the length of the gile
	        std::getline(file, line); //gets the line
	        string temp = ""; //declares a temporary string to hold value
	        for(int i = 0 ; i <  line.size(); i++){ //runs the size of the line
	            if(line[i] == ','){
	                stringstream s; //takes in a singular value
	                s << temp; //stores the value that proceeds the delimiter
	                int temporaryVar = 0;  //a storage integer value
					int vert = 0; //hold the verticies
					int edge = 0;
	                s >> temporaryVar; //sets the temporary storage integer
					//Based on the structure of the input file, every 4 item including the delimiter will be a vertex
					if (i == a)
					{
						vert = temporaryVar; //sets current item equal
						a = a + 4;//makes the a counter value odd
						count++;
					}
					else
					{
						edge = temporaryVar; //sets the item eqal to an edge
						count++;
					}

					if (count == 2)//Once the loop collects a vertice and edge it will add it to the dynamic array
					{
						input.insert(vert, make_pair(vert, edge));
						count = 0;
					}
	                //input.push_back(temporaryVar);
					
	                temp = "";
	                continue;
	            }
	            if(line[i] != ' '){ //runs to the next line
	                temp += line[i];
	            }
	        }
	    }

		DynamicArrayList<DynamicArrayList<pair<int, int>>> graph;
		int * weights;
		dijkstra(graph, weights);

/*
Creates the output file
*/
		ofstream myfile; 
		myfile.open("weight.csv");//opens the file
		pair<int, int> op = input.getEntry(0); //creates a temporary vector of pairs 
		int a = op.first; //gets the vertice
		int b = op.second; //gets the edges
		myfile << a, b; //displays the two output
		myfile.close(); //closes the file

	
	return 0;
}

void dijkstra(DynamicArrayList<DynamicArrayList<pair<int, int>>> graph, int * weights){
	HeapPriorityQueue<pair<int, int>> q; // first = weight, second = vertexIndex, Creates a queue of pairs

	int n = graph.getLength(); //Determines the amounge of verticies

	for (int v = 0; v < n-1; v++){

		weights[v] = INFINITY; //sets the weights array items equal to infinity
	}

	q.add(make_pair(0, 0)); //inserts vertex 0 into the priority queue with a weight of 0

	while (!q.isEmpty()){ //runs as long as the queue is not empty

		pair<int, int> currentVertexIndex = q.peek(); //creates a temorary storage pair that is equal to the top item in the queue

		q.remove(); //removes the item at the top of the list

		if (currentVertexIndex.first < weights[currentVertexIndex.second]) //if the weight of the first item is less then the weight of the current item
			weights[currentVertexIndex.second] = currentVertexIndex.first; //sets the weight of the current item to be equal to the first item

		int size = graph.getEntry(currentVertexIndex.first).getLength(); //Finds the total amount of verticies that are adjacent to the the v or the first item in the pair
		for (int i = 0; i < size; i++){ //Runs as long as the vertice has adjacents

			//Checks for (w[ u ] > w[ v ] + m[ v ] [ u ] )
			if (weights[graph.getEntry(currentVertexIndex.first).getEntry(i).first] > weights[currentVertexIndex.first] +
				graph.getEntry(currentVertexIndex.first).getEntry(i).second){

				q.add(make_pair(weights[currentVertexIndex.first] +
					graph.getEntry(currentVertexIndex.first).getEntry(i).second,
					graph.getEntry(currentVertexIndex.first).getEntry(i).first)); //adds the item into he queue with w[ v ] + m[ v ] [ u ] propriority

				weights[graph.getEntry(currentVertexIndex.first).getEntry(i).first] =
					weights[currentVertexIndex.first] +
					graph.getEntry(currentVertexIndex.first).getEntry(i).second; //updates the weight vector  to be w[ u ] = w[ v ] + m[ v ] [ u ]
			}
		}
	}
}
