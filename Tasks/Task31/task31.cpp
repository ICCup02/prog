#include <iostream>
#include <string>

std::string maze[25] = {
        "####B######################",
        "# #       #   #      #    #",
        "# # # ###### #### ####### #",
        "# # # #       #   #       #",
        "#   # # ######### # ##### #",
        "# # # #   #       #     # #",
        "###########################",
        "# #   #     # #           #",
        "# # #   ####### ###########",
        "# # # #       # #         C",
        "# # ##### ### # # ####### #",
        "# # #     ### # #       # #",
        "#   ##### ### # ######### #",
        "######### ### #           #",
        "# ####### ### #############",
        "A           #   ###   #   #",
        "# ############# ### # # # #",
        "# ###       # # ### # # # #",
        "# ######### # # ### # # # F",
        "#       ### # #     # # # #",
        "# ######### # ##### # # # #",
        "# #######   #       #   # #",
        "# ####### ######### #######",
        "#         #########       #",
        "#######E############D######"
};

int x_max = 26, y_max = 24, x_min = 0, y_min = 0;

void helper (int x, int y) {
    if (x <= ::x_max && x >= ::x_min && y <= ::y_max && y >= y_min) {
        if (::maze[y][x] == ' ') {
            ::maze[y][x] = '*';
            helper(x + 1, y);
            helper(x - 1, y);
            helper(x, y + 1);
            helper(x, y - 1);
        } else if (::maze[y][x] <= 'Z' && ::maze[y][x] >= 'A') std::cout << ::maze[y][x] << ' ';
    }
}

int main() {
    int x, y;
    std::cin >> x >> y;
    if (::maze[y][x] == '#' || x < ::x_min || x > ::x_max || y > ::y_max || y < ::y_min) {
        std::cout << "ERROR" << std::endl;
    } else {
        helper(x, y);
    }
    return 0;
}