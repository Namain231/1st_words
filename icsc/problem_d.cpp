#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdexcept>
#include <sstream>

using namespace std;
/**
 * Generate a 10x10 word search puzzle containing the given words.
 * 
 * @param words A vector of strings to include in the puzzle.
 * @return A 2D vector of chars representing the word search puzzle.
 **/

vector<vector<char>> create_crossword(const vector<string>& words) {

    // Create a 10x10 grid initialized with '.'
    vector<vector<char>> grid(10, vector<char>(10, '.'));

    for (const string& word : words) {
        if (word.length() > 10) {
            throw runtime_error("Word too long to fit in the grid");
        }
        
        bool placed = false;
        for (int attempt = 0; attempt < 100 && !placed; ++attempt) {
            int direction = rand() % 6; // 0: horizontal, 1: vertical, 2: diagonal (top-left to bottom-right), 3: diagonal (bottom-right to top-left), 4: diagonal (top-right to bottom-left), 5: diagonal (bottom-left to top-right)
            int row = rand() % 10; // random row
            int col = rand() % 10; // random column
            
            if (direction == 0) { // Horizontal placement
                if (col + word.length() <= 10) {
                    bool canPlace = true;
                    for (size_t i = 0; i < word.length(); ++i) {
                        if (grid[row][col + i] != '.' && grid[row][col + i] != word[i]) {
                            canPlace = false; //cell is occupied by a different letter
                            break;
                        }
                    }
                    if (canPlace) {
                        for (size_t i = 0; i < word.length(); ++i) {
                            grid[row][col + i] = word[i];
                        }
                        placed = true;
                    }
                }
            } else if (direction == 1) { // Vertical placement
                if (row + word.length() <= 10) {
                    bool canPlace = true;
                    for (size_t i = 0; i < word.length(); ++i) {
                        if (grid[row + i][col] != '.' && grid[row + i][col] != word[i]) {
                            canPlace = false;
                            break;
                        }
                    }
                    if (canPlace) {
                        for (size_t i = 0; i < word.length(); ++i) {
                            grid[row + i][col] = word[i];
                        }
                        placed = true;
                    }
                }
            } else if (direction == 2) { // Diagonal placement (top-left to bottom-right)
                if (row + word.length() <= 10 && col + word.length() <= 10) {
                    bool canPlace = true;
                    for (size_t i = 0; i < word.length(); ++i) {
                        if (grid[row + i][col + i] != '.' && grid[row + i][col + i] != word[i]) {
                            canPlace = false;
                            break;
                        }
                    }
                    if (canPlace) {
                        for (size_t i = 0; i < word.length(); ++i) {
                            grid[row + i][col + i] = word[i];
                        }
                        placed = true;
                    }
                }
            } else if (direction == 3) { // Diagonal placement (bottom-right to top-left)
                if (row - static_cast<int>(word.length()) + 1 >= 0 && col - static_cast<int>(word.length()) + 1 >= 0) {
                    bool canPlace = true;
                    for (size_t i = 0; i < word.length(); ++i) {
                        if (grid[row - i][col - i] != '.' && grid[row - i][col - i] != word[i]) {
                            canPlace = false;
                            break;
                        }
                    }
                    if (canPlace) {
                        for (size_t i = 0; i < word.length(); ++i) {
                            grid[row - i][col - i] = word[i];
                        }
                        placed = true;
                    }
                }
            } else if (direction == 4) { // Diagonal placement (top-right to bottom-left)
                if (row + word.length() <= 10 && col - static_cast<int>(word.length()) + 1 >= 0) {
                    bool canPlace = true;
                    for (size_t i = 0; i < word.length(); ++i) {
                        if (grid[row + i][col - i] != '.' && grid[row + i][col - i] != word[i]) {
                            canPlace = false;
                            break;
                        }
                    }
                    if (canPlace) {
                        for (size_t i = 0; i < word.length(); ++i) {
                            grid[row + i][col - i] = word[i];
                        }
                        placed = true;
                    }
                }
            } else if (direction == 5) { // Diagonal placement (bottom-left to top-right)
                if (row - static_cast<int>(word.length()) + 1 >= 0 && col + word.length() <= 10) {
                    bool canPlace = true;
                    for (size_t i = 0; i < word.length(); ++i) {
                        if (grid[row - i][col + i] != '.' && grid[row - i][col + i] != word[i]) {
                            canPlace = false;
                            break;
                        }
                    }
                    if (canPlace) {
                        for (size_t i = 0; i < word.length(); ++i) {
                            grid[row - i][col + i] = word[i];
                        }
                        placed = true;
                    }
                }
            }
        }
        if (!placed) {
            throw runtime_error("Failed to place all words in the grid");
        }
    }

    // Fill remaining '.' with random letters
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == '.') {
                grid[i][j] = 'A' + rand() % 26; // Random letter from A to Z
            }
        }
    }
    
    return grid;
}



// --- Main execution block. DO NOT MODIFY.  ---
int main() {
    try {
        // Seed random number generator
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        
        // Read words from first line (comma-separated)
        std::string wordsInput;
        std::getline(std::cin, wordsInput);
        
        std::vector<std::string> words;
        std::stringstream ss(wordsInput);
        std::string word;
        
        // Parse comma-separated words
        while (std::getline(ss, word, ',')) {
            // Trim whitespace
            word.erase(0, word.find_first_not_of(" \t\r\n"));
            word.erase(word.find_last_not_of(" \t\r\n") + 1);
            
            if (!word.empty()) {
                words.push_back(word);
            }
        }
        
        // Generate the word search puzzle
        std::vector<std::vector<char>> puzzle = create_crossword(words);
        
        // Print the result as a 2D grid
        for (const auto& row : puzzle) {
            for (char c : row) {
                std::cout << c;
            }
            std::cout << std::endl;
        }
        
    } catch (const std::runtime_error& e) {
        std::cerr << "Input Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}