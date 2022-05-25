# Mini-DMRC

### Problem Statement

This project finds the effective cost and time by choosing the shortest path among different metro lines using the Dijkstra algorithm. Dijkstra’s Algorithm is used to find the shortest path between nodes in a graph which in this case represents a network of metro stations.

### Reason to choose the topic

The motivation behind this project is to facilitate the journey of a common man in a crowded city like Delhi and understanding the complexities of its vast subway-like public transportation network.

As an outsider, one had to face enormous challenges understanding the DMRC network and had to literally sit down with its maps every time they wanted to go somewhere. Seeing that complex map can cause headaches in one’s brain so we decided to make a metro assistant which can help the user to have the perfect route where he/she desires to reach.
### Objective and scope of the project

In India, metro is one of the sectors that is growing in popularity as more commuters seek a reliable form of public transportation. The expectations, needs, and challenges to keep up with are at an all-time high, with the Union Budget for this year exposing a multitude of potential for the Metro Rail Industry. According to experts, utilising existing data insights and solutions to improve automation and assure safety and sustainability is critical in Metro Rail. It is also apparent that digital transformation will help with this.

### Methodology

This tool will function as an assistant to the user providing them with the fastest and shortest path to get from one station to another. The tool will also calculate the price of the journey. The user gives their origin and destination stations as an input and the tool finds the path for them.
```
I.	Overview of steps involved in producing the result
Gathering and bringing the data into the codebase:
•	The gathering of information such as names of stations, names of lines and connection between the lines and storing them into text files.  
•	Reading the Data into workable graphs which can be used to define the metro connections and network. The code for this is attached in the below process.  
•	Getting the inputs in starting and ending stations.  Finding the lines associated with the stations given by the user.  
•	Finding connection between those lines using the maps and graphs generated in the previous steps.  
•	Finding the most optimal path using the stations no to calculate the distance in the fashion of A* algorithm as it is used both the cost of reaching a given point and cost of the future journey into consideration.  
•	Representing the output as a set of line changes and stations at which it happens to reach from source to destination. 
II.	Data gathering and explanation of the gathered data
We collected the following data items: 
•	Names of all the stations. (stationname.txt)
•	 Colour codes of the stations. (colorcodes.txt)
•	The station no. that station has on the given line. (distvalues.txt)
```
### Hardware & Software requirements

Operating System: Windows 11/10(64-bit)
Compiler: C++ Compiler: MinGW gcc x64 (could work on others, not tested)
IDE Used: Visual Studio Code 
### Contribution that the project will be able to make

It will make things very easy for the new travellers to use the metro and would also help them to know from where to change the station and what path the metro will follow. It would be time efficient. The users would not have to ask others and can use this application to know about the path to follow.
