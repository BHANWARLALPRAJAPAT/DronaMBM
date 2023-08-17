#include <iostream>
#include <string>
#include <vector>
using namespace std;
int neighbour[5] = {-1, 0, 1, 0, -1}; // NESW
enum direction {N,E,S,W} dir; // Represent Direction of Robot
vector<vector<char>> mp = {
    //       0    1    2    3    4    5    6    7    8    9   10   11   12    13  14   15   16   17
    /* 0*/ {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    /* 1*/ {' ', '*', ' ', '*', '*', '*', '*', '*', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', ' '},
    /* 2*/ {' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' '},
    /* 3*/ {' ', '*', '*', '*', ' ', '*', ' ', '*', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' '},
    /* 4*/ {' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', '*', ' ', '*', '*', '*', ' ', '*', ' '},
    /* 5*/ {' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' '},
    /* 6*/ {' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' '},
    /* 7*/ {' ', ' ', ' ', ' ', ' ', '*', ' ', '*', '*', '*', '*', ' ', '*', ' ', '*', ' ', '*', ' '},
    /* 8*/ {' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' '},
    /* 9*/ {' ', '*', '*', '*', '*', '*', ' ', '*', '*', '*', ' ', ' ', '*', ' ', '*', ' ', '*', ' '},
    /*10*/ {' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' '},
    /*11*/ {' ', '*', ' ', '*', '*', '*', '*', '*', ' ', '*', '*', '*', '*', '*', '*', ' ', '*', ' '},
    /*12*/ {' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' '},
    /*13*/ {' ', 'S', ' ', 'G', '*', '*', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' '},
    /*14*/ {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
vector<vector<char>> mp2 = {
    {' ', ' ', ' ', ' ', ' '},
    {' ', '*', '*', '*', ' '},
    {' ', '*', ' ', '*', ' '},
    {' ', 'S', ' ', 'G', ' '},
    {' ', ' ', ' ', ' ', ' '},
};
int startRow = mp.size() - 2, startColoum = 1;
int currPos[2] = {startRow, startColoum};
void findMinPath(const vector<vector<char>> &mp, string &path){
    for (short i = 0; i < 4; i++){
        if (mp[currPos[0] + neighbour[i]][currPos[1] + neighbour[(i + 1) % 4]] != ' '){
            dir = direction(i);
            if (i % 2 == 0)
                currPos[0] += neighbour[i];
            else
                currPos[1] += neighbour[(i + 1) % 4];
            break;
        }
    }
    int pathSize = 0;
    while (mp[currPos[0]][currPos[1]] != 'G'){
        uint8_t count = 0;
        for (short i = 0; i < 3; i++)
            if (mp[currPos[0] + neighbour[(dir + i + 3) % 4]][currPos[1] + neighbour[(i + dir) % 4]] != ' ')
                count += (1 << (2 - i));
        switch (count){
            case 0:
                currPos[0] += neighbour[(dir + 2) % 4];
                currPos[1] += neighbour[(dir + 3) % 4];
                path.push_back('O');
                pathSize++;
                dir = direction((dir + 2) % 4);
            break;
            case 1:

                currPos[0] += neighbour[(dir + 1) % 4];
                currPos[1] += neighbour[(dir + 2) % 4];
                dir = direction((dir + 1) % 4);
            break;
            case 3:
                path.push_back('S');
                pathSize++;
            case 2:
                currPos[0] += neighbour[dir];
                currPos[1] += neighbour[(dir + 1) % 4];
            break;

            case 5:
            case 6:
            case 7:
                path.push_back('L');
                pathSize++;
            case 4:
                currPos[0] += neighbour[(dir + 3) % 4];
                currPos[1] += neighbour[dir];
                dir = direction((dir + 3) % 4);
                break;
            default:
                return;
        }
        if (pathSize >= 3 && path[pathSize - 2] == 'O'){
            string substring = path.substr(pathSize - 3, 3);
            path = path.substr(0, pathSize - 3);
            if (substring == "SOL" || substring == "LOS")
                path += 'R';
            else if (substring == "ROL" || substring == "LOR" || substring == "SOS")
                path += 'O';
            else if (substring == "LOL" || substring == "ROR")
                path += 'S';
            else if (substring == "SOR" || substring == "ROS")
                path += 'L';
            pathSize -= 2;
        }
    }
}
void applyMinPath(vector<vector<char>> &mp, const string &path){
    currPos[0] = startRow, currPos[1] = startColoum;
    int pathIndex = 0;
    for (int i = 0; i < 4; i++){
        if (mp[currPos[0] + neighbour[i]][currPos[1] + neighbour[(i + 1) % 4]] != ' '){
            dir = direction(i);
            if (i % 2 == 0)
                currPos[0] += neighbour[i];
            else
                currPos[1] += neighbour[(i + 1) % 4];
            mp[currPos[0]][currPos[1]] = '#';
            break;
        }
    }
    while (mp[currPos[0]][currPos[1]] != 'G')
    {
        short count = 0;
        for (int i = 0; i < 3; i++)
            if (mp[currPos[0] + neighbour[(dir + i + 3) % 4]][currPos[1] + neighbour[(i + dir) % 4]] != ' ')
                count += (1 << (2 - i));
        switch (count){
        case 0:
            cout << "Rotational Error";
            return;
        case 1:
            currPos[0] += neighbour[(dir + 1) % 4];
            currPos[1] += neighbour[(dir + 2) % 4];
            dir = direction((dir + 1) % 4);
            break;
        case 2:
            currPos[0] += neighbour[dir];
            currPos[1] += neighbour[(dir + 1) % 4];
            break;
        case 4:
            currPos[0] += neighbour[(dir + 3) % 4];
            currPos[1] += neighbour[dir];
            dir = direction((dir + 3) % 4);
            break;
        case 3:
        case 5:
        case 6:
        case 7:
            if (path[pathIndex] == 'L'){
                currPos[0] += neighbour[(dir + 3) % 4];
                currPos[1] += neighbour[dir];
                dir = direction((dir + 3) % 4);
            }
            else if (path[pathIndex] == 'S'){
                currPos[0] += neighbour[dir];
                currPos[1] += neighbour[(dir + 1) % 4];
            }
            else if (path[pathIndex] == 'R'){
                currPos[0] += neighbour[(dir + 1) % 4];
                currPos[1] += neighbour[(dir + 2) % 4];
                dir = direction((dir + 1) % 4);
            }
            pathIndex++;
            break;
        }
        if (mp[currPos[0]][currPos[1]] != 'G')
            mp[currPos[0]][currPos[1]] = '#';
    }
}
int main()
{
    string MinPathString;
    findMinPath(mp, MinPathString);
    applyMinPath(mp, MinPathString);
    for (int i = 0; i < mp.size(); i++){
        for (int j = 0; j < mp[0].size(); j++)
            cout << mp[i][j] << " ";
        cout << endl;
    }
    return 0;
}

// N -> 0 -> (3,0),(0,1), (1,2)
// E -> 1 -> (0,1),(1,2), (2,3)
// S -> 2 -> (1,2), (2,3),(3,0)
// W -> 3 -> (2,3),(3,0), (0,1)
// N {0,-1},{-1,0}, {0,1}     {1, 0} {-1, 0, 1, 0}
// E {-1,0},{0,1} , {1,0}     {0,-1}
// S {0,1} ,{1,0} ,{0,-1}     {-1,0}
// W {1,0} ,{0,-1} ,{-1,0}    {0, 1}

// LSOLOLLLOSLSOLLOLOLOLLSLOL

// SOL -> R
// ROL -> O
// LOL -> S
