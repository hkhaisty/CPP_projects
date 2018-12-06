#include <iostream>
#include <string>
#include <stack>
#include <cstring>

using namespace std;

template<class T>
class Stack : public stack<T> {

public:
    //pop top element off of stack
    T pop() {
        T tmp = Stack::top();
        stack<T>::pop();
        return tmp;
    }
};

class Cell {
public:
    //sets value of element position in matrix of maze
    Cell(int i = 0, int j = 0) {
        x = i;
        y = j;
    }

    //evaluates elements in cell
    bool operator==(const Cell &c) const {
        return x == c.x && y == c.y;
    }

private:
    int x, y;

    //Maze class can access private&protected members of "Cell"
    friend class Maze;
};

class Maze {
public:
   //calls maze
    Maze();

    void exitMaze();

private:
    //declares three variables of type Cell
    Cell currentCell, exitCell, entryCell;
    //sets constant the static values of the maze
    const char exitMarker, entryMarker, visited, passage, wall;
    //calls template
    Stack<Cell> mazeStack;
    char **store;

    //calls push univisited method
    void pushUnvisited(int, int);

    //declare rows and columns variables
    int rows, cols;


    friend ostream &operator<<(ostream &out, const Maze &maze) {
        for (int row = 0; row <= maze.rows + 1; row++)
            out << maze.store[row] << endl;
        out << endl;
        return out;
    }
};

//constructs maze and defines markers as static values in maze
Maze::Maze() : exitMarker('e'), entryMarker('m'), visited('.'),
               passage('0'), wall('1') {
    //calls generic template
    Stack<char *> mazeRows;
    //pointer to new character
    char str[80], *s;

    int col, row = 0;
    cout << "Enter a rectangular maze using the following "
         << "characters:\nm - entry\ne - exit\n1 - wall\n0 - passage\n"
         << "Enter one line at at time; end with Ctrl-z:\n";

    //sentinal value for char user input
    char user_input = 'D';

    //sets conditional for continued maze creation
    while (cin >> str) {

        //prompt user to exit maze (theoretically)
        cout << "Do you wish to complete your maze? (Y/N): ";
        cin >> user_input;

        if (user_input != 'n')
            break;

        row++;
        cols = strlen(str);
        s = new char[cols + 3];
        mazeRows.push(s);
        strcpy(s + 1, str);
        s[0] = s[cols + 1] = wall;
        s[cols + 2] = '\0';
        if (strchr(s, exitMarker) != 0) {
            exitCell.x = row;
            exitCell.y = static_cast<int>(strchr(s, exitMarker) - s);
        }
        if (strchr(s, entryMarker) != 0) {
            entryCell.x = row;
            entryCell.y = static_cast<int>(strchr(s, entryMarker) - s);
        }
    }

    rows = row;
    store = new char *[rows + 2];
    store[0] = new char[cols + 3];
    for (; !mazeRows.empty(); row--) {
        store[row] = mazeRows.pop();
    }
    store[rows + 1] = new char[cols + 3];
    store[0][cols + 2] = store[rows + 1][cols + 2] = '\0';
    for (col = 0; col <= cols + 1; col++) {
        store[0][col] = wall;
        store[rows + 1][col] = wall;
    }
}

void Maze::pushUnvisited(int row, int col) {
    if (store[row][col] == passage || store[row][col] == exitMarker) {
        mazeStack.push(Cell(row, col));
    }
}

void Maze::exitMaze() {
    int row, col;
    currentCell = entryCell;
    while (!(currentCell == exitCell)) {
        row = currentCell.x;
        col = currentCell.y;
        cout << *this;
        if (!(currentCell == entryCell))
            store[row][col] = visited;
        pushUnvisited(row - 1, col);
        pushUnvisited(row + 1, col);
        pushUnvisited(row, col - 1);
        pushUnvisited(row, col + 1);
        if (mazeStack.empty()) {
            cout << *this;
            cout << "Failure\n";
            return;
        } else currentCell = mazeStack.pop();
    }
    cout << *this;
    cout << "Success\n";
}

int main() {
    Maze().exitMaze();
    return 0;
}
