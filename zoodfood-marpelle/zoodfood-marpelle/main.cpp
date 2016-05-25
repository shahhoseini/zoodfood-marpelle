//
//  main.cpp
//  zoodfood-marpelle
//
//  Created by Soroush Shahhoseini on 3/5/1395 AP.
//  Copyright © 1395 AP Shahho. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define SIZE 256
#define WIN_PRIZE 4000
#define TURNS_COUNT 60

using namespace std;

//cellid cellType cellColor nextCellId,...
string cellRawDatas = "0 3 0 0,1 3 0 1,2 0 0 19,3 3 0 3,4 3 0 4,5 3 1000 5,6 0 0 57,7 3 0 7,8 3 0 8,9 3 0 9,10 3 100 10,11 3 0 11,12 3 0 12,13 3 0 13,14 3 0 14,15 3 400 15,16 3 0 16,17 3 0 17,18 0 0 53,19 3 1000 19,20 3 0 20,21 3 0 21,22 3 0 22,23 3 0 23,24 3 100 24,25 3 0 25,26 3 0 26,27 3 0 27,28 3 200 28,29 3 0 29,30 3 0 30,31 3 400 31,32 0 0 67,33 3 400 33,34 3 0 34,35 3 0 35,36 3 200 36,37 3 0 37,38 3 0 38,39 0 0 94,40 3 0 40,41 3 100 41,42 3 0 42,43 3 0 43,44 3 0 44,45 0 0 81,46 3 0 46,47 3 0 47,48 3 0 48,49 3 100 49,50 3 0 50,51 3 200 51,52 3 0 52,53 3 0 53,54 3 0 54,55 0 0 89,56 3 0 56,57 3 1000 57,58 3 0 58,59 3 0 59,60 3 0 60,61 3 0 61,62 3 0 62,63 3 0 63,64 3 0 64,65 3 0 65,66 3 0 66,67 3 400 67,68 3 0 68,69 3 0 69,70 3 0 70,71 3 0 71,72 3 0 72,73 3 200 73,74 3 0 74,75 3 0 75,76 3 0 76,77 3 0 77,78 3 0 78,79 3 0 79,80 3 0 80,81 3 200 81,82 3 0 82,83 3 0 83,84 3 0 84,85 3 400 85,86 3 0 86,87 3 0 87,88 3 0 88,89 3 0 89,90 3 0 90,91 3 0 91,92 3 0 92,93 3 0 93,94 3 1000 94,95 3 0 95,96 3 0 96,97 3 0 97,98 3 0 98,99 3 0 99,100 3 0 100,101 3 100 101,102 0 0 131,103 3 0 103,104 3 0 104,105 3 0 105,106 3 0 106,107 3 0 107,108 0 0 145,109 3 0 109,110 3 0 110,111 3 0 111,112 3 0 112,113 3 0 113,114 3 0 114,115 3 100 115,116 3 0 116,117 3 0 117,118 3 0 118,119 3 0 119,120 3 400 120,121 3 0 121,122 3 0 122,123 3 0 123,124 3 0 124,125 3 0 125,126 3 0 126,127 3 0 127,128 3 0 128,129 3 0 129,130 3 0 130,131 3 200 131,132 3 0 132,133 3 0 133,134 1 0 103,135 3 0 135,136 3 0 136,137 3 0 137,138 3 0 138,139 3 0 139,140 3 0 140,141 3 0 141,142 3 0 142,143 3 0 143,144 3 0 144,145 3 0 145,146 1 0 116,147 3 0 147,148 3 1000 148,149 3 0 149,150 3 0 150,151 3 0 151,152 3 100 152,153 3 0 153,154 3 0 154,155 3 0 155,156 3 0 156,157 3 0 157,158 3 0 158,159 3 0 159,160 3 0 160,161 3 0 161,162 3 0 162,163 3 0 163,164 3 0 164,165 3 400 165,166 3 0 166,167 3 0 167,168 3 0 168,169 3 0 169,170 3 0 170,171 3 0 171,172 3 0 172,173 3 0 173,174 3 0 174,175 3 0 175,176 3 0 176,177 3 0 177,178 3 0 178,179 3 0 179,180 3 0 180,181 3 0 181,182 3 200 182,183 3 0 183,184 3 0 184,185 3 0 185,186 3 0 186,187 3 0 187,188 3 0 188,189 3 100 189,190 3 0 190,191 3 0 191,192 3 200 192,193 3 0 193,194 3 0 194,195 3 1000 195,196 3 0 196,197 0 0 225,198 3 0 198,199 3 0 199,200 3 0 200,201 3 0 201,202 3 0 202,203 3 0 203,204 3 100 204,205 0 0 237,206 3 0 206,207 3 0 207,208 3 0 208,209 3 100 209,210 3 0 210,211 3 0 211,212 3 0 212,213 3 0 213,214 0 0 230,215 3 100 215,216 3 0 216,217 3 0 217,218 3 0 218,219 3 0 219,220 3 0 220,221 3 0 221,222 3 0 222,223 3 0 223,224 3 0 224,225 3 100 225,226 3 0 226,227 3 0 227,228 1 0 195,229 3 0 229,230 3 0 230,231 1 0 168,232 3 0 232,233 3 0 233,234 3 0 234,235 3 0 235,236 3 0 236,237 3 0 237,238 3 0 238,239 3 0 239,240 3 0 240,241 3 0 241,242 3 0 242,243 1 0 213,244 3 200 244,245 3 0 245,246 3 0 246,247 3 0 247,248 3 0 248,249 3 0 249,250 1 0 221,251 3 400 251,252 3 0 252,253 3 0 253,254 1 0 224,11220";


enum cellType {Ladder, Snake, Color, Normal};
enum colorType {Red = 1000, Orange = 400, Green = 200, Blue = 100, White = 0};

class Cell {
public:
    
    Cell(int id, int type = Normal, int colorStr = White, int nextMove = -1) {
        this->cellId = id;
        this->type = (cellType)type;
        this->color = (colorType)colorStr;
        if (nextMove == -1) {
            this->nextCellId = id;
        } else {
            this->nextCellId = nextMove;
        }
    }
    
    Cell(int id, cellType type, string colorStr, int nextMove) {
        
        if (colorStr == "red") {
            this->color = Red;
        }
        else if (colorStr == "blue") {
            this->color = Blue;
        }
        else if (colorStr == "orange") {
            this->color = Orange;
        }
        else if (colorStr == "green") {
            this->color = Green;
        }
        
        this->type = type;
        this->cellId = id;
        this->nextCellId = nextMove;
    }
    
    cellType type;
    colorType color;
    int nextCellId;
    int cellId;
};

using namespace std;

vector<Cell>cells;
// this array will help to prevent
int precalculateds[255][TURNS_COUNT];


int round_move(int move_no, int cellindex, int possible_moves) {
    
    int remained_moves = possible_moves + 1 - move_no;
    
    if (cellindex >= SIZE) {
        int result = remained_moves == 0 ? WIN_PRIZE + (256) * 10: 0;
        return result;
    }

    Cell finalCell = cells[cells[cellindex].nextCellId];
    
    if (precalculateds[cellindex][remained_moves] != -1) {
        return precalculateds[cellindex][remained_moves];
    }
    
    if (remained_moves == 0) {
        
        int result = finalCell.color + (finalCell.cellId+1) * 10;
        
        precalculateds[cellindex][remained_moves] = result;
        return result;
    }
    
    int max = 0;
    int max_index = 0;
    
    for (int i=1; i<=6; i++) {
        
        int nextresult = round_move(move_no+1, finalCell.cellId+i, possible_moves) + cells[cells[cellindex < SIZE ? cellindex : SIZE-1].nextCellId].color;
        
        if (nextresult > max) {
            max = nextresult;
            max_index =  finalCell.cellId + i;
        }
    }
    
    precalculateds[cellindex][remained_moves] = max;
    
    return max;
}

int main(int argc, const char * argv[]) {
    
    for (int i = 0; i<SIZE; i++) {
        for (int j = 0; j<TURNS_COUNT; j++) {
            precalculateds[i][j] = -1;
        }
    }
    
    stringstream sstream = stringstream(cellRawDatas);
    for (int i=0; i<SIZE; i++) {
        string line;
        getline(sstream, line, ',');
        stringstream lineStream = stringstream(line);
        int id, nextCellId, color, type;
        lineStream >> id >> type >> color >> nextCellId;
        Cell cell = Cell(id, type, color, nextCellId);
        cells.push_back(cell);
    }
    
    for (int i =1; i<=60; i++) {
        std::cout << i << " turn: " << round_move(1,0,i) << endl;
        for (int i = 0; i<SIZE; i++) {
            for (int j = 0; j<TURNS_COUNT; j++) {
                precalculateds[i][j] = -1;
            }
        }
    }
    
    return 0;
}